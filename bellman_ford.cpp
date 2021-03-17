#include<iostream>
#include<vector>

using namespace std;

class Graph
{
public:
    int V;
    vector<int> *adj;
    vector<int> *weight;      //vector<int> *weight;
    vector<int> visited;     //vector<int> visited
    vector<int> not_visited;     //not_visited
    int* distance;              // int* distance
    int* parent;                //int* parent

    Graph(int vertices);
    void addEdge(int v1, int v2, int w);
    int dijkstra(int src);
    void bellman_ford(int src);
};

Graph::Graph(int vertices)
{
    V = vertices;

    adj = new vector<int>[vertices];
    weight = new vector<int>[vertices];     //initialize weight

    for(int i=0; i<vertices; i++)
    {
        not_visited.push_back(i);
    }

    distance = new int[vertices];   //define size of parent and distance
    parent = new int[vertices];

    //initialize arrays
    for(int i=0; i<V; i++)
    {
        distance[i] = 99999;
        parent[i] = -1;
    }

}

void Graph::addEdge(int v1, int v2, int w)
{
    adj[v1].push_back(v2);
    weight[v1].push_back(w);       //update weight list
}

//implement dijkstra
int Graph:: dijkstra(int src)
{
    while(!not_visited.empty())
    {
        int init_distance = 99999;
        int temp_index = -1 ;
        for(int i =0; i<not_visited.size(); i++)
        {
            if( init_distance > distance[not_visited.at(i)] )
            {
                init_distance = distance[not_visited.at(i)] ;
                temp_index = i;
            }
        }

        visited.push_back(not_visited.at(temp_index)) ;
        int item = not_visited.at(temp_index);

        for(int i = temp_index; i<not_visited.size()-1 ; i++ )
        {
            not_visited[i] = not_visited[i+1];

        }

        not_visited.pop_back() ;

        for(int i=0; i<adj[item].size(); i++)
        {
            int new_node = adj[item].at(i);
            int temp_distance = distance[item] + weight[item].at(i) ;

            if(temp_distance < distance[new_node])
            {
                distance[new_node] = temp_distance ;
                parent[new_node] = item ;
            }
        }
    }


    for(int i=0; i<V; i++)
    {
        cout<<i<<" Shortage Distance "<<distance[i] <<"\n";
    }

    cout<<"\nParents\n";

    for(int i=0; i<V; i++)
    {
        cout<<i<<" Parent "<<parent[i]<<"\n";
    }

    cout<<"\n"<<" Shortest Path"<<endl;
    int v=3;
    while(v!=-1)
    {

        cout<< v<<"     ";
        v= parent[v];
    }
}


void Graph:: bellman_ford(int src)
{
    int i = 0;

    while(i<= V-1)      //update distance
    {
        int prnt= 0;

        for(int prnt= 0; prnt<V;prnt++)      //traverse node
        {
            for(int k= 0; k< adj[prnt].size(); k++)       // create index
            {
                int u= prnt;
                int v= adj[prnt].at(k);     //indexing for child
                int w= weight[prnt].at(k);
                int dist= distance[u]+w;

                if(distance[v] > dist)
                {
                    distance[v] = dist;
                    parent[v]= u;
                }

            }
        }

        i++ ;

    }

    cout<<"Distance\n";

    for(int i=0; i<V; i++)
    {
        cout<<i<<" Shortage Distance "<<distance[i] <<"\n";
    }

    cout<<"\nParents\n";

    for(int i=0; i<V; i++)
    {
        cout<<i<<" Parent "<<parent[i]<<"\n";
    }

   cout<<"\n"<<" Shortest Path"<<endl;
    int v=3;
    while(v!=-1)
    {

        cout<< v<<"     ";
        v= parent[v];
    }


}


int main()
{
    Graph g(4);

    g.addEdge(0,2,3);
    g.addEdge(0,1,5);
    g.addEdge(2,1,1);
    g.addEdge(1,3,2);

    int src = 0;
    g.distance[src] = 0;         //g.distance[src] = 0
   // g.dijkstra(src);              //dijkstra(src)

    g.bellman_ford(src);


}



