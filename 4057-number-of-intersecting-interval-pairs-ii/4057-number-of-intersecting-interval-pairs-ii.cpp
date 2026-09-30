class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end()) ;

        priority_queue<int , vector<int> , greater<int>> pq ;

        long long ans = 0 ;

        for (auto &interval : intervals)
        {
            int start = interval[0] ;
            int end = interval[1] ;

            while(!pq.empty() && pq.top() < start) pq.pop() ;

            ans += pq.size() ;
            pq.push(end) ;
        } 

        return ans ;
    }
};