#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <time.h>

using namespace std;


int partitiona(int* A,int p, int r)
{
    int x = A[r];
	int i = p-1;

	for(int j=p; j<=r-1; j++)
	{
		if(A[j] <= x)
		{
			i = i+1;
			swap(A[i],A[j]);
		}
	}

	swap(A[i+1],A[r]);

return i+1;
}

int quick_sort(int * A, int p, int r)
{
	int compare=0;
	if( p < r )
	{
		compare++;
		int q = partitiona(A,p,r);
		compare += (r-p-1)*2;//#of comparisons in partitiona
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}
  return compare;
}



int main(void)
{
	ofstream file("quick_analysis.csv",ios::out|ios::app);

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

            file << s << ',' << quick_sort(arr,0, s) << endl;
        }

    file.close();
    return 0;
}
