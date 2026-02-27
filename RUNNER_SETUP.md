# Self-Hosted Runner 配置指南

## 1. 在 GitHub 上获取配置命令

1. 打开：https://github.com/Wlinuxhv/pan3031-stc32g/settings/actions
2. 滚动到 "Runners" 部分
3. 点击 "New self-hosted runner"
4. 选择 **Windows** 标签
5. 复制显示的命令

## 2. 下载并配置 Runner

以**管理员身份**打开 PowerShell，执行：

```powershell
# 创建工作目录
mkdir C:\actions-runner ; cd C:\actions-runner

# 下载 runner（替换 URL 为 GitHub 显示的最新版本）
Invoke-WebRequest -Uri "https://github.com/actions/runner/releases/download/v2.311.0/actions-runner-win-x64-2.311.0.zip" -OutFile actions-runner.zip

# 解压
Expand-Archive actions-runner.zip -DestinationPath . -Force

# 配置 runner（替换 TOKEN 和 URL）
.\config.cmd --url https://github.com/Wlinuxhv/pan3031-stc32g --token YOUR_TOKEN_HERE --name WIN10-RUNNER --runnergroup Default --labels windows,sdcc

# 启动 runner
.\run.cmd
```

## 3. 验证 Runner

在 GitHub 仓库的 Actions → Runners 页面应该能看到：
- **Name**: WIN10-RUNNER
- **Status**: 🟢 Online
- **Labels**: windows, sdcc

## 4. 安装 SDCC（如果还没有）

下载并安装：https://sourceforge.net/projects/sdcc/files/

或使用 winget：
```powershell
winget install --id SDCC.Team.SDCC
```

验证安装：
```powershell
sdcc -v
```

## 5. 测试构建

推送一个 commit 触发构建：
```powershell
cd C:\Users\User\.openclaw\workspace\pan3031_stc32g
git commit --allow-empty -m "Test self-hosted runner build"
git push
```

然后在 GitHub Actions 页面查看构建状态。

## 6. 作为服务运行（可选）

让 runner 开机自动启动：

```powershell
# 以管理员身份运行
.\svcinstall.cmd

# 启动服务
net start actions.runner.Wlinuxhv-pan3031-stc32g.WIN10-RUNNER
```

## 7. 故障排查

### Runner 不在线
```powershell
cd C:\actions-runner
.\run.cmd
```

### 查看日志
```powershell
Get-Content C:\actions-runner\_diag\*.log -Tail 50
```

### 移除并重新配置
```powershell
# 停止服务（如果已安装）
net stop actions.runner.*
.\svcuninstall.cmd

# 移除 runner
.\config.cmd remove --token YOUR_TOKEN

# 重新配置
.\config.cmd --url https://github.com/Wlinuxhv/pan3031-stc32g --token NEW_TOKEN
```

---

## 快速命令汇总

```powershell
# 下载 runner
$url = "https://github.com/actions/runner/releases/download/v2.311.0/actions-runner-win-x64-2.311.0.zip"
Invoke-WebRequest -Uri $url -OutFile runner.zip
Expand-Archive runner.zip -DestinationPath . -Force

# 配置（替换 TOKEN）
.\config.cmd --url https://github.com/Wlinuxhv/pan3031-stc32g --token TOKEN --name WIN10-RUNNER --labels windows

# 运行
.\run.cmd
```
