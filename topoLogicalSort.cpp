#include<iostream>
#include<list>
#include<stack>


using namespace std;


class Graph{
    int v;
    list<int> *adj;
    void topoLogicalSortUtil(int v, bool visited[], stack<int> &Stack);
    public:
        Graph(int v);
        void addEdge(int v, int u);
        void topoLogicalSort();
};

Graph::Graph(int v){
    this->v = v;
    adj = new list<int>[v];
}
void Graph::addEdge(int v,int u){
    adj[v].push_back(u);
}
void Graph::topoLogicalSortUtil(int v,bool visited[],stack<int>&Stack){
    visited[v] = true;
    list<int>::iterator itr;
    for (itr = adj[v].begin(); itr != adj[v].end();itr++){
        if(!visited[*itr]){
            topoLogicalSortUtil(*itr, visited, Stack);
        }
    }
    Stack.push(v);
}
void Graph::topoLogicalSort(){
    stack<int> Stack;
    bool *visited = new bool[v];
    for (int i = 0; i < v;i++)
        visited[i] = false;
    for (int i = 0; i < v;i++){
        if(!visited[i]){
            topoLogicalSortUtil(i, visited, Stack);
        }
    }
    while(!Stack.empty()){
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topoLogicalSort();
    return 0;
}