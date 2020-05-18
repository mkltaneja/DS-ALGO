#include <iostream>
#include <queue>
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
    // gp[v].push_back(edge(u, w));
}

int findEdge(int v1, int v2)      //return whether there is a direct edge from v1 to v2
{
    int vtx = -1;
    for (int i = 0; i < graph[v1].size(); i++)
    {
        edge e = graph[v1][i];
        if (e.v == v2)
        {
            vtx = i;
            break;
        }
    }

    return vtx;
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
    while (graph[vtx].size() != 0)
    {
        edge e = graph[vtx].back();
        removeEdge(vtx, e.v);
    }
}

//QUESTIONS====================================================================================

bool HasPath(int src, int dest, vector<bool> vis) //DFS
{
    if (src == dest)
        return true;

    bool res = false;
    vis[src] = true; //MARK
    for (edge e : graph[src])
    {
        if (!vis[e.v]) //CHECK
        {
            res |= HasPath(e.v, dest, vis);
        }
    }
    return res;
}

int allPath(int src, int dest, int wsf, string ans)
{
    if (src == dest)
    {
        cout << ans << " @ " << wsf << endl;
        return 1;
    }

    int count = 0;
    // vis[src] = true;
    for (edge e : graph[src])
    {
        // if(!vis[e.v])
        // {
        count += allPath(e.v, dest, wsf + e.w, ans + to_string(e.v) + " --> ");
        // }
    }
    // vis[src] = false;

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
    if (src == dest)
    {
        cout << ans << " @ " << wsf << endl;
        pair.lightW = min(pair.lightW, wsf);
        pair.heavyW = max(pair.heavyW, wsf);
        if (wsf < data)
            pair.floor = max(wsf, pair.floor);
        if (wsf > data)
            pair.ceil = min(wsf, pair.ceil);

        return;
    }

    vis[src] = true;
    for (edge e : graph[src])
    {
        if (!vis[e.v])
        {
            allSolution(e.v, dest, vis, wsf + e.w, ans + to_string(e.v) + " --> ", pair, data);
        }
    }
    vis[src] = false;
}

void preoder(int src, int dest, vector<bool> vis, int wsf, string ans)
{
    cout << ans << " @ " << wsf << endl;

    vis[src] = true;

    for (edge e : graph[src])
        if (!vis[e.v])
            preoder(e.v, dest, vis, wsf + e.w, ans + to_string(e.v) + "->");

    vis[src] = false;
}

// Hamintonian=================================================================================================

void hamintonianPath(int src, int osrc, vector<bool> vis, int count, string ans)
{
    if (count == vis.size() - 1)
    {
        int idx = findEdge(src, osrc);
        if (idx != -1)
            cout << "Cycle: " << ans << to_string(osrc) << endl;
        else
            cout << "Path: " << ans << endl;

        return;
    }

    vis[src] = true;
    for (edge e : graph[src])
    {
        if (!vis[e.v])
            hamintonianPath(e.v, osrc, vis, count + 1, ans + to_string(src) + "  ");
    }
    vis[src] = false;
}

//GCC==================================================================================

int GCC_dfs(int src, vector<bool> &vis)
{
    int count = 0;

    vis[src] = true;
    for (edge e : graph[src])
        if (!vis[e.v])
            count += GCC_dfs(e.v, vis);

    return count + 1;
}

int GCC(int src, vector<bool> vis)
{
    int count = 0;
    int maxSize = 0;

    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
        {
            count++;
            maxSize = max(maxSize, GCC_dfs(i, vis));
        }
    }
    cout << "Max Size: " << maxSize << endl;
    return count;
}

//BFS===============================================================================================

void BFS(int src, vector<bool> &vis)
{
    queue<pair<int, string>> que;
    que.push({src, to_string(src) + ""});

    while (!que.empty())
    {
        pair<int, string> rvtx = que.front();
        que.pop();

        int dest = 6;

        if (vis[rvtx.first])
        {
            cout << "Cycle: " << rvtx.second << endl;
            continue;
        }

        vis[rvtx.first] = true;
        for (edge e : graph[rvtx.first])
            if (!vis[e.v])
                que.push({e.v, rvtx.second + to_string(e.v)});

        if (rvtx.first == dest)
            cout << "Destination: " << rvtx.second << endl;
    }
}

bool isBipartite_BFS(int src, vector<int> &vis)
{
    int n = graph.size();

    queue<pair<int, int>> que;
    que.push({src, 0});

    int cycle = 0;
    while (!que.empty())
    {
        pair<int, int> rvtx = que.front();
        que.pop();

        if (vis[rvtx.first] != -1)
        {
            cycle++;
            if(rvtx.second != vis[rvtx.first])
                return false;
        }

        vis[rvtx.first] = rvtx.second;

        for (edge e : graph[rvtx.first])
            if (vis[e.v] == -1)
                que.push({e.v, (rvtx.second + 1) % 2});
    }
    cout<<cycle<<" Cycles\n";
    return true;
}

void isBipartite()
{
    vector<int> vis(graph.size(), -1); // -1 : nothing, 0 : red, 1 : green
    for (int i = 0; i < graph.size(); i++)
        if (vis[i] == -1)
            cout<<(boolalpha)<<isBipartite_BFS(i, vis);
}

// Topological Sort and Kahn's(for directed)========================================================================================

vector<int> topological_sort_(int src, vector<bool> &vis, vector<int> &ans, vector<vector<edge>> graph)
{
    vis[src] = true;
    for (edge e : graph[src])
        if (!vis[e.v])
            topological_sort_(e.v, vis, ans, graph);

    ans.push_back(src);
    return ans;
}

void topological_sort()
{
    vector<bool> vis(graph.size(), 0);
    vector<int> ans;
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
            topological_sort_(i, vis, ans, graph);
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

void KahnsAlgo()
{
    vector<int> Indegree(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++)
    {
        for (edge e : graph[i])
            Indegree[e.v]++;
    }

    queue<int> que;
    for (int i = 0; i < graph.size(); i++)
        if (Indegree[i] == 0)
            que.push(i);

    vector<int> ans;
    while (!que.empty())
    {
        int rvtx = que.front();
        que.pop();
        ans.push_back(rvtx);

        for (edge e : graph[rvtx])
            if (--Indegree[e.v] == 0)
                que.push(e.v);
    }

    if (ans.size() != graph.size())
        cout << "Cycle";
    else
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
}

//Strongly connected components===================================================================

// int GSCC()
// {
//     vector<int> ans = topological_sort_(0,vis,ans,graph);
//     vector<vector<int>> ngraph(graph.size(),vector<int>());
//     for(int i=0;i<graph.size();i++)
//         for(int j=0;j<graph[i].size();j++)
//             ngraph[j].push_back(i);

//     for(int )
// }

//Union Find=============================================================================

vector<int> par;
vector<int> setSize;

int findPar(int vtx)
{
    if(par[vtx] == vtx)
        return vtx;
    return par[vtx] = findPar(par[vtx]);
}

void mergeSet(int p1, int p2)
{
    if(setSize[p1] < setSize[p2])
    {
        par[p1] = p2;
        setSize[p2] += setSize[p1];
    }
    else
    {
        par[p2] = p1;
        setSize[p1] += setSize[p2];
    }
}

// display and construction=================================================================
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
    // addEdge(graph, 5, 6, 8);
}

int main()
{
    constructGraph();
    // display(graph);

    // addEdge(graph, 1, 3, 10);
    // display(graph);

    // removeEdge(3,4);
    // display(graph);

    // removeVtx(3);
    // display(graph);

    vector<bool> vis(graph.size(), 0);

    // cout<<(boolalpha)<<HasPath(0,6,vis);

    // cout<<allPath(0,6,0,"0 --> ");

    // allSolpair pair;
    // allSolution(0,6,vis,0,"0 --> ",pair,30);
    // cout<<"Lightest weight = "<<pair.lightW<<", Heaviest weight = "<<pair.heavyW<<", Floor value = "<<pair.floor<<", Ceil value = "<<pair.ceil<<endl;

    // cout<<"Preoder Traversal : \n";
    // preoder(0,6,vis,0,"0->");

    // addEdge(graph,2,5,2);
    // hamintonianPath(2,2,vis,0," ");

    // removeEdge(2,3);
    // removeEdge(0,1);
    // cout<<GCC(0,vis)<<endl;
    // display(graph);

    // BFS(0,vis);

    // topological_sort();

    // KahnsAlgo();

    isBipartite();
}


