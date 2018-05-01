// C program for insertion sort
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
using namespace std;

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
   ofstream output;
   output.open("insertion_data.csv",ios::out|ios::app);
   int i, key, j;
   int compare = 0;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       compare++;
       while (j >= 0 && arr[j] > key)
       {
           compare++;
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
   cout<<"\n Comparisons : "<<compare<<endl;
   output << n<<","<<compare<<endl;
   output.close();
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}



/* Driver program to test insertion sort */
int main()
{
    int s;
      for(int j=0; j<100 ;j++){
            do{
                s = rand()%1000;
            }while(s<30);

            cout<<s;
            int arr[s];
             srand((unsigned)time(NULL));
            for(int i=0 ; i<s ; i++)
                arr[i] = rand()%100000 + 1;
            {
            }

            insertionSort(arr, s);
        }


    return 0;
}
