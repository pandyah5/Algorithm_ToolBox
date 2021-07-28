def insertion_sort(array):
    for index in range(0, len(array)):
        key = array[index]
        j = index - 1
        while(j >= 0 and key < array[j]):
            array[j + 1], array[j] = array[j], array[j + 1]
            j -= 1
        array[j + 1] = key
    return array

## Stress Testing
import numpy as np

def check(array):
    for i in range(0, len(array) - 1):
        if array[i] > array[i + 1]:
            return False
    return True

for j in range(0, 100):
    mylist = []
    for i in range(0, 50):
        mylist.append(np.random.randint(100))

    if not check(insertion_sort(mylist)):
        print("> Failed: ", mylist)
        
