class Solution {
    void rotateAntiClockwise(vector<int>& arr, int k) {
        int n = arr.size();

        k = k % n; // handle k > n

        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
        reverse(arr.begin(), arr.end());
    }
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size() ; //rows
        int n = grid[0].size() ; //cols

        int layers = min(m, n) / 2;

        for (int i = 0 ; i < layers ; i++)
        {
            vector<int> arr ;
            for (int col = i ; col <= n-1-i ; col++)
            {
                arr.push_back(grid[i][col]) ;
            }
            for (int row = i+1 ; row <= m-1-i ; row++)
            {
                arr.push_back(grid[row][n-1-i]) ;
            }
            for (int col = n-2-i ; col >= i ; col--)
            {
                arr.push_back(grid[m-1-i][col]) ;
            }
            for (int row = m-2-i ; row >= i+1 ; row--)
            {
                arr.push_back(grid[row][i]) ;
            }

            // arr is ready now do counter clockwise k cycles 
            rotateAntiClockwise(arr , k) ;
            int x = 0 ;
            for (int col = i ; col <= n-1-i ; col++)
            {
                grid[i][col] = arr[x++];
            }
            for (int row = i+1 ; row <= m-1-i ; row++)
            {
                grid[row][n-1-i] = arr[x++] ;
            }
            for (int col = n-2-i ; col >= i ; col--)
            {
                grid[m-1-i][col] = arr[x++] ;
            }
            for (int row = m-2-i ; row >= i+1 ; row--)
            {
                grid[row][i] = arr[x++] ;
            }
        }

        return grid;
    }
};