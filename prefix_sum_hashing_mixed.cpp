#include<bits/stdc++.h>
using namespace std;


int subarraySumEqualsK(vector<int>& nums, int k) {
     unordered_map<int,int> mp;
     int presum=0;

     int cnt=0;

     mp [0] = 1;
     for(int i=0;i<nums.size();i++){
        presum+=nums[i];
        cnt+=mp[presum-k];
        mp[presum]++;
     }

     return cnt;
}

int binarySubarraysWithSumK(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
     int presum=0;

     int cnt=0;

     mp [0] = 1;
     for(int i=0;i<nums.size();i++){
        presum+=nums[i];
        cnt+=mp[presum-k];
        mp[presum]++;
     }

     return cnt;
}


vector<int> distinctDifferenceArray(vector<int>& nums) {
       int n = nums.size();

        vector<int> prefix(n), suffix(n), ans(n);

        unordered_set<int> st;

        // Prefix distinct count
        for(int i = 0; i < n; i++) {
            st.insert(nums[i]);
            prefix[i] = st.size();
        }

        st.clear();

        // Suffix distinct count
        // suffix[i] = distinct elements from i+1 to n-1
        suffix[n-1] = 0;

        st.insert(nums[n-1]);

        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = st.size();
            st.insert(nums[i]);
        }

        // Build answer
        for(int i = 0; i < n; i++) {
            ans[i] = prefix[i] - suffix[i];
        }

        return ans;
    }

//contiguous array - longest subarray with equal number of 0s and 1s
//since this is longest subarray finding store difference, index in map
//consider 0 as -1 and 1 as +1 and do the subarray sum logic while storeing store the least indes possible and dont change once found
//k=0 since we want equal number of 0s and 1s
int findMaxLength(vector<int>& nums) {
       int presum=0; int k=0;
       unordered_map<int,int> mp;int cnt=0;
       mp[0]=-1;
       for(int i=0;i<nums.size();i++){
            if(nums[i]==0) presum+=-1;
            else presum+=nums[i];        
            if(mp.find(presum)!=mp.end()) cnt=max(cnt, i-mp[presum-k]);
            else mp[presum]=i;
       }
       return cnt;
}


//Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

// A good subarray is a subarray where:

// its length is at least two, and
// the sum of the elements of the subarray is a multiple of k.
// Note that:

// A subarray is a contiguous part of the array.
// An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.


bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0; int presum=0;
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int remainder=presum%k;
            if(mpp.find(remainder)!=mpp.end()) {
            if(i-mpp[remainder]>=2)return true;
            }
            else  mpp[remainder]=i;
        }
        return false;
    }

  int subarraysDivByK(vector<int>& nums, int k) {
         int n=nums.size();
        int cnt=0; int presum=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int remainder=presum%k;
            if(remainder<0) remainder+=k;
            cnt+=mpp[remainder];
            mpp[remainder]++;
        }
        return cnt;
    }

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;

    //--< subarray sum equals k >--
   
    cout <<"Subarray sum equals k: " << subarraySumEqualsK(a, k) << endl;

    //--< binary subarrays with sum k >--
    cout<<"Binary subarray with sum k: "<<" "<< binarySubarraysWithSumK(a, k) <<endl;

    //--< distinct difference array >--
    vector<int> ans=distinctDifferenceArray(a);
    cout<<"The distinct difference array is: ";

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;

    //--< longest subarray with equal number of 0s and 1s >--
    cout<<"Longest subarray with equal number of 0s and 1s: "<<findMaxLength(a)<<endl;


    //--< continuous subarray sum with k and length is atleast 2 >--
    cout<<"Continuous subarray sum with k and length at least 2: "<<checkSubarraySum(a, k)<<endl;

    //--< subarrays divisible by k >--
    cout<<"Subarrays divisible by k: "<<subarraysDivByK(a, k)<<endl;

    


}