#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("GROUP OF ADIL");
MODULE_DESCRIPTION("Time since module was loaded");

static unsigned long start_time;

static int __init session_length_init(void)
{
    printk(KERN_INFO "Session Length module loaded.\n");
    start_time = jiffies;
    return 0;
}

static void __exit session_length_exit(void)
{
    unsigned long elapsed_time = jiffies - start_time;
    unsigned int hours = elapsed_time / (60*60*HZ);
    unsigned int minutes = (elapsed_time / (60*HZ)) % 60;
    unsigned int seconds = (elapsed_time / HZ) % 60;
    printk(KERN_INFO "Session Length module unloaded.\n");
    printk(KERN_INFO "Session length: %u:%02u:%02u.\n", hours, minutes, seconds);
}

module_init(session_length_init);
module_exit(session_length_exit);
