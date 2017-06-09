#include <linux/init.h> // Linux init stuff
#include <linux/module.h> // Linux kernel module stuff

static int module_entry(void){
  printk(KERN_ALERT "basic kernel module: Entry");
  return 0;
}

static void module_exit(void){
  printk(KERN_ALERT "basic kernel module: Exit");
}

//Inform the kernel where to start and stop with our module/driver
module_init(module_entry);
module_exit(module_exit);

//Make kernels like Ubuntu not freak out and reject the module
// with dmsg showing module license 'unspecified' taints kernel.
//  and module verification failed: signature and/or required key missing - tainting kernel
MODULE_LICENSE("GPL");
