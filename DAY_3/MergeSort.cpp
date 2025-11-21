#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
  public:
  
  
   Node* middleNode(Node* head){
        Node* slow=head;
        Node* fast=head;
        
        while(fast && fast->next){
            fast=fast->next;
            slow=slow->next;
            
            if(fast->next){
                fast=fast->next;
            }
        }
        return slow;
    }
    
    Node* merge(Node*left , Node*right){
        if(!left)
        return right;
        
        if(!right)
        return left;
        
        Node* ans=new Node(-1);
        Node* temp=ans;
        
        while(left && right){
            if(left->data>right->data){
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
            
            else{
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }
        }
        
        if(left){
            temp->next=left;
        }
        
        if(right){
            temp->next=right;
        }
        return ans->next;
    }
    
Node* mergeSort(Node* head) {
    if(head==NULL || head->next==NULL)
    return head;        

Node* mid=middleNode(head);
Node* left=head;
Node* right=mid->next;
mid->next=NULL;

left=mergeSort(left);
right=mergeSort(right);

Node* mergeLL=merge(left,right);
return mergeLL;
    }
    
};