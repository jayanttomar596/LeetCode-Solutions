class Solution {
    bool dfs(vector<int>& arr , int i , vector<bool>& visited)
    {
        int n = arr.size() ;

        if (i < 0 || i >= n)
        {
            return false ;
        }

        if (visited[i]) return false ;

        if (arr[i] == 0) return true ;

        visited[i] = true ;

        return dfs(arr , i+arr[i] , visited) || dfs(arr , i-arr[i] , visited) ;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size() ;

        vector<bool> visited(n,false) ;

        return dfs(arr , start , visited) ;
    } 
};