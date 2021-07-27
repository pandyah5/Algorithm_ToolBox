def bubble_sort(array):
    change = 1
    while change:
        change = 0
        for i in range(0, len(array) - 1):
            if array[i] > array[i + 1]:
                temp = array[i + 1]
                array[i + 1] = array[i]
                array[i] = temp
                change = 1
    return array

my_list = [3, 5, 4, 7, 1, 9, 15]

print(bubble_sort(my_list))
