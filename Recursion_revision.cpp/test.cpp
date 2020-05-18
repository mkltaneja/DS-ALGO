#include <iostream>
#include <math.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
   
    int n;
    cin>>n;
    int i = 20;
    while(i != 0)
    {
        if(pow(2,i) < n)
        if(n % (int)pow(2,i) == 0)
        {
            cout<<i;
            break;
        }
        i--;
    }

    // cout << "answer" << endl;
}