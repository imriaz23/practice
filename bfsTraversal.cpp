#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph{

    int v;
    list<int> *adj;
    public:
        void addEdge(int v, int u);
        void BFS(int s);
        Graph(int v);
};
Graph::Graph(int v){
    this->v=v;
    adj = new list<int>[v];
}
void Graph::addEdge(int v,int u){
    adj[v].push_back(u);
}
void Graph::BFS(int s){
    bool *visited = new bool[v];
    for (int i = 0; i < v;i++)
        visited[i] = false;
    queue<int> Queue;
    Queue.push(s);
    visited[s] = true;
    list<int>::iterator itr;
    while(!Queue.empty()){
        s = Queue.front();
        cout << s << " ";
        Queue.pop();
        for (itr = adj[s].begin(); itr != adj[s].end();itr++){
            if(!visited[*itr])
            {
                visited[*itr] = true;
                Queue.push(*itr);
            }
        }
    }
}
int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(2);
    cout<<endl;
    return 0;
}
