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

// FIBONACCI ===========================================================================================================

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

void fibonacci()
{
    int n = 5;
    // cout<<fib(n)<<endl;

    // BY DP===========
    vector<int> dp(n + 1, 0);
    // cout << fib_dp(n, dp)<<endl;

    // BY Tabulation
    cout << fib_tab(n, dp) << endl;

    display(dp);
}

//    MAZE PATH SERIES  ==================================================================================

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

            if (i == n - 1 && j == m - 1)
            {
                dp[i][j] = 1;
                continue;
            }

            int count = 0;
            for (int jump = 1; i + jump <= n - 1; jump++)
                count += dp[i + jump][j];
            for (int jump = 1; j + jump <= m - 1; jump++)
                count += dp[i][j + jump];
            for (int jump = 1; i + jump <= n - 1 && j + jump <= m - 1; jump++)
                count += dp[i + jump][j + jump];

            dp[i][j] = count;
        }
    }
    return dp[0][0];
}

int dicepath(int si, int ei)
{
    if (si == ei)
        return 1;

    int count = 0;
    for (int dice = 1; dice <= 6 && si + dice <= ei; dice++)
        count += dicepath(si + dice, ei);

    return count;
}

int dicepath_dp(int si, int ei, vector<int> &dp)
{
    if (si == ei)
        return dp[si] = 1;

    if (dp[si] != 0)
        return dp[si];

    int count = 0;
    for (int dice = 1; dice <= 6 && si + dice <= ei; dice++)
        count += dicepath_dp(si + dice, ei, dp);

    return dp[si] = count;
}

int dicepath_tab(int si, int ei, vector<int> &dp)
{
    for (int i = ei; i >= si; i--)
    {
        if (i == ei)
        {
            dp[i] = 1;
            continue;
        }

        int count = 0;
        for (int dice = 1; dice <= 6 && i + dice <= ei; dice++)
            count += dp[i + dice];

        dp[i] = count;
    }
    return dp[si];
}

int dicepath_best(int si, int ei)
{
    list<int> ll;
    // ll.push_front(1);
    for (int i = ei; i >= si; i--)
    {
        cout << ll.front() << endl;
        if (i >= ei - 1)
        {
            ll.push_front(1);
            continue;
        }

        if (ll.size() <= 6)
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
    vector<int> dp1(x + 1, 0);
    // cout<<dicepath(0,x)<<endl;
    // cout<<dicepath_dp(0,x,dp1)<<endl;
    // cout<<dicepath_tab(0,x,dp1)<<endl;
    cout << dicepath_best(0, x - 1) << endl;

    // display(dp1);

    // display2(n, m, dp);
}

// COIN CHANGE ====================================================================================

int infi_permu(vector<int> &coins, int tar, vector<int> &dp)
{
    if (tar == 0)
        return dp[tar] = 1;

    int count = 0;
    for (int coin : coins)
        if (tar - coin >= 0)
            count += infi_permu(coins, tar - coin, dp);

    return dp[tar] = count;
}

int infi_permu_tab(vector<int> &coins, int tar, vector<int> &dp)
{
    dp[0] = 1;
    for (int t = 0; t <= tar; t++)
        for (int coin : coins)
            if (t - coin >= 0)
                dp[t] += dp[t - coin];
    return dp[tar];
}

int infi_combi_tab(vector<int> &coins, int tar, vector<int> &dp)
{
    dp[0] = 1;
    for (int coin : coins)
        for (int t = 0; t <= tar; t++)
            if (t - coin >= 0)
                dp[t] += dp[t - coin];

    return dp[tar];
}

int single_coin_combi_subseq(vector<int> &coins, int idx, int tar, vector<vector<int>> &dp)
{
    if (idx == coins.size() || tar == 0)
    {
        if (tar == 0)
            return dp[idx][tar] = 1;
        return dp[idx][tar] = 0;
    }
    if (dp[idx][tar] != 0)
        return dp[idx][tar];

    int count = 0;
    if (tar - coins[idx] >= 0)
        count += single_coin_combi_subseq(coins, idx + 1, tar - coins[idx], dp);
    count += single_coin_combi_subseq(coins, idx + 1, tar, dp);

    return dp[idx][tar] = count;
}

// int single_coin_combi_subseq_dp()

void coin_change()
{
    vector<int> arr = {2, 3, 5, 7};
    int tar = 10;
    vector<int> dp(tar + 1, 0);
    // cout<<infi_permu(arr, tar, dp)<<endl;
    // cout<<infi_permu_tab(arr, tar, dp)<<endl;

    // cout<<infi_combi(arr, tar, dp)<<endl;  --> not possible by memoization
    // cout << infi_combi_tab(arr, tar, dp) << endl;

    vector<vector<int>> dp2(arr.size() + 1, vector<int>(tar + 1));
    cout << single_coin_combi_subseq(arr, 0, 10, dp2) << endl;
    display2(arr.size() + 1, tar + 1, dp2);
}

// LIS ============================================================================================

// LIS_left_to_right_rec(vector<int> &arr)
// {

// }

// LIS
int LIS_left_to_right(vector<int> &arr, vector<int> &dp)
{
    int omax = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        omax = max(omax, dp[i]);
    }
    return omax;
}

// same as LIS
int LDS_right_to_left(vector<int> &arr, vector<int> &dp)
{
    int omax = 1;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] > arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        omax = max(omax, dp[i]);
    }
    return omax;
}

// LDS
int LDS_left_to_right(vector<int> &arr, vector<int> &dp)
{
    int omax = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        omax = max(omax, dp[i]);
    }
    return omax;
}

// Same as LDS
int LIS_right_to_left(vector<int> &arr, vector<int> &dp)
{
    int omax = 1;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        omax = max(omax, dp[i]);
    }
    return omax;
}

int LBS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> LIS(n, 1);
    vector<int> LDS(n, 1);
    LIS_left_to_right(arr, LIS);
    LIS_right_to_left(arr, LDS);

    int max_ = 1;
    for (int i = 0; i < n; i++)
    {
        int len = LIS[i] + LDS[i] - 1;
        max_ = max(max_, len);
    }
    return max_;
}

void LIS()
{
    vector<int> arr{0, 8, 12, 2, 10, 6, 14, 5, 13, 3};
    vector<int> dp(arr.size(), 1);
    // cout << LIS_left_to_right(arr, dp) << endl;
    // cout<<LIS_right_to_left(arr,dp)<<endl;
    cout<<LDS_left_to_right(arr,dp)<<endl;
    // cout<<LIS_right_to_left(arr,dp)<<endl;
    display(dp);
}

// MCM =========================================================================================

int min_MCM_cost(int si, int ei, vector<int> &arr)
{
    if(si + 1 == ei)
        return 0;

    int minans = 1e9;
    for(int cut = si+1; cut < ei; cut++)
    {
        int leftCost = min_MCM_cost(si, cut, arr);
        int rightCost = min_MCM_cost(cut, ei, arr);

        int myCost = leftCost + arr[si]*arr[cut]*arr[ei] + rightCost;

        if(myCost < minans)
        {
            minans = myCost;
        }
    }
    return minans;
}

int min_MCM_cost_mem(int si, int ei, vector<int> &arr, vector<vector<int>> &dp)
{
    if(si + 1 == ei)
        return dp[si][ei] = 0;

    if(dp[si][ei] != -1)
        return dp[si][ei];

    int minans = 1e9;
    for(int cut = si+1; cut < ei; cut++)
    {
        int leftCost = min_MCM_cost_mem(si, cut, arr, dp);
        int rightCost = min_MCM_cost_mem(cut, ei, arr, dp);

        int myCost = leftCost + arr[si]*arr[cut]*arr[ei] + rightCost;

        if(myCost < minans)
        {
            minans = myCost;
        }
    }
    return dp[si][ei] = minans;
}

// tabulation



// forming the string along with mincost




void MCM()
{
    vector<int> arr = {1,2,3,4,5,6};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n,-1));
    cout<<min_MCM_cost(0,n-1,arr)<<endl;
    cout<<min_MCM_cost_mem(0,n-1,arr,dp)<<endl;
    cout<<min_MCM_cost_dp(0,n-1,arr,dp)<<endl;

    display2(n,n,dp);
}

int main()
{
    // fibonacci();

    // pathset();

    // coin_change();

    // LIS();

    MCM();
}