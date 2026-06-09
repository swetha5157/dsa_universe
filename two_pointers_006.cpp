// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

// Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

// The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

#include<bits/stdc++.h>
using namespace std;

 int removeDuplicates(vector<int>& nums) {
        int i=1,j=1;
        int n=nums.size();
        if (n==0) return 0;
        while(i<n && j<n){
            if(nums[j]==nums[i-1]){
                j++;
            } else {
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k=removeDuplicates(nums);
    cout<<"Length of the array after removing duplicates is "<<k<<endl;
    cout<<"The array after removing duplicates is ";
    for(int i=0;i<k;i++){
        cout<<nums[i]<<" ";
    }
}