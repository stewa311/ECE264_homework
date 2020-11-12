// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifdef TEST_READLIST
// read line by line from the input file
// each line shorter than WORDLENGTH (including '\n' and '\0')
// arithlist should have memory to store head and tail
// If arithlist is NULL, return false
// If fopen fails, return false
// If a line is too long,
//    free memory of the list
//    fclose
//    return false
// If everything is fine
//    fclose
//    arithlist points to the head and tail of the list
//    return true
bool readList(char * filename, List * arithlist)
{
  if (arithlist == NULL)
  {
    return false;
  }
  
  FILE * fptr = fopen(filename, "r");
  if (fptr == NULL)
  {
    return false;
  }
  
  char * read;
  while(read = fgets(arithlist, WORDLENGTH, fptr))
  {
    if (read == -1)
    {
      flcose(fptr);
      free(arithlist);
      return false;
    }
  }
  
  fclose(fptr);
  return true;
}
#endif

#ifdef TEST_DELETELIST
// If arithlist is NULL, do nothing
// release the memory of every node in the list
// release the memory of the list 
void deleteList(List * arithlist)
{
  if (arithlist != NULL)
  {
    Node * h = arithlist -> head;
  }
  while (h != NULL)
  {
    Node * p = h -> next;
    free (h);
    h = p;
  }
}
#endif

#ifdef TEST_ADDNODE
// Input: 
// arithlist stores the addresses of head and tail
// If arithlist is NULL, do nothing
// word is the word to be added
//
// Output:
// a ListNode is added to the end (become tail)
//
// allocate memory for a new ListNode
// copy word to the word attribute of the new ListNode
// insert the ListNode to the list
void addNode(List * arithlist, char * word)
{
  if (arithlist -> tail != NULL)
  {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = word;
    new_node -> next = (*tail_ref);
    (*tail_ref) = new_node;
  }
}
#endif

#ifdef TEST_DELETENODE
//  Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, return false
// If the list is empty (head and tail are NULL), return false
// ln is the node to be deleted
// If ln is not in the list, return false
// 
// Output:
// arithlist stores the addresses of head and tail
//   after ln is deleted
// return true.
//
// Be careful about delete the first or the last node
bool deleteNode(List * arithlist, ListNode * ln)
{
  if ((arithlist == NULL) | (arithlist -> tail == NULL) | (arithlist -> head == NULL))
  {
    return false
  }
  
  Node * h = arithlist -> head;
  Node * p = h;
  Node * q = p -> next;
  while ((q != NULL) && ((q -> value) != ln))
  {
    p = p -> next;
    q = q -> next;
  }
  
  if (q != NULL)
  {
    p -> next = q -> next;
    free (q);
  }
  
  return true;
}
#endif

