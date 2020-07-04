#include <iostream>
#include <vector>
using namespace std;

int LIS_left_to_right(vector<int> &arr, vector<int> &dp)
{
    int omax = 1;
    for(int i=0;i<arr.size();i++)
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
// LDS
int LIS_right_to_left(vector<int> &arr, vector<int> &dp)
{
    int omax = 1;
    for(int i=arr.size()-1;i>=0;i--)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i],dp[j]+1);
        }
        omax = max(omax, dp[i]);
    }
    return omax;
}


int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        if(n == 0)
        {
            cout<<0;
            continue;
        }
        
        vector<int> LIS(n,1);
        vector<int> LDS(n,1);
        LIS_left_to_right(arr,LIS);
        LIS_right_to_left(arr,LDS);
        
        int max_ = 1;
        for(int i=0;i<n;i++)
        {
            int len = LIS[i] + LDS[i] - 1;
            max_ = max(max_,len);
        }
        cout<<max_<<endl;
    }
	//code
	return 0;
}