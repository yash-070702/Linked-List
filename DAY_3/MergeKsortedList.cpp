#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

    

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        int n =0;
        
        if(!head)
        return NULL;
        
        
        Node* last=head;
        
        if(!head)
        return NULL;
        
        while(last){
            n++;
            
            if(last->next)
            last=last->next;
            
            else
            break;
        }
        k=k%n;
        
        if(k==0)
        return head;
        
        Node* start=head;
        
        while(k!=1){
            start=start->next;
            k--;
        }
        
        Node* newHead=start->next;
        
        start->next=NULL;
        last->next=head;
        
        return newHead;
    }
};