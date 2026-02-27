# SDCC Makefile for PAN3031 STC32G (Windows compatible)

CC = sdcc

# Directories
BUILD_DIR = build
USER_DIR = User
HAL_DIR = HAL
RADIO_DIR = Radio

# Source files
C_SOURCES = ^
  $(USER_DIR)/main.c ^
  $(HAL_DIR)/spi/spi.c ^
  $(HAL_DIR)/gpio/gpio.c ^
  $(HAL_DIR)/delay/delay.c ^
  $(HAL_DIR)/uart/uart.c ^
  $(RADIO_DIR)/src/pan3031.c ^
  $(RADIO_DIR)/src/pan3031_port.c ^
  $(RADIO_DIR)/src/radio.c ^
  $(RADIO_DIR)/src/crc.c

# Include paths
INCLUDES = ^
  -I. ^
  -I$(HAL_DIR)/spi ^
  -I$(HAL_DIR)/gpio ^
  -I$(HAL_DIR)/delay ^
  -I$(HAL_DIR)/uart ^
  -I$(RADIO_DIR)/inc ^
  -I$(USER_DIR)

# Compiler flags
CFLAGS = -mmcs51 --model-large --std-sdcc99 --out-fmt-ihx -DSTC32G12K128

# Output
TARGET = $(BUILD_DIR)/pan3031_stc32g
HEX_FILE = $(TARGET).hex

# Create build directory
all: $(BUILD_DIR) $(HEX_FILE)
	@echo.
	@echo ========================================
	@echo Build complete: $(HEX_FILE)
	@echo ========================================

$(BUILD_DIR):
	@if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"

# Compile and link
$(HEX_FILE): $(C_SOURCES) | $(BUILD_DIR)
	@echo Compiling...
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(C_SOURCES)

# Clean
clean:
	@if exist "$(BUILD_DIR)" (
		del /Q "$(BUILD_DIR)\*.rel" 2>nul
		del /Q "$(BUILD_DIR)\*.hex" 2>nul
		del /Q "$(BUILD_DIR)\*.lst" 2>nul
		del /Q "$(BUILD_DIR)\*.map" 2>nul
		del /Q "$(BUILD_DIR)\*.sym" 2>nul
		del /Q "$(BUILD_DIR)\*.rst" 2>nul
		del /Q "$(BUILD_DIR)\*.lk" 2>nul
		del /Q "$(BUILD_DIR)\*.mem" 2>nul
		del /Q "$(BUILD_DIR)\*.asm" 2>nul
	)

.PHONY: all clean
