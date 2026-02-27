# PAN3031 STC32G 项目状态

## ✅ 已完成

1. **代码移植** - PAN3031 驱动已从 STM32F0 移植到 STC32G12K128
2. **GitHub 仓库** - 代码已推送到 https://github.com/Wlinuxhv/pan3031-stc32g
3. **GitHub Actions** - CI/CD 配置文件已创建
4. **硬件抽象层** - SPI/GPIO/UART/Delay 已重写为 STC32G 版本

## ⚠️ 当前问题

### 1. SDCC 编译错误

需要修复的问题：
- `STC32G.h` 中的类型定义与 SDCC 标准库冲突
- `main.c` 中的中断函数语法需要调整
- `OK/FAIL` 宏定义冲突

### 2. 建议的解决方案

**方案 A：使用 Keil C51（推荐）**
- 在本地 Windows 上使用 Keil uVision 编译
- STC32G 官方支持 Keil C51
- 下载：https://www.keil.com/

**方案 B：修复 SDCC 兼容性**
- 移除 `STC32G.h` 中的类型定义（使用 SDCC 内置的）
- 修改中断函数语法
- 统一宏定义

## 📁 项目结构

```
pan3031_stc32g/
├── .github/workflows/    # GitHub Actions 配置
├── HAL/                  # 硬件抽象层
├── Radio/                # PAN3031 驱动
├── User/                 # 用户代码
├── STC32G.h             # 寄存器定义
├── Makefile             # SDCC 编译配置
└── README.md            # 项目说明
```

## 🔧 本地编译步骤（推荐）

### 使用 Keil C51

1. 安装 Keil uVision5
2. 创建新工程，选择 STC32G12K128
3. 添加所有 `.c` 文件
4. 配置 Include Paths
5. 编译生成 HEX

### 使用 SDCC（需要修复）

```bash
# 安装 SDCC
sudo apt-get install sdcc  # Linux
# 或从 https://sourceforge.net/projects/sdcc/files/ 下载 Windows 版本

# 修复代码后编译
make clean
make all
```

## 📥 下载 HEX 文件

一旦构建成功，HEX 文件将通过 GitHub Actions 自动生成：
1. 进入仓库 Actions 标签
2. 点击最近的构建
3. 下载 Artifacts 中的 `pan3031_stc32g_hex.zip`

## 📝 下一步

1. **修复 SDCC 兼容性** 或 **使用 Keil 编译**
2. **烧录测试** - 使用 STC-ISP 工具
3. **硬件调试** - 验证 SPI 通信和无线功能

## 🔗 相关链接

- 仓库：https://github.com/Wlinuxhv/pan3031-stc32g
- Actions: https://github.com/Wlinuxhv/pan3031-stc32g/actions
- STC32G 数据手册：https://www.stcmcu.com/datasheet/stc/stc32g/stc32g12k128.pdf
