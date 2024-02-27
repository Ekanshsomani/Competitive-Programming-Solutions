# max product for longest contiguous subsequence

import sys

for line in sys.stdin:
    numbers = line.split()
    numbers = numbers[0:len(numbers)-1]

    maxProduct = -999999
    num_length = len(numbers)
    for i in range(num_length):
        currrentProduct = (int)(numbers[i])
        maxProduct = max(currrentProduct, maxProduct)
        for j in range(i+1, num_length):
            currrentProduct *= (int)(numbers[j])
            maxProduct = max(currrentProduct, maxProduct)
    print(maxProduct)
