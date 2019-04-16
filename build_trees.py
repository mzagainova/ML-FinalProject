import node
import random

## Node type encoding ##
# 0 = THEN
# 1 = OR
# 2 = AND
# 3# = PLACE_#

PLACE_NODE = 0

def printCombos(combos, file):
	for i in combos:
		for j in i:
			file.write(str(j))
			file.write(" ")
		file.write(",")
	file.write("\n")

def getNodeName(num):
    if num == 0:
        return "T"
    elif num == 1:
        return "O"
    else:
        return "A"

def genTree(max_depth, cur_depth):
    global PLACE_NODE
    x = random.randint(0,100000);
    node_type = x % 4
    cur_depth += 1

    if node_type == 3 or cur_depth == max_depth:
        PLACE_NODE += 1
        return node.Node(PLACE_NODE,3)
    else:
        newNode = node.Node(node_type, node_type)
        newNode.insert_left(genTree(max_depth, cur_depth))
        newNode.insert_right(genTree(max_depth, cur_depth))
        return newNode

file = open("trees.txt", "w")
random.seed()
x = random.randint(0, 100000);
node_type = x % 3
max_depth = 5
cur_depth = 1

for i in range(0,10000):
    global PLACE_NODE
    PLACE_NODE = 0
    x = random.randint(0, 100000);
    node_type = x % 4
    cur_depth = 1

    if node_type != 3:
        tree = node.Node(node_type, node_type)
        tree.insert_left(genTree(max_depth, cur_depth))
        tree.insert_right(genTree(max_depth, cur_depth))
	tree.PrintTree()
	tree.PrintTreeToFile(file)
	file.write("\n")
	x = tree.genCombos()
	printCombos(x, file)


x = tree.genCombos()

print "GENRATED Combos: \n"
print x
file.close()
