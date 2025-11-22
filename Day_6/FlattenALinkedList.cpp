#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *bottom;
    Node(int x) : data(x), next(NULL), bottom(NULL) {}
};
class Solution {
  public:
  
  struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; 
    }
  };

  Node *flatten(Node *root) {
     
      priority_queue<Node*, vector<Node*>, cmp> st;
      Node* temp = root;

      while(temp){
          Node* innerTemp = temp->next;
          Node* temp2 = temp;

          while(temp2->bottom){
              st.push(temp2);
              temp2->next = temp2->bottom;
              temp2 = temp2->next;
          }

          st.push(temp2);
          temp2->bottom = NULL;
          temp2->next = innerTemp;
          temp = innerTemp;
      }

     
      Node* newHead = new Node(-1);
      Node* tem = newHead;
      
      while(!st.empty()){
          auto it = st.top();
          st.pop();

          it->next = NULL;    
          it->bottom = NULL;   

          tem->bottom = it;    
          tem = tem->bottom;
      }

      return newHead->bottom;
  }
};
