#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>  
#include<linux/sched/signal.h> 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("KOMAL");
MODULE_DESCRIPTION("System call to count running processes task_struct");

static int __init display_init(void)
{    
     printk(KERN_INFO "Syscall module loaded\n");
     
     
     struct task_struct *call;
      int count = 0;
       struct task_struct *current_task = current;
      int v=0;
      int f=0;
      for_each_process(call){
      v++;
          if (call->pid != current_task->pid){
          f++;
          }
        else {
        if (call->comm==current_task->comm){
        //if (task_is_running(task))
        count++;
     
        }
      }
      }
      printk(KERN_INFO "Number of running processes: %d\n", count);
      printk(KERN_INFO "f %d\n", f);

      return count;
     }

static void __exit display_cleanup(void)
{
      printk(KERN_INFO "Syscall module unloaded\n");
}

module_init(display_init);      
module_exit(display_cleanup);  
