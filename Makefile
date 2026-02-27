# SDCC Makefile for PAN3031 STC32G (Windows compatible)

# Compiler
CC = sdcc

# Directories
BUILD_DIR = build
USER_DIR = User
HAL_DIR = HAL
RADIO_DIR = Radio

# Source files
C_SOURCES = \
  $(USER_DIR)/main.c \
  $(HAL_DIR)/spi/spi.c \
  $(HAL_DIR)/gpio/gpio.c \
  $(HAL_DIR)/delay/delay.c \
  $(HAL_DIR)/uart/uart.c \
  $(RADIO_DIR)/src/pan3031.c \
  $(RADIO_DIR)/src/pan3031_port.c \
  $(RADIO_DIR)/src/radio.c \
  $(RADIO_DIR)/src/crc.c

# Include paths
INCLUDES = \
  -I. \
  -I$(HAL_DIR)/spi \
  -I$(HAL_DIR)/gpio \
  -I$(HAL_DIR)/delay \
  -I$(HAL_DIR)/uart \
  -I$(RADIO_DIR)/inc \
  -I$(USER_DIR)

# Compiler flags for STC89C52RC (8051 compatible)
CFLAGS = -mmcs51 --model-large --opt-code-size
CFLAGS += -DSTC32G12K128
CFLAGS += --out-fmt-ihx
CFLAGS += --std-sdcc99

# Output
TARGET = $(BUILD_DIR)/pan3031_stc32g
HEX_FILE = $(TARGET).hex

# Create build directory
$(shell if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)")

# Object files
OBJECTS = $(patsubst %.c,$(BUILD_DIR)/%.rel,$(C_SOURCES))

# Default target
all: $(HEX_FILE)
	@echo Build complete: $(HEX_FILE)

# Link
$(HEX_FILE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile
$(BUILD_DIR)/%.rel: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean
clean:
	-if exist "$(BUILD_DIR)\*.rel" del /Q "$(BUILD_DIR)\*.rel"
	-if exist "$(BUILD_DIR)\*.hex" del /Q "$(BUILD_DIR)\*.hex"
	-if exist "$(BUILD_DIR)\*.lst" del /Q "$(BUILD_DIR)\*.lst"
	-if exist "$(BUILD_DIR)\*.map" del /Q "$(BUILD_DIR)\*.map"
	-if exist "$(BUILD_DIR)\*.sym" del /Q "$(BUILD_DIR)\*.sym"

.PHONY: all clean
