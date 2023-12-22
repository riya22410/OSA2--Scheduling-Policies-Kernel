import matplotlib.pyplot as plt

data = []
with open("text1.txt",'r') as f:
	data.append(float(f.read()))

with open("text2.txt",'r') as f:
	data.append(float(f.read()))

with open("text3.txt",'r') as f:
	data.append(float(f.read()))


#print(data)
colors = ['orange', 'red', 'blue']
labels = ['SCHED_OTHER', 'SCHED_RR', 'SCHED_FIFO']
plt.bar(labels, data,color=colors)
plt.xlabel('Sheduling policy')
plt.ylabel('Time taken')
plt.title('Histogram of time taken vs scheduling policy')
plt.show()
