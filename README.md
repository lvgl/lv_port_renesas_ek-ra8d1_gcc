# LVGL ported to Renesas EK-RA8D1

**:rocket: This repository is available in the [LVGL Project Creator](https://lvgl.io/tools/project-creator), making it easy to create and customize a new project in just a few clicks.**

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
](https://www.youtube.com/watch?v=WkJPB8wto_U)
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

- [Install the FSP v6.5.0 Platform](https://www.renesas.com/en/software-tool/ra-flexible-software-package-fsp#overview).
  - When prompted, choose "Custom Install".
  - Ensure "Renesas RA" is included in your selection of "Additional Software" to install.
  - Ensure "Renesas FSP v6.5.0" and "GNU ARM Embedded 13.2-Rel1" are selected.
- [Download the FSP v6.5.1 Pack](https://github.com/renesas/fsp/releases/tag/v6.5.1)
  - On **Windows**, download the `FSP_Packs_v6.5.1.exe` file and run it.
  - On **Linux**, download the `FSP_Packs_v6.5.1.zip` file and extract it into your packs folder:
    - Locate the e2 studio install location. The most reliable way is to go through
      **Help > CMSIS Pack Management > Renesas RA** — the packs location is shown at the top of the menu.
    - If the location is something like `~/.eclipse/com.renesas.platform_808163849/internal/projectgen/ra/packs`
      and the pack was downloaded to `Downloads`, run:
      ```bash
      unzip -o ~/Downloads/FSP_Packs_v6.5.1.zip -d ~/.eclipse/com.renesas.platform_808163849
      ```
      The directory structure in the ZIP overlaps with the packs install location. This is expected.
      The `unzip` process will update the directory structure with the new FSP files from the ZIP
      and preserve any existing FSP packs.

> **Note:** If you already have a recent e2 studio installed, the pack overlay on its own is
> usually enough — you can skip the platform install and just check that "6.5.1" appears in the
> FSP version dropdown. This was verified working on e2 studio 25.10.0.

### Run the project

- Clone this repository:
    ```bash
    git clone https://github.com/lvgl/lv_port_renesas_ek-ra8d1_gcc.git
    ```
    LVGL itself ships with the FSP LVGL pack, so there are no submodules to check out.
- Open e2 studio and go to **File > Open Projects from File System...**. Click "Directory",
  navigate to the cloned project, then click "Finish".
- Ensure "GNU ARM Embedded 13.2-Rel1" is selected as the toolchain in
  **Project > Properties > C/C++ Build > Settings > Toolchain**.
- Click the hammer to build the project. If it is greyed-out, first single-click the project
  "lv_port_renesas_ek-ra8d1_gcc" in the left sidebar and the hammer should become clickable.
- To upload and run the project, click the bug (debug) icon. The debugger will break (stop execution)
  at the beginning. Click the "Resume" button to continue execution.
- To upload the optimized Release version of the build, open the dropdown next to the bug
  icon and click "Debug Configurations...". Change the "C/C++ Application:" to start with
  "Release/" instead of "Debug/". It's also recommended to set the "Build Configuration:"
  to "Release". Remember to change these settings back if you want a good experience debugging
  the app.

- To learn more about Renesas's *RA family* check out this section of the [*documentation*](https://docs.lvgl.io/master/integration/chip/renesas.html#get-started-with-the-renesas-ecosystem).

### Debugging
- In the previous section, the project was run using the debugger.
  Simply continue using the interactive debugger in e2 studio to debug your program.
  Set breakpoints, continue, step, etc. as with any other Eclipse-based IDE.

## LVGL Pro

FSP 6.5.1 uses LVGL v9.5.0 which you can build your UI for using [LVGL Pro](https://lvgl.io/pro).

Check out the official [LVGL Pro e2 studio integration documentation](https://lvgl.io/docs/pro/integration/renesas).

## Notes

e2 studio has a configurator to adjust configuration settings. If you want to change an
LVGL config, first check if it's an option present in the FSP Configurator. To get there,
open the "FSP Configuration" perspective by clicking the tab in the very top-right corner
of the window. Next, open "configuration.xml" by double-clicking it in the "Project Explorer".
When you are done, make sure to click "Generate Project Content".
For all other configs, `src/lv_conf_user.h` is the file to edit. `ra_cfg/fsp_cfg/lvgl/lvgl/lv_conf.h`
includes this file and has some defaults which will be set if they are not explicitly set in
`src/lv_conf_user.h`.
To see all the possible LVGL configs, look at `./ra/lvgl/lvgl/lv_conf_template.h`.

LVGL comes from the FSP so the source code will appear upon building. It can be edited
in-place, but changes will be lost if a "clean" is performed.

Debug `printf` output is via the J-Link VCOM port, 921600 8,n,1.
You can open any serial terminal on your PC to view it.

## Contribution and Support

If you find any issues with the development board feel free to open an Issue in this repository. For LVGL related issues (features, bugs, etc) please use the main [lvgl repository](https://github.com/lvgl/lvgl). 

If you found a bug and found a solution too please send a Pull request. If you are new to Pull requests refer to [Our Guide](https://lvgl.io/docs/open/contributing/pull_requests) to learn the basics.

