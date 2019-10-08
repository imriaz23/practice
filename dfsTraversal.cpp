#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int v;                               // No. of vertices
    list<int> *adj;                      // Pointer to an array containg adjcency lists
    void DFSUtil(int v, bool visited[]); // A function used by DFS
public:
    Graph(int v);               //constructor
    void addEdge(int v, int w); //funtion to add an edge to graph
    void DFS(int);                 //print DFS traversal of complete graph
};
Graph ::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}
void Graph ::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph ::DFSUtil(int v, bool visited[])
{
    //mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
    //recur for all the vertices adjacenct to this vertices
    list<int>::iterator itr;
    for (itr = adj[v].begin(); itr != adj[v].end(); ++itr)
    {
        if (!visited[*itr])
            DFSUtil(*itr, visited);
    }
}
void Graph::DFS(int v)
{
    //mark all the vertex as not visited
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            DFSUtil(i, visited);
    }
}
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);
    return 0;
}