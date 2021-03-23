#include<iostream>
#include<vector>
using namespace std;

int maze_path_01(int sr, int sc, int er, int ec, string ans)
{
    if(sr == er && sc == ec)
    {
        cout<<ans<<endl;
        return 1;
    }

    int count = 0;
    if(sr+1 <= er)
        count += maze_path_01(sr+1,sc,er,ec,ans+"H");
    if(sc+1 <= ec)
        count += maze_path_01(sr,sc+1,er,ec,ans+"V");
    if(sc+1 <= ec && sr+1 <= er)
        count += maze_path_01(sr+1,sc+1,er,ec,ans+"D");
    
    return count;
}

int maze_path_02(int sr, int sc, int er, int ec, string ans)
{
    if(sr == er && sc == ec)
    {
        cout<<ans<<endl;
        return 1;
    }

    int count = 0;
    if(sr+1 <= er)
        count += maze_path_02(sr+1,sc,er,ec,ans+"H");
    if(sc+1 <= ec)
        count += maze_path_02(sr,sc+1,er,ec,ans+"V");

    return count;
}

int maze_path_03(int sr, int sc, int er, int ec, int covered, vector<vector<bool>> &vis, string ans)
{
    if(sr == er && sc == ec)
    {
        if(covered == vis.size()*vis[0].size())
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }

    vis[sr][sc] = true;
    int count = 0;
    if(sr+1 <= er && !vis[sr+1][sc])
        count += maze_path_03(sr+1,sc,er,ec,covered+1,vis,ans+"D");
    if(sc+1 <= ec && !vis[sr][sc+1])
        count += maze_path_03(sr,sc+1,er,ec,covered+1,vis,ans+"R");
    if(sr-1 >= 0 && !vis[sr-1][sc])
        count += maze_path_03(sr-1,sc,er,ec,covered+1,vis,ans+"U");
    if(sc-1 >= 0 && !vis[sr][sc-1])
        count += maze_path_03(sr,sc-1,er,ec,covered+1,vis,ans+"L");

    vis[sr][sc] = false;

    return count;
}


int main()
{
    // cout<<maze_path_01(0,0,2,2,"");
    // cout<<maze_path_02(0,0,1,1,"");
    vector<vector<bool>> vis(4,vector<bool>(4,0));
    cout<<maze_path_03(0,0,3,3,0,vis,"");
    return 0;
}
