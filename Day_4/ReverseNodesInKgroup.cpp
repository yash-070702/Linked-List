#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

Node* reverseLL(Node* head) {
    Node* t1=head;
    Node* t2=nullptr;
    Node* t3=nullptr;

    while(t1){
       t3=t1->next;
         t1->next=t2;
         t2=t1;
         t1=t3;
    }
    return t2;
}

Node* kReverse(Node* head, int k) {
    Node* last=head;
    Node* curr=head;
    Node* prev=NULL;
    Node* temp=curr;
    int count=0;

    while(last){
     count++;

     if(count==k){
     count=0;
     
     Node* lastTemp=last->next; 

     last->next=NULL;
     
     if(prev==NULL){
     head=reverseLL(head);
     }

     else{
         curr=reverseLL(curr);
         prev->next=curr;

     }
        temp->next=lastTemp;
        curr=lastTemp;
        prev=temp;
        temp=curr;

         last = lastTemp;
     }

     else{
         last=last->next;
     }

    }

    return head;
}