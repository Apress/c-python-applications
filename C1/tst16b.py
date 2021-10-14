# Define our 3 functions
def func1():
    print("This is from func1")

def func2(name, pretax):
   aftertax = pretax * 0.85
   print("%s This is from func1, You salary after tax is %f"%(name,aftertax))

def func3(first,second,third):
    return 3.5*first + second/2 - third

# call func1
func1()

#call func2
func2("Bernard", 23.78)

#call func3
x = func3(1,2,3)
print(x)
