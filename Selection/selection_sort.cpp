// C program for implementation of selection sort
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <time.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int selectionSort(int arr[], int n)
{
    int i, j, min_idx, compare=0;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        compare++;
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            compare++;
          if (arr[j] < arr[min_idx])
          {
            compare++;
            min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
    return compare;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    ofstream file("bubble_analysis.csv",ios::out|ios::app);

    int s;
        for(int j=0; j<100 ;j++)
        {
            //generating random size of array between 30-1000
            do{
                s = rand()%1000;
               }while(s<30);


            int arr[s];
            //seeding random
            srand((unsigned)time(NULL));
            //generating random inputs of random sized array
            for(int i=0 ; i<s ; i++)
                arr[i] = rand()%100000 + 1;

            file << s << ',' << selectionSort(arr, s) << endl;
        }

    file.close();
    return 0;
}
