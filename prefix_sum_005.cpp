//PIVOT INDEX OR EQUILIBRIUM POINT IN AN ARRAY


// Given an array of integers nums, calculate the pivot index of this array.

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

// Return the leftmost pivot index. If no such index exists, return -1


#include<bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total=nums[0];
        for(int i=1;i<n;i++) total+=nums[i];

        int leftsum=0;

        for(int i=0;i<n;i++){
            total-=nums[i];
            if(total ==leftsum) return i;
            leftsum+=nums[i];
        }

        return -1;
}

// Given an array of integers nums, return an array answer such that answer[i] is equal to the absolute 
// difference between the sum of the elements to the left of i and the sum of the elements to the right of i.
vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>rps(nums.size());
        int n=nums.size();
        rps[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--) {
            rps[i]=rps[i+1]+nums[i];
        }

        vector<int>ans(n);
        int lps=0;
        for(int i=0;i<n;i++){
                lps+=nums[i];
                ans[i]=abs(lps-rps[i]);
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

    cout<<"The pivot index is: "<<pivotIndex(nums)<<endl;
    vector<int> ans=leftRightDifference(nums);
    cout<<"The left right difference array is: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}