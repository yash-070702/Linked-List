#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int count=0;
        unordered_set<int> st(nums.begin(), nums.end());
       
        while(head){
            if(st.count(head->val)){
             
                if(!head->next || !st.count(head->next->val))
                    count++;
            }
            head = head->next;
        }
        return count;
    }
};
