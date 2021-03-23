#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int n = a.size();

    int p0 = 0, p1 = 0, p2 = 0;
    map<pair<int,int>, int> m;
    m[{0,0}] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] == '0') p0++;
        else if(a[i] == '1') p1++;
        else if(a[i] == '2') p2++;

        if(m.count({p0-p1,p1-p2}))
            ans += m[{p0-p1, p1-p2}];
        m[{p0-p1, p1-p2}]++;
    }
    cout << ans << endl;

    return 0;
}