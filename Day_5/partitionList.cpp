#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    ListNode* head1=new ListNode(-1);
    ListNode* head2=new ListNode(-1);

    ListNode* temp1=head1;
    ListNode* temp2=head2;

    while(head){
        if(head->val<x){
            temp1->next=head;
            temp1=temp1->next;
        }
        else{
            temp2->next=head;
            temp2=temp2->next;
        }
        head=head->next;
    }
    temp2->next=NULL;
    temp1->next=head2->next;
    return head1->next;
    }
};