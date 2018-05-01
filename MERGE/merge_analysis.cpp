#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <time.h>
using namespace std;

int merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int compare = 0;
    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = l; // Initial index of merged sub-array
	compare++;
    while (i < n1 && j < n2)
    {
        compare ++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            compare++;
        }
        else
        {
            compare++;
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        compare++;
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        compare++;
        arr[k] = R[j];
        j++;
        k++;
    }
    return compare;
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
int mergeSort(int arr[], int l, int r)
{
    int comp = 0;

    if (l < r)
    {
        comp++;
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

       comp += merge(arr, l, m, r);
    }
    return comp;
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    ofstream file("merge_analysis.csv",ios::out|ios::app);

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

            file << s << ',' << mergeSort(arr,0, s) << endl;
        }

    file.close();
    return 0;
}

