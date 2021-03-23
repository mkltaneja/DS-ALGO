#include<iostream>
#include<list>
#include<vector>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

// DISPLAY ==========================================================

void display1(vi &dp)
{
    for(int i : dp)
        cout<<i<<" ";
    cout<<endl;
}

void display2(vvi &dp)
{
    for(vi v : dp)
    {
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    cout<<endl;
}

// FIBONACCI ======================================================

int fib_rec(int n)
{
    if(n <= 1)
        return n;
    return fib_rec(n-1) + fib_rec(n-2);
}

int fib_dp(int n, vi &dp)
{
    if(n <= 1)
        return dp[n] = n;
    if(dp[n])
        return dp[n];
    return dp[n] = fib_dp(n-1, dp) + fib_dp(n-2, dp);
}

int fib_tab(int n, vi &dp)
{
    // dp[0] = 1;
    // dp[1] = 1;
    for(int i=0;i<=n;i++)
    {
        if(i <= 1)
        {
            dp[i] = i;
            continue;
        }
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fib_3ptrs(int n)
{
    if(n <= 1)
        return n;
    int a=0,b=1,c=0;
    while(n-- - 1)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

void fibonacci()
{
    int n = 3;
    // cout<<fib_rec(n)<<endl;

    vi dp(n+1,0);
    // cout<<fib_dp(n,dp)<<endl;

    // cout<<fib_tab(n,dp)<<endl;

    cout<<fib_3ptrs(n);
    
    // display1(dp);
}

// MAZE PATH SERIES ====================================================

int MazepathHVD_rec(int sr, int sc, int er, int ec)
{
    if(sr == er && sc == ec)
        return 1;
    if(sr < 0 || sc < 0 || sr > er || sc > ec)
        return 0;

    int count = 0;

    count += MazepathHVD_rec(sr+1, sc, er, ec);
    count += MazepathHVD_rec(sr, sc+1, er, ec);
    count += MazepathHVD_rec(sr+1, sc+1, er, ec);

    return count;
}

int MazepathHVD_dp(int sr, int sc, int er, int ec, vvi &dp)
{
    if(sr == er && sc == ec)
        return dp[sr][sc] = 1;
    if(sr < 0 || sc < 0 || sr > er || sc > ec)
        return dp[sr][sc] = 0;

    if(dp[sr][sc] != -1)
        return dp[sr][sc];
    int count = 0;

    count += MazepathHVD_dp(sr+1, sc, er, ec, dp);
    count += MazepathHVD_dp(sr, sc+1, er, ec, dp);
    count += MazepathHVD_dp(sr+1, sc+1, er, ec, dp);

    return dp[sr][sc] = count;
}
int MazepathHVD_tab(int sr, int sc, int er, int ec, vvi &dp)
{
    for(int i=er;i>=sr;i--)
    {
        for(int j=ec;j>=sc;j--)
        {
            if(i == er || j == ec)
            {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] += dp[i+1][j] + dp[i][j+1] + dp[i+1][j+1];
        }
    }
    return dp[sr][sc];
}

int MazepathMulti_rec(int sr, int sc, int er, int ec)
{
    if(sr == er && sc == ec)
        return 1;

    int count = 0;

    for(int m=1; (m+sr) <= er; m++)
        count += MazepathMulti_rec(sr+m, sc, er, ec);
    for(int m=1; (m+sc) <= ec; m++)
        count += MazepathMulti_rec(sr, sc+m, er, ec);
    for(int m=1; (m+sr) <= er && (m+sc) <= ec; m++)
        count += MazepathMulti_rec(sr+m, sc+m, er, ec);

    return count;
}

int MazepathMulti_dp(int sr, int sc, int er, int ec, vvi &dp)
{
    if(sr == er && sc == ec)
        return dp[sr][sc] = 1;
    
    if(dp[sr][sc])
        return dp[sr][sc];

    int count = 0;

    for(int m=1; (m+sr) <= er; m++)
        count += MazepathMulti_dp(sr+m, sc, er, ec, dp);
    for(int m=1; (m+sc) <= ec; m++)
        count += MazepathMulti_dp(sr, sc+m, er, ec, dp);
    for(int m=1; (m+sr) <= er && (m+sc) <= ec; m++)
        count += MazepathMulti_dp(sr+m, sc+m, er, ec,dp);

    return dp[sr][sc] = count;
}

int MazepathMulti_tab(int sr, int sc, int er, int ec, vvi &dp)
{
    for(int i = er; i >= sr; i--)
    {
        for(int j = ec; j >= sc; j--)
        {
            if(i == er && j == ec)
            {
                dp[i][j] = 1;
                continue;
            }            
            int count = 0;

            for(int m=1; (m+i) <= er; m++)
                dp[i][j] += dp[i+m][j];
            for(int m=1; (m+j) <= ec; m++)
                dp[i][j] += dp[i][j+m];
            for(int m=1; (m+i) <= er && (m+j) <= ec; m++)
                dp[i][j] += dp[i+m][j+m];
        }
    }
    return dp[sr][sc];
}

int dicepath(int sn, int en)
{
    if(sn == en)
        return 1;
    
    int count = 0;
    for(int d = 1; (d <= 6) && (sn+d <= en); d++)
        count += dicepath(sn+d, en);

    return count;
}

int dicepath_dp(int sn, int en, vi &dp)
{
    if(sn == en)
        return dp[sn] = 1;

    if(dp[sn])
        return dp[sn];
    
    int count = 0;
    for(int d = 1; (d <= 6) && (sn+d <= en); d++)
        count += dicepath_dp(sn+d, en, dp);

    return dp[sn] = count;
}

int dicepath_tab(int sn, int en, vi &dp)
{
    for(int n = en; n >= sn; n--)
    {
        if(n == en)
        {
            dp[n] = 1;
            continue;
        }
        for(int d = 1; (d <= 6) && (n+d <= en); d++)
            dp[n] += dp[n+d];

    }
    return dp[sn];
}

int dicepath_optimized(int sn, int en)
{
    list<int> ll;
    ll.push_front(1);
    ll.push_front(1);

    while((en--) - (sn+1))
    {
        if(ll.size() <= 6)
            ll.push_front(2*ll.front());
        else 
        {
            ll.push_front(2*ll.front() - ll.back());
            ll.pop_back();
        }
    }
    cout<<endl;
    return ll.front();
}

void pathset()
{
    int n = 10, m = 30;
    // cout<<MazepathHVD_rec(0,0,n-1,m-1)<<endl;
    // vvi dp(n+1, vi(m+1,-1));
    // cout<<MazepathHVD_dp(0,0,n-1,m-1,dp)<<endl;
    vvi dp(n, vi(m,0));
    // cout<<MazepathHVD_tab(0,0,n-1,m-1,dp)<<endl;

    // cout<<MazepathMulti_rec(0,0,n-1,m-1)<<endl;
    // cout<<MazepathMulti_dp(0,0,n-1,m-1,dp)<<endl;
    // cout<<MazepathMulti_tab(0,0,n-1,m-1,dp)<<endl;

    cout<<dicepath(0,n)<<endl;
    vi dp1(n+1,0);
    // cout<<dicepath_dp(0,n,dp1)<<endl;
    cout<<dicepath_tab(0,n,dp1)<<endl;
    cout<<dicepath_optimized(0,n)<<endl;

    display1(dp1);

    // display2(dp);
}


int main()
{
    // fibonacci();
    pathset();
}