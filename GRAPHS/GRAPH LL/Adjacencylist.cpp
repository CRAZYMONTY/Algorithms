#include <iostream>
#include "linkedlist.h"


class Adjacency{
private:
	int vsize;
	linkedlist<int> *heads;
public:
	Adjacency(int size)
	{
		vsize = size;
		heads = new linkedlist<int> [size];
	}

	void add_edge(int n1, int n2)
    {

    	if( n1 > vsize || n2 > vsize || n1 < 0 || n2 < 0)
        {
            cout<<"Invalid edge!\n";
        }
        else
        {
            heads[n1-1].Insertlast(n2);
        }
    }

    void display()
    {
    	for(int i=0; i<vsize; i++)
    	{
    		cout<<"["<<i+1<<"]->>>>";
    		heads[i].forwtraversal();
    		cout<<endl;
    	}
    }
};

int main()
{
    int size, max_edges, origin, destin,d;
    cout<<"Enter number of nodes: ";
    cin>>size;
    Adjacency al(size);
    max_edges = size * (size - 1);
    for (int i = 0; i < max_edges; i++)
    {
        cout<<"Enter edge (-1 -1 to exit): ";
        cin>>origin>>destin;
        if((origin == -1) && (destin == -1))
            break;
        al.add_edge(origin, destin);
    }
    al.display();
    return 0;
}
