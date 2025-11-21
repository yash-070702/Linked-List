#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node* reverseLL(Node* head){
    if(!head || !head->next)
    return head;

    Node* t1=head;
    Node* t2=NULL;
    Node* t3=NULL;

    while(t1){
        t3=t1->next;
        t1->next=t2;
        t2=t1;
        t1=t3;
    }

    return t2;
}


Node *addOne(Node *head)
{
   head=reverseLL(head);
   Node* temp=head;
   
   int carry=0;
   
   temp->data++;

   if(temp->data>9){
   carry=1;
   temp->data=0;
   temp=temp->next;
   }




   while(carry && temp){
   int num=temp->data;
   num++;
   temp->data=num%10;
   carry=num/10;

   if(temp->next)
   temp=temp->next;

   else
   break;
   }

   if(carry){
   Node* newNode=new Node(carry);
   temp->next=newNode;
   head=reverseLL(head);
   return head;
   }
   
       head=reverseLL(head);
       return head;
}
