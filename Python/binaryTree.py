class Node:

    def __init__(self, value):
        self.left = self.right = None
        self.value = value


class Tree:

    def __init__(self):
        self.root = None

    def getRoot(self):
        return self.root

    def add(self, value):
        if (self.root is None):
            self.root = Node(value)
        else:
            self._add(self.root, value)

    def _add(self, node, value):
        if (value > node.value):
            if (node.right is not None):
                self._add(node.right, value)
            else:
                node.right = Node(value)
        else:
            if (node.left is not None):
                self._add(node.left, value)
            else:
                node.left = Node(value)

    def search(self, value):
        return None if self.root is None else self._search(self.root, value)

    def _search(self, node, value):
        if (value is node.value):
            return True
        elif (value > node.value and node.right is not None):
            return self._search(node.right, value)
        elif (value < node.value and node.left is not None):
            return self._search(node.left, value)
        else:
            return False

    def deleteTree(self):
        self.root == None

    def printTree(self):
        if (self.root is not None):
            self._printTree(self.root)

    def _printTree(self, node):
        if (node is not None):
            self._printTree(node.left)
            print(str(node.value) + " ")
            self._printTree(node.right)


tree = Tree()
tree.add(3)
[tree.add(i*2) for i in range(22)]
check = tree.getRoot()
tree.printTree()
print("S")
print(tree.search(8))
