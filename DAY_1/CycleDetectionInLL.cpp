#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool detectCycle(Node *head)
{
	Node* slow=head;
    Node* fast=head;

    while(fast){
        fast=fast->next;

        if(fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==fast)
        return true;
    }

    return false;
}

bool hasCycle(Node *head) {
    unordered_set<Node*> visited;

    while (head != NULL) {
        if (visited.find(head) != visited.end())
            return true;

        visited.insert(head);
        head = head->next;
    }
    return false;
}