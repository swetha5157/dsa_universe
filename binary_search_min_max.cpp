#include<bits/stdc++.h>
using namespace std;

// reusable functions common
 int findMin(vector<int> & arr){
        int minn=INT_MAX;
        for(int i=0;i<arr.size();i++){
            minn=min(minn,arr[i]);
        }
        return minn;
    }
int findMax(vector<int> & arr){
        int maxx=INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxx=max(maxx,arr[i]);
        }
        return maxx;
    } 


// aggressive cows
// max of minimum distance between cows
bool CanwePlace(vector<int>& arr,int mid, int k){
        int cnt=1, lastPlaced=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-lastPlaced>=mid) {cnt++; lastPlaced=arr[i];}
                    if(cnt>=k) return true;
        }
        return false;
    }
int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int l=1,h=stalls[n-1]-stalls[0]; int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(CanwePlace(stalls,mid,k)==true){
                ans=mid;
                l=mid+1;
            }else h=mid-1;
        }
        return ans;
    }

// min book allocation problem
int studentsCount(vector<int>&arr,int mid, int k){
    int students=1; long long  pages=0; 
    for(int i=0;i<arr.size();i++){
        if(pages+arr[i]>mid) {
            students++;
            pages=arr[i];
        }else{
            pages+=arr[i];
        }
    }
    return students;
     
}

int findPages(vector<int> &arr, int k) {
        // code here
        if(k>arr.size()) return -1;// when students>no of books
        int l=findMax(arr); int h=accumulate(arr.begin(),arr.end(),0);int ans=0;
        while(l<=h){
            int mid=(l+h)/2; 
            int students=studentsCount(arr,mid,k);
            if(students<=k){ans=mid; h=mid-1;} // reduce the max pages student can have 
            else{ // more book is left to be allocated
            l=mid+1;
                
            } 
        }
       return ans; 
    }

/*
SIMILAR QUESTIONS AS MIN ALLCATION PROBLEM:
1. PAINTERS PARTITION PROBLEM
2.SPLIT ARRAY LARGEST SUM

*/

//median of 2 sorted arrays of different sizes
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int l=0,h=n1; int left=(n1+n2+1)/2;
        int n=n1+n2;
        while(l<=h){
            int mid1=(l+h)/2;
            int mid2=left-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];
            if(l1<=r2 && l2<=r1){
                if(n%2==1) return max(l1,l2);
                return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
            }else if(l1>r2) h=mid1-1;
            else l=mid1+1;
        }

     return 0;   
    }


int main(){
    // --- Aggressive Cows ---
    vector<int> stalls = {1, 2, 8, 4, 9};
    int k = 3;
    cout << "Maximum distance between cows: " << aggressiveCows(stalls, k) << endl;
   
    // --- Min Book Allocation Problem ---
    vector<int> books = {12, 34, 67, 90};
    int students = 2;
    cout << "Minimum number of pages allocated to a student: " << findPages(books, students) << endl;



   


    return 0;
}