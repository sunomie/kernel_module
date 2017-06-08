obj-m := solidusmodule.o


KERNEL_DIR = /lib/modules/3.2.0-25-generic/build
PWD := $(shell pwd)
all:
 $(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules

clean:
 rm -rf *.o *.ko *.mod.* *.symvers *.order *~