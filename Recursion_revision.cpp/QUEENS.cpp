#include<iostream>
#include<vector>
using namespace std;

///////// QUEEN 1D =====================================================================

int queenpermu(int n, int tnq, vector<bool> &isplaced, string ans)
{
    if(tnq == 0)
    {
        // cout<<ans<<endl;
        return 1;
    }

    int count = 0;
    for(int i=1;i<=n;i++)
    {
        if(!isplaced[i])
        {
            isplaced[i] = true;
            count += queenpermu(n,tnq-1,isplaced,ans+"B"+to_string(i)+" Q"+to_string(tnq)+"  ");
            isplaced[i] = false;
        }
    }
    return count;
}

int queencombi(int n, int lqpl, int q, int tnq, string ans)
{
    if(q == tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i=lqpl;i<=n;i++)
        count += queencombi(n,i+1,q+1,tnq,ans+"B"+to_string(i)+" Q"+to_string(q)+"  ");
    return count;
}

int main()
{
    int q;
    cout<<"ENTER NO. OF QUEENS: ";
    cin>>q;
    int n;
    cout<<"ENTER NO. OF BOXES (rowise): ";
    cin>>n;
    vector<bool> arr(n+1,false);

    //////////////1D/////////////
    // cout<<"TOTAL PERMUTATIONS IN PLACING THE QUEENS ARE: "<<queenpermu(n,q,arr,"");
    // cout<<"TOTAL COMBINATIONS IN PLACING THE QUEENS ARE: "<<queencombi(n,1,0,q,"");

    /////////////2D//////////////
    int m;
    cout<<"ENTER NO. OF BOXES (columnise): ";
    cin>>m;
    vector<vector<bool>> arr2d(n,vector<bool>(m,0));
    // cout<<"TOTAL 2D PERMUTATIONS IN PLACING THE QUEENS ARE: "<<queen2d_permu(arr2d,q,"[");
    cout<<"TOTAL 2D COMBINATIONS IN PLACING THE QUEENS ARE: "<<queen2d_combi(arr2d,q,0,"[");
}