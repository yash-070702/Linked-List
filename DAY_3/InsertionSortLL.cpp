#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

/*Link list node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
  
   
    Node* insertionSort(struct Node* head) {
       if (!head || !head->next) 
        return head;
    
    Node* dummy = new Node(-1); 
    dummy->next = NULL;
    
    Node* curr = head;
    
    while (curr) {
        Node* nextNode = curr->next;  
        
     
        Node* temp = dummy;
        while (temp->next && temp->next->data < curr->data) {
            temp = temp->next;
        }
        
       
        curr->next = temp->next;
        temp->next = curr;
        
        curr = nextNode; 
    }
    
    return dummy->next;
    }
};