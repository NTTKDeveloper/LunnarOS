#Copyright @TuanKhanh
whoami = tuankhanh

OSNAME = LunnarOS
#UEFI libary
OVMFDIR = ./OVMFbin
CMDDIR = ./cmd
LFS = /mnt/lfs
partition = loop19
LFS_EFI = /mnt/lfs/boot/efi


KERNELDIR = ./kernel-6.0.7/arch/x86_64/boot/bzImage
BUSYBOXDIR = ./busybox-1.34.1/initramfs.cpio.gz

buildimg: 
	echo "Create Partition !!!!!!!!!!!!!!!!!!"
	sudo gdisk ./$(OSNAME).iso < $(CMDDIR)/create_partition
	echo "==================================="
	echo "Format Disk !!!!!!!!!!!!!!!!!!!!!!!"
	#$(partition): p1 fat32, p2 ext4
	sudo losetup -P -f $(OSNAME).iso
	lsblk /dev/$(partition)
	sudo mkfs.vfat -F32 /dev/$(partition)p1
	sudo mkfs.ext4 /dev/$(partition)p2
	echo "==================================="
	echo "Mount Disk !!!!!!!!!!!!!!!!!!!!!!!!"
	sudo mkdir -p /mnt/lfs
	sudo mount -v /dev/$(partition)p2 /mnt/lfs #Root Partition
	#Thay doi chu so huu
	sudo chown -v $(whoami) /mnt/lfs
	echo "==================================="
	echo "Create dir in Disk !!!!!!!!!!!!!!!!"
#   Mount EFI
	sudo mkdir -pv $(LFS)/boot/efi
	sudo mount /dev/$(partition)p1 /mnt/lfs/boot/efi

	sudo mkdir -pv $(LFS)/etc/
	sudo mkdir -pv $(LFS)/dev
	sudo mkdir -pv $(LFS)/etc 
	sudo mkdir -pv $(LFS)/proc
	sudo mkdir -pv $(LFS)/run 
	sudo mkdir -pv $(LFS)/sys 
	sudo mkdir -pv $(LFS)/var
	sudo mkdir -pv $(LFS)/usr/bin 
	sudo mkdir -pv $(LFS)/usr/lib 
	sudo mkdir -pv $(LFS)/usr/src 

	#link forder 
	sudo ln -sv $(LFS)/usr/lib $(LFS)/lib
	sudo ln -sv $(LFS)/usr/lib $(LFS)/lib64
	sudo ln -sv $(LFS)/usr/lib $(LFS)/usr/lib64
	sudo ln -sv $(LFS)/usr/bin $(LFS)/bin 
	sudo ln -sv $(LFS)/usr/bin $(LFS)/sbin
	sudo ln -sv $(LFS)/usr/bin $(LFS)/usr/sbin


grub-install:
	sudo grub-install --target=x86_64-efi --bootloader-id=$(OSNAME) --efi-directory=$(LFS_EFI)

run_without_grub:
	qemu-system-x86_64 -kernel $(KERNELDIR) -initrd $(BUSYBOXDIR)

run_bios:
	#Bios Iso
	qemu-system-x86_64 -boot d -cdrom $(OSNAME).iso -m 512 

run_efi:
	qemu-system-x86_64 -bios $(OVMFDIR)/OVMF_CODE-pure-efi.fd -drive format=raw,file=$(OSNAME).iso

umount:
	sudo umount /dev/$(partition)p1
	sudo umount /dev/$(partition)p2

mount:
	sudo mount /dev/$(partition)p2 /mnt/lfs/
	sudo mount /dev/$(partition)p1 /mnt/lfs/boot/efi

clean: 
	sudo rm -rf /mnt/lfs
	sudo losetup -D /dev/$(partition)
	sudo gdisk ./$(OSNAME).iso < $(CMDDIR)/delete_a_partition

