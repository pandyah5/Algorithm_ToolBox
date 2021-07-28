import numpy as np

def quicksort(array):
    if len(array) <= 1:
        return array
    pivot = len(array) - 1
    i = -1
    for j in range(0, pivot):
        if array[j] < array[pivot]:
            i += 1
            array[i], array[j] = array[j], array[i]
    array[i + 1], array[pivot] = array[pivot], array[i + 1]
    # array[:i + 1] = quicksort(array[:i + 1])
    # array[i + 2:] = quicksort(array[i + 2:])
    return quicksort(array[:i + 1]) + [array[i + 1]] + quicksort(array[i + 2:])

## Stress Testing

def check(array):
    for i in range(0, len(array) - 1):
        if array[i] > array[i + 1]:
            return False
    return True

for j in range(0, 100):
    mylist = []
    for i in range(0, 50):
        mylist.append(np.random.randint(100))

    if not check(quicksort(mylist)):
        print("> Failed: ", mylist)
