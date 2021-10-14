import matplotlib.pyplot as plt 
# x values:
marks = list(range(0,100,10)) 
# y values:
male = [4, 7, 9, 17, 22, 25, 28, 18, 6, 2] 
female = [2, 5, 8, 13, 28, 25, 23, 20, 18, 12] 
plt.xlabel('marks') 
plt.ylabel('number of students') 

plt.title('Comparison of male / female examination scores')
plt.plot(marks, female, label="female") 

plt.plot(marks, female, "ob") 
plt.plot(marks, male, label="male") 
plt.plot(marks, male, "or")

plt.legend()
plt.show() 


