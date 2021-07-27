## Algorithm
def bubble_sort(array):
    for i in range(0, len(array)):
        for j in range(i, len(array)):
            if array[i] > array[j]:
                array[i], array[j] = array[j], array[i]
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

    if not check(bubble_sort(mylist)):
        print("> Failed: ", mylist)
