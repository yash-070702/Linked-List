#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    int gcd(int a , int b){
        if(b==0)
        return a;

        return gcd(b,a%b);
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
    if(!head || !head->next)
    return head;

    ListNode* curr=head;
    ListNode* forw=head->next;

    while(forw && curr){
        int currgcd=gcd(curr->val,forw->val);
        ListNode* nwNode= new ListNode(currgcd);

        nwNode->next=forw;
        curr->next=nwNode;
        forw=forw->next;
        curr=curr->next->next;
    }

    return head;
    }
};