#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// majority element - appears more than n/2 times
// using hashing, tc: O(n), sc: O(n)
// topic: array, sorting, hashing, moore's voting algorithm

int majorityElement(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i : arr)
    {
        mp[i]++;
        if (mp[i] > n / 2)
            return i;
    }
    return -1; // no majority element
}

// count subarrays where one element is greater than k
//  tc: O(n), sc: O(1)
// complement counting approach -
// count total subarrays and count subarrays where all elements are less than or equal to k,
// subtract the two counts to get the count of subarrays where at least one element is greater than k
ll countSubarray(int arr[], int n, int k)
{
    // code here
    ll res = 0, len = 0;
    ll tot = (1LL * n * (n + 1)) / 2;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            len++;
        else
        {
            res += (len * (len + 1)) / 2;
            len = 0;
        }
    }
    res += (len * (len + 1)) / 2;

    return tot - res;
}
// next permutation, tc: O(n), sc: O(1)
void nextPermutation(vector<int> &nums)
{
    int ind = -1;
    int n = nums.size();
    if (n == 1)
        return;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > nums[ind])
        {
            swap(nums[i], nums[ind]);
            break;
        }
    }
    reverse(nums.begin() + ind + 1, nums.end());
    return;
}

// max product subarray, tc: O(n), sc: O(1)
// left product, right product, max product is the maximum of left product and right product at each index,
// left and right product are used by same variable curr
// if curr=0, then set curr=1;
int maxProduct(vector<int> &arr)
{
    // code here
    int maxx = INT_MIN;
    int curr = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        curr *= arr[i];
        maxx = max(maxx, curr);
        if (curr == 0)
            curr = 1;
    }

    curr = 1;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        curr *= arr[i];
        maxx = max(maxx, curr);
        if (curr == 0)
            curr = 1;
    }
    return maxx;
}

// merge intervals, tc: O(nlogn), sc: O(n)
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    res.push_back(intervals[0]);
    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= res.back()[1])
        {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
            // res.back()[1] here [1] means the end time of the last interval in res, we update it to be the maximum of the current end time and the end time of the current interval
        }
        else
        {
            res.push_back(intervals[i]);
        }
    }
    return res;
}

// sieve of eratosthenes, tc: O(nloglogn), sc: O(n)
vector<int> sieve(int n)
{
    // code here
    vector<int> res;
    vector<bool> isPrime(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {

        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            res.push_back(i);
    }
    return res;
}

int main()
{
    // ---<Majority Element in an Array>---
    cout << "======= Majority Element in an Array ======= " << endl;
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int majority = majorityElement(arr);
    if (majority != -1)
    {
        cout << "The majority element is: " << majority << endl;
    }
    else
    {
        cout << "No majority element found." << endl;
    }

    // ---<Count Subarrays where One Element is Greater than K>---
    cout << "======= Count Subarrays where One Element is Greater than K ======= " << endl;
    int n = 5;
    int arr2[] = {1, 2, 3, 4, 5};
    int k = 3;
    ll count = countSubarray(arr2, n, k);
    cout << "The number of subarrays where at least one element is greater than " << k << " is: " << count << endl;

    // ---<Next Permutation>---
    cout << "======= Next Permutation ======= " << endl;
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    cout << "The next permutation is: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    // ---<Maximum Product Subarray>---
    cout << "======= Maximum Product Subarray ======= " << endl;
    vector<int> arr3 = {2, 3, -2, 4};
    int maxProductResult = maxProduct(arr3);
    cout << "The maximum product of a subarray is: " << maxProductResult << endl;

    // ---<Merge Intervals>---
    cout << "======= Merge Intervals ======= " << endl;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = merge(intervals);
    cout << "The merged intervals are: ";
    for (const auto &interval : mergedIntervals)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    // ---<Sieve of Eratosthenes>---
    cout << "======= Sieve of Eratosthenes ======= " << endl;
    int limit = 30;
    vector<int> primes = sieve(limit);
    cout << "The prime numbers up to " << limit << " are: ";
    for (int prime : primes)
    {
        cout << prime << " ";
    }
    cout << endl;

  

    return 0;
}