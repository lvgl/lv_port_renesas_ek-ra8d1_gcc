# LVGL ported to Renesas EK-RA8D1

## Overview

The EK-RA8D1 evaluation kit enables users to effortlessly evaluate the features of the RA8D1 MCU Group and develop embedded systems applications using Renesas’ Flexible Software Package (FSP) and e2 studio IDE. Utilize rich on-board features along with your choice of popular ecosystem add-ons to bring your big ideas to life.

The MCU has a Cortex-M85 core which utilizes the Helium (SIMD) instruction set of Arm. Besides that the chip is equipped with a GPU (called DAVE2D) to off load the MCU.

## Buy

You can purchase the Renesas EK-RA8D1 board from many distributors. See the sources at https://renesas.com/ek-ra8d1

## Benchmark

During the benchmark 2 frame buffer were used in the external SRRAM. LVGL was configured to `LV_DISPLAY_RENDER_MODE_DIRECT` and the buffer were swapped on VSYNC to avoid tearing.

As observed in the video, the FPS only drops in highly complex scenarios, while CPU usage remains low. For instance, when multiple ARGB images were rotated, the FPS dropped to 12 and the rendering time increased to 66 ms, but the CPU usage stayed at 10%. Using software rendering only the FPS would be significantly lower, and the CPU usage would peak at 100%.

Check out EK-RA8D1 in action, running LVGL's benchmark demo:
[![image](https://github.com/lvgl/lv_port_renesas_ek-ra8d1/assets/7599318/7dab86d6-b092-495b-a989-2555118d7570)
](https://www.youtube.com/watch?v=WkJPB8wto_U)$

## Specification

### CPU and Memory
- **MCU:** R7FA8D1BHECBD (Cortex-M85, 480MHz)
- **RAM:** 1MB internal, 64MB external SDRAM
- **Flash:** 2MB internal, 64MB External Octo-SPI Flash
- **GPU:** Dave2D

### Display and Touch
- **Resolution:** 480x854
- **Display Size:** 4.5”
- **Interface:** 2-lane MIPI
- **Color Depth:** 24-bit
- **Technology:** IPS
- **DPI:** 217 px/inch
- **Touch Pad:** Capacitive

### Connectivity
- Camera expansion board
- Micro USB device cable (type-A male to micro-B male)
- Micro USB host cable (type-A male to micro-B male)
- Ethernet patch cable

## Getting started

### Hardware setup
- Attach the MIPI LCD PCB to the main PCB
- On SW1 DIP switched (middle of the board) 7 should be ON, all others are OFF
- Connect the USB cable to the `Debug1` (J10) connector

### Software setup
- Get e2studio (Eclipse based Renesas IDE) and the latest FSP (Flexible Software Package, the SDK of Renesas) from [https://github.com/renesas/fsp/releases](https://github.com/renesas/fsp/releases).
- Clone this repository with the following command:
    ```
    git clone https://github.com/lvgl/lv_port_renesas_ek-ra8d1.git --recurse-submodules
    ```
    Downloading the `.zip` from GitHub doesn't work as it doesn't download the submodules.

- Import the project in e2studio File -> Import -> General -> Existing Projects into Workspace.
- Open configuration.xml, which should open the FSP configuration view. Update the FSP if prompted.
- Click on the *Generate Project Content* to ensure the generated files are generated/up-to-date.
- Build the project.
- Flash the project using the Debug menu.
- You can now use the **Continue** button to start the execution.


- **Note:** Debug  `printf` output is via the Jlink VCOM port, 921600 8,n,1
- To learn more about Renesas's *RA family* check out this section of the [*documentation*](https://docs.lvgl.io/master/integration/chip/renesas.html#get-started-with-the-renesas-ecosystem).


### FSP version
The FSP currently used by this port is the version **5.8.0**. FSPs are backward compatible so when prompted, feel free to select the latest FSP.
In case e2studio updates the FSP, you can open an Issue asking to bump this port to the latest version, or read the Contribution section and add it yourself.


## OSPI usage
This port enables the OSPI external flash. The linker script defines a section called `graphical_assets`.

### Place all images & fonts in the OSPI
To place all images and fonts in the OSPI, set `LV_ATTRIBUTE_LARGE_CONST` in `lv_conf.h`:

``` c
#define LV_ATTRIBUTE_LARGE_CONST __attribute__((section(".graphical_assets")))
```
This will effectively place all images and fonts in the OSPI `.graphical_assets` section.

### Place some assets in the OSPI
If one wants to only place some images into the OSPI, it can be done by modifying the custom definition created by the image converter. The example bellow sets `LV_ATTRIBUTE_MY_IMAGE` to `__attribute__((section(".graphical_assets")))`.
It is then used in the `my_image_map` declaration:

``` c
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#elif defined(LV_BUILD_TEST)
#include "../lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_MY_IMAGE
#define LV_ATTRIBUTE_MY_IMAGE __attribute__((section(".graphical_assets")))
#endif

static const
LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_ARROWTOP
uint8_t my_image_map[] = ...
```
In that case, one must keep `LV_ATTRIBUTE_LARGE_CONST` undefined in `lv_conf.h`.

### OSPI initialization
The OSPI initialization is done in `board_init.c`. The initialization source code is taken from [this Renesas example](https://github.com/renesas/ra-fsp-examples/tree/master/example_projects/ek_ra8d1/ospi_b/ospi_b_ek_ra8d1_ep).


## Contribution and Support

If you find any issues with the development board feel free to open an Issue in this repository. For LVGL related issues (features, bugs, etc) please use the main [lvgl repository](https://github.com/lvgl/lvgl).

If you found a bug and found a solution too please send a Pull request. If you are new to Pull requests refer to [Our Guide](https://docs.lvgl.io/master/CONTRIBUTING.html#pull-request) to learn the basics.


