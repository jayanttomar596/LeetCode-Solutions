class NumArray {
    vector<int> nums ;
    vector<int> tree ;
    int n ;

    void build(int node , int start , int end)
    {
        if (start == end)
        {
            tree[node] = nums[start] ;
            return ;
        }

        int mid = start + (end - start)/2 ;

        build(2*node + 1 , start , mid);
        build(2*node + 2 , mid + 1 , end) ;

        tree[node] = tree[2*node + 1] + tree[2*node+2] ;
    }

    void update(int node , int start , int end , int index , int val)
    {
        if (start == end)
        {
            nums[index] = val ;
            tree[node] = val ;
            return ;
        }

        int mid = start + (end-start)/2 ;

        if (index <= mid)
        {
            update(2*node + 1 , start , mid , index , val) ;
        }
        else
        {
            update(2*node + 2 , mid + 1 , end , index , val) ;
        }


        tree[node] = tree[2*node + 1] + tree[2*node + 2] ;
    }

    int query(int node , int start , int end , int left , int right)
    {
        if (end < left || start > right)
        {
            return 0 ;
        }

        if (left <= start && end <= right) return tree[node] ;

        int mid = start + (end - start)/2 ;

        int leftsum = query(2*node+1 , start , mid , left , right) ;
        int rightsum = query(2*node +2 , mid + 1 , end , left , right) ;

        return leftsum + rightsum ;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums ;
        this->n = nums.size() ;

        tree.resize(4 * n);

        build(0 , 0 , n-1) ;
    }
    
    void update(int index, int val) {
        update(0 , 0 , n-1 , index , val) ;
    }
    
    int sumRange(int left, int right) {
        return query(0 , 0 , n-1 , left , right) ;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */