#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
    pid_t child1, child2, child3;
    child1 = fork(); //SCHED_OTHER
    if (child1 == 0) {
        execl("/Users/riyagupta/Documents/C_Riya/OSAssign2_Q2/program1.c", "program1", NULL); 
    }

    child2 = fork(); //SCHED_RR
    if (child2 == 0) {
        execl("/Users/riyagupta/Documents/C_Riya/OSAssign2_Q2/program2.c", "program2", NULL); 
    }
    child3 = fork(); //SCHED_FIFO
    if (child3 == 0) {
        execl("/Users/riyagupta/Documents/C_Riya/OSAssign2_Q2/program3.c", "program3", NULL); 
    }

    waitpid(child1, NULL, 0);
    waitpid(child2, NULL, 0);
    waitpid(child3, NULL, 0);
    return 0;
}
