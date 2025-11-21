#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        unordered_set<int>st;
        
        Node* temp=head;
        Node* prev=head;
        
        if(!head)
        return NULL;
        
        while(temp){
            if(st.count(temp->data)){
              prev->next=temp->next;
              temp=temp->next;
            }
            else{
                st.insert(temp->data);
                prev=temp;
                temp=temp->next;
                
            }
        }
        return head;
    }
};

