@echo off
REM PAN3031 STC32G 编译器（SDCC 多文件编译）

echo ========================================
echo PAN3031 STC32G 编译器
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

REM 编译每个文件为目标文件
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IHAL\spi -IHAL\gpio -IHAL\delay -IHAL\uart -IRadio\inc -IUser -c User\main.c -o build\main.rel
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IHAL\spi -IHAL\gpio -IHAL\delay -IHAL\uart -IRadio\inc -IUser -c HAL\spi\spi.c -o build\spi.rel
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IHAL\spi -IHAL\gpio -IHAL\delay -IHAL\uart -IRadio\inc -IUser -c HAL\gpio\gpio.c -o build\gpio.rel
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IHAL\spi -IHAL\gpio -IHAL\delay -IHAL\uart -IRadio\inc -IUser -c HAL\delay\delay.c -o build\delay.rel
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IHAL\spi -IHAL\gpio -IHAL\delay -IHAL\uart -IRadio\inc -IUser -c HAL\uart\uart.c -o build\uart.rel
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IHAL\spi -IHAL\gpio -IHAL\delay -IHAL\uart -IRadio\inc -IUser -c Radio\src\pan3031.c -o build\pan3031.rel
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IHAL\spi -IHAL\gpio -IHAL\delay -IHAL\uart -IRadio\inc -IUser -c Radio\src\pan3031_port.c -o build\pan3031_port.rel
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IHAL\spi -IHAL\gpio -IHAL\delay -IHAL\uart -IRadio\inc -IUser -c Radio\src\radio.c -o build\radio.rel
sdcc -mmcs51 --model-large --std-sdcc99 -DSTC32G12K128 -I. -IHAL\spi -IHAL\gpio -IHAL\delay -IHAL\uart -IRadio\inc -IUser -c Radio\src\crc.c -o build\crc.rel

REM 链接
sdcc -mmcs51 --model-large --out-fmt-ihx build\main.rel build\spi.rel build\gpio.rel build\delay.rel build\uart.rel build\pan3031.rel build\pan3031_port.rel build\radio.rel build\crc.rel -o build\pan3031_stc32g.hex

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
