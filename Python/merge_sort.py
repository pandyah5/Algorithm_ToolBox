import numpy as np

def merge(f_arr, s_arr):
    out = np.array([])
    while (len(f_arr) and len(s_arr)):
        if f_arr[0] < s_arr[0]:
            out = np.append(out, f_arr[0])
            f_arr = np.delete(f_arr, 0)
        else:
            out = np.append(out, s_arr[0])
            s_arr = np.delete(s_arr, 0)

    for elem in f_arr:
        out = np.append(out, elem)

    for elem in s_arr:
        out = np.append(out, elem)

    return out


def merge_sort(arr):
    if (len(arr) <= 1):
        return arr

    first_arr = np.array(arr[:int(len(arr)/2)])
    sec_arr = np.array(arr[int(len(arr)/2):])

    first_arr = merge_sort(first_arr)
    sec_arr = merge_sort(sec_arr)

    return merge(first_arr, sec_arr)

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

    if not check(merge_sort(mylist)):
        print("> Failed: ", mylist)

my_list = [3, 5, 6, 1, 7, 9, 8, 4, 2]
print(merge_sort(my_list))
