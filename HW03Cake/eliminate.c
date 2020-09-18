// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements

  int i = 0;
  int j = 0;
  int ex = n;
  int last = 0;
  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked
  /*
  while (ex > 1)
  {
    if ((i + 1) % k == 0)
      {
        while (arr[i] == -1)
	  {
	    i++;
	    if (i == n)
              {
                i = 0;
              }
	  }
        arr[i] = -1;
	ex = ex - 1;
	printf("%d\n", i);
      }
    i++;
    if (i == n)
      {
        i = 0;
      }
  }
  */
  
  while (ex > 1) 
    {
      for (j = 1; j <= k; j++)
        {
	  while (arr[i] == -1)
	    {
	      i++;
	      if (i == n)
	        {
		  i = 0;
		}
	    }
	  if (j == k)
	    {
	      arr[i] = -1;
	      ex = ex - 1;
	      printf("%d\n", i);
	    }
	  i++;
	  if (i == n)
	    {
	      i = 0;
	    }
	}
    }
  
  // print the last one

  while (arr[last] == -1)
    {
      last++;
    }
  printf("%d\n", last);


  // release the memory of the array
  free (arr);
}
#endif
