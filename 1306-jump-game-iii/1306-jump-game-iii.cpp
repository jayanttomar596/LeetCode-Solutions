class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size() ;

        vector<bool> visited(n,false) ;

        queue<int> q ;
        q.push(start) ;
        visited[start] = true ;

        while(!q.empty())
        {
            int front = q.front() ;
            q.pop() ;

            if (arr[front] == 0) return true ;
            int op1 = front + arr[front] ;
            int op2 = front - arr[front] ;

            if (op1 < n && !visited[op1])
            {
                q.push(op1) ;
                visited[op1] = true ;
            }

            if (op2 >= 0 && !visited[op2])
            {
                q.push(op2) ;
                visited[op2] = true ;
            }
        }

        return false ;
    } 
};