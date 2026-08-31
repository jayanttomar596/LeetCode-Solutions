/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head) return {-1,-1} ;
        vector<int> cri ;
        int prev = head->val ;
        head = head -> next ;
        if (!head) return {-1,-1} ;
        int i = 1 ;
        
        while(head->next != NULL)
        {
            if (head -> val > prev && head -> val > head -> next -> val) cri.push_back(i) ;

            if (head -> val < prev && head -> val < head -> next -> val) cri.push_back(i) ;

            i++ ;
            prev = head -> val ;
            head = head -> next ;
        }

        // we got the vector now we want max and min gap

        if (cri.size() < 2) return {-1,-1} ;
        int maxi = cri.back() - cri.front() ;

        int mini = INT_MAX ;
        for (int i = 1 ; i < cri.size() ; i++)
        {
            mini = min(mini , cri[i] - cri[i-1]) ;
        }
        return {mini , maxi} ;
    }
};