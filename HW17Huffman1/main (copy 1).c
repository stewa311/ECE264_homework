#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
/* Node of a doubly linked list */
struct Node 
{
  int data;
  struct Node* right;
  struct Node* left;
  struct Node* next;
  struct Node* prev;
};

void mergeNode(struct Node** head_ref)
{
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  
  struct Node* last = *head_ref;
 
  new_node->data = -1;
 
  new_node->next = NULL;

  while (last->next != NULL)
  {
    last = last->next;
  }
  
  printf("%c %d num\n", last->data, last->data);
 
  return;
}

/* Given a reference (pointer to pointer) to the head
   of a DLL and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data)
{
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  
  struct Node* last = *head_ref;
  
  new_node->data = new_data;
  
  new_node->next = NULL;
  new_node->right = NULL;
  new_node->left = NULL;
  
  if (*head_ref == NULL) 
  {
    new_node->prev = NULL;
    *head_ref = new_node;
    return;
  }
  
  while (last->next != NULL)
  {
    last = last->next;
  }

  last->next = new_node;

  new_node->prev = last;
 
  return;
}

// This function prints contents of linked list starting from the given node
void printList(struct Node* node)
{
  while (node != NULL)
  {
    printf("%c %d \n", node->data, node->data);
    node = node->right;
  }
}

int main(int argc, char * * argv)
{
  FILE *fp;
  long lSize;
  char *buffer;

  fp = fopen (argv[1], "rb");
  if(!fp) 
  {
    return EXIT_FAILURE;
  }

  fseek(fp, 0L, SEEK_END);
  lSize = ftell(fp);
  rewind(fp);

  /* allocate memory for entire text */
  buffer = calloc(1, lSize+1);
  if(!buffer)
  {
    fclose(fp);
    return EXIT_FAILURE;
  }

  /* copy the text into buffer */
  if(1 != fread(buffer, lSize, 1, fp))
  {
    fclose(fp);
    free(buffer);
    return EXIT_FAILURE;
  }
  
  fclose(fp);
  
  struct Node* head = NULL;
  
  for (int i = 0; i < lSize; i++)
  {
    if (buffer[i] == '1')
    {
      i = i + 1;
      append(&head, buffer[i]);
    }
    
    if (buffer[i] == '0')
    {
      printf("is it getting here\n");
      mergeNode(&head);
    }
  }
  
  printList(head);

  free(buffer);
  
  
  
  return EXIT_SUCCESS;
}
