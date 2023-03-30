// Program to print all combination of size r in an array of size n
#include <stdio.h>
void combinationUtil(char arr[], char data[], int start, int end,
                     int index, int len, int v);

// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(char arr[], int n, int len, int v)
{
    // A temporary array to store all combination one by one
    char data[len];

    // Print all combination using temporary array 'data[]'
    combinationUtil(arr, data, 0, n-1, 0, len, v);
}

/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void combinationUtil(char arr[], char data[], int start, int end,
                     int index, int len, int v)
{
    // Current combination is ready to be printed, print it
    if (index == len){
        for (int j=0; j<len; j++){
            printf("%c ", data[j]);
        }
        printf("\n");
        return;
    }

    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (int i=start; i<=end && end-i+1 >= len-index; i++){
      for (int j=v; j<16; j++){
        data[index] = arr[j];
        combinationUtil(arr, data, i+1, end, index+1, len, j);
      }

    }
}

// Driver program to test above functions
int main()
{
    char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    int len = 64;
    int hex = 16;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, len, 0);
}


/*
int i =0;
int j = 0;

char input [64];  //64 bit char array, each index will be hexadecimal

for(i=0; i<64; i++){
  for(j=0; j<16; j++){
    if(j<10){
      input[i]=j;
    }
    else{
      if(j==10)
        input[i]='a';
      else if(j==11)
        input[i]='b';
    }
    hash(sha(input))=input;
  }
}

0000
1000
2000
3000

0100
0200
0300

0010
0020
0030

0001
0002
0003

1100
1200
1300
2100
2200
2300
3100
3200
3300

*/


/*
// C# program for the above approach
using System;
using System.Collections.Generic;
class GFG
{

  // Function to generate permutations of
  // at most X elements from array arr[]
  static void differentFlagPermutations(int X, List<string> arr)
  {
    List<string> ml = new List<string>();
    ml = arr;
    for(int i = 0; i < ml.Count; i++)
    {
      Console.Write(ml[i] + " ");
    }

    int count = ml.Count;

    // Traverse all possible lengths
    for(int z = 0; z < X - 1; z++)
    {

      // Stores all combinations
      // of length z
      List<string> tmp = new List<string>();

      // Traverse the array
      for(int i = 0; i < arr.Count; i++)
      {
        for(int k = 0; k < ml.Count; k++)
        {
          if (arr[i] != ml[k])
          {

            // Generate all
            // combinations of length z
            tmp.Add(ml[k] + arr[i]);
            count += 1;
          }
        }
      }

      // Print all combinations of length z
      for(int i = 0; i < tmp.Count; i++)
      {
        Console.Write(tmp[i] + " ");
      }

      // Replace all combinations of length z - 1
      // with all combinations of length z
      ml = tmp;
    }
  }

  // Driver code
  static void Main()
  {

    // Given array
    List<string> arr = new List<string>(new string[] { "c", "a", "b" });

    // Given X
    int X = 2;

    differentFlagPermutations(X, arr);
  }
}
*/
