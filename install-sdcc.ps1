# SDCC 自动安装脚本
# 使用方法：以管理员身份运行 PowerShell，执行 .\install-sdcc.ps1

$ErrorActionPreference = 'Stop'
Write-Host "=== SDCC 自动安装脚本 ===" -ForegroundColor Cyan

# 方法 1: 尝试 winget
Write-Host "`n[1/3] 尝试使用 winget 安装..." -ForegroundColor Yellow
try {
    $winget = Get-Command winget -ErrorAction Stop
    winget install --id SDCC.Team.SDCC --silent --accept-package-agreements
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✓ winget 安装成功" -ForegroundColor Green
        & "$env:ProgramFiles\SDCC\bin\sdcc.exe" -v
        return
    }
} catch {
    Write-Host "✗ winget 不可用或安装失败" -ForegroundColor Red
}

# 方法 2: 尝试 Chocolatey
Write-Host "`n[2/3] 尝试使用 Chocolatey 安装..." -ForegroundColor Yellow
try {
    $choco = Get-Command choco -ErrorAction Stop
    choco install sdcc -y
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✓ Chocolatey 安装成功" -ForegroundColor Green
        sdcc -v
        return
    }
} catch {
    Write-Host "✗ Chocolatey 不可用或安装失败" -ForegroundColor Red
}

# 方法 3: 手动下载
Write-Host "`n[3/3] 打开下载页面..." -ForegroundColor Yellow
Write-Host "请从以下地址下载并安装 SDCC:" -ForegroundColor Cyan
Write-Host "  https://sourceforge.net/projects/sdcc/files/sdcc/4.4.0/" -ForegroundColor White
Write-Host "`n下载后运行安装程序，默认安装路径为:" -ForegroundColor Cyan
Write-Host "  C:\Program Files\SDCC" -ForegroundColor White

Start-Process "https://sourceforge.net/projects/sdcc/files/sdcc/4.4.0/"

Write-Host "`n安装完成后，重新运行此脚本验证安装。" -ForegroundColor Yellow
