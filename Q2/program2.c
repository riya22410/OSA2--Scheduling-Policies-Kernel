#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>

int main() {
    // Set SCHED_RR scheduling policy
    struct sched_param param;
    param.sched_priority = 0;  // Set a priority (1-99) for SCHED_RR--> 1 for highest priority //0 
    sched_setscheduler(0, SCHED_RR, &param);

    //start time
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    pid_t pid = fork();

    if (pid == 0) {
        execl("/Users/riyagupta/Documents/C_Riya/OSAssign2_Q2/counter2.c", "counter2", NULL); // Child process
    } else if (pid > 0) { // Parent process
        waitpid(pid, NULL, 0);
        clock_gettime(CLOCK_REALTIME, &end);  //end time
        double execution_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        printf("Execution Time of process 2: %f seconds\n", execution_time);
    }
    else{
        perror("Error in fork");
    }

    return 0;
}
