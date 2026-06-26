#include<bits/stdc++.h>
using namespace std;

// find the kth element of 2 sorted arrays, tc: O(log(min(n,m))), sc: O(1)

// find the kth element of 2 sorted arrays, tc: O(log(min(n,m))), sc: O(1)
int kthElement(vector<int> &a, vector<int> &b, int k) {
        /*
        why l and h are set to max(0,k-n2) and min(n1,k) respectively?eg:
        a=[1,3,5], b=[2,4,6], k=4
        n1=3, n2=3
        l=max(0,4-3)=1, h=min(3,4)=3
        This means we are considering at least 1 element from a and at most 3 elements
        from a to find the kth element. This is because if we take 0 elements from a, we would need to take all k elements from b, which may not be possible if b has less than k elements. Similarly, if we take more than k elements from a, we would not have enough elements left in b to reach the kth element. Therefore, we set the lower bound to max(0,k-n2) and the upper bound to min(n1,k) to ensure that we are considering a valid range of elements from both arrays.
        */
        int n1=a.size();
        int n2=b.size();
        if(n1>n2) return kthElement(b,a,k);
        int l=max(0,k-n2),h=min(n1,k); int left=k;
        int n=n1+n2;
        while(l<=h){
            int mid1=(l+h)/2;
            int mid2=left-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;
            if(mid1<n1) r1=a[mid1];
            if(mid2<n2) r2=b[mid2];
            if(mid1-1>=0) l1=a[mid1-1];
            if(mid2-1>=0) l2=b[mid2-1];
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }else if(l1>r2) h=mid1-1;
            else l=mid1+1;
        }

     return 0;
    
    }



// find the peak in a matrix
  int findMaxIndex(vector<vector<int>>&arr,int r,int c,int mid){
        int maxx=-1; int index=-1;
        for(int i=0;i<r;i++){
            if(arr[i][mid]>maxx){
                maxx=arr[i][mid];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r=mat.size();int c=mat[0].size();

        int l=0;int h=c-1;
        while(l<=h){
            int mid=(l+h)/2;
            int maxIndex=findMaxIndex(mat,r,c,mid);
            int left=mid-1 >= 0? mat[maxIndex][mid-1]:-1;
            int right=mid+1<c?mat[maxIndex][mid+1]:-1;
            if(mat[maxIndex][mid]>left && mat[maxIndex][mid]>right) return {maxIndex,mid};
            else if(mat[maxIndex][mid]<left)h=mid-1;
            else l=mid+1;

        }
        return {-1,-1};
    }// tc: O(rlogc), sc: O(1)










    int main (){
    // -- Kth Element of Two Sorted Arrays ---
    vector<int> nums1 = {1, 3}; 
    vector<int> nums2 = {2};
    cout << "Kth element of the two sorted arrays: " << kthElement(nums1, nums2, 2) << endl;

    // --- Find Peak Element in a Matrix ---
    vector<vector<int>> matrix = {
        {1, 4, 3},
        {6, 5, 2},
        {7, 8, 9}
    };
    vector<int> peak = findPeakGrid(matrix);
    cout << "Peak element in the matrix: " << matrix[peak[0]][peak[1]] << endl;
    return 0;
}