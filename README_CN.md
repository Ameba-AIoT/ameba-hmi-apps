<div align="center">

<img src="docs/image.png" alt="ameba-hmi-apps HMI 演示集" width="800">

# ameba-hmi-apps

**面向瑞昱 Ameba 系列芯片、基于 LVGL 的开箱即用 HMI 演示应用集。**

[![LVGL](https://badgen.net/badge/LVGL/9.3/blue)](https://lvgl.io)
[![Language](https://badgen.net/badge/language/C/blue)](https://github.com/Ameba-AIoT/ameba-hmi-apps/search?l=c)
[![Based on](https://badgen.net/badge/based%20on/ameba--rtos%20%2B%20ameba--ui/blue)](https://github.com/Ameba-AIoT/ameba-rtos)
[![Last Commit](https://badgen.net/github/last-commit/Ameba-AIoT/ameba-hmi-apps/master?icon=github)](https://github.com/Ameba-AIoT/ameba-hmi-apps/commits/master)

[English](README.md) · [中文版](README_CN.md) · [文档](https://aiot.realmcu.com/zh/latest/rtos/index.html) · [ameba-rtos](https://github.com/Ameba-AIoT/ameba-rtos) · [ameba-ui](https://github.com/Ameba-AIoT/ameba-ui)

</div>

ameba-hmi-apps 是面向瑞昱 Ameba 系列芯片的人机界面（HMI）演示应用集合。每个应用都基于 LVGL 图形库与 [ameba-ui](https://github.com/Ameba-AIoT/ameba-ui) 中间件，运行在 [ameba-rtos](https://github.com/Ameba-AIoT/ameba-rtos) 之上。它们可作为参考设计——直接烧录、学习并改造成你自己的产品 UI。

## 🎨 应用一览

| 应用              | 芯片                   | 显示                                 | 亮点                                                                       |
|:----------------- |:---------------------- |:------------------------------------ |:-------------------------------------------------------------------------- |
| **caffee-machine**| RTL8721F| RGB                              | 咖啡机控制界面                                                                |
| **e-bike**        | RTL8721F| RGB                               | 电动车仪表界面——车速、电量与骑行组件                                              |
| **smart-hub**     | RTL8730E| MIPI                               | 智能家居中枢——智能家居、温控、EV 充电、智能电表、关于等多个子应用                     |


## 🔌 支持的芯片

| 芯片                   |         master         |
|:---------------------- |:----------------------:|
| RTL8721F| ![alt text][supported] |
| RTL8730E | ![alt text][supported] |

[supported]: https://img.shields.io/badge/-%E6%94%AF%E6%8C%81-green "supported"

## 🚀 快速开始

这些演示使用 ameba-rtos 工具链构建，开箱即可编译。

**1. 把 ameba-rtos 放在演示目录同级**

克隆 [ameba-rtos](https://github.com/Ameba-AIoT/ameba-rtos)（带 submodule，这样 `component/ui`（即 ameba-ui）也会一并拉取），并与演示文件夹放在**同一级目录**：

```bash
git clone --recurse-submodules https://github.com/Ameba-AIoT/ameba-rtos.git
```

```text
<workspace>/
├── ameba-rtos/
└── ameba-hmi-apps/caffee-machine/   # （或 e-bike）
```

**2. 启用所需的 LVGL 字体**

例如 `caffee-machine` 需要在
`component/ui/LVGL/lvgl-9.3/port/amebagreen2/lv_conf.h` 中启用 `LV_FONT_MONTSERRAT_46`：

```c
#define LV_FONT_MONTSERRAT_46 1
```

**3. 编译**

在演示文件夹内执行：

```bash
source env.sh && ameba.py build   # Linux
env.bat && ameba.py build         # Windows
```

**4. 烧录**

用 **Ameba Image Tool** 把固件与图片资源下载到板子。

## 💬 反馈

* 如果你在开发过程中有任何问题或建议，请登录 [Real-AIOT 论坛](https://forum.real-aiot.com/) 给我们反馈。
* 如果你发现了错误或需要新功能，请先[查看 GitHub Issues](https://github.com/Ameba-AIoT/ameba-hmi-apps/issues)，确保该问题尚未被提交。
