#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    int p0 = 0, p1 = 0;
    unordered_map<int,int> m;
    m[0] = 1;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
        {
            p0++;
        }
        else if(a[i] == 1)
        {
            p1++;
        }
        int diff = p0-p1;
        if(m.count(diff))
            ans += m[diff];
        m[diff]++;
        // cout<<p0<<" "<<p1<<" "<<m[diff]<<endl;
    }
    cout<<ans<<endl;

    return 0;
}