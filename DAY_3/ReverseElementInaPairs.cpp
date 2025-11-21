#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};



Node *reverseKElements(Node *head, int n, int b[], int idx) {
   
    if (head == NULL || idx >= n) {
        return head;
    }

   
    int K = b[idx];

   
    if (K == 0) {
        return reverseKElements(head, n, b, idx + 1);
    }

    Node *cur = head, *prev = NULL, *ahead = NULL;

   
    int cnt = 0;

   
    while (cur != NULL && cnt < K) {
        ahead = cur->next;
        cnt++;
        cur->next = prev;
        prev = cur;
        cur = ahead;
    }

    
    head->next = reverseKElements(ahead, n, b, idx + 1);
    return prev;
}

Node * getListAfterReverseOperation(Node *head, int n, int b[]) {
 
    if (head == NULL) {
        return NULL;
    }

   
    head = reverseKElements(head, n, b, 0);


    return head;
}