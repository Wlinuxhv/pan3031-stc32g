# PAN3031 STC32G Keil 工程配置

## 项目结构

```
pan3031_stc32g/
├── User/
│   └── main.c
├── HAL/
│   ├── gpio/
│   │   ├── gpio.c
│   │   └── gpio.h
│   ├── spi/
│   │   ├── spi.c
│   │   └── spi.h
│   ├── delay/
│   │   ├── delay.c
│   │   └── delay.h
│   └── uart/
│       ├── uart.c
│       └── uart.h
├── Radio/
│   ├── inc/
│   │   ├── pan3031.h
│   │   ├── pan3031_port.h
│   │   ├── radio.h
│   │   └── crc.h
│   └── src/
│       ├── pan3031.c
│       ├── pan3031_port.c
│       ├── radio.c
│       └── crc.c
├── STC32G.h
├── STARTUP.A51
└── README.md
```

## Keil uVision5 配置步骤

### 1. 创建新工程
1. 打开 Keil uVision5
2. Project -> New uVision Project
3. 选择保存路径，输入工程名（如 `PAN3031_STC32G.uvproj`）
4. 选择 STC32G 系列芯片（STC32G12K128 或类似）

### 2. 添加源文件到工程
创建以下 Groups 并添加对应文件：

- **StartUp**: `STARTUP.A51`
- **User**: `User/main.c`
- **HALgpio**: `HAL/gpio/gpio.c`
- **HALspi**: `HAL/spi/spi.c`
- **HALdelay**: `HAL/delay/delay.c`
- **HALuart**: `HAL/uart/uart.c`
- **Radio**: 
  - `Radio/src/pan3031.c`
  - `Radio/src/pan3031_port.c`
  - `Radio/src/radio.c`
  - `Radio/src/crc.c`

### 3. 配置 Include Path
在 Options for Target -> C51 -> Include Paths 中添加：

```
..\..\HAL\gpio
..\..\HAL\spi
..\..\HAL\delay
..\..\HAL\uart
..\..\Radio\inc
..\.
```

### 4. 晶振设置
Options for Target -> Target -> Xtal (MHz): 24.0

### 5. 烧录配置
使用 STC-ISP 工具进行烧录：
- 波特率：115200 或 57600
- 冷启动烧录
- 勾选 "复位脚用作IO口"（如需节省IO）

## 引脚分配

| 功能 | 引脚 | 说明 |
|------|------|------|
| SCK | P2.0 | SPI 时钟 |
| MISO | P2.1 | SPI 数据输出 |
| MOSI | P2.2 | SPI 数据输入 |
| CS | P2.3 | SPI 片选 |
| IRQ | P3.2 | 无线模块中断输出 |
| RST | P3.3 | 无线模块复位 |
| TX_EN | P3.4 | 发射使能 |
| RX_EN | P3.5 | 接收使能 |
| LED1 | P5.4 | 状态指示灯 |
| UART1 | P3.0(TX)/P3.1(RX) | 调试串口 |

## 编译选项建议

- Enable Use Linker Code Banking: No (STC32G 有足够 Flash)
- Memory Model: Small: Variables in DATA
- Code ROM Size: Large: 64K program
