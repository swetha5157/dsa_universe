#include<bits/stdc++.h>
using namespace std;


// union of two arrays
vector<int> unionOfArrays(vector<int>& a, vector<int>& b) {
    unordered_set<int> s;
    for (int num : a) s.insert(num);
    for (int num : b) s.insert(num);
    return vector<int>(s.begin(), s.end());
} // tc: O(n+m), sc: O(n+m)

// optimal approach when arrays are sorted: two pointers, tc: O(n+m), sc: O(1) if we don't count the output array
vector<int> unionOfSortedArrays(vector<int>& a, vector<int>& b) {
    vector<int> res;
    int i=0, j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            if(res.empty() || res.back()!=a[i]) res.push_back(a[i]);
            i++;
        }
        else if(a[i]>b[j]){
            if(res.empty() || res.back()!=b[j]) res.push_back(b[j]);
            j++;
        }
        else{
            if(res.empty() || res.back()!=a[i]) res.push_back(a[i]);
            i++; j++;
        }
    }
    while(i<a.size()){
        if(res.empty() || res.back()!=a[i]) res.push_back(a[i]);
        i++;
    }
    while(j<b.size()){
        if(res.empty() || res.back()!=b[j]) res.push_back(b[j]);
        j++;
    }
    return res;

    /* sample iteration 
    a=[1,2,3,4,5] b=[1,2,3,6,7]
    i=0,j=0 res=[]
    a[i]=1,b[j]=1 res=[1] i=1,j=1
    a[i]=2,b[j]=2 res=[1,2] i=2,j=2
    a[i]=3,b[j]=3 res=[1,2,3] i=3,j=3
    a[i]=4,b[j]=6 res=[1,2,3,4] i=4,j=3
    a[i]=5,b[j]=6 res=[1,2,3,4,5] i=5,j=3
    // outer while loop starts for j , outer loop for i ends as index reached end of array
    i=5,j=3 res=[1,2,3,4,5,6] j=4
    i=5,j=4 res=[1,2,3,4,5,6,7] j=5 
    // both loops end, final res=[1,2,3,4,5,6,7]
    */
} // tc: O(n+m), sc: O(1) if we don't count the output array
// if we count the output array, sc is O(n+m) in worst case when there are no common elements and all elements are unique in both arrays

// merge sorted arrays leetcode no extra space, tc: O(n+m), sc: O(1)
// array a size m+n, first m elements are valid, array b size n, all n elements are valid
void mergeSortedArrays(vector<int>& a, int m, vector<int>& b, int n) {
    int i=m-1, j=n-1, k=m+n-1;
    while(i>=0 && j>=0){
        if(a[i]>b[j]){
            a[k]=a[i];
            i--; k--;
        }
        else{
            a[k]=b[j];
            j--; k--;
        }
    }
    while(j>=0){
        a[k]=b[j];
        j--; k--;
    }
} // tc: O(n+m), sc: O(1)

// intersection of tw oarrays(non sorted)

vector<int> intersectionOfArrays(vector<int>& a, vector<int>& b) {
    unordered_set<int> s(a.begin(), a.end());
    vector<int> res;
    for (int num : b) {
        if (s.count(num)) {
            res.push_back(num);
            s.erase(num); // to avoid duplicates in result
        }
    }
    return res;
} // tc: O(n+m), sc: O(n) for the set

// using sort+ two pointers :  tc: O(nlogn + mlogm), sc: O(1)
vector<int> intersectionOfArraysUsingTwoPointers(vector<int>& a, vector<int>& b) {
    vector<int> res;
    int i=0, j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]) i++;
        else if(a[i]>b[j]) j++;
        else{
            if(res.empty() || res.back()!=a[i]) res.push_back(a[i]);

            //if duplicates have to be skipped use below 2 lines
            while(i<a.size() && a[i]==res.back()) i++; // skip duplicates in a
            while(j<b.size() && b[j]==res.back()) j++; // skip duplicates in b

            i++; j++;
        }
    }
    return res;
} // tc: O(nlogn + mlogm), sc: O(1) if we don't count the output array

// remove duplicates from sorted array 
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        // tc: o(n logn) sc: o(n);
        // set<int>s(arr.begin(),arr.end());
        // return vector<int>(s.begin(),s.end());
        
        
        //tc:o(n) sc o(1)
        vector<int>res;
        res.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            if(res.back()!=arr[i]) res.push_back(arr[i]);
        }
        
        return res;
        
    }

// kth element of 2 sorted arrays
//two pointers approach: tc: O(k), sc: O(1)
  int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int i=0, j=0,cnt=0;
        
        int as=a.size();int bs=b.size();
        
        while(i<as && j<bs){
            int curr=0;
            if(a[i]<b[j]){
                curr=a[i];i++;cnt++;
            }else{
                curr=b[j];j++;cnt++;
            }
            if(cnt==k) return curr;
        }
        while(i < as){
    cnt++;
    if(cnt == k) return a[i];
    i++;
}

while(j < bs){
    cnt++;
    if(cnt == k) return b[j];
    j++;
}
return -1;

}

// longest subarray with sum k
 int longestSubarray(vector<int>& arr, int k) {
         int presum=0;
        int ans=0;
        unordered_map<int,int>mp; // sum, i
        mp[0]=-1;
        
        for(int i=0;i<arr.size();i++){
            presum+=arr[i];
            
            if(mp.find(presum-k)!=mp.end())
             ans=max(ans,i-mp[presum-k]);
            if(mp.find(presum) == mp.end())
             mp[presum]=i;
        }
        return ans;
        
    }
// trapping rain water
// hint - left max, right max, water trapped at i = min(leftmax,rightmax) - height[i]
// cumulative i sum gives ans

// why we need to subtract height[i] from min(leftmax,rightmax) ?
// because the water can only be trapped above the height of the current bar.
/*
The Mental Model

At every index:

Step 1:
Find tallest wall on left

Step 2:
Find tallest wall on right

Step 3:
Smaller wall decides maximum water level

Step 4:
Remove the space already occupied by the barx
*/
int trap(vector<int>& arr) {
 int n=arr.size();
        vector<int> lm(n);
        int c=0;
        lm[0]=arr[0];
        for(int i=1;i<n;i++){
            lm[i]=max(lm[i-1],arr[i]);
        }
        vector<int> rm(n);
        rm[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rm[i]=max(rm[i+1],arr[i]);
        }
        for(int i=0;i<n;i++){
            c+=max(0,min(lm[i],rm[i])-arr[i]);
        }
        return c;
}

// maximum subarray sum when negative numbers are also present, kadane's algorithm, tc: O(n), sc: O(1)
//using prefix sum and hashing, tc: O(n), sc: O(n)
int maxSubarraySum(vector<int>& arr) {
        int presum=0; int maxsum=INT_MIN;
        unordered_map<int,int>mp; // sum, i
        mp[0]=-1;
        
        for(int i=0;i<arr.size();i++){
            presum+=arr[i];
            
            if(mp.find(presum)!=mp.end())
             maxsum=max(maxsum,presum);
            if(mp.find(presum) == mp.end())
             mp[presum]=i;
        }
        return maxsum;
} // tc: O(n), sc: O(n) 

// tc: O(n), sc: O(1) 
// kadane's algorithm - if current sum becomes negative, reset it to 0, as negative sum will not contribute to maximum sum in future
int maxSubarraySumKadane(vector<int>& arr) {
        int maxsum=INT_MIN; int currsum=0;
        for(int i=0;i<arr.size();i++){
            currsum+=arr[i];
            maxsum=max(maxsum,currsum);
            if(currsum<0) currsum=0;
        }
        return maxsum;
    }
//  maximum subarray return the subarray also
vector<int> maxSubarray(vector<int>& arr) {
        int maxsum=INT_MIN; int currsum=0;
        int start=0, end=0, s=0;
        for(int i=0;i<arr.size();i++){
            currsum+=arr[i];
            if(currsum>maxsum){
                maxsum=currsum;
                start=s;
                end=i;
            }
            if(currsum<0){
                currsum=0;
                s=i+1; // potential start of next subarray
            }
        }
        return vector<int>(arr.begin()+start, arr.begin()+end+1);
    }

int main(){
    cout << "======= Union of Two Arrays ======= " << endl;
    vector<int> a = {1, 22, 343, 14, 5};
    vector<int> b = {1099, 21, 3232, 6,71, 712};
    vector<int> result = unionOfArrays(a, b);
    cout << "Union of the two arrays is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    cout << "======= Union of Two Sorted Arrays ======= " << endl;
    vector<int> aa = {1, 2, 3, 4, 5};
    vector<int> bb = {1, 2, 3, 6, 7};
    vector<int> sortedResult = unionOfSortedArrays(aa, bb);
    cout << "Union of the two sorted arrays is: ";
    for (int num : sortedResult) {
        cout << num << " ";
    }
    cout << endl;

    cout << "======= Merge Two Sorted Arrays without Extra Space ======= " << endl;
    vector<int> aaa = {1, 2, 3, 0, 0, 0}; // size m+n=6, first m=3 elements are valid
    vector<int> bbb = {2, 5, 6}; // size n=3, all n elements are valid
    mergeSortedArrays(aaa, 3, bbb, 3);
    cout << "Merged array is: ";
    for (int num : aaa) {
        cout << num << " ";
    }
    cout << endl;

    cout << "======= Intersection of Two Arrays ======= " << endl;
    vector<int> c = {1, 2, 3, 4, 5};
    vector<int> d = {3, 4, 5, 6, 7};
    vector<int> intersectionResult = intersectionOfArrays(c, d);
    //vector<int> intersectionResult = intersectionOfArraysUsingTwoPointers(c, d);
    cout << "Intersection of the two arrays is: ";
    for (int num : intersectionResult) {
        cout << num << " ";
    }
    cout << endl;

    cout << "======= Remove Duplicates from Sorted Array ======= " << endl;
    vector<int> e = {1, 1, 2, 2, 3, 4, 4, 5};
    vector<int> noDuplicates = removeDuplicates(e);
    cout << "Array after removing duplicates: ";
    for (int num : noDuplicates) {
        cout << num << " ";
    }
    cout << endl;

    cout << "======= Kth Element of Two Sorted Arrays ======= " << endl;
    vector<int> f = {1, 3, 5};
    vector<int> g = {2, 4, 6};
    int k = 4;
    int kthElementResult = kthElement(f, g, k);
    cout << "The " << k << "th element of the two sorted arrays is:" << kthElementResult << endl;


    cout << "======= Longest Subarray with Sum K ======= " << endl;
    vector<int> h = {1, 2, 3, 4, 5};
    int k_sum = 5;
    int longestSubarrayResult = longestSubarray(h, k_sum);
    cout << "The length of the longest subarray with sum " << k_sum << " is: " << longestSubarrayResult << endl;

    cout << "======= Trapping Rain Water ======= " << endl;
    vector<int> water = {3, 0, 2, 0, 4};
    int trapResult = trap(water);
    cout << "The amount of water that can be trapped is: " << trapResult << endl;

    cout << "======= Maximum Subarray Sum ======= " << endl;
    vector<int> i = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSubarraySumResult = maxSubarraySum(i);
    cout << "The maximum subarray sum is: " << maxSubarraySumResult << endl;

    cout << "======= Maximum Subarray Sum (Kadane's Algorithm) ======= " << endl;
    int maxSubarraySumKadaneResult = maxSubarraySumKadane(i);
    cout << "The maximum subarray sum (Kadane's Algorithm) is: " << maxSubarraySumKadaneResult << endl;

    cout << "======= Maximum Subarray ======= " << endl;
    vector<int> maxSubarrayResult = maxSubarray(i);
    cout << "The maximum subarray is: ";
    for (int num : maxSubarrayResult) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}