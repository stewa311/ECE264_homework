// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
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

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

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
