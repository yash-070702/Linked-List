#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *findMiddle(Node *head) {
    Node* fast=head;
    Node* slow=head;

    while(fast){
        fast=fast->next;

        if(fast){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}
    