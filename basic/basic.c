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

