/* TRICKS TO WHEN TO USE MIN AND MAX HEAPS
Min-Heap when you need to repeatedly access and remove the smallest element
Max-Heap when you need to repeatedly access and remove the largest element

// eg: in k largest elements in an array,
we can maintain a min heap of size k,
and whenever we encounter an element greater than the top of the min heap, we pop the top and push the new element.
This way, we always have the k largest elements in the min heap,
 and the top of the min heap will be the kth largest element.

*/

#include <bits/stdc++.h>
using namespace std;

// Kth largest element in an array
int kthlargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    for (int n : nums)
    {
        minh.push(n);
        if (minh.size() > k)
            minh.pop();
    }
    return minh.top();
}

// K largest elements in an array
vector<int> klargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh(nums.begin(), nums.begin() + k); // this means that we are creating a min heap with the first k elements of the array
    vector<int> ans;
    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > minh.top())
        {
            minh.pop();
            minh.push(nums[i]);
        }
    }
    while (!minh.empty())
    {
        ans.push_back(minh.top());
        minh.pop();
    }
    reverse(ans.begin(), ans.end()); // since we want the k largest elements in descending order
    return ans;
}

// Top K frequent elements in an array
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (int v : nums)
        mp[v]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;

    for (auto &p : mp)
    {
        int n = p.first;
        int freq = p.second;
        minh.push({freq, n});
        if (minh.size() > k)
            minh.pop();
    }
    vector<int> ans;
    while (!minh.empty())
    {
        ans.push_back(minh.top().second);
        minh.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// top k frequent words in an array
vector<string> topKFrequent(vector<string> &words, int k)
{
    unordered_map<string, int> mp;
    for (string v : words)
        mp[v]++;

    auto comp = [](const pair<int, string> &a, const pair<int, string> &b)
    {
        if (a.first == b.first)
        {
            // Same frequency: pop lexicographically larger string first becoz we dont want that
            return a.second < b.second;
        }
        // Different frequency: pop lower frequency first as we dont want that
        return a.first > b.first;
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> minh(comp);

    for (auto &p : mp)
    {
        string n = p.first;
        int freq = p.second;
        minh.push({freq, n});
        if (minh.size() > k)
            minh.pop();
    }
    vector<string> ans;
    while (!minh.empty())
    {
        ans.push_back(minh.top().second);
        minh.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
} // tc: O(n log k) where n is the number of unique words and k is the number of top frequent words we want to return.

// kth smallest element in an array
int kthSmallest(vector<int> &arr, int k)
{
    // code here
    priority_queue<int> pq;
    for (int i : arr)
        pq.push(i);

    while (pq.size() > k)
        pq.pop();

    return pq.top();
}
// sort characters by frequency:
// used max heap so that we need not do reverse at end
// if we use min heap, then we need to reverse the string at end
string frequencySort(string s)
{
    unordered_map<char, int> mp;
    for (char c : s)
        mp[c]++;

    priority_queue<pair<int, char>> pq;

    for (auto e : mp)
    {
        pq.push({e.second, e.first});
    }
    string res;
    while (!pq.empty())
    {
        int f = pq.top().first;
        char c = pq.top().second;
        res.append(f, c);
        pq.pop();
    }
    return res;
}

// kth largest element in a stream:
/*
Given an input stream arr[] of n integers. Find the Kth largest element (not Kth largest unique element) after insertion of each element in the stream and if the Kth largest element doesn't exist, the answer will be -1 for that insertion.

Return a list of size n, where each element represents the Kth largest value after the corresponding insertion.
*/
vector<int> kthLargest(vector<int> &arr, int k)
{
    // code here
    vector<int> res;
    int n = arr.size();
    int i = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    while (i < n)
    {
        pq.push(arr[i]);
        if (pq.size() == k)
            res.push_back(pq.top());
        else if (pq.size() > k)
        {
            pq.pop();
            res.push_back(pq.top());
        }
        else
            res.push_back(-1);
        i++;
    }
    return res;
}

// reorganize string:
// no two adjacent characters are the same
string reorganizeString(string s)
{
    priority_queue<pair<int, char>> pq;
    int n = s.size();
    unordered_map<char, int> mp;
    for (char a : s)
        mp[a]++;

    for (auto &e : mp)
    {
        pq.push({e.second, e.first});
    }

    string res = "";

    while (pq.size() > 1)
    {
        int f1 = pq.top().first;
        char c1 = pq.top().second;
        pq.pop();

        int f2 = pq.top().first;
        char c2 = pq.top().second;
        pq.pop();

        res += c1;
        res += c2;
        f1--;
        f2--;

        if (f1 > 0)
            pq.push({f1, c1});
        if (f2 > 0)
            pq.push({f2, c2});
    }
    // when 1 element stays in the pq
    if (!pq.empty())
    {
        int f = pq.top().first;
        char c = pq.top().second;
        if (f > 1)
            return ""; // not possible
        res += c;
    }
    return res;
}

// reorganize string s with k distance apart
//eg: s="aaabc", k=2, op: abaca if can be placed correctly return 1
// if k =3 then abca one more a is left so return 0 
/*
Example: k = 2
a b a c
0 1 2 3

Positions of a:

0 and 2

Distance:

2 - 0 = 2

Valid ✅
*/
int favString(string s, int k)
{
	priority_queue<pair<int,char>>pq;
	queue<pair<int,char>>wait;

	unordered_map<char,int>mp;
	for(char c:s) mp[c]++;
	for(auto &e:mp){
		pq.push({e.second,e.first});
	}
	string res="";
	while(!pq.empty()){
		int f=pq.top().first;
		char ch=pq.top().second;
		pq.pop();
		res+=ch;
		f--;
		wait.push({f,ch});

		while(wait.size()>=k){
			auto front = wait.front();
            wait.pop();

			if(front.first>0)
            pq.push(front);
		}
	}

	if(s.size()!=res.size()) return 0;
	return 1;
}

// minimum cost to connect all ropes
 int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>,greater<int>>pq;
        
        for(int v:arr)pq.push(v);
        int cost=0;
        while(pq.size()>1){
            int s=pq.top();pq.pop();
            int sl=pq.top();pq.pop();
            cost+=s+sl;
            pq.push(s+sl);
        }
        return cost;
    }

// k pairs with smallest sums
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        for(int i = 0; i < min((int)nums1.size(), k); i++)
        {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while(k-- && !pq.empty())
        {
            auto cur = pq.top();
            pq.pop();

            int i = cur[1];
            int j = cur[2];

            ans.push_back({nums1[i], nums2[j]});

            if(j + 1 < nums2.size())
            {
                pq.push({
                    nums1[i] + nums2[j + 1],
                    i,
                    j + 1
                });
            }
        }

        return ans;
    }

// kth smallest element in a sorted matrix
// tc: O(k log n) where n is the number of rows in the matrix, sc: O(n) for the priority queue
int kthSmallest(vector<vector<int>>& matrix, int k) {
       int ans=-1;

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;
        int n=matrix.size();
        for(int i = 0; i < n; i++)
        {
            pq.push({matrix[i][0], i, 0});
        }

        while(--k)
        {
            auto cur = pq.top();
            pq.pop();
            int v=cur[0];
            int i = cur[1];
            int j = cur[2];

            if(j+1<n) {
                pq.push({matrix[i][j+1],i,j+1});
            }

        }

        return pq.top()[0];
    
    }
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;

    //--< Kth largest element in an array >--
    cout << "Kth largest element is " << kthlargest(a, k) << endl;

    /// ---< K largest elements in an array >---
    vector<int> k_largest = klargest(a, k);
    cout << "K largest elements are: ";
    for (int x : k_largest)
        cout << x << " ";
    cout << endl;
    cout << endl;

    /// ---<Top K frequent elements in an array >---
    vector<int> top_k_frequent = topKFrequent(a, k);
    cout << "Top K frequent elements are: ";
    for (int x : top_k_frequent)
        cout << x << " ";
    cout << endl;

    /// ---< Kth smallest element in an array >---
    cout << "Kth smallest element is " << kthSmallest(a, k) << endl;

    // ---< Top K frequent words in an array >---
    int m;
    cin >> m;
    vector<string> words(m);
    for (int i = 0; i < m; i++)
        cin >> words[i];
    vector<string> top_k_frequent_words = topKFrequent(words, k);
    cout << "Top K frequent words are: ";
    for (string s : top_k_frequent_words)
        cout << s << " ";
    cout << endl;

    // ---< Sort characters by frequency >---
    string str;
    cin >> str;
    cout << "String after sorting characters by frequency is: " << frequencySort(str) << endl;

    // ---< Kth largest element in a stream >---
    vector<int> kth_largest_stream = kthLargest(a, k);
    cout << "Kth largest elements in the stream are: ";
    for (int x : kth_largest_stream)
        cout << x << " ";
    cout << endl;

    // ---< Reorganize string >---
    cout << "Reorganize string such that no two adjacent characters are the same: " << endl;
    string str2;
    cin >> str2;
    string reorganized_string = reorganizeString(str2);
    cout << "Reorganized string is: " << reorganized_string << endl;

    // ---< Reorganize string with k distance apart >---
    cout << "Reorganize string such that same characters are at least k distance apart:" << endl;
    string str3;
    cin >> str3;
    int k2;
    cin >> k2;
    int can_reorganize = favString(str3, k2);
    if (can_reorganize)
        cout << "String can be reorganized with k distance apart." << endl;
    else
        cout << "String cannot be reorganized with k distance apart." << endl;

    // ---< Minimum cost to connect all ropes >---
    vector<int> arr={4, 3, 2, 6};
    cout << "Minimum cost to connect all ropes is: " << minCost(arr) << endl;

    // ---< K pairs with smallest sums >---
    vector<int> nums1 = {1, 7};
    vector<int> nums2 = {3, 4};
    int k3 = 3;
    vector<vector<int>> pairs = kSmallestPairs(nums1, nums2, k3);
    cout << "K pairs with smallest sums are: " << endl;
    for (const auto &pair : pairs)
    {
        cout << "[" << pair[0] << ", " << pair[1] << "]" << endl;
    }
    cout << endl;
    return 0;

}