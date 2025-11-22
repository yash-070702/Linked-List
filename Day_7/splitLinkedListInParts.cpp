#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
      vector<ListNode*> result(k, NULL);

        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }

        int each = n / k;
        int extra = n % k;  

        temp=head;

        for(int i=0;i<k;i++){
            result[i]=temp;

            int size=each+(extra>0 ? 1 : 0);

            for(int j=0 ;j<size-1 && temp ; j++){
                temp=temp->next;
            }

            if(temp){
                ListNode* newTemp=temp->next;
                temp->next=NULL;
                temp=newTemp;
            }

            extra--;
       }
       return result;
    }
};