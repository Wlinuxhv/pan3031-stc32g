# 🚀 快速编译指南

## 方式 1：使用 GitHub Actions（推荐）

### 步骤 1：安装 SDCC

1. **下载页面已打开**：https://sourceforge.net/projects/sdcc/files/sdcc/4.4.0/
2. 点击 **"Download"** 按钮
3. 运行下载的 `sdcc-4.4.0-x64-setup.exe`
4. 使用默认路径安装：`C:\Program Files\SDCC`
5. 安装完成后**重启 PowerShell**

### 步骤 2：验证安装

```powershell
# 打开新的 PowerShell
"C:\Program Files\SDCC\bin\sdcc.exe" -v
```

应该看到：`SDCC : mcs51/gbz80/z80/z180/r2k/r2ka/r3ka/... 4.4.0`

### 步骤 3：触发构建

```powershell
cd C:\Users\User\.openclaw\workspace\pan3031_stc32g
git commit --allow-empty -m "Trigger HEX build"
git push
```

### 步骤 4：下载 HEX

1. 打开：https://github.com/Wlinuxhv/pan3031-stc32g/actions
2. 点击最近的构建（应该显示 ✅ success）
3. 在页面底部找到 **"Artifacts"**
4. 点击 **`pan3031_stc32g_hex`** 下载

---

## 方式 2：本地一键编译

### 安装 SDCC 后

双击运行：`build.bat`

或命令行：
```powershell
cd C:\Users\User\.openclaw\workspace\pan3031_stc32g
.\build.bat
```

编译成功后，HEX 文件位置：
```
build\pan3031_stc32g.hex
```

---

## 方式 3：手动触发 GitHub Actions

如果 push 没有自动触发构建：

1. 打开：https://github.com/Wlinuxhv/pan3031-stc32g/actions
2. 点击 **"Build HEX (Self-Hosted)"** workflow
3. 点击 **"Run workflow"** 按钮
4. 选择分支（master）
5. 点击 **"Run workflow"**
6. 等待构建完成（约 1-2 分钟）
7. 下载 HEX 文件

---

## 📥 烧录到 STC32G

1. 下载 **STC-ISP** 工具
   - http://www.stcmcu.com/
   
2. 连接开发板 USB

3. 打开 STC-ISP

4. 选择：
   - 芯片型号：**STC32G12K128**
   - HEX 文件：`build\pan3031_stc32g.hex`

5. 点击 **"下载/编程"**

6. 给开发板**断电再上电**（冷启动）

7. 等待烧录完成

---

## 🔧 故障排查

### SDCC 安装后找不到命令

```powershell
# 刷新环境变量
$env:Path = [System.Environment]::GetEnvironmentVariable("Path","Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path","User")

# 验证
& "C:\Program Files\SDCC\bin\sdcc.exe" -v
```

### 编译错误

查看 `build/` 目录下的 `.lst` 文件获取详细错误信息。

### Runner 不在线

```powershell
# 检查 runner 状态
cd C:\actions-runner
.\run.cmd
```

---

## 📝 下一步

HEX 文件生成后：

1. **烧录到开发板**（见上方）
2. **连接串口调试**（115200 波特率）
3. **测试无线功能**

---

**需要帮助？** 查看：
- [BUILD_INSTRUCTIONS.md](BUILD_INSTRUCTIONS.md) - 详细构建说明
- [KEIL_SETUP.md](KEIL_SETUP.md) - Keil 配置指南
- [STATUS.md](STATUS.md) - 项目状态
