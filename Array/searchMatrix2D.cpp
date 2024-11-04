#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// time complexity O(m+n) and space complexity O(1)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int i = 0, j = cols - 1; // Start from the top-right corner

    while (i < rows && j >= 0)
    {
        if (matrix[i][j] == target)
        {
            return true;
        }
        else if (matrix[i][j] > target)
        {
            j--; // Move left
        }
        else
        {
            i++; // Move down
        }
    }
    return false;
}

int main()
{

    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30},
    };

    cout << searchMatrix(mat, 5) << endl;

    return 0;
}