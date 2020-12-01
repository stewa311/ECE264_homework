// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE
TreeNode* newtNode(int value)
{
  TreeNode* tnode = (TreeNode*)malloc(sizeof(TreeNode));
  tnode->value = value;
  tnode->left = tnode->right = NULL;
  return (tnode);
}

int search(int arr[], int strt, int end, int value)
{
  int i;
  for (i = strt; i <= end; i++) 
  {
    if (arr[i] == value)
    {
      break;
    }
  }
  return i;
}

TreeNode* buildtnode(int in[], int post[], int inStrt, int inEnd, int* pIndex)
{
  if (inStrt > inEnd)
  {
    return NULL;
  }
  
  TreeNode* tnode = newtNode(post[*pIndex]);
  (*pIndex)--;
  
  if (inStrt == inEnd)
  {
    return tnode;
  }
  
  int iIndex = search(in, inStrt, inEnd, tnode->value);
  
  tnode->right = buildtnode(in, post, iIndex + 1, inEnd, pIndex);
  tnode->left = buildtnode(in, post, inStrt, iIndex - 1, pIndex);
  
  return tnode;
}

Tree * buildTree(int * inArray, int * postArray, int size)
{
  int pIndex = size - 1;
  Tree * trnode = (Tree*)malloc(sizeof(Tree));
  trnode->root = buildtnode(inArray, postArray, 0, size - 1, &pIndex);
  return trnode;
}
#endif

#ifdef TEST_PRINTPATH
void printNode(TreeNode * tn)
{
  if (tn == NULL)
  {
    return;
  }
  printNode(tn -> left);
  printf("%d\n", tn -> value);
}

void printPath(Tree * tr, int val)
{
  
  if (tr == NULL)
  {
    return;
  }
  printNode(tr->root);
}
#endif
