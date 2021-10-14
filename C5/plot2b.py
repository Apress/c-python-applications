import matplotlib.pyplot as plt 

values = [1,2,3,4,45,66,67,68,69,70,84.88,91,94]
# draw a histogram with 10 bins of the `values` data

number_of_bins = 10

n = plt.hist(values, number_of_bins, facecolor='blue')

print(n[0]) # counts in each bin


# plot the histogram

plt.title('test histogram')
plt.xlabel('preset numbers between 1 and 100')
plt.ylabel('Number in each bin')
plt.show()