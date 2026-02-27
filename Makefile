# SDCC Makefile for PAN3031 STC32G
# 分步编译每个文件

CC = sdcc

# Directories
BUILD_DIR = build

# Source files
C_SOURCES = \
  User/main.c \
  HAL/spi/spi.c \
  HAL/gpio/gpio.c \
  HAL/delay/delay.c \
  HAL/uart/uart.c \
  Radio/src/pan3031.c \
  Radio/src/radio.c \
  Radio/src/crc.c

# Include paths
INCLUDES = \
  -I. \
  -IHAL/spi \
  -IHAL/gpio \
  -IHAL/delay \
  -IHAL/uart \
  -IRadio/inc \
  -IUser

# Compiler flags
CFLAGS = -mmcs51 --model-large --std-sdcc99 --out-fmt-ihx -DSTC32G12K128

# Object files
OBJECTS = $(patsubst %.c,$(BUILD_DIR)/%.rel,$(C_SOURCES))

# Output
TARGET = $(BUILD_DIR)/pan3031_stc32g.hex

.PHONY: all clean

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile each source file
$(BUILD_DIR)/%.rel: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link all object files
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) --out-fmt-ihx $(OBJECTS) -o $@

clean:
	rm -rf $(BUILD_DIR)
