// #include <bits/stdc++.h>
// using namespace std;

// int RAW(char arr[], int i, int n, string ans)
// {
//     if (i == n)
//     {
//         cout << ans << endl;
//         return 1;
//     }

//     int count = 0;
//     // cout<<ans<<endl;
//     if (arr[i] == '0')
//         count += RAW(arr, i + 1, n, ans);
//     else
//     {
//         count += RAW(arr, i + 1, n, ans + arr[i] + " ");

//         if ((i != n - 1) && ((arr[i] - '0') < 3) && ((arr[i] - '0') * 10 + (arr[i + 1] - '0')) <= 26)
//             count += RAW(arr, i + 2, n, ans + to_string((arr[i] - '0') * 10 + (arr[i + 1] - '0')) + " ");
//     }
//     //write your code here
//     return count;
// }

// int main()
// {
//     string input;
//     getline(cin, input);
//     int n = input.length();
//     char char_array[n];
//     int c[26] = {};
//     strcpy(char_array, input.c_str());
//     int ans = RAW(char_array, 0, n, "");
//     cout << ans;
//     return 0;
// }

#include<iostream>
#include<string>
using namespace std;

// string kstr = "";
// void kth_perm(int n, int k, string que, string ans)
// {
//     if (que.size() == 0)
//     {
//         cout << ans << endl;
//         if (k-- == 1)
//             kstr = ans;
//         return;
//     }
//     cout << que << endl;
//     for (int i = 0; i < que.size(); i++)
//     {
//         kth_perm(n, k, que.substr(0, i) + que.substr(i + 1), ans + que[i]);
//     }
//     return;
// }

// string getPermutation(int n, int k)
// {
//     string s = "";
//     for (int i = 1; i <= n; i++)
//         s += to_string(i);
//     // cout<<s;
//     kth_perm(n, k, s, "");
//     return kstr;
// }
int fact(int n)
{
    if(n == 1 || n == 0)
        return 1;
    return n*fact(n-1);
}
int main()
{
    int n=9, k=3;
    cout<<fact(n);
}