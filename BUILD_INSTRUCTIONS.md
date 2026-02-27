# PAN3031 STC32G 构建说明

## 方法 1：使用 Self-Hosted Runner（自动）

### 前提条件

Runner 机器上需要安装以下工具之一：

#### 选项 A：SDCC（推荐）
下载地址：https://sourceforge.net/projects/sdcc/files/

或使用 Chocolatey：
```powershell
choco install sdcc -y
```

验证安装：
```powershell
sdcc -v
```

#### 选项 B：Keil uVision5
- 安装 Keil uVision5
- 确保安装路径为 `C:\Keil_v5` 或更新 PATH

### 触发构建

```powershell
cd C:\Users\User\.openclaw\workspace\pan3031_stc32g
git commit --allow-empty -m "Trigger build"
git push
```

### 下载 HEX

构建完成后：
1. 打开 https://github.com/Wlinuxhv/pan3031-stc32g/actions
2. 点击最近的构建
3. 下载 `pan3031_stc32g_hex.zip`

---

## 方法 2：本地手动编译（Keil）

### 步骤

1. **打开 Keil uVision5**

2. **创建新工程**
   - Project → New uVision Project
   - 选择芯片：STC32G12K128

3. **添加文件**
   - User: `User/main.c`
   - HAL: `HAL/*/ *.c` (所有 .c 文件)
   - Radio: `Radio/src/*.c` (所有 .c 文件)

4. **配置 Include Paths**
   - Options → C51 → Include Paths
   - 添加：
     ```
     .\HAL\spi
     .\HAL\gpio
     .\HAL\delay
     .\HAL\uart
     .\Radio\inc
     .\User
     .
     ```

5. **配置晶振**
   - Options → Target → Xtal: 24.0 (MHz)

6. **编译**
   - Project → Rebuild all target files
   - 输出：`Objects\pan3031_stc32g.hex`

---

## 方法 3：本地手动编译（SDCC）

```powershell
cd C:\Users\User\.openclaw\workspace\pan3031_stc32g

# 安装 SDCC（如果还没有）
# 从 https://sourceforge.net/projects/sdcc/files/ 下载

# 编译
make clean
make all

# 输出：build/pan3031_stc32g.hex
```

---

## 烧录到 STC32G

1. 下载 **STC-ISP** 工具
2. 连接开发板
3. 选择 HEX 文件
4. 点击"下载/编程"
5. 冷启动复位

---

## 故障排查

### SDCC 编译错误

如果遇到类型定义冲突：
- 检查 `STC32G.h` 是否包含重复的 typedef
- 使用 `--std-sdcc99` 标志

### Keil 编译错误

- 确保选择了正确的芯片型号
- 检查 Include Paths 是否正确
- 尝试 Clean 后 Rebuild

### Runner 不工作

```powershell
# 检查 runner 状态
cd C:\actions-runner
.\run.cmd

# 查看日志
Get-Content _diag\*.log -Tail 50
```
