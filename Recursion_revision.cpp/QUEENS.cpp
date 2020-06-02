#include <iostream>
#include <vector>
using namespace std;

///////// QUEEN 1D =====================================================================

int queenpermu(int n, int tnq, vector<bool> &isplaced, string ans)
{
    if (tnq == 0)
    {
        // cout<<ans<<endl;
        return 1;
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!isplaced[i])
        {
            isplaced[i] = true;
            count += queenpermu(n, tnq - 1, isplaced, ans + "B" + to_string(i) + " Q" + to_string(tnq) + "  ");
            isplaced[i] = false;
        }
    }
    return count;
}

int queencombi(int n, int lqpl, int q, int tnq, string ans)
{
    if (q == tnq)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = lqpl; i <= n; i++)
        count += queencombi(n, i + 1, q + 1, tnq, ans + "B" + to_string(i) + " Q" + to_string(q) + "  ");
    return count;
}

///////// QUEEN 2D ===============================================================================

bool isSafetoPlace_permu(int i, int j, vector<vector<bool>> &boxes)
{
    int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

    for (int d = 0; d < 8; d++)
    {
        for (int rad = 1; rad < max(boxes.size(), boxes[0].size()); rad++)
        {
            int r = i + rad * dir[d][0];
            int c = j + rad * dir[d][1];
            if (r < 0 || r >= boxes.size() || c < 0 || c >= boxes[0].size())
                break;
            if (boxes[r][c])
                return false;
        }
    }
    return true;
}

int queen2d_permu(vector<vector<bool>> &boxes, int tnq, string ans)
{
    if (tnq == 0)
    {
        cout << ans << "]" << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < boxes.size() * boxes[0].size(); i++)
    {
        int r = i / boxes[0].size();
        int c = i % boxes[0].size();
        if (!boxes[r][c] && isSafetoPlace_permu(r, c, boxes))
        {
            boxes[r][c] = true;
            count += queen2d_permu(boxes, tnq - 1, ans + "[ " + to_string(r) + " , " + to_string(c) + " ], ");
            boxes[r][c] = false;
        }
    }
    return count;
}

bool isSafetoPlace_combi(int i, int j, vector<vector<bool>> &boxes)
{
    int dir[4][2] = {{-1, 1}, {-1, 0}, {-1, -1}, {0, -1}};
    for (int d = 0; d < 4; d++)
    {
        for (int rad = 1; rad < max(boxes.size(), boxes[0].size()); rad++)
        {
            int r = i + rad * dir[d][0];
            int c = j + rad * dir[d][1];
            if (r < 0 || c < 0 || r >= boxes.size() || c >= boxes.size())
                break;
            if (boxes[r][c])
                return false;
        }
    }
    return true;
}

int queen2d_combi(vector<vector<bool>> &boxes, int tnq, int lqpl, string ans)
{
    if (tnq == 0)
    {
        cout << ans << "]" << endl;
        return 1;
    }

    int count = 0;
    for (int i = lqpl; i < boxes.size() * boxes[0].size(); i++)
    {
        int r = i / boxes[0].size();
        int c = i % boxes[0].size();

        if (isSafetoPlace_combi(r, c, boxes))
        {
            boxes[r][c] = true;
            count += queen2d_combi(boxes, tnq - 1, i + 1, ans + "[ " + to_string(r) + ", " + to_string(c) + " ], ");
            boxes[r][c] = false;
        }
    }
    return count;
}

////////////OPTIMIZED METHOD FOR 2D N-QUEEN=================================================

int queen2d_permu_2(vector<vector<bool>> &boxes, vector<bool> row, vector<bool> col, vector<bool> rdiag, vector<bool> ldiag, int n, int m, int tnq, string ans)
{
    if (tnq == 0)
    {
        cout << ans << "]" << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < n * m; i++)
    {
        int r = i / m;
        int c = i % m;
        if (!boxes[r][c] && !row[r] && !col[c] && !rdiag[(m - 1) - (c - r)] && !ldiag[r + c])
        {
            boxes[r][c] = true;
            row[r] = true;
            col[c] = true;
            rdiag[(m - 1) - (c - r)] = true;
            ldiag[r + c] = true;

            count += queen2d_permu_2(boxes, row, col, rdiag, ldiag, n, m, tnq - 1, ans + "[ " + to_string(r) + ", " + to_string(c) + " ] ");

            boxes[r][c] = false;
            row[r] = false;
            col[c] = false;
            rdiag[(m - 1) - (c - r)] = false;
            ldiag[r + c] = false;
        }
    }
    return count;
}
int queen2d_combi_2(vector<vector<bool>> &boxes, vector<bool> row, vector<bool> col, vector<bool> rdiag, vector<bool> ldiag, int n, int m, int tnq, int lqpl, string ans)
{
    if (tnq == 0)
    {
        cout << ans << "]" << endl;
        return 1;
    }

    int count = 0;
    for (int i = lqpl; i < n * m; i++)
    {
        int r = i / m;
        int c = i % m;
        if (!boxes[r][c] && !row[r] && !col[c] && !rdiag[(m - 1) - (c - r)] && !ldiag[r + c])
        {
            boxes[r][c] = true;
            row[r] = true;
            col[c] = true;
            rdiag[(m - 1) - (c - r)] = true;
            ldiag[r + c] = true;

            count += queen2d_combi_2(boxes, row, col, rdiag, ldiag, n, m, tnq - 1, i + 1, ans + "[ " + to_string(r) + ", " + to_string(c) + " ] ");

            boxes[r][c] = false;
            row[r] = false;
            col[c] = false;
            rdiag[(m - 1) - (c - r)] = false;
            ldiag[r + c] = false;
        }
    }
    return count;
}

int main()
{
    int q;
    cout << "ENTER NO. OF QUEENS: ";
    cin >> q;
    int n;
    cout << "ENTER NO. OF BOXES (rowise): ";
    cin >> n;
    vector<bool> arr(n + 1, false);

    //////////////1D/////////////
    // cout<<"TOTAL PERMUTATIONS IN PLACING THE QUEENS ARE: "<<queenpermu(n,q,arr,"");
    // cout<<"TOTAL COMBINATIONS IN PLACING THE QUEENS ARE: "<<queencombi(n,1,0,q,"");

    /////////////2D//////////////
    int m;
    cout << "ENTER NO. OF BOXES (columnise): ";
    cin >> m;
    vector<vector<bool>> arr2d(n, vector<bool>(m, 0));
    // cout<<"TOTAL 2D PERMUTATIONS IN PLACING THE QUEENS ARE: "<<queen2d_permu(arr2d,q,"[")<<endl<<endl;
    cout<<"TOTAL 2D COMBINATIONS IN PLACING THE QUEENS ARE: "<<queen2d_combi(arr2d,q,0,"[")<<endl<<endl;

    ////// Alternative method for 2D N queen ===========================

    vector<bool> row(n, false);
    vector<bool> col(m, false);
    vector<bool> rdiag(n + m - 1, false);
    vector<bool> ldiag(n + m - 1, false);

    // cout<<"TOTAL 2D PERMUTATIONS IN PLACING THE QUEENS ARE: "<<queen2d_permu_2(arr2d,row,col,rdiag,ldiag,n,m,q,"[");
    cout << "TOTAL 2D COMBINATIONS IN PLACING THE QUEENS ARE: " << queen2d_combi_2(arr2d, row, col, rdiag, ldiag, n, m, q, 0, "[");
}