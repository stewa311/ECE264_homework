// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 9
 
void print(int arr[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%d",arr[i][j]);
    }
  printf("\n");
  }
}
 
int isSafe(int grid[N][N], int row, int col, int num)
{
  for (int x = 0; x <= 8; x++)
  {
    if (grid[row][x] == num)
    {
      return 0;
    }
  }

  for (int x = 0; x <= 8; x++)
  {
    if (grid[x][col] == num)
    {
      return 0;
    }
  }

  int startRow = row - row % 3, startCol = col - col % 3;
   
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (grid[i + startRow][j + startCol] == num)
      {
        return 0;
      }
    }
  }
  return 1;
}
 
int solveSuduko(int grid[N][N], int row, int col)
{
  if (row == N - 1 && col == N)
  {
    return 1;
  }
 
  if (col == N) 
  {
    row++;
    col = 0;
  }
    
  if (grid[row][col] > 0)
  {
    return solveSuduko(grid, row, col + 1);
  }
 
  for (int num = 1; num <= N; num++) 
  {
    if (isSafe(grid, row, col, num)==1) 
    {
      grid[row][col] = num;

      if (solveSuduko(grid, row, col + 1)==1)
      {
        return 1;
      }
    }
    grid[row][col] = 0;
  }
  return 0;
}
 
int main(int argc, char * * argv)
{
  // argv[1]: input file
  if (argc < 2)
    {
      return EXIT_FAILURE;
    }
    
    FILE *fptr = fopen(argv[1], "r");
    
    int grid[N][N];
    
    if (fptr == NULL)
    {
      return EXIT_FAILURE;
    }
    
    char c;
    int x, row, column;
    x = row = column = 0;
    
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        grid[i][j] = 0;
      }
    }
    
    while(!feof(fptr) && (c = fgetc(fptr)))
    {
       if(c == '\n')
       {
         row++;
	 column = 0;
       }
       if(c != '\n' && c != '\r')
       {
         x = atoi(&c);
	 if(grid[row][column] == 0)
	 {
	   grid[row][column] = x;
	   column++;
	 }
       }
    }
    fclose(fptr);
 
    if (solveSuduko(grid, 0, 0)==1)
        print(grid);
    else
        printf("Invalid Input or No Solution\n");
 
    return EXIT_SUCCESS;
}
