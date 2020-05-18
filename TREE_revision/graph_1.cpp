#include <iostream>
#include <vector>
using namespace std;

class edge
{
public:
    int v = 0;
    int w = 0;
    edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

int N = 7;
vector<vector<edge>> graph(N, vector<edge>());

// BASIC=======================================================================================

void addEdge(vector<vector<edge>> &gp, int u, int v, int w)
{
    // if (u >= graph.size() || v >= graph.size() || u < 0 || v < 0)
    //     return;

    gp[u].push_back(edge(v, w));
    gp[v].push_back(edge(u, w));
}

int findEdge(int v1, int v2)
{
    int i = 0;
    while (i < graph[v1].size())
    {
        edge e = graph[v1][i];
        if (e.v == v2)
            break;
        i++;
    }

    return i;
}


void removeEdge(int u, int v)
{
    int idx1 = findEdge(u, v);
    int idx2 = findEdge(v, u);

    graph[u].erase(graph[u].begin() + idx1);
    graph[v].erase(graph[v].begin() + idx2);
}

void removeVtx(int vtx)
{
    // for(edge e : graph[u])
    // {
    //     removeEdge(u,e.v);
    // }
    while(graph[vtx].size() != 0)
    {
        edge e = graph[vtx].back();
        removeEdge(vtx,e.v);
    }
}

//QUESTIONS====================================================================================

bool HasPath(int src, int dest, vector<bool> vis)   //DFS
{
    if(src == dest)
        return true;

    bool res = false;
    vis[src] = true;            //MARK
    for(edge e : graph[src])
    {
        if(!vis[e.v])            //CHECK
        {
            res |= HasPath(e.v,dest,vis);
        }
    }
    return res;
}   

int allPath(int src, int dest, vector<bool> vis, int wsf, string ans)
{
    if(src == dest)
    {
        cout<<ans<<" @ "<<wsf<<endl;
        return 1; 
    }

    int count = 0;
    vis[src] = true;
    for(edge e : graph[src])
    {
        if(!vis[e.v])
        {
            count += allPath(e.v,dest,vis,wsf+e.w,ans+to_string(e.v)+" --> ");
        }
    }
    vis[src] = false;

    return count;
}

class allSolpair
{
    public:
    int floor = -1e9;
    int ceil = 1e9;
    int lightW = 1e9;
    int heavyW = 0;
};

void allSolution(int src, int dest, vector<bool> vis, int wsf, string ans, allSolpair &pair, int data)
{
    if(src == dest)
    {
        cout<<ans<<" @ "<<wsf<<endl;
        pair.lightW = min(pair.lightW,wsf);
        pair.heavyW = max(pair.heavyW,wsf);
        if(wsf < data)
            pair.floor = max(wsf,pair.floor);
        if(wsf > data)
            pair.ceil = min(wsf,pair.ceil);

        return;
    }

    vis[src] = true;
    for(edge e : graph[src])
    {
        if(!vis[e.v])
        {
            allSolution(e.v,dest,vis,wsf+e.w,ans+to_string(e.v)+" --> ",pair,data);
        }
    }
    vis[src] = false;
}

void preoder(int src, int dest, vector<bool> vis, int wsf, string ans)
{
    cout<<ans<<" @ "<<wsf<<endl;

    vis[src] = true;

    for(edge e : graph[src])
        if(!vis[e.v])
            preoder(e.v,dest,vis,wsf+e.w,ans+to_string(e.v)+ "->");
    
    vis[src] = false;
}

void display(vector<vector<edge>> &gp)
{
    for (int i = 0; i < gp.size(); i++)
    {
        cout << i << " --> ";
        for (edge e : graph[i])
            cout << "(" << e.v << ", " << e.w << ")  ";
        cout << endl;
    }
    cout << endl;
}

void constructGraph()
{
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 40);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 2);
    addEdge(graph, 4, 6, 3);
    addEdge(graph, 5, 6, 8);

}

int main()
{
    constructGraph();
    // display(graph);

    addEdge(graph, 1, 3, 10);
    // display(graph);


    // removeEdge(3,4);
    // display(graph);

    // removeVtx(3);
    // display(graph);

    vector<bool> vis(graph.size(),0);

    // cout<<(boolalpha)<<HasPath(0,6,vis);

    // cout<<allPath(0,6,vis,0,"0 --> ");

    allSolpair pair;
    // allSolution(0,6,vis,0,"0 --> ",pair,30);
    // cout<<"Lightest weight = "<<pair.lightW<<", Heaviest weight = "<<pair.heavyW<<", Floor value = "<<pair.floor<<", Ceil value = "<<pair.ceil<<endl;

    cout<<"Preoder Traversal : \n";
    preoder(0,6,vis,0,"0->");
}