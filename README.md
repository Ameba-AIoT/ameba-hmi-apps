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
| **caffee-machine**| RTL8721F | RGB     | Coffee-machine control UI                                                           |
| **e-bike**        | RTL8721F | RGB     | E-bike dashboard UI — speed, battery and ride widgets                               |
| **smart-hub**     | RTL8730E| MIPI    | Smart-home hub — smart home, thermostat, EV charging, smart meter, about and more   |

## 🔌 Supported Chips

| Chip                   |         master         |
|:---------------------- |:----------------------:|
| RTL8721F | ![alt text][supported] |
| RTL8730E| ![alt text][supported] |

[supported]: https://img.shields.io/badge/-supported-green "supported"

## 🚀 Quick Start

These demos are built with the ameba-rtos toolchain and are ready to build out of the box.

**1. Place ameba-rtos next to the demo**

Clone [ameba-rtos](https://github.com/Ameba-AIoT/ameba-rtos) (with submodules, so `component/ui` / ameba-ui is included) at the **same directory level** as the demo folder:

```bash
git clone --recurse-submodules https://github.com/Ameba-AIoT/ameba-rtos.git
```

```text
<workspace>/
├── ameba-rtos/
└── ameba-hmi-apps/caffee-machine/   # (or e-bike)
```

**2. Enable any required LVGL fonts**

For example, `caffee-machine` needs `LV_FONT_MONTSERRAT_46` enabled in
`component/ui/LVGL/lvgl-9.3/port/amebagreen2/lv_conf.h`:

```c
#define LV_FONT_MONTSERRAT_46 1
```

**3. Build**

From inside the demo folder:

```bash
source env.sh && ameba.py build   # Linux
env.bat && ameba.py build         # Windows
```

**4. Flash**

Download the firmware and image assets to the board with the **Ameba Image Tool**.

## 💬 Feedback

* For questions or suggestions during development, visit the [Real-AIOT Forum](https://forum.real-aiot.com/).
* For bugs or feature requests, [check the GitHub Issues](https://github.com/Ameba-AIoT/ameba-hmi-apps/issues). Please check existing issues before opening a new one.
