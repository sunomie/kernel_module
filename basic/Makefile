obj-m := basic.o

KDIR = /usr/src/linux-headers-4.4.0-79--$(shell uname -r)

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order *~