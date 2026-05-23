// Given an integer array nums, find the subarray with the largest sum, and return its sum.

 //eg:  [-2,1,-3,4,-1,2,1,-5,4]

 // curr = -2 1 -2 4 3 5 6 1 5
 // ans  = -2 1  1 4 4 5 6 6 6 ans =6
#include<bits/stdc++.h>
using namespace std;

 int maxSubArray(vector<int>& nums) {
        int  ans=nums[0];int curr=nums[0];

        for(int i=1;i<nums.size();i++){
            curr=max(curr+nums[i],nums[i]);
            ans=max(ans,curr);
            
        }
       
        return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<maxSubArray(nums);
}