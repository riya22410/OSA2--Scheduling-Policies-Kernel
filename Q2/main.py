import subprocess
import matplotlib.pyplot as plt
import os
import time

# # Define the scheduling policies and corresponding program names
# processes = [
#     {"name": "process1", "policy": "SCHED_OTHER"},
#     {"name": "process2", "policy": "SCHED_RR"},
#     {"name": "process3", "policy": "SCHED_FIFO"},
# ]

# # Store execution times for each process
# execution_times = {}

# for process in processes:
#     try:
#         # Compile the C program using subprocess
#         compile_command = ["gcc", f"{process['name']}.c", "-o", process['name']]
#         subprocess.run(compile_command, check=True)

#         # Fork a child process
#         pid = os.fork()

#         if pid == 0:
#             # In the child process, execute the C program
#             execution_command = ["./" + process['name']]
#             subprocess.run(execution_command, check=True)

#         else:
#             # In the parent process, wait for the child to finish
#             _, child_status = os.waitpid(pid, 0)
#             if os.WIFEXITED(child_status):
#                 # Sleep for a moment to ensure child process completes time measurement
#                 time.sleep(1)
#                 # Measure execution time
#                 with open(f"{process['name']}.txt", "r") as file:
#                     execution_time = float(file.read())
#                     execution_times[process['policy']] = execution_time
#                     os.remove(f"{process['name']}.txt")

#     except subprocess.CalledProcessError as e:
#         print(f"Error running {process['name']}")

# Plot the histogram
plt.bar(execution_times.keys(), execution_times.values())
plt.xlabel("Scheduling Policy")
plt.ylabel("Execution Time (s)")
plt.title("Execution Time vs. Scheduling Policy")
plt.show()


import matplotlib.pyplot as plt

# Execution times of the three processes (update with your measured values)
execution_times = [time1, time2, time3]

# Scheduling policies and priorities
schedulers = ['SCHED_OTHER', 'SCHED_RR', 'SCHED_FIFO']

# Create a histogram
plt.bar(schedulers, execution_times, color=['blue', 'green', 'red'])
plt.xlabel('Scheduling Policies')
plt.ylabel('Execution Time (ms)')
plt.title('Execution Time Comparison')
plt.show()
