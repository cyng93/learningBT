all:
	g++ -o myBinaryTree myBinaryTree.c
run:
	g++ -o myBinaryTree myBinaryTree.c && ./myBinaryTree
clean:
	rm myBinaryTree
