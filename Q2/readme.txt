This contains a set of C programs and a Python script to measure and visualize the execution times of these programs under different scheduling policies. The programs use different scheduling policies - SCHED_OTHER, SCHED_RR, and SCHED_FIFO. 
The main goal is to observe how these scheduling policies affect the execution times of the programs and visualize the results using a histogram/bar graph.

Contents-->

1) counter1.c, counter2.c, counter3.c: These C programs are simple counters that run in a loop and count till 2^32. Each program is associated with a specific scheduling policy - counter1.c with SCHED_OTHER, counter2.c with SCHED_RR, and counter3.c with SCHED_FIFO.

2) main.c: This C program is responsible for creating child processes and executing the counter programs with their respective scheduling policies. It uses fork() to create child processes and execl() to execute the programs which further use execl() to execute the counter programs.

3) graph.py: This Python script reads the execution times recorded in text files (text1.txt, text2.txt, text3.txt) and generates a histogram to visualize the differences in execution times under different scheduling policies.

4) Makefile: The makefile provides easy compilation and execution of the C programs and Python script. It defines rules for compiling the C programs, executing the main program, and generating the histogram/bar graph.
