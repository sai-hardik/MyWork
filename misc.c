#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/errno.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sai Hardik");
MODULE_DESCRIPTION("Misc char device driver with open,close,read and write operations.");

#define TL_ID "PES2UG20CS296"
#define TL_ID_LENGTH 14


static int misc_open(struct inode *inode, struct file *file)
{
        pr_info("Misc device open\n");
        return 0;
}
        
static int misc_close(struct inode *inode, struct file *file)
{
        pr_info("Misc device close\n");
        return 0;
}

static ssize_t my_read(struct file *file, char __user *buff, size_t count, loff_t *ppos)
{
	char *print_str = TL_ID;
	int len = TL_ID_LENGTH;
	pr_info("Misc device read");

	return simple_read_from_buffer(buff, count, ppos, print_str, len);
}

static ssize_t my_write(struct file *file, char const __user *buff, size_t count, loff_t *ppos)
{
        
	char *print_str = TL_ID;
	char input[TL_ID_LENGTH];
	int len = TL_ID_LENGTH;
	ssize_t retval = -EINVAL;
	pr_info("Misc device write");
	

	if (count != len)
		return retval;

	retval = simple_write_to_buffer(input, count, ppos, buff, count);

	if (retval < 0)
		return retval;

	retval = strncmp(print_str, input, count) ? count : -EINVAL;
	return retval;
}

static const struct file_operations my_fops = {
	.owner = THIS_MODULE,
	.read = my_read,
	.write = my_write,
	.open = misc_open,
	.release = misc_close,
	
};

static struct miscdevice my_dev = {
	MISC_DYNAMIC_MINOR,
	"PESSRN",
	&my_fops
};

static int __init my_init(void)
{
	int ret;

	ret = misc_register(&my_dev);
	pr_debug("Hello world");
	return ret;
}

static void __exit my_exit(void)
{
	misc_deregister(&my_dev);
}

module_init(my_init);
module_exit(my_exit);
