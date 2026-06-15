#include<bits/stdc++.h>
using namespace std;

// duplicate number with O(1) space
// floyd's tortoise and hare algorithm
int findDuplicateFloyd(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];
    // first phase
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // second phase
    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}


// duplicate numbers in an array 
//size n , indices 0 to n-1
vector<int> findDuplicates(vector<int>& arr) {
         int n=arr.size();
         vector<int>res;
        for(int num:arr){
            int ind=abs(num)-1;
            if(arr[ind]<0) res.push_back(ind+1);

            arr[ind]=-arr[ind];
        }
        return res;
        
 }


// first repeating element in an array
// Given an array arr[], find the first repeating element index. 
// The element should occur more than once and the index of its first occurrence should be the smallest.
// Note:- The position you return should be according to 1-based indexing. 
int firstRepeating(vector<int>& arr) {
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    for(int i=0;i<arr.size();i++){
        if(mp[arr[i]]>1) return i+1; // 1-based indexing
    }
    return -1;
}

// two sum return the indices of the pairs
vector<int> twosum(vector<int>&nums, int target){
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        if(mp.find(nums[i]) != mp.end()){
            return {mp[nums[i]], i};
        }
        mp[target-nums[i]] = i;
    }
    return {-1,-1}; // no pair found
}

// three sum return the triplets there may be multiple triplets return all
vector<vector<int>> threeSum(vector<int>& nums , int target){
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for(int i=0;i<nums.size()-2;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int l=i+1;int r=nums.size()-1;
        while(l<r){
            int sum = nums[i]+nums[l]+nums[r];
            if(sum==target){
                res.push_back({nums[i], nums[l], nums[r]});
                while(l<r && nums[l]==nums[l+1]) l++;
                while(l<r && nums[r]==nums[r-1]) r--;
                l++;r--;
            }
            else if(sum<target) l++;
            else r--;
        }
    }
    return res;
}


// four sum 
 vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r) {
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1])
                            l++;
                        while (l < r && nums[r] == nums[r - 1])
                            r--;
                        l++;
                        r--;
                    } else if (sum < target)
                        l++;
                    else
                        r--;
                }
            }
        }
        return res;
    }


// count distinct triplets such that arr[c]=arr[a]+arr[b], any order of a,b,c
int countTriplet(vector<int>& arr) {
		// code here
		sort(arr.begin(), arr.end());
		// Code Here
		int n = arr.size(); int cnt = 0;
		for (int i = n - 1; i >= 2; i--) {
		     if(i < n-1 && arr[i] == arr[i+1])
            continue; // skip duplicate elements to avoid counting the same triplet multiple times
			
			int l = 0; int r = i - 1;
			
			while (l<r) {
				long long sum = arr[l]+arr[r];
				
				if (sum == arr[i]) {
					cnt++;
					while (l<r && arr[l] == arr[l + 1])
						l++; // skip duplicate elements to avoid counting the same triplet multiple times
					while (l<r && arr[r] == arr[r - 1])
						r--; // skip duplicate elements to avoid counting the same triplet multiple times
					
					l++;
					r--;
					
				}
				else if (sum<arr[i])
					l++;
				else
					r--;
			}
			
		}
		return cnt;
	}


int main(){
    cout << "======= Find Duplicate Number in an Array using Floyd's Tortoise and Hare Algorithm ======= " << endl;
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << findDuplicateFloyd(nums) << endl;

    cout << "======= Find Duplicate Numbers in an Array ======= " << endl;
    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1}; // Duplicate numbers are 2 and 3
    vector<int> duplicates = findDuplicates(arr);
    cout << "Duplicate numbers are: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;

    cout << "======= Find First Repeating Element ======= " << endl;
    vector<int> arr2 = {1, 5, 3, 4, 3, 5, 6};
    cout << firstRepeating(arr2) << endl;

    cout << "======= Two Sum ======= " << endl;
    vector<int> arr3 = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twosum(arr3, target);
    if (result[0] != -1) {
        cout << "Indices of the two numbers that add up to " << target << " are: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two numbers add up to " << target << endl;
    }

    cout << "======= Three Sum ======= " << endl;
    vector<int> arr4 = {-1, 0, 1, 2, -1, -4};
    int target2 = 0;
    vector<vector<int>> triplets = threeSum(arr4, target2);
    cout << "Triplets that add up to " << target2 << " are: " << endl;
    for (const auto& triplet : triplets) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    cout<< endl;



    cout << "======= Four Sum ======= " << endl;
    vector<int> arr5 = {1, 0, -1, 0, -2, 2};
    int target3 = 0;
    vector<vector<int>> quadruplets = fourSum(arr5, target3);
    cout << "Quadruplets that add up to " << target3 << " are: " << endl;
    for (const auto& quadruplet : quadruplets) {
        cout << "[" << quadruplet[0] << ", " << quadruplet[1] << ", " << quadruplet[2] << ", " << quadruplet[3] << "]" << endl;
    }
    cout<< endl;

    cout << "======= Count Distinct Triplets such that arr[c]=arr[a]+arr[b] ======= " << endl;
    vector<int> arr6 = {1, 2, 3, 4, 5};
    cout << countTriplet(arr6) << endl;

    

    return 0;
}