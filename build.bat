@echo off
echo ========================================
echo PAN3031 STC32G 编译器 (简化版)
echo ========================================
echo.

set SDCC_PATH=C:\Program Files\SDCC\bin
set PATH=%SDCC_PATH%;%PATH%

where sdcc >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo [错误] 未找到 SDCC!
    exit /b 1
)

sdcc -v
echo.

if not exist "build" mkdir build

echo [信息] 编译中...
echo.

REM 编译每个文件
echo Compiling STC32G.h...
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -c STC32G.h -o build\stc32g.rel 2>nul

echo Compiling main.c...
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IHAL\spi -IHAL\gpio -IHAL\delay -IHAL\uart -IRadio\inc -IUser -c User\main.c -o build\main.rel

echo Compiling spi.c...
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IHAL\spi -IHAL\gpio -c HAL\spi\spi.c -o build\spi.rel

echo Compiling gpio.c...
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IHAL\gpio -c HAL\gpio\gpio.c -o build\gpio.rel

echo Compiling delay.c...
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IHAL\delay -c HAL\delay\delay.c -o build\delay.rel

echo Compiling uart.c...
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IHAL\uart -c HAL\uart\uart.c -o build\uart.rel

echo Compiling pan3031.c...
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IRadio\inc -c Radio\src\pan3031.c -o build\pan3031.rel

echo Compiling radio.c...
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IRadio\inc -c Radio\src\radio.c -o build\radio.rel

echo Compiling crc.c...
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IRadio\inc -c Radio\src\crc.c -o build\crc.rel

echo.
echo Linking...
sdcc -mmcs51 --model-large --out-fmt-ihx build\main.rel build\spi.rel build\gpio.rel build\delay.rel build\uart.rel build\pan3031.rel build\radio.rel build\crc.rel -o build\pan3031_stc32g.hex

if %ERRORLEVEL% equ 0 (
    echo.
    echo ========================================
    echo [成功] HEX 生成完成!
    echo 文件：build\pan3031_stc32g.hex
    echo ========================================
    dir build\*.hex
) else (
    echo.
    echo ========================================
    echo [错误] 编译失败
    echo ========================================
)

pause
