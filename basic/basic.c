#include <linux/init.h>
#include <linux/module.h>

static int driver_entry(void){
  printk(KERN_ALERT "basic kernel module: Entry");
  return 0;
}

static void driver_exit(void){
  printk(KERN_ALERT "basic kernel module: Exit");
}

//Inform the kernel where to start and stop with our module/driver
module_init(driver_entry);
module_exit(driver_exit);

//Make kernels like Ubuntu not freak out and reject the module
// with dmsg showing module license 'unspecified' taints kernel.
//  and module verification failed: signature and/or required key missing - tainting kernel
MODULE_LICENSE("GPL");
