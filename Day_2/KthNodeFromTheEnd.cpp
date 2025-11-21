#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *findKthFromLast(Node *head, int k)
{
	Node* fast=head;
	Node* slow=head;

	for(int i=0;i<k;i++){
		if(!fast)
		return NULL;

		fast=fast->next;
	}

	while(fast){
		fast=fast->next;
		slow=slow->next;
	}

	return slow;
}
