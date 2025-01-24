#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int MaximumScore(vector<vector<int>>& grid) {
    int m = grid.size();    // Number of rows
    int n = grid[0].size(); // Number of columns
    
    // Ensure the MSB of each row is 1
    for (int i = 0; i < m; ++i) {
        if (grid[i][0] == 0) { // Toggle the entire row
            for (int j = 0; j < n; ++j) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }
    
    // Step 2: Optimize each column (except the first)
    for (int j = 1; j < n; ++j) {
        int ones = 0;
        for (int i = 0; i < m; ++i) {
            if (grid[i][j] == 1) {
                ++ones;
            }
        }
        // If the number of 0's is greater than the number of 1's, toggle the column
        if (ones < m - ones) {
            for (int i = 0; i < m; ++i) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }
    
    // Calculate the total score
    int score = 0;
    for (int i = 0; i < m; ++i) {
        int rowValue = 0;
        for (int j = 0; j < n; ++j) {
            rowValue = (rowValue << 1) | grid[i][j];
        }
        score += rowValue;
    }
    
    return score;
}

int main()
{
	 vector<vector<int>> grid = {
        {0, 0, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 0}
    };
    
    int sonuc = MaximumScore(grid) ;
    cout << sonuc << '\n';
}
