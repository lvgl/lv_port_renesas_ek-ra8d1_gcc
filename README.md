# Renesas and LVGL

This repository hosts ready to use Renesas development board projects to easily get started with LVGL on these devices

## Prerequisites
1. Install [Renesas E2 Studio](https://www.renesas.com/us/en/software-tool/e-studio)
2. Be sure `git` is installed

## Usage
1. `git clone https://github.com/lvgl/lv_renesas.git --recurse-submodules`
2. Open E2 Studio and import the project you like
3. Hit the build and Flush or Debug button

## EK-RA8D1 Board Configuration
1. MIPI LCD PCB attached to the main PCB using plastic stand-offs provided
2. USB cable connected from J10 to the development PC
3. DIP switch SW1 settings :- 
    SW1-7 - ON (SDRAM) (Framebuffer is located in SDRAM)
    Rest of SW1 OFF (Other settings are possible, check documentation and schematics)
   
4. Debug printf output is via the Jlink VCOM port, 921600 8,n,1

## Contributing
- Feel free to open issues if you find any bugs or have suggestions
- If you found the solution for an issue, please send a Pull request 
