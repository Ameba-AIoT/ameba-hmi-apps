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
| **coffee-machine**| RTL8721F| RGB                              | 咖啡机控制界面                                                                |
| **e-bike**        | RTL8721F| RGB                               | 电动车仪表界面——车速、电量与骑行组件                                              |
| **smart-hub**     | RTL8730E| MIPI                               | 智能家居中枢——智能家居、温控、EV 充电、智能电表、关于等多个子应用                     |


## 🔌 支持的芯片

| 芯片                   |         master         |
|:---------------------- |:----------------------:|
| RTL8721F| ![alt text][supported] |
| RTL8730E | ![alt text][supported] |

[supported]: https://img.shields.io/badge/-%E6%94%AF%E6%8C%81-green "supported"

## 🚀 快速开始

下面以 **coffee-machine** 为例。编 **e-bike** 时把目录名换掉，并跳过第 2 步。

### 1. 把 ameba-rtos 放在 ameba-hmi-apps 同级

在同一个工作目录下克隆两个仓库。ameba-rtos 要带 submodule（`component/ui` 就是 ameba-ui，必需）：

```bash
git clone https://github.com/Ameba-AIoT/ameba-hmi-apps.git
git clone --recurse-submodules https://github.com/Ameba-AIoT/ameba-rtos.git
```

```text
<workspace>/
├── ameba-rtos/              # SDK
└── ameba-hmi-apps/
    ├── coffee-machine/      # 应用（外部工程）
    ├── e-bike/              # 应用（外部工程）
    └── smart-hub/
```

应用目录里的 `env.sh` / `env.bat` 只有一行，作用是加载 ameba-rtos 里的 `env.sh` / `env.bat`，默认路径是 `../../ameba-rtos/env.sh` / `..\..\ameba-rtos\env.bat`，对应上面的目录结构。ameba-rtos 放在其他位置也可以，把这一行改成指向你的 `ameba-rtos/env.sh` / `ameba-rtos\env.bat` 即可。

### 2. 打开 LVGL 字体（仅 coffee-machine）

coffee-machine 用到 Montserrat 46 号字体，默认是关的。修改
`<workspace>/ameba-rtos/component/ui/LVGL/config/amebagreen2/lv_conf.h`：

```c
#define LV_FONT_MONTSERRAT_46 1
```

e-bike 不需要这一步。

### 3. 编译

所有命令都在应用目录里、**同一个终端**中执行（`ameba.py` 命令由 `env.sh` / `env.bat` 设置，只对当前终端有效）：

```bash
cd ameba-hmi-apps/coffee-machine
source env.sh                 # Linux / macOS
# env.bat                     # Windows
ameba.py soc RTL8721F         # 选择芯片，只需执行一次
ameba.py build
```

最后输出 `Build done` 即编译成功。镜像生成在应用目录下：

```text
coffee-machine/build_RTL8721F/
├── boot.bin
├── app.bin
└── ota_all.bin
```

### 4. 烧录并运行

用 **Ameba Image Tool** 烧录 `boot.bin` 和 `app.bin`，或者在同一个终端里执行：

```bash
ameba.py flash -p <PORT>              # 烧录 build_RTL8721F/ 下的镜像
ameba.py monitor -p <PORT> -b 1500000 # 打开串口日志
```

复位后，屏幕上会显示应用界面。

> 这些演示没有开启触摸输入。

## 💬 反馈

* 如果你在开发过程中有任何问题或建议，请登录 [Real-AIOT 论坛](https://forum.real-aiot.com/) 给我们反馈。
* 如果你发现了错误或需要新功能，请先[查看 GitHub Issues](https://github.com/Ameba-AIoT/ameba-hmi-apps/issues)，确保该问题尚未被提交。
