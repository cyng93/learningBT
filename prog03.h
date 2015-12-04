//Environment: Dev-C++
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <new>
#include <math.h>

using namespace std;



class TreeNode{
friend class Tree;
public:
	int data;
	TreeNode *leftChild;
	TreeNode *rightChild;
	TreeNode *parent;
	TreeNode(){
		data = 0;
		leftChild = NULL;
		rightChild = NULL;
		parent = NULL;
	}
};

class BT{
public:
	//Tree operations
	BT(){root = NULL;
	}
	bool IsEmpty(){return (root == NULL);
	}
	
	BT(const char *a){
		int numOfLevel,i,treeDataSize;
		char *pch;
		char *copyOfA = strdup(a);
		TreeNode *nodeArray;
		
		pch = strtok(copyOfA, " ");
		numOfLevel = atoi(pch);
		treeDataSize = pow(2,numOfLevel)-1;
		nodeArray = new TreeNode[treeDataSize+1];
		
		i=0;
		while(pch != NULL){
			nodeArray[i].data = atoi(pch);
			pch = strtok(NULL, " ");
			//cout << pch << " ";
			i++;
		}
		while(i<treeDataSize+1){
			nodeArray[i].data = -1;
			i++;
		}
		
		i=1;
		root = &nodeArray[i];
		i++;
		while(i<treeDataSize+1){
			// TreeNode* nodeArray
			// nodeArray[i].parent = &nodeArray[i/2]
			// nodeArray[i] = 6
			// &nodeArray[i] = 0xff0560
			
			// TreeNode* nodeArray[] = TreeNode* * nodeArray
			// nodeArray[0] = 0xff0560
			// *(0xff0560) = nodeArray[0]
			// nodeArray[i]->parent = nodeArray[i/2]
			nodeArray[i].parent = &nodeArray[i/2];
			if(i<(treeDataSize+1)/2){
				nodeArray[i].leftChild = &nodeArray[2*i];
				nodeArray[i].rightChild = &nodeArray[2*i+1];
			}
			//cout << nodeArray[i].data << " ";
			i++;
		}
		
		for (i=0; i<treeDataSize+1; i++)
		 	printf("[%d] %d\n", i, nodeArray[i].data);
		
	}
	
	void inorder() 
	// Driver calls workhorse for traversal of the entire tree.
	 // Declared as a public member function of Tree.
	{
		myInorder(root); 
	} 
	
	void myInorder(TreeNode *CurrentNode) 
	// Workhorse traverses the subtree rooted at CurrentNode
	// Declared as a private member function of Tree. 
	{ 
		if(CurrentNode){ 
			myInorder(CurrentNode -> leftChild); 
			cout << CurrentNode -> data;
			myInorder(CurrentNode-> rightChild); 
		} 
	}
	
private:
	TreeNode *root;
};
