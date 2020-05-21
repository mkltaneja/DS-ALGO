// #include <iostream>
// #include <math.h>

// using namespace std;

// /**
//  * Auto-generated code below aims at helping you parse
//  * the standard input according to the problem statement.
//  **/

// int main()
// {

//     // Write an answer using cout. DON'T FORGET THE "<< endl"
//     // To debug: cerr << "Debug messages..." << endl;

//     int n;
//     cin>>n;
//     int i = 20;
//     while(i != 0)
//     {
//         if(pow(2,i) < n)
//         if(n % (int)pow(2,i) == 0)
//         {
//             cout<<i;
//             break;
//         }
//         i--;
//     }

//     // cout << "answer" << endl;
// }

#include <iostream>
#include <vector>

using namespace std;
// // void fun(int *ptr) {
// //     *ptr = 30;
// // }

int countSquares(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int squares = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int s = 0; (j + s < m) && (i + s < n); s++)
            {
                bool flag = true;
                for (int k = 0; k <= s; k++)
                {
                    cout << matrix[i + s][j + k] << " " << matrix[i + k][j + s] << endl;
                    if (matrix[i + s][j + k] == 0 || matrix[i + k][j + s] == 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
                squares++;
                cout << endl;
            }
        }
    }
    return squares;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12}};
    cout << endl
         << endl
         << countSquares(arr) << endl;
}
// //      int y = 20;
// //     fun(&y);
// //     cout<<y++ + 10<<endl;
// //     return 0;

// // }
