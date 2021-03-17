#include<iostream>
#include<vector>

using namespace std;


class Graph
{
public:     // main function a class create kore main function theke access kora
    int V;
    vector<int> *adj;
    bool *visited;

    Graph(int V);
    void addEdge(int v1, int v2);
    void DFS(int s);

};


Graph::Graph(int V)
{
    this ->V = V;                   //LAST er v holo parameter er v, constructor
    adj = new vector<int>[V];      //parameter v    //array er size vex=ztor er array
    visited = new bool[V];
    for(int i=0; i<V; i++)
    {
        visited[i] = false;


    }
}


void Graph:: addEdge(int v1,int v2)         //graph class er moddhe addEdge funtion define kora hocche
{
    adj[v1].push_back(v2);          //push back means vector k add kora, by directional
    ///adj[v2].push_back(v1);    // by directional er jnnoo

}


void Graph::DFS(int s)
{
    cout<<s<<"," ;
    visited[s] = true;

    for(int i=0; i<adj[s].size(); i++)
    {
        int v = adj[s].at(i);
        if( ! visited[v])
        {
            DFS(v);
        }
    }
}


int main()
{
    Graph g(4) ;

    g.addEdge(0,2);
    g.addEdge(0,1) ;
    //g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(1,3);
    //g.DFS(3);   //for deyar karone comment kora hoise
  for(int i =0; i<g.V; i++)     //vertex count kori
  {
      if(!g.visited[i])
      {
          g.DFS(i);
      }
  }

    /*
    for(int i=0; i<4; i++)
    {
        cout<<i<<": " ;

        for(int j=0; j<g.adj[i].size(); j++)
        {
            cout<<g.adj[i].at(j)<<", " ;  //i er adjaacent list a j er value print
        }
        cout<<"\n";
    } */
}





