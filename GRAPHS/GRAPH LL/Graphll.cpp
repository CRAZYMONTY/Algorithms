#include <iostream>
#include <limits>
#include "linkedlist.h"
#include <list>
class vertex{
public:
    int alias;
    bool color;
    int dist;
    int parent;

    vertex()
    {
        color = false;
        dist = std::numeric_limits<int>::max(); //sentenel
    }
};


class Graph{
public:
    int vsize;
    vertex *V;
    linkedlist<int> *AdjList;

    Graph(int size)
    {
        vsize = size;
        V = new vertex [size+1];
        for(int i=1; i<size+1 ; i++)
        {
            V[i].alias = i;
        }

        AdjList = new linkedlist<int> [vsize];

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
            AdjList[n1-1].Insertlast(n2);
            }
    }

    void display()
    {
        cout<<"\n Adj LIST :";
        for(int i=0; i<vsize; i++)
        {
            cout<<"["<<i+1<<"]->>>>";
            AdjList[i].forwtraversal();
            cout<<endl;
        }

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
            node<int>* temp = AdjList[u.alias-1].head;

            while(temp != NULL)
            {
                if (!V[temp->alias].color)
                {
                    V[temp->alias].color = true;
                    V[temp->alias].dist = V[u.alias].dist + 1;
                    V[temp->alias].parent = u.alias;
                    Q.push_back(V[temp->alias]);
                }

                temp = temp->next;
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

        node<int>* temp = AdjList[v->alias-1].head;
        while(temp != NULL)
            {
                if (!V[temp->alias].color)
                {
                    V[temp->alias].color = true;
                    V[temp->alias].dist = V[v->alias].dist + 1;
                    V[temp->alias].parent = v->alias;
                    visit(&V[temp->alias]);
                }

                temp = temp->next;
            }
    }
};

int main()
{
    Graph *G = new Graph(4);
    G->display();
    G->dfs(1);
    G->bfs(1);
    return 0;
}

