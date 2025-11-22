#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
    vector<int>ans;

    while(head){
        ans.push_back(head->val);
        head=head->next;
    }

    int n=ans.size();
    int sum=INT_MIN;
    int i=0;
    int j=n-1;

    while(i<j){
    int currSum=ans[i]+ans[j];
    i++;
    j--;
    sum=max(sum,currSum);
    }
    return sum;
    }
};

