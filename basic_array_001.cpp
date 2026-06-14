/*
==============================
FUNCTION RULE: "See Before Use"
==============================

Normal Functions:
Compiler reads TOP → DOWN.

Call a function?
→ Compiler must have SEEN it already.

Either:
1. Definition above
2. Declaration above

❌ Error

main() {
    fun();  // Compiler: "Who is fun?"
}

void fun() {}

✅ Fix

void fun(); // declaration

main() {
    fun();
}

void fun() {}

------------------------------------------------

CLASS RULE: "Class Knows Its Members"

Inside a class, all member functions are
known to each other.

class A {
public:
    void fun() {
        hello();   // Works even if hello() is below
    }

    void hello() {
        cout << "Hi";
    }
};

Mnemonic:
Normal Functions  -> "See Before Use"
Class Functions   -> "Class Already Knows"

Think:
Outside class = Stranger → Introduce first.
Inside class  = Family   → Already known.
*/

/*
C++  : Compiler says
       "Show me first, then I'll call it."

JS Function Declaration:
       "I'll remember all functions before running."

JS Arrow/Const Function:
       "No memory. Define first, then call."
*/


#include <bits/stdc++.h>
using namespace std;

// third largest element in an array
//  the condition nums[i]!=l is needed when in question they say numbers are distinct,
//  if we have duplicate largest element, we should not update second largest with the same value
//  or else remove all those conditions and we will get the second largest element even if there are duplicates

int thirdLargest(vector<int> &nums)
{
    int l, m, s;
    l = m = s = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > l)
        {
            s = m;
            m = l;
            l = nums[i];
        }
        else if (nums[i] > m && nums[i] != l)
        {
            // why need to check nums[i]!=l?
            // because if we have duplicate largest element, we should not update second largest with the same value
            s = m;
            m = nums[i];
        }
        else if (nums[i] > s && nums[i] != m && nums[i] != l)
        {
            s = nums[i];
        }
    }
    return s;
}

// second largest element in an array
// the condition nums[i]!=l is needed when in question they say numbers are distinct,
// if we have duplicate largest element, we should not update second largest with the same value
// or else remove all those conditions and we will get the second largest element even if there are duplicates
int secondLargest(vector<int> &nums)
{
    int l, s;
    l = s = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > l)
        {
            s = l;
            l = nums[i];
        }
        else if (nums[i] > s && nums[i] != l)
        {
            // why need to check nums[i]!=l?
            // because if we have duplicate largest element, we should not update second largest with the same value
            s = nums[i];
        }
    }
    return s;
}

// find missing number in an array of size n containing numbers from 1 to n
int findMissingNumber(vector<int> &nums)
{
    int n = nums.size() + 1;
    // arr=[1,2,4,5], sum=1+2+4+5=12
    // if n=nums.size(), then n=4, original sum=1+2+3+4=10, missing number=10-12=-2 (wrong)
    // if n=nums.size()+1, then n=5, original sum=1+2+3+4+5=15, missing number=15-12=3 (correct)

    int totalSum = n * (n + 1) / 2;
    int arrSum = 0;
    for (int i : nums)
    {
        arrSum += i;
    }
    return totalSum - arrSum; // tc: O(n), sc: O(1)
}
// other approach: using XOR
int findMissingNumberXOR(vector<int> &nums)
{
    int n = nums.size() + 1;
    int xorAll = 0;
    for (int i = 1; i <= n; i++)
    {
        xorAll ^= i;
    }
    int xorArr = 0;
    for (int i : nums)
    {
        xorArr ^= i;
    }
    return xorAll ^ xorArr; // tc: O(n), sc: O(1)
    // Iterations: a=[1,2,4,5]
    //  n= 4+1 =5
    //  xorAll = (n%4==0) ?n: (n%4==1) ? 1 : (n%4==2) ? n+1 : 0; // xor of first n natural numbers
    //  xorAll of n=5 is 1

    // xorArr = 1^2^4^5 = 2
    // missing number = xorAll ^ xorArr = 1 ^ 2 = 3
    // This approach is based on the property of XOR operation,
    // where a number XORed with itself results in 0, and a number XORed with 0 results in the number itself.
    // By XORing all numbers from 1 to n and then XORing the result with all numbers in the array,
    // we effectively cancel out all numbers that are present in the array,
    // leaving us with the missing number.
}

// find duplicate number in an array of size n containing numbers from 1 to n, size is n+1
int findDuplicate(vector<int> &nums)
{
    // mark visied as negative
    int n = nums.size();
    for (int num : nums)
    {
        int ind = abs(num);
        if (nums[ind] < 0)
            return ind;

        nums[ind] = -nums[ind];
    }
    return n;
    /**
    iteration a=[1,3,4,2,2]
    num=1 ; ind=1; a[1]>0; a[1]=-1
    num=3; ind=3; a[3]>0; a[3]=-2
    num=4; ind=4; a[4]>0; a[4]=-2
    num=-2; ind=2; a[2]>0; a[2]=-3
    num=-2; ind=2;a[2]<0; ans=2

    */
} // tc: O(n), sc: O(1)

// if there is no n+1 and 1 to n condition, we can use hash set to find duplicate number in an array of size n containing numbers from 1 to n, size is n+1
int findDuplicateHashSet(vector<int> &nums)
{
    unordered_set<int> s;
    for (int num : nums)
    {
        if (s.count(num))
            return num;
        s.insert(num);
    }
    return -1; // no duplicate found
} // tc: O(n), sc: O(n)

// sort 012 or Dutch National Flag Problem
void sort012(vector<int> &arr)
{
    // code here
    int i = 0, j = 0;
    int k = arr.size() - 1;
    while (j <= k)
    {
        if (arr[j] == 1)
            j++;
        else if (arr[j] == 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else
        {
            swap(arr[j], arr[k]);
            k--;
        }
    }
}

// equal array or not by elements and frequency
bool checkEqual(vector<int> &a, vector<int> &b)
{

    if (a.size() != b.size())
        return false;
    unordered_map<int, int> mp;
    for (int v : a)
        mp[v]++;
    for (int v : b)
    {
        if (mp[v] == 0)
            return false;
        mp[v]--;
    }

    return true;
}

// reverse array
void rev(vector<int> &arr, int st, int end)
{
    int l = st;
    int r = end;
    while (l < r)
    {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}
// rotate array by k elements
// left rotate- counterclockwise
void rotateLeft(vector<int> &arr, int k)
{
    // code here
    int n = arr.size();
    int d = k % n;
    if (d == 0)
        return;
    rev(arr, 0, d - 1);
    rev(arr, d, n - 1);
    rev(arr, 0, n - 1);
}

// rotate array by k elements
// right rotate- clockwise
void rotateRight(vector<int> &arr, int k)
{
    // code here
    int n = arr.size();
    int d = k % n;
    if (d == 0)
        return;
    rev(arr, 0, n - 1);
    rev(arr, 0, d - 1);
    rev(arr, d, n - 1);
}


// array subset of another array
 bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        unordered_map<int,int>m;
        for(int i:a){
            m[i]++;
        }
        
        for(int j:b){
            if(m[j]==0) return false;
            else m[j]--;
        }
        return true;
}

// frequencies of elements in an array when range [1, n]
//approach 1: using hash map
 vector<int> frequencyCount(vector<int>& arr) {
        // code here
        unordered_map<int,int>mp;
        for(int v:arr) mp[v]++;
        vector<int> res; 
        int n=arr.size();
        for(int i=1;i<=n;i++){
            if(mp.find(i)!=mp.end()) res.push_back(mp[i]);
            else res.push_back(0);
        }
        return res;
    }
// approach 2: since range is [1,n] we can directly use array itself

vector<int> frequencyCountArray(vector<int>& arr) {
    int n=arr.size();
    vector<int>res(n,0);
    for(int v:arr){
        res[v-1]++;
    }
    return res;
}



int main()
{
    cout << "======= Third Largest Element in an Array ======= " << endl;
    vector<int> nums = {3, 1, 2, 5, 4, 5, 5, 6, 4};
    cout << thirdLargest(nums) << endl; // Output: 3
    cout << "======= Second Largest Element in an Array ======= " << endl;
    cout << secondLargest(nums) << endl; // Output: 4
    cout << "======= Find Missing Number in an Array ======= " << endl;
    vector<int> arr = {1, 2, 4, 5};         // Missing number is 3
    cout << findMissingNumber(arr) << endl; // Output: 3

    cout << "======= Find Missing Number in an Array using XOR ======= " << endl;
    cout << findMissingNumberXOR(arr) << endl; // Output: 3

    cout << "======= Find Duplicate Number in an Array ======= " << endl;
    vector<int> arr2 = {1, 3, 4, 2, 2};  // Duplicate number is 2
    cout << findDuplicate(arr2) << endl; // Output: 2

    cout << "======= Find Duplicate Number in an Array using Hash Set ======= " << endl;
    cout << findDuplicateHashSet(arr2) << endl; // Output: 2

    cout << "======= Sort 012 ======= " << endl;
    vector<int> arr3 = {0, 1, 2, 0, 1, 2}; // Sorted array is [0, 0, 1, 1, 2, 2]
    sort012(arr3);
    for (int num : arr3)
    {
        cout << num << " ";
    }
    cout << endl;

    // equal array or not by elements and frequency
    cout << "======= Check if Two Arrays are Equal by Elements and Frequency ======= " << endl;
    vector<int> c = {1, 2, 3, 4};
    vector<int> d = {4, 3, 2, 2};
    cout << checkEqual(c, d) << endl; // Output: 0 (false)

    cout << "======= Rotate Array Left by k Elements ======= " << endl;
    vector<int> arr4 = {1, 2, 3, 4, 5};
    int k = 2; // Left rotated array by 1 element is [2, 3, 4, 5, 1]
    rotateLeft(arr4, k);

    for (int num : arr4)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "======= Rotate Array Right by k Elements ======= " << endl;
    vector<int> arr5 = {1, 2, 3, 4, 5};
    k = 2; // Right rotated array by 1 element is [5, 1, 2, 3, 4]
    rotateRight(arr5, k);

    for (int num : arr5)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "======= Check if Array b is Subset of Array a ======= " << endl;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 4, 5};
    cout << isSubset(a, b) << endl; // Output: 1 (true

    cout << "======= Frequencies of Elements in an Array when Range [1, n] ======= " << endl;
    vector<int> arr6 = {2, 3, 2, 3, 5};
    vector<int> freq = frequencyCount(arr6);
    for (int i = 0; i < freq.size(); i++)
    {
        cout << "Frequency of " << i + 1 << ": " << freq[i] << endl;
    }

    cout << "======= Frequencies of Elements in an Array when Range [1, n] using Array ======= " << endl;
    vector<int> freq2 = frequencyCountArray(arr6);
    for (int i = 0; i < freq2.size(); i++)
    {
        cout << "Frequency of " << i + 1 << ": " << freq2[i] << endl;
    }

    return 0;
}