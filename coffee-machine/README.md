# Demo coffee-machine

## Table of Contents

- [Demo coffee-machine](#demo-coffee-machine)
  - [Table of Contents](#table-of-contents)
  - [Supported IC](#supported-ic)
  - [Hardware configurations](#hardware-configurations)
  - [How to use](#how-to-use)

## Supported IC

1. AmebaGreen2

## Hardware configurations

Need to prepare a ST7262 screen with RGB interface and insert it on the board.

## How to use

Build and Download:

* Git clone source code ameba-rtos from github and put it at the same level as this demo coffee-machine folder
* Need to enable the macro `#define LV_FONT_MONTSERRAT_46 1` in `component/ui/LVGL/lvgl-9.3/port/amebagreen2/lv_conf.h`
* Use CMD `source env.sh && ameba.py build` to compile this example.
* `Download` images to board by Ameba Image Tool.
