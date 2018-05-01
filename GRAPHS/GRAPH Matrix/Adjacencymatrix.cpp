#include <iostream>
#include <limits>
using namespace std;
#define MAX 20

struct node{
    bool color;
    int dist;
    int parent;
};
//Defining class for Adjacency Matrix
class adjmatrix{
private:
	int size;
	node **adj;
public:

	adjmatrix(int n)
	{
		size = n;
		adj = new node* [n];

		for (int i = 0; i < n; i++)
        {
            adj[i] = new node [n];
            for(int j = 0; j < n; j++)
            {
                adj[i][j].dist = -1;
                adj[i][j].color = 0;
                adj[i][j].parent = NULL;
            }
        }
    }


    void add_edge(int n1, int n2)
    {

    	if( n1 > size || n2 > size || n1 < 0 || n2 < 0)
        {
            cout<<"Invalid edge!\n";
        }
        else
        {
            adj[n1 - 1][n2 - 1].dist = std::numeric_limits<int>::max() ;
        }
    }


    void display()
        {
            int i,j;
            for(i = 0;i < size;i++)
            {
                for(j = 0; j < size; j++)
                {
                    if(adj[i][j].dist >= 0)
                    {
                        cout<<"("<<adj[i][j].dist<<","<<adj[i][j].color<<","<<adj[i][j].parent<<")";
                    }
                    else
                        cout<<"0  ";
                }
                cout<<endl;
            }
        }

	};
int main()
{
    int nodes, max_edges, origin, destin;
    cout<<"Enter number of nodes: ";
    cin>>nodes;
    adjmatrix am(nodes);
    max_edges = nodes * (nodes - 1);
    for (int i = 0; i < max_edges; i++)
    {
        cout<<"Enter edge (-1 -1 to exit): ";
        cin>>origin>>destin;
        if((origin == -1) && (destin == -1))
            break;
        am.add_edge(origin, destin);
    }
    am.display();
    return 0;
}
