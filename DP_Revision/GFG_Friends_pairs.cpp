#include <iostream>
#include <vector>
#include <cmath>
#define vi vector<long long int>
#define vii vector<vi>
using namespace std;

long long int total_pairs(int n, vi &dp)
{
    if (n <= 1)
        return dp[n] = 1;

    if (dp[n] != 0)
        return dp[n];

    long long int single = total_pairs(n - 1, dp);
    long long int pairup = total_pairs(n - 2, dp) * (n - 1);

    return dp[n] = (single + pairup);
}

int total_pairs_tab(int N, vi &dp)
{
    for (int n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = 1;
            continue;
        }
        int single = dp[n-1];
        int pairup = dp[n-2] * (n-1);

        dp[n] = (single + pairup);
    }
    return dp[N];
}

void display(vi &dp)
{
    for (int i : dp)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vi dp(n + 1, 0);
        // cout << total_pairs(n, dp) << endl;
        // int ans = ;
        cout << total_pairs(n, dp) % 1000000007 << endl;

        display(dp);
    }
}