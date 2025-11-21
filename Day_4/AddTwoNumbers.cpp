#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

Node<int>* reverseLL(Node<int>* head){
    Node<int>* t1 = head;
    Node<int>* t2 = NULL;
    Node<int>* t3 = NULL;

    while(t1){
        t3 = t1->next;
        t1->next = t2;
        t2 = t1;
        t1 = t3;
    }
    return t2;
}

Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {

    first = reverseLL(first);
    second = reverseLL(second);

    Node<int>* head = NULL;
    Node<int>* tail = NULL;

    int carry = 0;

    while(first || second || carry){

        int sum = carry;

        if(first){
            sum += first->data;
            first = first->next;
        }
        if(second){
            sum += second->data;
            second = second->next;
        }

        Node<int>* newNode = new Node<int>(sum % 10);
        carry = sum / 10;

        if(!head){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = reverseLL(head);
    return head;
}


