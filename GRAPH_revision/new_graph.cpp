
// QUESTION - Total ways to go from one position to another in a 4*4 MATRIX, such that all psitions are covered exactly once.

#include<iostream>
#include<vector>
using namespace std;
class edge
{
    public:
    int v = 0;
    edge(int v)
    {
        this->v = v;
    }
};
vector<vector<edge>> graph(17,vector<edge>());
void addEdge(int u, int v)
{
    graph[u].push_back(edge(v));
    graph[v].push_back(edge(u));
}

void construct_graph()
{
    addEdge(1,2);
    addEdge(1,5);
    addEdge(2,3);
    addEdge(2,6);
    addEdge(3,4);
    addEdge(3,7);
    addEdge(4,8);
    addEdge(5,6);
    addEdge(5,9);
    addEdge(6,7);
    addEdge(6,10);
    addEdge(7,8);
    addEdge(7,11);
    addEdge(8,12);
    addEdge(9,10);
    addEdge(9,13);
    addEdge(10,11);
    addEdge(10,14);
    addEdge(11,12);
    addEdge(11,15);
    addEdge(12,16);
    addEdge(13,14);
    addEdge(14,15);
    addEdge(15,16);
}
void display()
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<" --> ";
        for(edge e : graph[i])
            cout<<e.v<<" ";
            cout<<endl;
    }
}
int allPath(int source, int destination, int covered, vector<bool> &vis, string ans)
{
    if(source == destination)
    {
        if(covered == graph.size()-1)
        {
            cout<<ans+to_string(destination)<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    vis[source] = true;
    for(edge e : graph[source])
    {
        if(!vis[e.v])
            count += allPath(e.v,destination,covered+1,vis,ans+to_string(source)+" --> ");
    }
    vis[source] = false;
    return count;
}
int main()
{
    construct_graph();
    // display();
    vector<bool> vis(graph.size(),false);
    cout<<allPath(1,4,1,vis,"")<<" WAYS ";
}
