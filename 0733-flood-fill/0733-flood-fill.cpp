class Solution {
    void dfs(vector<vector<int>>& image , int sr , int sc , int &org , int &color)
    {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) return ;

        if (image[sr][sc] == org) image[sr][sc] = color ; 

        int dx[] = {0,0,1,-1} ;
        int dy[] = {1,-1,0,0} ;

        for (int i = 0 ; i < 4 ; i++)
        {
            int nr = sr + dx[i] ;
            int nc = sc + dy[i] ;

            if ((nr >= 0 && nc >= 0 && nr < image.size() && nc < image[0].size()) && image[nr][nc] == org)
            {
                dfs(image , nr , nc , org , color) ;
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org = image[sr][sc] ;
        if (org == color) return image ;
        dfs(image , sr , sc , org , color) ;
        return image ;
    }
};