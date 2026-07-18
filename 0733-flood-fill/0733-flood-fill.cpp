class Solution {
    void dfs(vector<vector<int>>& image , int r , int c , int &org , int &color)
    {
        if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size()) return ;

        if (image[r][c] != org)return ;

        image[r][c] = color ;

        dfs(image , r+1,c,org,color) ;
        dfs(image,r-1,c,org,color) ;
        dfs(image,r,c+1,org,color) ;
        dfs(image,r,c-1,org,color) ;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org = image[sr][sc] ;
        if (org == color) return image ;
        dfs(image , sr , sc , org , color) ;
        return image ;
    }
};