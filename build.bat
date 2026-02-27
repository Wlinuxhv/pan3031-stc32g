@echo off
REM PAN3031 STC32G 一键编译脚本（不依赖 make）
REM 使用前请确保已安装 SDCC (C:\Program Files\SDCC)

echo ========================================
echo PAN3031 STC32G 编译器
echo ========================================
echo.

REM 设置 SDCC 路径
set SDCC_PATH=C:\Program Files\SDCC\bin
set PATH=%SDCC_PATH%;%PATH%

REM 检查 SDCC 是否可用
where sdcc >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo [错误] 未找到 SDCC!
    echo 请安装 SDCC: https://sourceforge.net/projects/sdcc/files/
    pause
    exit /b 1
)

echo [信息] SDCC 版本:
sdcc -v
echo.

REM 创建输出目录
if not exist "build" mkdir build

REM 编译
echo [信息] 开始编译...
echo.

set SOURCES=User\main.c HAL\spi\spi.c HAL\gpio\gpio.c HAL\delay\delay.c HAL\uart\uart.c Radio\src\pan3031.c Radio\src\pan3031_port.c Radio\src\radio.c Radio\src\crc.c

sdcc -mmcs51 --model-large --std-sdcc99 --out-fmt-ihx -DSTC32G12K128 -I. -IHAL\spi -IHAL\gpio -IHAL\delay -IHAL\uart -IRadio\inc -IUser -o build\pan3031_stc32g.hex %SOURCES%

if %ERRORLEVEL% equ 0 (
    echo.
    echo ========================================
    echo [成功] 编译完成!
    echo HEX 文件位置：build\pan3031_stc32g.hex
    echo ========================================
    dir build\*.hex
) else (
    echo.
    echo ========================================
    echo [错误] 编译失败!
    echo ========================================
)

pause
