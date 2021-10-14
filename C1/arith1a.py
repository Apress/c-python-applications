#Initialise the variables v1,v2,v3 and v4 with integer values
v1= 2
v2 = 4
v3 = 7
v4 = 8
#Add v1 to v2 and store the result in v5
v5 = v1 + v2
print(v5)
#The result is
#6
#You can combine the adding with the print as follows
print(v1+v2)
#Giving the same answer
#6
#Now a subtraction
v6 = v4 - v3
print(v6)
#giving
#1
#Now a multiplication
v7 = v4 * v3

print(v7)
#giving
#56
#Now a division
v8 = v4 / v1
print(v8)
#giving
#4.0


v10 = v3 % v2 # the % sign means show the remainder of the division
print(v10)
#gives
#3

#Raise by the power 2 
v11 = v2 ** 2
print(v11)
#gives
#16
#Raise to the power held in variable V1
#Here V2 contains 4 and V1 contains 2
v11 = v2 ** v1
print(v11)
#gives
#16
#Show how Python obeys the rules of BODMAS (BIDMAS)
#Here v2 contains 4,  v1 contains 2,  v3 contains 7,  v4 contains 8

v11 = v1 + v2 * v4 - v3 # show BODMAS
print(v11)
#gives
#27
#Show how Python obeys the normal algebra rules
v11 = (v1 + v2) * (v4 - v3)
print(v11)
#gives
#6
