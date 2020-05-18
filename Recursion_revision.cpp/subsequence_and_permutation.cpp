// #include<iostream>
// using namespace std;

// int subsequence(string que, string ans)
// {
//     if(que.length() == 0)
//     {
//         cout<<ans<<endl;
//         return 1;
//     }
//     int count = 0;
//     count += subsequence(que.substr(1),ans+que[0]);
//     count += subsequence(que.substr(1),ans);
//     return count;
// }

// int permutation_01(string que, string ans)
// {
//     if(que.length() == 0)
//     {
//         cout<<ans<<endl;
//         return 1;
//     }

//     int count = 0;
//     for(int i=0;i<que.length();i++)
//         count += permutation_01(que.substr(0,i)+que.substr(i+1),ans+que[i]);

//     return count;
// }

// int permutation_02(string que, string ans)
// {
//     if(que.length() == 0)
//     {
//         cout<<ans<<endl;
//         return 1;
//     }

//     int count = 0;
//     int isSet = 0;
//     for(int i=0;i<que.length();i++)
//     {
//         int mask = (1<<(que[i]-'a'));
//         if((isSet & mask) == 0)
//         {
//             count += permutation_02(que.substr(0,i)+que.substr(i+1),ans+que[i]);
//             isSet |= mask;
//         }
//     }
//     return count;
// }

// int main()
// {
//     // cout<<subsequence("akbc","");
//     // cout<<permutation_01("abc","");
//     cout<<permutation_02("aab","");
// }


#include<iostream> 

using namespace std; 
void fun(int *ptr) {
    *ptr = 30;
}

int main() {
     int y = 20;
    fun(&y);
    cout<<y++ + 10<<endl;
    return 0;

}