#include <bits/stdc++.h>
using namespace std;
#include <list>

class Graph{
    public:
    int V;
    list<int> *l;

 Graph(int v){
    this->V = v;   
    l = new list<int>[V];
}


    void addEdges(int v, int u){
        l[u].push_back(v);
        l[v].push_back(u);
    
    }
    void printAdjList(){
        for(int i=0;i<V; i++){
            cout<<i<<"  ";

            for (int neigh : l[i])
            {
                cout<<neigh<<"  ";
            }

            cout<<endl;
            
        }
    }
};

int main() {

    Graph g(5);
    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(2,0);
    g.addEdges(3,0);
    g.addEdges(4,3);
    g.printAdjList();

    return 0;
}