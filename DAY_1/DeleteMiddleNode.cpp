#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* deleteMiddle(Node* head){

     if(head == NULL || head->next == NULL) 
        return NULL;

        
    Node* prev=head;
    Node* slow=head;
    Node* fast=head;

    while(fast && fast->next){
        fast=fast->next;
        prev=slow;
        slow=slow->next;

        if(fast)
        fast=fast->next;
    }
    prev->next=slow->next;
    slow->next=NULL;

    return head;
}

