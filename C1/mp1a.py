import matplotlib.pyplot as plt 
# x values: 
marks = list(range(0, 100, 10)) 

print(marks) 
# y values: 
people = [4, 7, 9, 17, 22, 25, 28, 18, 6, 2] 

plt.xlabel('marks') 
plt.ylabel('people') 

plt.plot(marks, people) 
plt.show() 