#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// User function Template for C++
class Solution {
  public:
    int countTriplets(struct Node* head, int x) {
        int count=0;
        vector<int>arr;
        
        while(head){
            arr.push_back(head->data);
            head=head->next;
        }
        
        unordered_map<int,int>mp;
        sort(arr.begin(),arr.end());
        
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int currSum=arr[i]+arr[j];
                
                if(currSum>=x)
                    continue;
        
                int rem=x-currSum;
                
                if(mp.find(rem)!=mp.end() && mp[rem]>j)
                count++;
                
            }
        }
        return count;
    }
};