#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
      Node* temp=head;
      Node* prev=NULL;
      
      while(temp){
          if(temp->val==x){
              if(prev==NULL){
                  head=temp->next;
              }
              
              else{
                  prev->next=temp->next;
              }
            break;  
          }
          temp=temp->next;
      }
      
      return head;
        
    }
};