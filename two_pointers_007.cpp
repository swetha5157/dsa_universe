// Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements 
// in the subarray is strictly less than k.

#include<bits/stdc++.h>
using namespace std;


 int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int s=0,e=0;
        int prod=1;
        if(k<=1) return 0;
        int cnt=0;
        while(e<nums.size()){
            prod*=nums[e];
            while(prod>=k){
                prod/=nums[s];
                s++;
            }
            cnt+=e-s+1;
            e++;
        }
        return cnt;
    }

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"The number of subarrays with product less than k is: "<<numSubarrayProductLessThanK(nums,k)<<endl;
}