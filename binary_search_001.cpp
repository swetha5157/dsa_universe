#include <bits/stdc++.h>
using namespace std;

// Search in a Sorted Array
// TC: O(log n), SC: O(1)
bool binarySearch(vector<int> &arr, int k)
{
    int l = 0, r = arr.size() - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == k)
            return true;
        else if (arr[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return false;
}

// Find Floor (largest element <= x)
// Returns index of last occurrence of floor value
// TC: O(log n), SC: O(1)
int findFloor(vector<int> &arr, int x)
{
    int l = 0, r = arr.size() - 1;
    int ind = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] <= x)
        {
            ind = mid;
            l = mid + 1; // search right for a larger valid floor
        }
        else
        {
            r = mid - 1;
        }
    }

    return ind;
}




// Find Ceil (smallest element >= x)
// Returns index of first occurrence of ceil value
// TC: O(log n), SC: O(1)
int findCeil(vector<int> &arr, int x)
{
    int l = 0, r = arr.size() - 1;
    int ind = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] >= x)
        {
            ind = mid;
            r = mid - 1; // search left for an earlier valid ceil
        }
        else
        {
            l = mid + 1;
        }
    }

    return ind;
}


// find first and last occurrence of an element in a sorted array using binary search
// TC: O(log n), SC: O(1)
vector<int> find(vector<int>& arr, int x) {
        // code here
        int n=arr.size(); int l=0,r=n-1;
        int first=-1,last=-1; int sl=0,sr=n-1;
        
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]==x){
                first=mid;r=mid-1;
            }else if(arr[mid]<x){
                l=mid+1;
            }else r=mid-1;
        }
        while(sl<=sr){
            int mid=(sl+sr)/2;
            if(arr[mid]==x){
                last=mid;sl=mid+1;
            }else if(arr[mid]<x){
                sl=mid+1;
            }else sr=mid-1;
        }
        
        return {first,last};
        
    }

// search in a rotated sorted array without duplicates
// TC: O(log n), SC: O(1)
int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[l]){
                if(nums[mid]>=target && nums[l]<=target) r=mid-1;
                else l=mid+1;
            } else {
                if(nums[mid]<=target && nums[r]>=target) l=mid+1;
                else r=mid-1; 
            }
        }
        return -1;
    }

// search in a rotated sorted array with duplicates
// TC: O(log n) in average case, O(n) in worst case, SC: O(1)
int searchWithDuplicates(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>nums[l]){
                if(nums[mid]>=target && nums[l]<=target) r=mid-1;
                else l=mid+1;
            } else if(nums[mid]<nums[l]){
                if(nums[mid]<=target && nums[r]>=target) l=mid+1;
                else r=mid-1; 
            } else {
                l++;
            }
        }
        return -1;
    }

// find the peak element in a mountain array, tc: O(log n), sc: O(1)
// return index of the peak element
int peakElement(vector<int> &arr) {
        // code here
        int n=arr.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(arr[mid]>arr[mid+1]){
                // we are in the decreasing part of the array, so the peak element is in the left half (including mid)
                r=mid;
            }else l=mid+1;
        }
        return l;
    }

// search in a bitonic array
// bitonic array is an array which is first increasing and then decreasing
// tc: O(log n), sc: O(1)

int firstBS(vector<int>&arr,int l,int r,int x){
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]<x){
            l=mid+1;
        }else r=mid-1;
    }
    return -1;
}
int secondBS(vector<int>&arr,int l,int r,int x){
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]<x){
            r=mid-1;
        }else l=mid+1;
    }
    return -1;
}
int findInBitonic(vector<int> &A, int B) {
    // first find peak
    int n=A.size();
    int peakInd= peakElement(A);
    
    // find from ind 0 to peak using binary search
    
    int indone=firstBS(A,0,peakInd,B);
    
    if(indone !=-1) return indone;
    
    //if no index from 1st binary search next search from peak+1 to last index
    
    return secondBS(A,peakInd+1,n-1,B);
     
}
// find the min number in a rotated sorted array, tc: O(log n), sc: O(1)
//same question: sorted and rotated minimum
int minNumber(int arr[], int low, int high) {
        // Your code here
        int res=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            res=res<arr[mid]?res:arr[mid];
            if(arr[mid]<arr[high]) high=mid-1; // if mid element is less than high element then the minimum element is in the left half (including mid)
            else low=mid+1;
        }
        return res;

        /*
        how minnumber is different from normal BINARY SEARCH?
        1. In normal binary search we are looking for a specific element, but in min
        number we are looking for the minimum element in a rotated sorted array.
        2. In normal binary search we are comparing the mid element with the target element, but in min number we are comparing the mid element with the high element.
        3. In normal binary search we are moving the left or right pointer based on the comparison, but in min number we are moving the left or right pointer based on the comparison with the high element.
        4. In normal binary search we are returning the index of the target element, but in min number we are returning the minimum element.
        interview level mind model to remember:
        1. If mid element is less than high element, then the minimum element is in the left half (including mid).
        2. If mid element is greater than high element, then the minimum element is in
    the right half (excluding mid).
        */
    }

// sorted and rotated maximum element
// tc: O(log n), sc: O(1)
int maxNumber(int arr[], int low, int high) {
        // Your code here
        int res=INT_MIN;
        while(low<=high){
            int mid=low + (high - low ) / 2; // to avoid infinite loop when low and high are adjacent
            res=res>arr[mid]?res:arr[mid];
            if(arr[mid]>=arr[low]) low=mid+1; // if mid element is less than high element then the minimum element is in the left half (including mid)
            else high=mid-1;
        }
        return res;
    }

// find the number of rotations happened in a sorted rotated array
// find the index of the min element to find the number of rotations
 int findKRotation(vector<int> &arr) {
       int res=INT_MAX; int ans=-1; int n=arr.size();
       int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]<res){res=arr[mid];ans=mid;}
            if(arr[mid]<arr[high]) high=mid-1; // if mid element is less than high element then the minimum element is in the left half (including mid)
            else low=mid+1;
        }
        return ans;
    }

int main()
{

    cout << "======= Search in a Sorted Array =======" << endl;

    vector<int> arr = {1, 2, 3, 5, 5, 8, 8, 9, 10};

    int k = 5;

    if (binarySearch(arr, k))
        cout << "Element " << k << " found in the array." << endl;
    else
        cout << "Element " << k << " not found in the array." << endl;

    cout << "\n======= Find Floor and Ceil =======" << endl;

    int x = 7;

    int floorIndex = findFloor(arr, x);
   
    int ceilIndex = findCeil(arr, x);

    if (floorIndex != -1)
        cout << "Floor of " << x << " = "
             << arr[floorIndex]
             << " at index " << floorIndex << endl;
    else
        cout << "No floor found" << endl;
 

    if (ceilIndex != -1)
        cout << "Ceil of " << x << " = "
             << arr[ceilIndex]
             << " at index " << ceilIndex << endl;
    else
        cout << "No ceil found" << endl;

    cout << "\n======= Find First and Last Occurrence of an Element =======" << endl;
    int target = 8;
    vector<int> occurrences = find(arr, target);
    if (occurrences[0] != -1)
        cout << "First occurrence of " << target << " is at index " << occurrences[0] << endl;
    else
        cout << "Element " << target << " not found in the array." << endl;

    if (occurrences[1] != -1)
        cout << "Last occurrence of " << target << " is at index " << occurrences[1] << endl;
    else
        cout << "Element " << target << " not found in the array." << endl;
    
    cout << "\n======= Search in a Rotated Sorted Array =======" << endl;
    vector<int> rotatedArr = {4, 5, 6, 7, 0, 1, 2};
    int rotatedTarget = 0;
    cout << "Searching for " << rotatedTarget << " in the rotated sorted array." << endl;
    int rotatedIndex = search(rotatedArr, rotatedTarget);
    if (rotatedIndex != -1)
        cout << "Element " << rotatedTarget << " found at index " << rotatedIndex << endl;
    else
        cout << "Element " << rotatedTarget << " not found in the array." << endl;
    
    cout << "\n======= Search in a Rotated Sorted Array with Duplicates =======" << endl;
    vector<int> rotatedArrWithDuplicates = {2, 5, 6, 0, 0, 1, 2};
    int rotatedTargetWithDuplicates = 0;
    cout << "Searching for " << rotatedTargetWithDuplicates << " in the rotated sorted array with duplicates." << endl;
    int rotatedIndexWithDuplicates = searchWithDuplicates(rotatedArrWithDuplicates, rotatedTargetWithDuplicates);
    if (rotatedIndexWithDuplicates != -1)
        cout << "Element " << rotatedTargetWithDuplicates << " found at index " << rotatedIndexWithDuplicates << endl;
    else
        cout << "Element " << rotatedTargetWithDuplicates << " not found in the array." << endl;

    cout << "\n======= Find Peak Element in a Mountain Array =======" << endl;
    vector<int> mountainArr = {1, 3, 5, 7, 6, 4, 2};
    int peakIndex = peakElement(mountainArr);
    cout << "Peak element is at index " << peakIndex << " with value " << mountainArr[peakIndex] << endl;

    cout << "\n======= Search in a Bitonic Array =======" << endl;
    vector<int> bitonicArr = {1, 3, 8, 12, 4, 2};
    int bitonicTarget = 4;
    int bitonicIndex = findInBitonic(bitonicArr, bitonicTarget);
    if (bitonicIndex != -1)
        cout << "Element " << bitonicTarget << " found at index " << bitonicIndex << endl;
    else
        cout << "Element " << bitonicTarget << " not found in the array." << endl;
    
    cout << "\n======= Find Minimum Number in a Rotated Sorted Array =======" << endl;
    int rotatedSortedArr[] = {5, 6, 1, 2, 3, 4};
    int low = 0;
    int high = sizeof(rotatedSortedArr) / sizeof(rotatedSortedArr[0]) - 1;
    int minElement = minNumber(rotatedSortedArr, low, high);
    cout << "Minimum element in the rotated sorted array is: " << minElement << endl;

    cout << "\n======= Find Maximum Number in a Rotated Sorted Array =======" << endl;
    int maxElement = maxNumber(rotatedSortedArr, low, high);
    cout << "Maximum element in the rotated sorted array is: " << maxElement << endl;

    cout << "\n======= Find Number of Rotations in a Rotated Sorted Array =======" << endl;
    vector<int> rotatedSortedVector = {5, 6, 1, 2, 3, 4};
    int rotations = findKRotation(rotatedSortedVector);
    cout << "Number of rotations in the rotated sorted array is: " << rotations << endl;
    
    return 0;
}