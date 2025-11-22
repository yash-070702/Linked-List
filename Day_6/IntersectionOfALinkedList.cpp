#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        unordered_set<Node*>st;
        
        while(head1){
            st.insert(head1);
            head1=head1->next;
        }
        
        while(head2){
            if(st.count(head2))
            return head2;
            
            head2=head2->next;
        }
        return NULL;
    }
};


//<<<<<<<<<<=========OR========>>>>>>>>>>//

class Solution {
  public:
    Node* intersectPoint(Node* firstHead, Node* secondHead) {
    int count1=0;
    int count2=0;

    Node* temp1=firstHead;
    Node* temp2=secondHead;

    while(temp1 && temp2){
        
        temp1=temp1->next;
        temp2=temp2->next;
    }

    

    if(temp1){
        count1++;
        temp1=temp1->next;
    }

    if(temp2){
        count2++;
        temp2=temp2->next;
    }

    temp1=firstHead;
    temp2=secondHead;

    while(count1--){
        temp1=temp1->next;
    }

    while(count2--){
        temp2=temp2->next;
    }

    while(temp1 && temp2){
        if(temp1==temp2)
        return temp1;

        temp1=temp1->next;
        temp2=temp2->next;
    }
    return NULL;
    }
};