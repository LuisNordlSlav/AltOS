# Directories
SRC_DIR=./src
OBJ_DIR=./bin
BUILD_DIR=./build
OUT_DIR=./dist
INCL_DIR=./intf

ASM_OBJ_DIR=$(OBJ_DIR)/asm
C_OBJ_DIR=$(OBJ_DIR)/c

# Toolchain
AS=as
CC=gcc
LD=ld
GRUB=grub-mkrescue

# Flags
ASMFLAGS=--64
CFLAGS=-I$(INCL_DIR) -ffreestanding -MMD -MP
LDFLAGS=-n -T build/linker.ld

# Source Files
ASM_SRCS=$(wildcard $(SRC_DIR)/*.s) $(wildcard $(SRC_DIR)/**/*.s)
C_SRCS=$(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c)

# Object Files
OBJS=$(ASM_SRCS:$(SRC_DIR)/%.s=$(ASM_OBJ_DIR)/%.o) $(C_SRCS:$(SRC_DIR)/%.c=$(C_OBJ_DIR)/%.o)

DEP=$(OBJ:.o=.d)

# Target
TARGET=$(OUT_DIR)/kernel.bin
ISO=$(TARGET:.bin=.iso)

# Rules
all: $(ISO)

$(ISO): $(TARGET)
	cp $(TARGET) $(BUILD_DIR)/iso/boot/kernel.bin
	$(GRUB) /usr/lib/grub/i386-pc -o $(ISO) $(BUILD_DIR)/iso

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

$(C_OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(ASM_OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(dir $@)
	$(AS) $(ASMFLAGS) $< -o $@

-include $(DEP)

.PHONY: clean
clean:
	rm -rf \
		$(OBJ_DIR)/* \
		$(OUT_DIR)/* \
		$(BUILD_DIR)/iso/boot/kernel.bin

.PHONY: run
run: all
	qemu-system-x86_64 -cdrom dist/kernel.iso
