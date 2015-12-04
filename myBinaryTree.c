#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <iostream>
#include <string>

#define myCode

using namespace std;

/* A binary tree tNode has data, pointer to left child
   and a pointer to right child */
typedef struct tNode
{
   int data;
   struct tNode* left;
   struct tNode* right;
   struct tNode* parent;
} TreeNode;

/* Function to traverse binary tree without recursion and
   without stack */
void MorrisTraversal(struct tNode *root)
{
  struct tNode *current,*pre;

  if(root == NULL)
     return;

  current = root;
  while(current != NULL)
  {
    if(current->left == NULL)
    {
      printf(" %d ", current->data);
      current = current->right;
    }
    else
    {
      /* Find the inorder predecessor of current */
      pre = current->left;
      while(pre->right != NULL && pre->right != current)
        pre = pre->right;

      /* Make current as right child of its inorder predecessor */
      if(pre->right == NULL)
      {
        pre->right = current;
        current = current->left;
      }

      /* Revert the changes made in if part to restore the original
        tree i.e., fix the right child of predecssor */
      else
      {
        pre->right = NULL;
        printf(" %d ",current->data);
        current = current->right;
      } /* End of if condition pre->right == NULL */
    } /* End of if condition current->left == NULL*/
  } /* End of while */
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new tNode with the
   given data and NULL left and right pointers. */
struct tNode* newtNode(int data)
{
  struct tNode* tNode = (struct tNode*)
                       malloc(sizeof(struct tNode));
  tNode->data = data;
  tNode->left = NULL;
  tNode->right = NULL;

  return(tNode);
}

/* Driver program to test above functions*/
int main()
{
    char input[] = "4 3 11 5 6 12 8 4 -1 9 -1 -1 -1 17 -1 -1";
    struct tNode *root;

#ifdef myCode
    int i;          // for array purpose
    int *rawData;
    int treeLevel;
    int nodeNumbers;
    struct tNode **nodeArray;

    char *pch;
    pch = strtok(input, " ");
    treeLevel = atoi(pch);
    nodeNumbers = (int)pow(2, treeLevel)-1;

    rawData = new int[nodeNumbers+1];
    nodeArray = new tNode*[nodeNumbers+1];
#ifdef debugMore
    printf("nodeNumbers: %d !\n\n", (int)pow(2, treeLevel)-1);
#endif
    for(i=1; i<nodeNumbers+1; i++){
        pch = strtok(NULL, " ");
        rawData[i] = atoi(pch);
        nodeArray[i] = newtNode(rawData[i]);
#ifdef debugMore
        printf("[%d] %d\n", i, nodeArray[i]->data);
#endif
    }

    root = nodeArray[1];

    for(i=1; i<nodeNumbers+1; i++){
        if(i!=1){ // parent[i] = lowbound of i/2
            nodeArray[i]->parent = nodeArray[i/2];
        }

        if(i>=(int)pow(2, treeLevel)/2) //last level's Node have no child
            continue;

        if(nodeArray[2*i]->data != -1 || 1){ //valid left child
            nodeArray[i]->left = nodeArray[2*i];
        }
        if(nodeArray[2*i+1]->data != -1 || 1){ //valid right child
            nodeArray[i]->right = nodeArray[2*i+1];
        }
    }

#else
#endif

  MorrisTraversal(root);

  getchar();
  return 0;
}
