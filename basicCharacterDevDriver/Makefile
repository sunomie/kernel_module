obj-m := solidusmodule.o


KERNEL_DIR = /usr/src/linux-headers-$(shell uname -r)
PWD := $(shell pwd)
all:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order *~