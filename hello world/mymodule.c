#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("GROUP OF ADIL");
MODULE_DESCRIPTION("a hello world lkm");

static int __init my_init(void) {
	printk("hello, Kernel!\n");
	return 0;
}

static void __exit my_exit(void) {
	printk("Goodbye, Kernal\n");
}

module_init(my_init);
module_exit(my_exit);
