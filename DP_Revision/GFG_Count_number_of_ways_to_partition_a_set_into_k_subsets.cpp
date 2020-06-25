#include <iostream>
#include <vector>
#include <cmath>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

int count_ways(int n, int k, vii &dp)
{
    if (n == k || k == 1)
        return dp[k][n] = 1;

    if (dp[k][n] != 0)
        return dp[k][n];

    int new_g = count_ways(n - 1, k - 1, dp);
    int existing_g = count_ways(n - 1, k, dp) * k;

    return dp[k][n] = (new_g + existing_g);
}

int count_ways_tab(int N, int K, vii &dp)
{
    for (int k = 1; k <= K; k++)
    {
        for (int n = k; n <= N; n++)
        {
            if (n == k || k == 1)
            {
                dp[k][n] = 1;
                continue;
            }

            int new_g = dp[k-1][n-1];
            int existing_g = dp[k][n-1] * k;

            dp[k][n] = (new_g + existing_g);
        }
    }
    return dp[K][N];
}

void display(vector<vector<int>> &dp)
{
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j : dp[i])
            cout << j << " ";
        cout << endl;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    vii dp(k + 1, vi(n + 1, 0));
    // cout << count_ways(n, k, dp) << endl;
    cout << count_ways_tab(n, k, dp) << endl;
    display(dp);
}