AS = nasm
QEMU = qemu-system-x86_64
OUTDIR = build
TARGET = $(OUTDIR)/boot.bin

all: $(TARGET)

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(TARGET): boot.asm | $(OUTDIR)
	$(AS) -f bin -o $(TARGET) boot.asm

run: $(TARGET)
	$(QEMU) -drive format=raw,file=$(TARGET)

clean:
	rm -rf $(OUTDIR)

.PHONY: all run clean
