#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd=head;
        if(head==NULL)
        return head;
        ListNode* evenHead=head->next;
        ListNode* even=evenHead;

while(odd->next!=NULL && odd->next->next!=NULL){
odd->next=even->next;
odd=even->next;
even->next=odd->next;
even=odd->next;
}
odd->next=evenHead;
return head;
    }
};