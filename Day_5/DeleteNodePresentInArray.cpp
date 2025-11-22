#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;

        for(auto i : nums){
            st.insert(i);
        }

        ListNode* prev = head;
        ListNode* temp = head;

        while(temp!=NULL){
            int data = temp->val;
            if(st.count(data)){
                if(temp == head){
                    head = temp->next;
                    temp = temp->next;
                   
                }
                else{
                    prev->next = temp->next;
                    temp = temp->next;
                
                }
            }
            else{
                prev = temp;
                temp = temp->next;
            }
           
        }

        return head;
    }
};

