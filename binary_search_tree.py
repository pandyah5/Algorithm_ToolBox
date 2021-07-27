class node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, data):
        if (data < self.value):
            if (self.left == None):
                self.left = node(data)
            else:
                self.left.insert(data)
        elif (data > self.value):
            if (self.right == None):
                self.right = node(data)
            else:
                self.right.insert(data)

    def findMin(self, parent):
        if self.left:
            return self.left.findMin(self)
        else:
            return [parent, self]

    def delete(self, data):
        if (data == self.value):
            if (self.left and self.right):
                [p_succ, succ] = self.right.findMin(self)
                if p_succ.left == succ:
                    p_succ.left = succ.right
                else:
                    p_succ.right = succ.right

                succ.left = self.left
                succ.right = self.right

                return succ
            else:
                if (self.right):
                    return self.right
                else:
                    return self.left
        elif (data < self.value):
            if self.left:
                self.left = self.left.delete(data)
        else:
            if self.right:
                self.right = self.right.delete(data)

        return self


    def printTree(self):
        if self.left:
            self.left.printTree()
        print(self.value)
        if self.right:
            self.right.printTree()

def same(fir_node, sec_node):
    if (fir_node == None and sec_node == None):
        return True

    if (fir_node == None or sec_node == None):
        return False

    if (fir_node.value == sec_node.value and same(fir_node.left, sec_node.left) and same(fir_node.right, sec_node.right)):
        return True
    else:
        return False

def isBST(root):
    if root == None:
        return True
    if root.left and root.right:
        if (root.left.value < root.value and root.value < root.right.value):
            return (isBST(root.left) and isBST(root.right))
        else:
            return False
    elif root.left != None:
        if (root.left.value < root.value):
            return isBST(root.left)
        else:
            return False
    elif root.right != None:
        if (root.right.value > root.value):
            return isBST(root.right)
        else:
            return False
    else:
        return True

def find(root, data):
    if not root:
        return False
    if (data == root.value):
        return True
    if (data < root.value):
        return find(root.left, data)
    else:
        return find(root.right, data)

def lowestCommonAncestor(root, data1, data2):
    if root == None:
        return None
    if (data1 == root.value or data2 == root.value):
        if data1 == root.value:
            if find(root, data2):
                return root
            else:
                return None
        else:
            if find(root, data1):
                return root
            else:
                return None
    elif ((data1 < root.value and data2 > root.value) or (data1 > root.value and data2 < root.value)):
        return root
    elif (max(data1, data2) < root.value):
        return lowestCommonAncestor(root.left, data1, data2)
    elif (max(data1, data2) > root.value):
        return lowestCommonAncestor(root.right, data1, data2)

def levelOrderTraversal(root):
    queue = []
    if root == None:
        return
    else:
        queue.append(root)

    while(len(queue)):
        temp = queue.pop(0)
        if (temp.left):
            queue.append(temp.left)
        if (temp.right):
            queue.append(temp.right)
        print(temp.value)
    return

def preorder(root):
    print(root.value)
    if (root.left):
        preorder(root.left)
    if (root.right):
        preorder(root.right)

def postorder(root):
    if (root.left):
        postorder(root.left)
    if (root.right):
        postorder(root.right)
    print(root.value)


## Testing below
root = None
while (True):
    data = int(input("Enter a positive number: "))
    if data <= 0:
        break
    if root == None:
        root = node(data)
    else:
        root.insert(data)

root.printTree()

root = root.delete(4)

print(isBST(root))

if lowestCommonAncestor(root, 10, 7):
    print(lowestCommonAncestor(root, 10, 7).value)

print(find(root, 14))

levelOrderTraversal(root)

postorder(root)

preorder(root)
