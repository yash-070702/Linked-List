#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

Node* pairsSwap(Node *head)
{
    if(!head || !head->next)
    return head;

    Node* curr=head;
    Node* forw=head->next;
    Node* prev=NULL;

    Node* newHead=forw;

    while(forw && curr){
        curr->next=forw->next;
        forw->next=curr;
        if(prev!=NULL){
            prev->next=forw;
        }
        prev=curr;

        if(!curr->next || !curr->next->next)
        break;

        else{
            curr=curr->next;
            forw=curr->next;
        }
    }

    return newHead;
}

