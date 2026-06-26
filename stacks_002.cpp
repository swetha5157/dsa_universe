#include <bits/stdc++.h>
using namespace std;

// check balanced parentheses
/*
Each opening bracket has a corresponding closing bracket of the same type.
Opening brackets must be closed in the correct order.
*/
// tc: O(n), sc: O(n)
bool isBalanced(string &s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '{' || c == '[' || c == '(')
            st.push(c);
        else
        {
            if (st.empty())
                return false;
            if ((c == '}' && st.top() == '{') ||
                (c == ']' && st.top() == '[') ||
                (c == ')' && st.top() == '('))
                st.pop();
            else
                return false;
        }
    }
    // code here
    return st.empty();
}

// next greater element
vector<int> nextLargerElement(vector<int> &arr)
{
    // code here
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();
        if (!st.empty())
            res[i] = st.top();
        st.push(arr[i]);
    }
    return res;
}

// next greater element in circular array
// hint : traverse the array twice and use stack to store the elements
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
            st.pop();
        if (!st.empty())
            res[i % n] = st.top();
        st.push(nums[i % n]);
    }
    return res;
}

// next smallest element (NSE)
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> res(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= arr[i])
            st.pop();
        if (!st.empty())
            res[i] = st.top();
        st.push(arr[i]);
    }
    return res;
}

// previous smaller element (PSE)
vector<int> previousSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= arr[i])
            st.pop();
        if (!st.empty())
            res[i] = st.top();
        st.push(arr[i]);
    }
    return res;
}

// next greater element I :
// given two arrays find the next greater element of the first array in the second array
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> st;
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> res(n1, -1);
    unordered_map<int, int> mp;
    for (int i = n2 - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums2[i])
            st.pop();
        if (!st.empty())
            mp[nums2[i]] = st.top();
        st.push(nums2[i]);
    }

    for (int i = 0; i < n1; i++)
    {
        res[i] = (mp[nums1[i]] == 0) ? -1 : mp[nums1[i]];
    }

    return res;
}

// previous greater element (PGE)
vector<int> preGreaterEle(vector<int> &arr)
{
    //  code here
    int n = arr.size();
    stack<int> st;
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();
        if (!st.empty())
            res[i] = st.top();
        st.push(arr[i]);
    }
    return res;
}
// min stack implementation
class SpecialStack
{
    stack<int> st;
    int minele;

public:
    SpecialStack()
    {
        minele = INT_MAX;
    }

    void push(int x)
    {
        // Add an element to the top of Stack
        if (st.empty())
        {
            minele = x;
            st.push(x);
        }
        else
        {
            if (x < minele)
            {
                st.push(2 * x - minele);
                minele = x;
            }
            else
                st.push(x);
        }
    }

    void pop()
    {
        // Remove the top element from the Stack
        if (!st.empty())
        {
            int x = st.top();
            st.pop();
            if (x < minele)
                minele = 2 * minele - x;
        }
    }

    int peek()
    {
        // Returns top element of the Stack
        if (st.empty())
            return -1;
        if (st.top() >= minele)
            return st.top();
        return minele;
    }

    bool isEmpty()
    {
        // Check if stack is empty
        return st.empty();
    }

    int getMin()
    {
        // Finds minimum element of Stack
        if (st.empty())
            return -1;
        return minele;
    }
};

// min insertions to make balanced parentheses
// one (  needs )) two closing brackets to balance it

int minInsertions(string s)
{
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (st.empty() || st.top() == 2)
                st.push(2);
            else
            {
                st.pop();
                st.push(2);
                ans++;
            }
        }
        else
        {
            if (st.empty())
            {
                ans++;
                st.push(1);
            }
            else if (st.top() == 1)
                st.pop();
            else if (st.top() == 2)
            {
                st.pop();
                st.push(1);
            }
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

// stock span problem
// hint: find the previous greater element and subtract the index of that element from the current index to get the span

vector<int> calculateSpan(vector<int> &arr)
{
    // code here
    int n = arr.size();
    vector<int> ans(n);
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        // pop if top ele are less or equal to current ele
        while (!st.empty() && st.top().first <= arr[i])
            st.pop();
        if (st.empty())
            // if 0th index then span is 1
            ans[i] = i + 1;
        else
            ans[i] = i - st.top().second; // subtract the index of previous greater element from current index to get the span
        st.push({arr[i], i});
    }
    return ans;
}

// max reactanle area in histogram
// find nse, pse
// in a loop find maxx= max(maxx,arr[i]*(nse[i]-pse[i]-1))
// tc: O(n), sc: O(n)
// why need nse[i]-pse[i]-1 because we need to find the width of the rectangle which is the distance between the next smaller element and previous smaller element and 1 is subtracted because we need to exclude the current element from the width calculation.
// eg: arr=[2,1,5,6,2,3], nse=[1,5,4,4,5,-1], pse=[-1,-1,1,2,1,4], for i=2, width=nse[2]-pse[2]-1=4-1-1=2, area=arr[2]*width=5*2=10
vector<int> calculateNse(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans(n, n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> calculatePse(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
int getMaxArea(vector<int> &arr)
{
    // code here
    // calculate nse and pse store indices
    // nse
    int n = arr.size();
    vector<int> nse = calculateNse(arr, n);
    vector<int> pse = calculatePse(arr, n);

    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        maxx = max(maxx, arr[i] * (nse[i] - pse[i] - 1));
    }
    return maxx;

    /*
    Think of -1 and n as imaginary boundaries outside the array.

  -1                  n
   |                  |
   v                  v

[ 2 , 1 , 5 , 6 , 2 , 3 ]
No smaller on left → boundary before array (-1)
No smaller on right → boundary after array (n)
    */
}


// max rectangle area in binary matrix
// row wise largest rectangle area in histogram
// tc: O(n*m), sc: O(m)
// hint: for each row, calculate the height of the histogram and then calculate the max area in histogram for that row
int maxArea(vector<vector<int>> &mat) {
        // code here
        int r= mat.size();int c=mat[0].size();
        vector<int>height(c,0);
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                 if(mat[i][j]==1)  height[j]++;
            else   height[j]=0;
           
            }
            ans=max(ans,getMaxArea(height));
        }
         
        return ans;
    }
int main()
{

    // ---Check balanced parentheses---
    string s = "{[()]}";
    if (isBalanced(s))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }

    // ---Next greater element---
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextLargerElement(arr);
    cout << "Next greater elements: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    // ---Next greater element in circular array---
    vector<int> circularArr = {1, 2, 1};
    vector<int> circularResult = nextGreaterElements(circularArr);
    cout << "Next greater elements in circular array: ";
    for (int i = 0; i < circularResult.size(); i++)
    {
        cout << circularResult[i] << " ";
    }
    cout << endl;

    // ---Next smaller element (NSE)---
    vector<int> arr2 = {4, 5, 2, 10, 8};
    vector<int> result2 = nextSmallerElement(arr2, arr2.size());
    cout << "Next smaller elements ";
    for (int i = 0; i < result2.size(); i++)
    {
        cout << result2[i] << " ";
    }
    cout << endl;

    // ---Previous smaller element (PSE)---
    vector<int> arr3 = {4, 5, 2, 10, 8};
    vector<int> result3 = previousSmallerElement(arr3, arr3.size());
    cout << "Previous smaller elements ";
    for (int i = 0; i < result3.size(); i++)
    {
        cout << result3[i] << " ";
    }

    cout << endl;

    // ---Next greater element I---
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result4 = nextGreaterElement(nums1, nums2);
    cout << "Next greater elements in nums1 from nums2: ";
    for (int i = 0; i < result4.size(); i++)
    {
        cout << result4[i] << " ";
    }
    cout << endl;

    // ---Previous greater element (PGE)---
    vector<int> arr4 = {4, 5, 2, 10, 8};
    vector<int> result5 = preGreaterEle(arr4);
    cout << "Previous greater elements ";
    for (int i = 0; i < result5.size(); i++)
    {
        cout << result5[i] << " ";
    }
    cout << endl;

    // --- Min insertions to make balanced parentheses---
    string s2 = "(()))";
    int minInsertionsNeeded = minInsertions(s2);
    cout << "Minimum insertions needed to balance parentheses: " << minInsertionsNeeded << endl;

    // ---Min stack implementation---
    SpecialStack s1;
    s1.push(10);
    s1.push(20);
    s1.push(5);
    cout << "Minimum element in stack: " << s1.getMin() << endl;

    // ---Stock span problem---
    vector<int> stockPrices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = calculateSpan(stockPrices);
    cout << "Stock span: ";
    for (int i = 0; i < span.size(); i++)
    {
        cout << span[i] << " ";
    }
    cout << endl;

    // max reactanle area in histogram
    vector<int> histogram = {2, 1, 5, 6, 2, 3};
    int ans = getMaxArea(histogram);
    cout << "Maximum rectangular area in histogram: " << ans << endl;

    // max rectangle in binary matrix
    vector<vector<int>> binaryMatrix = {
        {1, 0, 1, 0},
        {1, 1, 1, 1},
        {0, 1, 1, 1},
        {1, 0, 0, 1}
    };
    int maxBinaryArea = maxArea(binaryMatrix);
    cout << "Maximum rectangular area in binary matrix: " << maxBinaryArea << endl;

    return 0;
}