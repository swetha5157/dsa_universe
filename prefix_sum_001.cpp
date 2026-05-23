// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

// Return the running sum of nums.

#include<bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
        vector<int>ans(nums.size());
        ans[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            ans[i] = ans[i-1]+nums[i];
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
    vector<int> ans=runningSum(nums);
    cout<<"The running sum of the array is ";   
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}