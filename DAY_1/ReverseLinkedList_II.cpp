#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
  public:
  
    Node*reverseLL(Node* head){
        if(!head || !head->next){
            return head;
        }
        
        Node* newHead=reverseLL(head->next);
        head->next->next=head;
        head->next=NULL;
        
        return newHead;
    }
    
  Node* reverseBetween(int a, int b, Node* head) {

    Node* start = head;
    Node* prev = NULL;
    a--;

    while(start && a--){
        prev = start;
        start = start->next;
    }

    Node* connectLeft = prev;
    Node* subHead = start;

    Node* end = head;
    b--;
    while(end && b--){
        end = end->next;
    }

    Node* temp = end->next;
    end->next = NULL;

    Node* newHead = reverseLL(subHead);

    if(connectLeft)
        connectLeft->next = newHead;
    else
        head = newHead;

    while(newHead->next){
        newHead = newHead->next;
    }

    newHead->next = temp;

    return head;
}

};