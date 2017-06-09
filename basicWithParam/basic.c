// Build and run this with:
// make clean; make; sudo rmmod basic.ko; sleep 1; sudo insmod basic.ko param_var=182 param_array_var=24,27,121; sleep 1; dmesg | grep basic

#include <linux/init.h> // Linux init stuff
#include <linux/module.h> // Linux kernel module stuff
#include <linux/moduleparam.h> // Allows take paramaters

int param_var = 0;
int param_array_var[3] = {0,1,2};

static int module_entry(void){
  printk(KERN_ALERT "basic kernel module: Entry");
  return 0;
}

static void module_exit(void){
  printk(KERN_ALERT "basic kernel module: Exit");
  printk(KERN_ALERT "basic kernel module: param = %d", param_var);
  printk(KERN_ALERT "basic kernel module: param_array = [%d.%d,%d]", param_array_var[0],param_array_var[1],param_array_var[2]);
}

//Inform the kernel where to start and stop with our module/driver
module_init(module_entry);
module_exit(module_exit);

//Make kernels like Ubuntu not freak out and reject the module
// with dmsg showing module license 'unspecified' taints kernel.
//  and module verification failed: signature and/or required key missing - tainting kernel
MODULE_LICENSE("GPL");

//module_param(name_var, type, permissions)
// permissions is xor (|) combination of: S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, 
module_param(param_var, int, S_IRUSR | S_IWUSR);
//module_param_array(name_var, type, number_of_params (can be NULL), permissions)
module_param_array(param_array_var, int, NULL, S_IRUSR | S_IWUSR);
