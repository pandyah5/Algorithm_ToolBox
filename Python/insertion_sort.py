def insertion_sort(array):
    if (len(array) <= 1):
        return array
    for index in range(0, len(array) - 1):
        if (array[index + 1] < array[index]):
            j = index
            while(j >= 0):
                if (array[j + 1] >= array[j]):
                    break
                array[j + 1], array[j] = array[j], array[j + 1]
                j -= 1

    return array

## Stress Testing
import numpy as np

def check(array):
    for i in range(0, len(array) - 1):
        if array[i] > array[i + 1]:
            return False
    return True

for j in range(0, 10):
    mylist = []
    for i in range(0, 100):
        mylist.append(np.random.randint(100))

    if not check(insertion_sort(mylist)):
        print("> Failed: ", mylist)
