#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int k=n-1;

        while(j<=k){
            if(nums[j]==0){
                swap(nums[i],nums[j]);
                i++;j++;
            }else if (nums[j]==1) j++;
            else{
                swap(nums[k],nums[j]);
                k--;
            }
        }
    }

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sortColors(nums);
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}