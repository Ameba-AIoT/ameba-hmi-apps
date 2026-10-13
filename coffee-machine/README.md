# Demo coffee-machine

## Table of Contents

- [Demo coffee-machine](#demo-coffee-machine)
  - [Table of Contents](#table-of-contents)
  - [Supported IC](#supported-ic)
  - [Hardware configurations](#hardware-configurations)
  - [How to use](#how-to-use)

## Supported IC

1. RTL8721F

## Hardware configurations

Prepare an 800×480 RGB screen (ST7262) and connect it to the board.

The SDK default panel setting (**Panel Selection → St7701s**, 800×480 RGB) is used, so no panel configuration is needed. Touch input is not enabled in this demo.

## How to use

Build and Download:

* Clone [ameba-rtos](https://github.com/Ameba-AIoT/ameba-rtos) with submodules and put it at the same level as `ameba-hmi-apps`:

  ```text
  <workspace>/
  ├── ameba-rtos/
  └── ameba-hmi-apps/
      └── coffee-machine/
  ```

  `env.sh` / `env.bat` in this folder loads `../../ameba-rtos/env.sh` / `..\..\ameba-rtos\env.bat`. If ameba-rtos is placed elsewhere, change that line to point to it.

* Enable the macro below in `ameba-rtos/component/ui/LVGL/config/amebagreen2/lv_conf.h`:

  ```c
  #define LV_FONT_MONTSERRAT_46 1
  ```

* Run the following commands in this folder to compile:

  ```bash
  source env.sh                 # Windows: env.bat
  ameba.py soc RTL8721F         # only needed once
  ameba.py build
  ```

  The images are generated in `build_RTL8721F/`.

* Download `boot.bin` and `app.bin` to the board with the Ameba Image Tool, or run `ameba.py flash -p <PORT>`.
