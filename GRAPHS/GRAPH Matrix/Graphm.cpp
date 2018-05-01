#include <iostream>
#include <limits>
#include <list>
using namespace std;
class vertex{
public:
	int alias;
    bool color;
    int dist;
    int parent;

    vertex()
    {
        color = false;
        dist = -1;
        parent = NULL;
    }
};

struct node{
    int  dist;
};

class Graph{
public:
    int vsize;
    vertex *V;
    node **adj;

    Graph(int size)
    {
        vsize = size;
        V = new vertex [vsize+1];

        for(int i=1; i<vsize+1 ; i++)
        {
            V[i].alias = i;
        }

        adj = new node* [vsize];
        for (int i = 0; i < vsize; i++)
        {
            adj[i] = new node [vsize];
            for(int j = 0; j < vsize; j++)
            {
                adj[i][j].dist = -1;
            }
        }
        int max_edges = size * (size - 1);
        int origin, destin;

        for (int i = 0; i < max_edges; i++)
        {
            cout<<"Enter edge (-1 -1 to exit): ";
            cin>>origin>>destin;
            if((origin == -1) && (destin == -1))
                break;
            add_edge(origin, destin);
        }
    }

     void add_edge(int n1, int n2)
    {

    	if( n1 > vsize || n2 > vsize || n1 < 0 || n2 < 0)
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
        cout<<"\n Adj Matrix :";
       int i,j;
            for(i = 0;i < vsize;i++)
            {
                for(j = 0; j < vsize; j++)
                {
                    if(adj[i][j].dist > 0)
                        cout<<" 1 ";
                    else
                        cout<<" 0  ";
                }
                cout<<endl;
            }
                cout<<endl;

        cout<<"\n \n Vertex : ";
        for(int i=1; i<vsize+1 ;i++)
            cout<<V[i].alias<<" ";
    }


    void bfs(int s)
    {
        list<vertex> Q;
        for(int i=1; i<vsize+1;i++)
        {
                V[i].color = false;
                V[i].dist = std::numeric_limits<int>::max();
                V[i].parent = NULL;
            }

        V[s].color = true;
        V[s].dist = 0;
        V[s].parent = NULL;

        Q.push_back(V[s]);

        cout<<"\n BFS : ";
        while(!Q.empty())
        {
            vertex u = Q.front();
            cout<<" "<<u.alias;
            Q.pop_front();

            for(int i=0; i<vsize ;i++)
            {
                if(!V[i+1].color && adj[u.alias-1][i].dist >= 0)
                {
                        V[i+1].color = true;
                        V[i+1].dist = V[u.alias-1].dist + 1;
                        V[i+1].parent = u.alias;
                        Q.push_back(V[i+1]);
                 }
            }
        }
    }

    void dfs(int s)
    {
        cout<<"\n DFS :";
        for(int i=1 ; i<vsize+1 ; i++)
        {
             V[i].color = false;
                V[i].dist = std::numeric_limits<int>::max();
                V[i].parent = NULL;
        }
        V[s].dist = 0;
        V[s].parent = NULL;
        V[s].dist = -1;
        visit(&V[s]);

        }

    void visit(vertex *v)
    {
        v->dist++;
        v->color = true;
        cout<<" "<<v->alias;

            for(int i=0; i<vsize ; i++)
            {
                if (!V[i+1].color && adj[v->alias-1][i].dist >= 0)
                {
                    V[i+1].color = true;
                    V[i+1].dist = V[v->alias-1].dist + 1;
                    V[i+1].parent = v->alias;
                    visit(&V[i+1]);
                }
            }
    }
};

int main()
{
    Graph *G = new Graph(5);
    G->display();
    G->bfs(1);
    G->dfs(1);
    return 0;
}
