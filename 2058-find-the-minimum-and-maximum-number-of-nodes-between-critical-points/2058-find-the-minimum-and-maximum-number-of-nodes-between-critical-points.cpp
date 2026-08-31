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
        int prev = head->val ;
        head = head -> next ;
        if (!head) return {-1,-1} ;
        int i = 1 ;
        int first = -1 ;
        int prevcri = -1 ;
        int minDist = INT_MAX ;
        
        while(head->next != NULL)
        {
            if ((head -> val > prev && head -> val > head -> next -> val) || (head -> val < prev && head -> val < head -> next -> val))
            {
                if (first == -1)
                {
                    first = i ;
                    prevcri = i ;
                }
                else 
                {
                    minDist = min(minDist , i - prevcri) ;
                    prevcri = i ;
                }
            }

            i++ ;
            prev = head -> val ;
            head = head -> next ;
        }

        if (first == -1 || prevcri == first) return {-1, -1} ;

        int maxi = prevcri - first ;

        
        return {minDist , maxi} ;
    }
};