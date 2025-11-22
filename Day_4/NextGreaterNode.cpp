#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

int getLength(Node* head){
	int len=0;

	Node* temp=head;

	while(temp){
		len++;
		temp=temp->next;
	}

	return len;
}

vector<int> findNextGreaterNodeList(Node* head)
{

	int size=getLength(head);
    vector<int>arr(size);

	int i=0;

	while(head){
    arr[i]=head->data;
	i++;
	head=head->next;
	}


	stack<int>st;
    vector<int>ans(size);

	st.push(0);

     
	for(int i=size-1;i>=0;i--){
    while(arr[i]>=st.top() && st.top()!=0)
	st.pop();

	ans[i]=st.top();
	st.push(arr[i]);
	}

	return ans;
}