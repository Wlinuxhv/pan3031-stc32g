# SDCC Makefile for PAN3031 STC32G
# Compatible with both Windows and Linux

CC = sdcc

# Directories
BUILD_DIR = build
USER_DIR = User
HAL_DIR = HAL
RADIO_DIR = Radio

# Source files (Unix line continuation)
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

# Compiler flags
CFLAGS = -mmcs51 --model-large --std-sdcc99 --out-fmt-ihx -DSTC32G12K128

# Output
TARGET = $(BUILD_DIR)/pan3031_stc32g
HEX_FILE = $(TARGET).hex

.PHONY: all clean

# Default target
all: $(BUILD_DIR) $(HEX_FILE)
	@echo "Build complete: $(HEX_FILE)"

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile and link
$(HEX_FILE): $(C_SOURCES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(C_SOURCES)

# Clean
clean:
	rm -rf $(BUILD_DIR)/*.rel $(BUILD_DIR)/*.hex $(BUILD_DIR)/*.lst
	rm -rf $(BUILD_DIR)/*.map $(BUILD_DIR)/*.sym $(BUILD_DIR)/*.rst
	rm -rf $(BUILD_DIR)/*.lk $(BUILD_DIR)/*.mem $(BUILD_DIR)/*.asm
