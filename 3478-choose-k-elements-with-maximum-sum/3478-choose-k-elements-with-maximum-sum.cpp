class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size() ;

        vector<array<int , 3>> arr ;
        for (int i = 0 ; i < n ; i++)
        {
            arr.push_back({nums1[i] , nums2[i] , i}) ;
        }

        sort(arr.begin() , arr.end()) ;

        vector<long long> ans(n,0) ;

        priority_queue<int , vector<int> , greater<int>> pq ;
        long long heapSum = 0 ;

        int i = 0 ;

        while(i < n)
        {
            int j = i ;

            while(j < n && arr[j][0] == arr[i][0])
            {
                ans[arr[j][2]] = heapSum ;
                j++ ;
            }

            for (int t = i ; t < j ; t++)
            {
                int val = arr[t][1] ;

                if ((int)pq.size() < k)
                {
                    pq.push(val) ;
                    heapSum += val ;
                }
                else if (val > pq.top())
                {
                    heapSum -= pq.top() ;
                    pq.pop() ;

                    pq.push(val) ;
                    heapSum += val ;
                }
            }

            i = j ;
        }

        return ans ;
    }
};