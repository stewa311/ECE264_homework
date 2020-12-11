#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Node of a tree */
struct tnode
{
  int data;
  struct tnode* right;
  struct tnode* left;
};

/* Node of a doubly linked list */
struct Node 
{
  struct tnode* data;
  struct Node* next;
  struct Node* prev;
  char* code;
};

struct tnode* buildtree(int data, struct tnode* right, struct tnode* left)
{
  struct tnode* new_node = (struct tnode*)malloc(sizeof(struct tnode));
  
  new_node->data = data;
  new_node->right = right;
  new_node->left = left;
  return (new_node);
}

void deleteTreeNode(struct tnode* tr)
{
  if (tr == NULL)
  {
    return;
  }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void push(struct Node** head, struct tnode* new_data)
{
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
  new_node->data = new_data;
 
  new_node->next = (*head);
  new_node->prev = NULL;
  new_node->code = "";
 
  if ((*head) != NULL)
  {
    (*head)->prev = new_node;
  }
  (*head) = new_node;
}

void append(struct Node** head, struct tnode* new_data)
{
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
  struct Node* last = *head;
 
  new_node->data = new_data;
 
  new_node->next = NULL;
 
  if (head == NULL) {
    new_node->prev = NULL;
    *head = new_node;
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

void deleteNode(struct Node** head, struct Node* del)
{
  if (*head == NULL || del == NULL)
  {
    return;
  }

  if (*head == del)
  {
    *head = del->next;
  }

  if (del->next != NULL)
  {
    del->next->prev = del->prev;
  }
 
  if (del->prev != NULL)
  {
    del->prev->next = del->next;
  }

  free(del);
  return;
}

int printNode(struct tnode * tn, int val, char* str)
{ 
  if (tn == NULL)
  {
    return 0;
  }
  
  if(tn->data == val)
  {
    printf("%c %d ", tn -> data, tn -> data);
    return 1;
  }
  
  if(printNode(tn->right, val, str))
  {
    strncat(str, "1", 1);
    return 1;
  }
  
  if(printNode(tn->left, val, str))
  {
    strncat(str, "0", 1);
    return 1;
  }
  
  printNode(tn->right, val, str);
  printNode(tn->left, val, str);
  return 0;
}

// This function prints contents of linked list starting from the given node
void printList(struct Node* node)
{
  while (node != NULL)
  {
    printf("%c %d ", node->data->data, node->data->data);
    if(node->code != NULL)
    {
      printf("%s", node->code);
    }
    printf("\n");
    node = node->next;
  }
}

void deleteList(struct Node** head) 
{ 
  struct Node* current = *head; 
  struct Node* next; 
  
  while (current != NULL)  
  { 
    next = current->next;
    if(current->data != NULL)
    { 
      free(current->data);
    }
    free(current);
    current = next; 
  } 

} 

char* search(struct Node* head, int x) 
{ 
    struct Node* current = head;  // Initialize current 
    while (current != NULL) 
    { 
        if (current->data->data == x) 
            return current->code; 
        current = current->next; 
    } 
    return current->code; 
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
  
  struct Node* charlist = NULL;
  
  for (int i = 0; i < lSize; i++)
  {
    if (buffer[i] == '1')
    {
      i = i + 1;
      push(&charlist, buildtree(buffer[i], NULL, NULL));
    }
  }
  
  struct Node* head = NULL;
  for (int i = 0; i < lSize-1; i++)
  {
    if (buffer[i] == '1')
    {
      i = i + 1;
      push(&head, buildtree(buffer[i], NULL, NULL));
    }
    
    if (buffer[i] == '0')
    {
      push(&head, buildtree(-1, head->data, head->next->data));
      deleteNode(&head, head->next);
      deleteNode(&head, head->next);
    }
  }
  
  free(buffer);
  char str[8];
  int l;
  char* r;
  struct Node* temp = charlist;
  while (charlist != NULL)
  {
    str[0] = '\0';
    printNode(head->data, charlist->data->data, str);
    l = strlen(str);
    r = (char*)malloc((l+1)* sizeof(char));
    r[l] = '\0';
    for(int i = 0; i < l; i++)
    {
      r[i] = str[l-1-i];
    }
    printf("%s\n", r);
    charlist->code = r;
    charlist = charlist -> next;
  }
  
  FILE *fptr;
  char* text;
  fptr = fopen (argv[2], "rb");
  if(!fptr) 
  {
    return EXIT_FAILURE;
  }
  
  fseek(fptr, 0L, SEEK_END);
  lSize = ftell(fptr);
  rewind(fptr);

  /* allocate memory for entire text */
  text = calloc(1, lSize+1);
  if(!text)
  {
    fclose(fptr);
    return EXIT_FAILURE;
  }

  /* copy the text into buffer */
  if(1 != fread(text, lSize, 1, fptr))
  {
    fclose(fptr);
    free(text);
    return EXIT_FAILURE;
  }
  
  fclose(fptr);
  
  fptr = fopen (argv[3], "w");
  if(!fptr) 
  {
    return EXIT_FAILURE;
  }
  
  int j;
  for (j = 0; j < lSize; j++);
  {
    printf("%s", search(charlist, text[j]));
  }
  
  free(text);
  
  charlist = temp;
  deleteTreeNode(head->data);
  deleteList(&charlist);
  //deleteList(&head);
  return EXIT_SUCCESS;
}
