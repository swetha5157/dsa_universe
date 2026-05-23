// Given an integer array nums, return true if any value 
//appears at least twice in the array, and return false if 
// every element is distinct.

#include<bits/stdc++.h>
using namespace std;

    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int v:nums) mp[v]++;

        for(auto x:mp){
             if (x.second>1)
              return true;
        }
        return false;
    }
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    if(containsDuplicate(nums)) cout<<"True";
    else cout<<"False";
}