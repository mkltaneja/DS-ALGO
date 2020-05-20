#include<iostream>
using namespace std;

int keypad(string words[], string que, string ans)
{
    if(que.size() == 0)
    {
        cout<<ans<<endl;
        return 1;
    }

    int idx1 = que[0] - '0';
    string word1 = words[idx1];
    int count = 0;
    for(int i=0;i<word1.size();i++)
    {
        count += keypad(words,que.substr(1),ans+word1[i]);
    }

    if(que.size() >= 2)
    {
        int idx2 = 10*(que[0] - '0') + (que[1] - '0');
        // cout<<idx2<<endl;
        if(idx2 == 10 || idx2 == 11)
        {
            string word2 = words[idx2];
            for(int i=0;i<word2.size();i++)
            {
                count += keypad(words,que.substr(2),ans+word2[i]);
            }
        }
    }
    return count;
}

int main()
{
    string words[12] = {".,:;", "abc", "def", "ghi", "jkl", "mno", "pqrs",
                        "tuv", "wx", "yz", "@$&", "-_%"};
    string num;
    cout<<"ENTER THE NUMBER YOU LIKE AND I WILL FIND YOUR CONTACTS :) \n";
    cin>>num;
    cout<<"I found "<<keypad(words,num,"")<<" contacts in your list \n";
}