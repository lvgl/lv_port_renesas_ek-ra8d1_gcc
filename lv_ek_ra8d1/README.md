# lv_ek_ra8d1

LVGL ported to Renesas EK-RA8D1 development board.

## Board setup
- Attach the MIPI LCD PCB to the main PCB
- On SW1 DIP switched (middle of the board) 7 should be ON, all others are OFF
- Connect the USD cable to the `Debug1` (J10) connector

## Get started
- Install [Renesas E2 Studio](https://www.renesas.com/us/en/software-tool/e-studio)
- Clone the `lv_renesas` repository with submodules: `git clone https://github.com/lvgl/lv_renesas.git --recurse-submodules`
- Import `lv_ek_ra8d1` in E2 Studio
- Build and Flash the

## Debugging
- Debug  `printf` output is via the Jlink VCOM port, 921600 8,n,1
