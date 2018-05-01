#include <iostream>
#include <stdio.h>
#include <cmath>
#include <limits>

#define m 20
using namespace std;

class Heap{
public:
	int *heap;
	int heap_size;
	int max_size;
//initializing heap with size Zero
	Heap()
	{
		max_size = m;
		heap = new int[m];
		heap_size = -1;
	}


//returns index of parent of i
	int parent(int i) { return floor(i/2); }


//returns left child index of i
	int left(int i) { return i*2+1; }


//returns right child index of i
	int right(int i) { return i*2+2; }


//returns maximum key of heap
	int heap_maximum() { return heap[1]; }

//heapify the heap at node i
	void heapify(int i)
	{
		int largest = i;
		int l = left(i);
		int r = right(i);

		if( (l < max_size) && (heap[l] > heap[largest]) )
			largest = l;

		if( (r < max_size) && (heap[r] > heap[largest]) )
			largest = r;

		if(largest != i)
		{
			swap(heap[i], heap[largest]);
        	heapify(largest);
		}
	}


//Increase value of key at i
	void heap_increase_key(int i, int key)
	{
		if( key < heap[i] )
			return;

		heap[i] = key;
		while( (i>0) && (heap[parent(i)] < heap[i]) )
		{
			swap(heap[i],heap[parent(i)]);
			i = parent(i);
		}
	}

//extract and returns the maximum key of the heap
	int heap_extract_max()
	{
		if( heap_size < 1)
		{
			cout<<"\n Heap underflow error ... ";
			return 0000;
		}

		int max = heap[1];

		heap[1] = heap[heap_size];
		heap_size--;
		heapify(1);

		return max;
	}


//Insert key into the heap
	void heap_insert(int key)
	{
		heap_size++;
		heap[heap_size] = -1*std::numeric_limits<int>::max(); //negative infinity
		heap_increase_key(heap_size,key);
	}
//display heap
	void show_heap()
	{
		for(int i=0 ; i<heap_size+1 ;i++)
			cout<<heap[i] << " ";
	}
};


int main(void)
{
	Heap h = Heap();

	h.heap_insert(16);
	h.heap_insert(1);
	h.heap_insert(15);
	h.heap_insert(2);
	h.heap_insert(8);
	h.heap_insert(7);
	h.heap_insert(9);
	h.heap_insert(3);
	h.heap_insert(10);
	h.heap_insert(14);

	h.show_heap();
return 0;
}
