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

    reverse(ListNode*l, ListNode *r)
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        };
        stack<int>st;
        ListNode *l= head;
        ListNode* temp= l;
        ListNode *r= head;
        left-=1; right-=1;
        while(left--){
            l= l->next;
        };
        while(right--){
            r= r->next;
        }
        while(temp->next!=r){
            st.push(temp->val);

        }
        st.push(r->val);

        while(l->next!=r->next){
            l->val= st.top();
            st.pop(); 
        }
        return head;
    }
};