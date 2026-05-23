// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.


//HINT

// calculate right product in an array 

//calculate left product storing in a single variable and multiply with corresponding right product to get the answer

// lp =1 and rp[n-1]=1

#include<bits/stdc++.h>
using namespace std;

 vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>rp(n);
        rp[n-1]=1;
        vector<int>ans(n);
        for(int i=n-2;i>=0;i--){
                rp[i]=rp[i+1]*nums[i+1];
        }

        int lp=1;
        ans[0]=rp[0];
        for(int i=1;i<n;i++){
            lp *= nums[i-1];
            ans[i]=lp*rp[i];
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
    vector<int> ans=productExceptSelf(nums);
    cout<<"The product of the array except self is ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}