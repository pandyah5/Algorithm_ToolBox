class node:
    def __init__(self, value):
        self.value = value
        self.next = None

    def value(self, data):
        self.value = data

    def print_list(self):
        ptr = self
        while(ptr):
            print(ptr.value)
            ptr = ptr.next

    def next(self, node):
        self.next = node

    def insert_end(self, value):
        ptr = self
        while(ptr.next):
            ptr = ptr.next
        ptr.next = node(value)



import numpy as np

head = node(10)
ptr = head
for i in range (9):
    rand = np.random.randint(10)
    print("Added: ", rand)
    ptr.next = node(rand)
    ptr = ptr.next

## Testing insert end
head.print_list()
head.insert_end(11)
head.print_list()
