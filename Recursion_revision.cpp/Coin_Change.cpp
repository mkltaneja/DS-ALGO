#include <iostream>
using namespace std;

int permu(int n, int coins[], int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
        if (tar - coins[i] >= 0)
            count += permu(n, coins, tar - coins[i], ans + to_string(coins[i]) + " ");
    return count;
}

int permu_norep(int n, int coins[], int tar, int iscoin_used, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int mask = (1 << i);
        if (!(iscoin_used & mask) && tar - coins[i] >= 0)
        {
            iscoin_used ^= mask;
            count += permu_norep(n, coins, tar - coins[i], iscoin_used, ans + to_string(coins[i]) + " ");
            iscoin_used ^= mask;
        }
    }
    return count;
}

int combi(int n, int coins[], int idx, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < n; i++)
        if (tar - coins[i] >= 0)
            count += combi(n, coins, i, tar - coins[i], ans + to_string(coins[i]) + " ");
    return count;
}

int combi_norep(int n, int coins[], int idx, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < n; i++)
        if (tar - coins[i] >= 0)
            count += combi_norep(n, coins, i + 1, tar - coins[i], ans + to_string(coins[i]) + " ");
    return count;
}

// BY SUBSEQUENCE METHOD=======================================================================================

int permu_subseq(int n, int coins[], int idx, int tar, string ans)
{
    if (idx == n || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (tar - coins[idx] >= 0)
        count += permu_subseq(n, coins, 0, tar - coins[idx], ans + to_string(coins[idx]) + " ");
    count += permu_subseq(n, coins, idx + 1, tar, ans);

    return count;
}
int permu_subseq_norep(int n, int coins[], int iscoin_used, int idx, int tar, string ans)
{
    if (idx == n || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    int mask = (1 << idx);
    if (!(iscoin_used & mask) && tar - coins[idx] >= 0)
    {
        iscoin_used ^= mask;
        count += permu_subseq_norep(n, coins, iscoin_used, 0, tar - coins[idx], ans + to_string(coins[idx]) + " ");
        iscoin_used ^= mask;
    }
    count += permu_subseq_norep(n, coins, iscoin_used, idx + 1, tar, ans);

    return count;
}

int combi_subseq(int n, int coins[], int idx, int tar, string ans)
{
    if (idx == n || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (tar - coins[idx] >= 0)
        count += combi_subseq(n, coins, idx, tar - coins[idx], ans + to_string(coins[idx]) + " ");
    count += combi_subseq(n, coins, idx + 1, tar, ans);

    return count;
}

int combi_subseq_norep(int n, int coins[], int idx, int tar, string ans)
{
    if (idx == n || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (tar - coins[idx] >= 0)
        count += combi_subseq_norep(n, coins, idx + 1, tar - coins[idx], ans + to_string(coins[idx]) + " ");
    count += combi_subseq_norep(n, coins, idx + 1, tar, ans);

    return count;
}

int count = 0;
int subsets(int n, int idx, int* arr, string sub)
{
    count++;
    cout<<sub<<"]\n";
    if(idx == n)
    {
        return 1;
    }
    for(int i=idx;i<n;i++)
        subsets(n,i+1,arr, sub + to_string(arr[i])+ " ");
    return count;
}

int main()
{
    // int n;
    // cout << "Enter the no. of coins, you have: \n";
    // cin >> n;
    // int coins[n];
    // cout << "Enter the coins, you have \n";
    // for (int i = 0; i < n; i++)
    //     cin >> coins[i];
    // int target;
    // cout << "Enter the amount of money to spend: \n";
    // cin >> target;

    // cout<<"There are *"<<permu(n,coins,target,"")<<"* ways to spend your money \n";
    // cout<<"There are *"<<permu_norep(n,coins,target,0,"")<<"* ways to spend your money \n";
    // cout<<"There are *"<<combi(n,coins,0,target,"")<<"* ways to spend your money \n";
    // cout << "There are *" << combi_norep(n, coins, 0, target, "") << "* ways to spend your money \n";

    // BY SUBSEQUENCE METHOD=======================================================================================

    // cout<<"There are *"<<permu_subseq(n,coins,0,target,"")<<"* ways to spend your money \n";
    // cout<<"There are *"<<permu_subseq_norep(n,coins,0,0,target,"")<<"* ways to spend your money \n";
    // cout<<"There are *"<<combi_subseq(n,coins,0,target,"")<<"* ways to spend your money \n";
    // cout << "There are *" << combi_subseq_norep(n, coins, 0, target, "") << "* ways to spend your money \n";

    // SUBSETS OF ARRAY==============================================================================================

    int m;
    cout << "ENTER SIZE OF ARRAY: \n";
    cin >> m;
    int arr[m];
    cout << "ENTER THE ARRAY: \n";
    for(int i=0;i<m;i++)
        cin>>arr[i];
    cout<<subsets(m,0,arr,"[");
}