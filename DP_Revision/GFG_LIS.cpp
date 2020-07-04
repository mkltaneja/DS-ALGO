#include <iostream>
#include <vector>
using namespace std;

int LIS_left_to_right(vector<int> &arr)
{
    vector<int> dp(arr.size(),1);
    int omax = 1;
    for(int i=1;i<arr.size();i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i],dp[j]+1);
        }
        omax = max(omax, dp[i]);
    }
    return omax;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    if(n == 0)
        {
            cout<<0<<endl;
            continue;
        }
	    vector<int> arr(n,0);
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    cout<<LIS_left_to_right(arr)<<endl;
	}
	return 0;
}