#include<iostream>
using namespace std;

void lexicographical_01(int n, string s)
{
    if(s != "")
        cout<<s<<endl;
    for(int i=0;i<=9;i++)
    {
        if(s == "" && i == 0)
            continue;  
        if(stoi(s+to_string(i)) < n)
            lexicographical_01(n,s+to_string(i));
        else
            break; 
    }
}

//////////////OR//////////////////////

void lexicographical_02(int sn, int en)
{
    cout<<sn<<endl;
    for(int i=0;i<=9;i++)
    {
        if(sn * 10 + i < en)
            lexicographical_02(sn*10+i,en);    
    }
    if(sn < 9)
        lexicographical_02(sn+1,en);
}

int main()
{
    int n;
    cout<<"ENTER n\n";
    cin>>n;
    // lexicographical_01(n,"");
    lexicographical_02(1,n);
}