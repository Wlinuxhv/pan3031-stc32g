# SDCC Makefile for PAN3031 STC32G

# Compiler
CC = sdcc
AS = sdas8051

# Target MCU
MCU = stc89c52rc  # SDCC compatible 8051 variant

# Directories
SRC_DIR = .
HAL_DIR = HAL
RADIO_DIR = Radio
USER_DIR = User
BUILD_DIR = build

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

# Compiler flags
CFLAGS = -mmcs51 --model-large --opt-code-size --no-xinit-opt
CFLAGS += -DSTC32G12K128
CFLAGS += --out-fmt-ihx

# Output
TARGET = $(BUILD_DIR)/pan3031_stc32g
HEX_FILE = $(TARGET).hex

# Create build directory
$(shell mkdir -p $(BUILD_DIR))

# Object files
OBJECTS = $(patsubst %.c,$(BUILD_DIR)/%.rel,$(C_SOURCES))

# Default target
all: $(HEX_FILE)

# Link
$(HEX_FILE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile
$(BUILD_DIR)/%.rel: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean
clean:
	rm -rf $(BUILD_DIR)/*.rel $(BUILD_DIR)/*.hex $(BUILD_DIR)/*.lst $(BUILD_DIR)/*.map $(BUILD_DIR)/*.sym $(BUILD_DIR)/*.rst $(BUILD_DIR)/*.lk $(BUILD_DIR)/*.mem $(BUILD_DIR)/*.asm

# Flash (requires stcgal)
flash: $(HEX_FILE)
	stcgal -P stc89 -p /dev/ttyUSB0 -b 115200 $(HEX_FILE)

.PHONY: all clean flash
