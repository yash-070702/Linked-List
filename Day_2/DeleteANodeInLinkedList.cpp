#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* deleteNode(Node* head, int pos) {
    if (head == NULL) return head;

   
    if (pos == 0) {
        Node* newHead = head->next;
        head->next = NULL;
        delete head;  
        return newHead;
    }

    Node* temp = head;
    Node* prev = NULL;

   
    while (pos-- > 0 && temp != NULL) {
        prev = temp;
        temp = temp->next;
    }


    if (temp == NULL) return head;

    prev->next = temp->next;
    temp->next = NULL;
    delete temp;  

    return head;
}

    