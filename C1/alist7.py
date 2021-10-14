firstlist = ['k', 97 ,56.42, 64.08, 'bernard']
#We specify the elements within square brackets.
#We can then access individual elements in the list using the index (starting from 0).
#For example:-
print(firstlist[0])
#gives
#k
print(firstlist[1:3])
#gives
#[97, 56.42]
#We can amend an element in a list.
firstlist[3] = 'plj'
print(firstlist)
#giving
#['k', 97, 56.42, 'plj', 'bernard']
#We can delete an element from a list
del firstlist[3]
print(firstlist)
#giving
#['k', 97, 56.42, 'bernard']
#We can append an element to the list
firstlist.append(453.769)
print(firstlist)
#giving
#['k', 97, 56.42, 'bernard', 453.769]

