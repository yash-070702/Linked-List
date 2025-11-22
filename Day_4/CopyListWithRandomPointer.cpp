#include<bits/stdc++.h>
using namespace std;



class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};


class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
      
        if(head==NULL)
        return NULL;
      
        
        Node* temp=head;
        Node* curr=NULL;
        while(temp){
            Node* clonedNode=new Node(temp->data);
            clonedNode->next=temp->next;
            temp->next=clonedNode;
            temp=temp->next->next;
        }

       
        temp=head;
        curr=head->next;

    while(curr->next){
        if(temp->random!=NULL){
            curr->random=temp->random->next;
            curr=curr->next->next;
            temp=temp->next->next;
        }
        else
        {
            curr->random=NULL;
            curr=curr->next->next;
            temp=temp->next->next;

        }
    }

    if(temp->random!=NULL)
    curr->random=temp->random->next;
        
     else
    curr->random=NULL;
        

    Node* prev=head;
    curr=head->next;
    Node* finalHead=head->next;

    while(curr->next){
        prev->next=curr->next;
        curr->next=curr->next->next;
        prev=prev->next;
        curr=curr->next;
    }
    
    prev->next=NULL;

    return finalHead;


                            
    }
};