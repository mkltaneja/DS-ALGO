#include <iostream>
#include <vector>
#include <list>
using namespace std;

//    DISPLAY  ==============================================================================

void display(vector<int> &dp)
{
    for (int i : dp)
        cout << i << " ";
    cout << endl;
}

void display2(int n, int m, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

//    FIBONACCI ============================================================================

int fib(int n)
{
    if (n <= 1)
        return n;
    int ans = fib(n - 1) + fib(n - 2);
    return ans;
}

int fib_dp(int n, vector<int> &dp)
{
    if (n <= 1)
        return dp[n] = n;
    if (dp[n] != 0)
        return dp[n];
    int ans = fib_dp(n - 1, dp) + fib_dp(n - 2, dp);
    return dp[n] = ans;
}

int fib_tab(int N, vector<int> &dp)
{
    for (int n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = n;
            continue;
        }
        dp[n] = dp[n - 1] + dp[n - 2];
    }
    return dp[N];
}

int mazepathHVD(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
        return 1;

    int count = 0;
    if (sr + 1 <= er)
        count += mazepathHVD(sr + 1, sc, er, ec);
    if (sc + 1 <= ec)
        count += mazepathHVD(sr, sc + 1, er, ec);
    if (sr + 1 <= er && sc + 1 <= ec)
        count += mazepathHVD(sr + 1, sc + 1, er, ec);

    return count;
}

int mazepathHVD_dp(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
        return dp[sr][sc] = 1;

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    int count = 0;
    if (sr + 1 <= er)
        count += mazepathHVD_dp(sr + 1, sc, er, ec, dp);
    if (sc + 1 <= ec)
        count += mazepathHVD_dp(sr, sc + 1, er, ec, dp);
    if (sr + 1 <= er && sc + 1 <= ec)
        count += mazepathHVD_dp(sr + 1, sc + 1, er, ec, dp);

    return dp[sr][sc] = count;
}

int mazepathHVD_tab(int n, int m, vector<vector<int>> &dp)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1)
            {
                dp[i][j] = 1;
                continue;
            }

            int count = 0;
            if (i + 1 <= n - 1)
                count += dp[i + 1][j];
            if (j + 1 <= m - 1)
                count += dp[i][j + 1];
            if (i + 1 <= n - 1 && j + 1 <= m - 1)
                count += dp[i + 1][j + 1];

            dp[i][j] = count;
        }
    }
    return dp[0][0];
}

int mazepathMulti(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
        return 1;

    int count = 0;
    for (int jump = 1; sr + jump <= er; jump++)
        count += mazepathMulti(sr + jump, sc, er, ec);
    for (int jump = 1; sc + jump <= ec; jump++)
        count += mazepathMulti(sr, sc + jump, er, ec);
    for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
        count += mazepathMulti(sr + jump, sc + jump, er, ec);

    return count;
}

int mazepathMulti_dp(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
        return dp[sr][sc] = 1;

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    int count = 0;
    for (int jump = 1; sr + jump <= er; jump++)
        count += mazepathMulti_dp(sr + jump, sc, er, ec, dp);
    for (int jump = 1; sc + jump <= ec; jump++)
        count += mazepathMulti_dp(sr, sc + jump, er, ec, dp);
    for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
        count += mazepathMulti_dp(sr + jump, sc + jump, er, ec, dp);

    return dp[sr][sc] = count;
}

int mazepathMulti_tab(int n, int m, vector<vector<int>> &dp)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            if (i == n-1 && j == m-1)
            {
                dp[i][j] = 1;
                continue;
            }

            int count = 0;
            for (int jump = 1; i + jump <= n-1; jump++)
                count += dp[i + jump][j];
            for (int jump = 1; j + jump <= m-1; jump++)
                count += dp[i][j + jump];
            for (int jump = 1; i + jump <= n-1 && j + jump <= m-1; jump++)
                count += dp[i + jump][j + jump];

            dp[i][j] = count;
        }
    }
    return dp[0][0];
}

int dicepath(int si, int ei)
{
    if(si == ei)
        return 1;

    int count = 0;
    for(int dice = 1; dice <= 6 && si + dice <= ei; dice++)
        count += dicepath(si + dice, ei);

    return count;
}

int dicepath_dp(int si, int ei, vector<int> &dp)
{
    if(si == ei)
        return dp[si] = 1;

    if(dp[si] != 0)
        return dp[si];

    int count = 0;
    for(int dice = 1; dice <= 6 && si + dice <= ei; dice++)
        count += dicepath_dp(si + dice, ei, dp);

    return dp[si] = count;
}

int dicepath_tab(int si, int ei, vector<int> &dp)
{
    for(int i = ei; i >= si; i--)
    {
        if(i == ei)
        {
            dp[i] = 1;
            continue;
        }

        int count = 0;
        for(int dice = 1; dice <= 6 && i + dice <= ei; dice++)
            count += dp[i + dice];
    
        dp[i] = count;
    }
    return dp[si];
}

int dicepath_best(int si, int ei)
{
    list<int> ll;
    ll.push_front(1);
    for(int i = ei; i >= si; i--)
    {
        cout<<ll.front()<<endl;
        if(i == ei)
        {
            ll.push_front(1);
            continue;
        }

        if(ll.size() <= 6)
            ll.push_front(2 * ll.front());
        else 
        {
            // cout<<ll.front()<<" "<<ll.back()<<endl;
            ll.push_front(2 * ll.front() - ll.back());
            ll.pop_back();
        }
    }
    return ll.front();
}

void fibonacci()
{
    int n = 5;
    // cout<<fib(n)<<endl;

    // BY DP===========
    vector<int> dp(n + 1, 0);
    // cout << fib_dp(n, dp)<<endl;

    // BY Tabulation
    // cout << fib_tab(n, dp)<<endl;

    display(dp);
}

//    MAZE PATH SERIES  ==================================================================================

void pathset()
{
    int n = 3, m = 3;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // cout<<mazepathHVD(0,0,n-1,m-1);

    // BY DP ===========
    // cout << mazepathHVD_dp(0, 0, n - 1, m - 1, dp) << endl;

    // BY Tabulation
    // cout << mazepathHVD_tab(n, m, dp) << endl;

    // cout<<mazepathMulti(0,0,n-1,m-1)<<endl;

    // BY DP ================
    // cout << mazepathMulti_dp(0, 0, n - 1, m - 1, dp) << endl;

    // BY Tabulation ===========
    // cout << mazepathMulti_tab(n, m, dp) << endl;

    int x = 10;
    vector<int> dp1(x+1,0);
    // cout<<dicepath(0,x)<<endl;
    // cout<<dicepath_dp(0,x,dp1)<<endl;
    // cout<<dicepath_tab(0,x,dp1)<<endl;
    cout<<dicepath_best(0,x-1)<<endl;

    // display(dp1);

    // display2(n, m, dp);
}

int main()
{
    // fibonacci();

    pathset();
}