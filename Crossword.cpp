#include <iostream>
#include <vector>
#define vi vector<int>
#define vb vector<bool>
using namespace std;

vector<vector<char>> board = {
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

bool isSafePWH(int x, int y, string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (board[x][y + i] != '-' && board[x][y + i] != word[i])
            return false;
    }
    return true;
}

vb PWH(int x, int y, string word)
{
    vb loc(word.size(), false);
    for (int i = 0; i < word.size(); i++)
    {
        if (board[x][y] == '-')
        {
            loc[i] = true;
            board[x][y + i] = word[i];
        }
    }
}

void UnPWH(int x, int y, vb &loc)
{
    for (int i = 0; i < loc.size(); i++)
    {
        if (loc[i])
        {
            board[x][y + i] = '-';
        }
    }
}

bool isSafePWV(int x, int y, string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (board[x + i][y] != '-' && board[x + i][y] != word[i])
            return false;
    }
    return true;
}

vb PWV(int x, int y, string word)
{
    vb loc(word.size(), false);
    for (int i = 0; i < word.size(); i++)
    {
        if (board[x][y] == '-')
        {
            loc[i] = true;
            board[x + i][y] = word[i];
        }
    }
}

void UnPWV(int x, int y, vb &loc)
{
    for (int i = 0; i < loc.size(); i++)
    {
        if (loc[i])
        {
            board[x + i][y] = '-';
        }
    }
}

int crossWord(vector<string> &arr, int idx)
{
    if (idx == arr.size())
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return 1;
    }

    string word = arr[idx];
    int count = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '-' || board[i][j] == word[0])
            {
                if (isSafePWH(i, j, word))
                {
                    vb loc = PWH(i, j, word);
                    count += crossWord(arr, idx + 1);
                    UnPWH(i, j, loc);
                }

                if (isSafePWV(i, j, word))
                {
                    vb loc = PWV(i, j, word);
                    count += crossWord(arr, idx + 1);
                    UnPWV(i, j, loc);
                }
            }
        }
        return count;
    }
}

void crossW()
{
    vector<string> words = {"agra", "norway", "england", "gwalior"};
    cout << crossWord(words, 0) << endl;
}

int main()
{
    crossW();
    return 0;
}