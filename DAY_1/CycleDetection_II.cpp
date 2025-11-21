#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *firstNode(Node *head)
{

	Node* temp=head;
    unordered_set<Node*>st;
    

    while(temp){
        if(st.count(temp))
        return temp;
        
        st.insert(temp);
        temp=temp->next;
    }

    return NULL;

}
