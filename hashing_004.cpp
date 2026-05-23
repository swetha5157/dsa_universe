// Given an integer array nums and an integer k, 
//return true if there are two distinct indices i and j in the array 
// such that nums[i] == nums[j] and abs(i - j) <= k.

#include<bits/stdc++.h>
using namespace std;


  bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        int n=nums.size();
        for(int i=0;i<nums.size();i++) {
            if(mp.find(nums[i])!=mp.end()){
                if(abs(i-mp[nums[i]]) <= k) return true;
            }
            mp[nums[i]]=i;
        
        }
        return false;
    }
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    if(containsNearbyDuplicate(nums,k)) cout<<"True";
    else cout<<"False";
}