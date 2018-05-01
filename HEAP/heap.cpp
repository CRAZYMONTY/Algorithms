#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
int heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    int counter = 0;
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
    {
         largest = l;
    }

    // If right child is larger than largest so far

    if (r < n && arr[r] > arr[largest])
     {
        largest = r;
        }

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        counter++;
        // Recursively heapify the affected sub-tree
        counter += heapify(arr, n, largest);
    }
    return counter;
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    int c = 0;
    ofstream file("heap.csv",ios::out|ios::app);
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=1; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        c += heapify(arr, i, 0);
    }
    cout<<n<<"-"<<c<<endl;
    file << n << ',' << c <<endl;
    file.close();
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program
int main()
{
   int s;
      for(int j=0; j<100 ;j++){
            do{
                s = rand()%1000;
            }while(s<30);

            int arr[s];
             srand((unsigned)time(NULL));
            for(int i=0 ; i<s ; i++)
            {
              arr[i] = rand()%100000 + 1;
            }

            heapSort(arr, s);
        }
    return 0;
}
