#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseLinkedList(Node* head) {
    Node* t1=head;
    Node* t2=nullptr;
    Node* t3=nullptr;

    while(t1){
       t3=t1->next;
         t1->next=t2;
         t2=t1;
         t1=t3;
    }
    return t2;
}

Node* reverseLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) 
        return head;

    Node* newHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

Node* reverseLinkedList(Node* head) {
    if (!head) return head;
    stack<Node*> st;

    Node* temp = head;
    while (temp) {
        st.push(temp);
        temp = temp->next;
    }

    Node* newHead = st.top();
    st.pop();
    temp = newHead;

    while (!st.empty()) {
        temp->next = st.top();
        st.pop();
        temp = temp->next;
    }
    temp->next = NULL;
    return newHead;
}



