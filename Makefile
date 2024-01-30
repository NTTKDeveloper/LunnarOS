OSNAME = LunnarOS

OVMFDIR = ./OVMFbin

KERNELDIR = ./kernel-6.0.7/arch/x86_64/boot/bzImage
BUSYBOXDIR = ./busybox-1.34.1/initramfs.cpio.gz

buildimg: 
	mkdir -p iso/boot/grub
	cp $(KERNELDIR) ./iso/boot
	cp $(BUSYBOXDIR) ./iso/boot
	cp ./grub.cfg ./iso/boot/grub
	echo "Move Kernel, File System and Grub.cfg into boot folder"
	echo "<======================================================>"
	grub-mkrescue -o $(OSNAME).iso iso/ 
	echo "Complete !!!!!!!!!!!!!!"


run_without_grub:
	qemu-system-x86_64 -kernel $(KERNELDIR) -initrd $(BUSYBOXDIR)

run_bios:
	#Bios Iso
	qemu-system-x86_64 -boot d -cdrom $(OSNAME).iso -m 512 
# 	qemu-system-x86_64 -boot d -cdrom ./$(OSNAME).iso -m 256M -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="$(OVMFDIR)/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="$(OVMFDIR)/OVMF_VARS-pure-efi.fd" -vga std

run_efi:
	qemu-system-x86_64 -boot d -cdrom ./$(OSNAME).iso -m 256M -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="$(OVMFDIR)/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="$(OVMFDIR)/OVMF_VARS-pure-efi.fd"

clean: 
	rm -rf ./iso ./$(OSNAME).iso
