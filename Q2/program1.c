#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>

int main() {
    // Set SCHED_OTHER with nice:0 scheduling policy
    struct sched_param param;
    param.sched_priority = 0;

    int result = sched_setscheduler(0, SCHED_OTHER, &param);

    if (result == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

    // Start time
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);  

    pid_t pid = fork();

    if (pid == 0) {         // Child process
        execl("/Users/riyagupta/Documents/C_Riya/OSAssign2_Q2/counter1.c", "counter1", NULL);
    } else if (pid > 0) {   // Parent process
        waitpid(pid, NULL, 0);
        clock_gettime(CLOCK_REALTIME, &end);  // End time
        double execution_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;  // tv_sec= seconds; tv_nsec= nanoseconds; /1e9: 1 billion --> converts nsec to sec
        printf("Execution Time of process 1: %f seconds\n", execution_time);
    }
    else{
        perror("Error in fork");
    }

    return 0;
}
