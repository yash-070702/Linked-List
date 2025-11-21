#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:

   
    Node* reverseLL(Node* head) {
        if (!head || !head->next) return head;

        Node* newHead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    void reorderList(Node* head) {
        if (!head || !head->next) return;

        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

       
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

      
        prev->next = NULL;

     
        Node* second = reverseLL(slow);
        Node* first = head;
        
        
        while (first && second) {
            Node* temp1 = first->next;
            Node* temp2 = second->next;

            first->next = second;
            if (temp1 == NULL) break;

            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
