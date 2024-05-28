// Given the head of a singly linked list and two integers left and right where left <= right, 
// reverse the nodes of the list from position left to position right, and return the reversed list.
// leetcode problem 92
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode*current=head;
        ListNode*prev=NULL;
        ListNode*next=NULL;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode*a=NULL;
        ListNode*b=NULL;
        ListNode*c=NULL;
        ListNode*d=NULL;
        int length=1;
        ListNode*temp=head;
        while(temp!=NULL){
            if(length==left-1) a=temp;
            if(length==left) b=temp;
            if(length==right) c=temp;
            if(length==right+1) d=temp;
            temp=temp->next;
            length++;
        }
        if(a!=NULL) a->next=NULL;
        c->next=NULL;
        c=reverseLinkedList(b);
        if(a!=NULL) a->next=c;
        b->next=d;
        if(a!=NULL) return head;
        return c;
    }
};
