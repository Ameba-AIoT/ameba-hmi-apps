<div align="center">

<img src="docs/image.png" alt="ameba-hmi-apps HMI demos" width="800">

# ameba-hmi-apps

**Ready-to-run HMI demo applications for Realtek Ameba series chips, built on LVGL.**

[![LVGL](https://badgen.net/badge/LVGL/9.3/blue)](https://lvgl.io)
[![Language](https://badgen.net/badge/language/C/blue)](https://github.com/Ameba-AIoT/ameba-hmi-apps/search?l=c)
[![Based on](https://badgen.net/badge/based%20on/ameba--rtos%20%2B%20ameba--ui/blue)](https://github.com/Ameba-AIoT/ameba-rtos)
[![Last Commit](https://badgen.net/github/last-commit/Ameba-AIoT/ameba-hmi-apps/master?icon=github)](https://github.com/Ameba-AIoT/ameba-hmi-apps/commits/master)

[English](README.md) · [中文版](README_CN.md) · [Documentation](https://aiot.realmcu.com/en/latest/rtos/index.html) · [ameba-rtos](https://github.com/Ameba-AIoT/ameba-rtos) · [ameba-ui](https://github.com/Ameba-AIoT/ameba-ui)

</div>

ameba-hmi-apps is a collection of ready-to-run Human-Machine Interface (HMI) demo applications for Realtek Ameba series SoCs. Each app is built on the LVGL graphics library and the [ameba-ui](https://github.com/Ameba-AIoT/ameba-ui) middleware, and runs on top of [ameba-rtos](https://github.com/Ameba-AIoT/ameba-rtos). They serve as reference designs you can flash, study and adapt for your own product UI.

## 🎨 Applications

| App               | Chip                   | Display | Highlights                                                                          |
|:----------------- |:---------------------- |:------- |:----------------------------------------------------------------------------------- |
| **coffee-machine**| RTL8721F | RGB     | Coffee-machine control UI                                                           |
| **e-bike**        | RTL8721F | RGB     | E-bike dashboard UI — speed, battery and ride widgets                               |
| **smart-hub**     | RTL8730E| MIPI    | Smart-home hub — smart home, thermostat, EV charging, smart meter, about and more   |

## 🔌 Supported Chips

| Chip                   |         master         |
|:---------------------- |:----------------------:|
| RTL8721F | ![alt text][supported] |
| RTL8730E| ![alt text][supported] |

[supported]: https://img.shields.io/badge/-supported-green "supported"

## 🚀 Quick Start

The steps below use **coffee-machine** as the example. For **e-bike**, replace the folder name and skip step 2.

### 1. Place ameba-rtos next to ameba-hmi-apps

Clone both repositories into the same workspace folder. Clone ameba-rtos with submodules (`component/ui` is the ameba-ui submodule and is required):

```bash
git clone https://github.com/Ameba-AIoT/ameba-hmi-apps.git
git clone --recurse-submodules https://github.com/Ameba-AIoT/ameba-rtos.git
```

```text
<workspace>/
├── ameba-rtos/              # SDK
└── ameba-hmi-apps/
    ├── coffee-machine/      # app (external project)
    ├── e-bike/              # app (external project)
    └── smart-hub/
```

The `env.sh` / `env.bat` in each app folder is a single line that loads `env.sh` / `env.bat` from ameba-rtos. By default it points to `../../ameba-rtos/env.sh` / `..\..\ameba-rtos\env.bat`, which matches the layout above. ameba-rtos can be placed anywhere else; just change that line to point to your `ameba-rtos/env.sh` / `ameba-rtos\env.bat`.

### 2. Enable the LVGL font (coffee-machine only)

coffee-machine uses the Montserrat 46 font, which is disabled by default. Edit
`<workspace>/ameba-rtos/component/ui/LVGL/config/amebagreen2/lv_conf.h`:

```c
#define LV_FONT_MONTSERRAT_46 1
```

e-bike does not need this step.

### 3. Build

Run all commands from inside the app folder, in the **same terminal** (the `ameba.py` command is set up by `env.sh` / `env.bat` for the current terminal only):

```bash
cd ameba-hmi-apps/coffee-machine
source env.sh                 # Linux / macOS
# env.bat                     # Windows
ameba.py soc RTL8721F         # select the chip, only needed once
ameba.py build
```

The build ends with `Build done`. The images are generated in the app folder:

```text
coffee-machine/build_RTL8721F/
├── boot.bin
├── app.bin
└── ota_all.bin
```

### 4. Flash and run

Flash `boot.bin` and `app.bin` with the **Ameba Image Tool**, or from the same terminal:

```bash
ameba.py flash -p <PORT>              # flashes the images in build_RTL8721F/
ameba.py monitor -p <PORT> -b 1500000 # open the serial log
```

After reset, the panel shows the app UI.

> Touch input is not enabled in these demos.

## 💬 Feedback

* For questions or suggestions during development, visit the [Real-AIOT Forum](https://forum.real-aiot.com/).
* For bugs or feature requests, [check the GitHub Issues](https://github.com/Ameba-AIoT/ameba-hmi-apps/issues). Please check existing issues before opening a new one.
