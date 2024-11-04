#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> linerSearch(int mat[][3], int rows, int cols, int key)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] == key)
            {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(1, -1);
}
int diagonalSum(int mat[][3], int n)
{
    int sum = 0;

    // for O(n*n)
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i == j)
    //         {
    //             sum += mat[i][j];
    //         }
    //         else if (j == n - i - 1)
    //         {
    //             sum += mat[i][j];
    //         }
    //     }
    // }

    // for O(n)
    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i];

        if (i != n - i - 1)
        {
            sum += mat[i][n - i - 1];
        }
    }

    return sum;
}

int main()
{
    // int matrix[3][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9},
    //     // {10, 11, 12},
    // };

    // int rows = 4;
    // int cols = 3;
    // pair<int, int> result = linerSearch(matrix, rows, cols, 73);
    // cout << result.first << "," << result.second << endl;

    // int res = diagonalSum(matrix, 3);
    // cout << "Diagonal Sum is : " << res << endl;

    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10},
    };

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}