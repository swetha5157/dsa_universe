#include <bits/stdc++.h>
using namespace std;

// max subarray sum of size k
int maxSubarraySum(vector<int> &arr, int k)
{
    // code here
    int n = arr.size();
    int currsum = 0;
    int maxx = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        currsum += arr[i];
    }
    maxx = currsum;

    for (int i = k; i < n; i++)
    {
        currsum += arr[i];
        currsum -= arr[i - k];
        maxx = max(currsum, maxx);
    }
    return maxx;
}

// count distinct elements in every window of size k
vector<int> countDistinct(vector<int> &arr, int k)
{
    // code here
    int n = arr.size();
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        mp[arr[i]]++;
    }
    ans.push_back(mp.size());
    for (int i = k; i < n; i++)
    {
        mp[arr[i - k]]--;
        if (mp[arr[i - k]] == 0)
            mp.erase(arr[i - k]);
        mp[arr[i]]++;

        ans.push_back(mp.size());
    }

    return ans;
}

// first negative integer in every window of size k
vector<int> firstNegInt(vector<int> &arr, int k)
{
    int n = arr.size();
    deque<int> dq;
    vector<int> ans;

    // First window
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            dq.push_back(i);
    }

    if (dq.empty())
        ans.push_back(0);
    else
        ans.push_back(arr[dq.front()]);

    // Remaining windows
    for (int i = k; i < n; i++)
    {

        // Remove elements going out of window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // Add current element if negative
        if (arr[i] < 0)
            dq.push_back(i);

        // Answer for current window
        if (dq.empty())
            ans.push_back(0);
        else
            ans.push_back(arr[dq.front()]);
    }

    return ans;
}
// max of all subarrays of size k
vector<int> maxOfSubarrays(vector<int> &arr, int k)
{
    // code here

    int n = arr.size();
    priority_queue<pair<int, int>> pq;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i], i});
    }

    ans.push_back(pq.top().first);

    for (int i = k; i < n; i++)
    {
        pq.push({arr[i], i});
        while (i - pq.top().second >= k)
            pq.pop();

        ans.push_back(pq.top().first);
    }

    return ans;
}

// substring of length k with k-1 distinct characters
int substrCount(string &s, int k)
{
    // code here
    unordered_map<int, int> mp;
    int cnt = 0;

    for (int i = 0; i < k; i++)
    {
        mp[s[i]]++;
    }
    if (mp.size() == k - 1)
        cnt++;

    for (int i = k; i < s.size(); i++)
    {
        mp[s[i - k]]--;
        if (mp[s[i - k]] == 0)
            mp.erase(s[i - k]);
        mp[s[i]]++;
        if (mp.size() == k - 1)
        {
            cnt++;
        }
    }
    return cnt;
}

// subarray with given sum k, return the starting and ending index of the subarray
vector<int> subarraySum(vector<int> &arr, int target)
{
    // code here
    int n = arr.size();
    vector<int> ans;
    int j = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        while (sum > target && j < i)
        {
            sum -= arr[j];
            j++;
        }

        if (sum == target)
        {
            ans.push_back(j + 1);
            ans.push_back(i + 1);
            return ans;
        }
    }

    return {-1};
}

//  find the length of the smallest window that contains all the characters of the given string at least once.

int findSubString(string &str)
{
    // code here
    unordered_map<char, int> mp;
    unordered_map<char, int> temp;
    for (char c : str)
        mp[c]++;

    int limit = mp.size();

    int n = str.size();
    int ans = INT_MAX;
    int r = 0, l = 0;
    while (l < n && r < n)
    {
        temp[str[r]]++;
        while (limit == temp.size())
        {
            ans = min(ans, (r - l + 1));
            temp[str[l]]--;

            if (temp[str[l]] == 0)
                temp.erase(str[l]);

            l++;
        }
        r++;
    }

    return ans;
}

// length of  smallest substring that has 0,1,2 in it
int smallestSubstring(string s)
{
    // code here

    // code here
    unordered_map<char, int> temp;
    int n = s.size();
    int ans = INT_MAX;
    int r = 0, l = 0;
    while (l < n && r < n)
    {
        if (s[r] == '0' || s[r] == '1' || s[r] == '2')
            temp[s[r]]++;
        while (temp.size() == 3)
        {
            ans = min(ans, (r - l + 1));
            temp[s[l]]--;

            if (temp[s[l]] == 0)
                temp.erase(s[l]);

            l++;
        }
        r++;
    }

    return ans == INT_MAX ? -1 : ans;
}  //tc: O(n), sc: O(1) (3 characters only auxiliary space is o(1))


//smallest window in a string containing all characters of another string including duplicates
  string minWindow(string &s, string &p) {
        unordered_map<char, int>mp;
		unordered_map<char, int>temp;
		for (char c:p)
			mp[c]++;
		
		int limit = mp.size();
		int req=0;
		
		int n = s.size(); int ans = INT_MAX;
		int r = 0, l = 0; int si=0;
		while (l<n && r<n) {
			temp[s[r]]++;
			if(mp.count(s[r]) && temp[s[r]]==mp[s[r]])
               req++;
			while (limit == req ) {
			    
				if(ans> (r - l + 1)){
				    ans=r-l+1;
				si=l;
				}
				temp[s[l]]--;
				
				if(mp.count(s[l]) && temp[s[l]]<mp[s[l]])
                req--;
				
				l++;
			} 
			r++;
			
		}
		
		return ans==INT_MAX?"" : s.substr(si,ans);
        
    }//tc: O(n), sc: O(1) (26 characters only auxiliary space is o(1))

// longest substring without repeating characters
int longestUniqueSubstring(string &s) {
        // code
        int n=s.size();
        int ans=0;
        unordered_map<char,int>mp; int i=0;
        for(int j=0;j<n;j++){
            
                mp[s[j]]++;
            
              while(mp[s[j]]>1){
               
                mp[s[i]]--;
                 i++;
            }
           ans=max(ans, j-i+1);
            
         }
        return ans;
    }// tc: O(n), sc: O(1) (26 characters only auxiliary space is o(1))


// count the occurences of anagrams of a string in another string
 int search(string &pat, string &txt) {
        // code here
       vector<int> patFreq(26,0);
    vector<int> winFreq(26,0);

    for(char c:pat)
        patFreq[c-'a']++;

    int k=pat.size();

    for(int i=0;i<k;i++)
        winFreq[txt[i]-'a']++;

    int cnt=0;

    if(winFreq==patFreq)
        cnt++;

    for(int i=k;i<txt.size();i++)
    {
        winFreq[txt[i-k]-'a']--;
        winFreq[txt[i]-'a']++;

        if(winFreq==patFreq)
            cnt++;
    }

    return cnt;
    }

// max consecutive ones with at most k flips
int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]==0) k--;
            if(k<0){
                if(nums[i]==0) k++;
                i++;
            }
            j++;
        }
        return j-i;
    }

// number of substrings containing all 3 characters a,b,c
//similar to length of smallest substring that has 0,1,2 in it, but here we are counting the number of substrings instead of finding the length of the smallest substring
// return the number of substrings containing all 3 characters a,b,c using n-r logic
// if lt r has abc then all substrings starting from l to r will have abc, so we can add n-r to the count and move l to the right
 int numberOfSubstrings(string s) {
          // code here
    unordered_map<char, int> temp;
    int n = s.size();
    int ans = 0;
    int r = 0, l = 0;
    while (l < n && r < n)
    {
        if (s[r] == 'a' || s[r] == 'b' || s[r] == 'c')
            temp[s[r]]++;
        while (temp.size()==3)
        {
            ans += (n - r);
            temp[s[l]]--;

            if (temp[s[l]] == 0)
                temp.erase(s[l]);

            l++;
        }
        r++;
    }

    return ans;
    }
    int main()
{
    // max subarray sum of size k
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;
    int maxSum = maxSubarraySum(arr, k);
    cout << "Maximum subarray sum of size " << k << ": " << maxSum << endl;

    // --< count distinct elements in every window of size k >--
    vector<int> distinctCounts = countDistinct(arr, k);
    cout << "Distinct counts in every window of size " << k << ": ";
    for (int count : distinctCounts)
    {
        cout << count << " ";
    }
    cout << endl;

    // --< first negative integer in every window of size k >--
    vector<int> arr2 = {12, -1, -7, 8, 15, 30, 16, 28};
    vector<int> firstNegatives = firstNegInt(arr2, k);
    cout << "First negative integers in every window of size " << k << ": ";
    for (int neg : firstNegatives)
    {
        cout << neg << " ";
    }
    cout << endl;

    // --< max of all subarrays of size k >--
    vector<int> arr3 = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> maxSubarrays = maxOfSubarrays(arr3, k);
    cout << "Maximum of all subarrays of size " << k << ": ";
    for (int maxVal : maxSubarrays)
    {
        cout << maxVal << " ";
    }
    cout << endl;

    // --< substring of length k with k-1 distinct characters >--
    string s = "abcabc";
    int substrCountResult = substrCount(s, k);
    cout << "Count of substrings of length " << k << " with " << k - 1 << " distinct characters: " << substrCountResult << endl;

    // --< subarray with given sum k >--
    vector<int> arr4 = {1, 2, 3, 7, 5};
    int targetSum = 12;
    vector<int> subarrayIndices = subarraySum(arr4, targetSum);
    if (subarrayIndices.size() == 2)
    {
        cout << "Subarray with sum " << targetSum << " found at indices: " << subarrayIndices[0] << " to " << subarrayIndices[1] << endl;
    }
    else
    {
        cout << "No subarray with sum " << targetSum << " found." << endl;
    }

    // --< smallest window that contains all characters of the string >--
    string str = "aabcbcdbca";
    int smallestWindowLength = findSubString(str);
    cout << "Length of the smallest window that contains all characters of the string: " << smallestWindowLength << endl;

    // --< length of smallest substring that has 0,1,2 in it >--
    string str2 = "012012"; 
    int smallestSubstringLength = smallestSubstring(str2);
    cout << "Length of the smallest substring that has 0,1,2 in it: " << smallestSubstringLength << endl;

    // --< smallest window in a string containing all characters of another string including duplicates >--
    string s1 = "ADOBECODEBANC";
    string p1 = "ABC";
    string minWindowResult = minWindow(s1, p1);
    cout << "Smallest window in the string containing all characters of another string: " << minWindowResult << endl;


    // --< longest substring without repeating characters >--
    string s3 = "abcabcbb"; 
    int longestUniqueLength = longestUniqueSubstring(s3);
    cout << "Length of the longest substring without repeating characters: " << longestUniqueLength << endl;
   
   // --< count the occurrences of anagrams of a string in another string >--
    string pat = "ab";
    string txt = "abxaba";
    int anagramCount = search(pat, txt);
    cout << "Count of occurrences of anagrams of the string in another string: " << anagramCount << endl;
    
    // --< max consecutive ones with at most k flips >--
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1};
    int flips = 2;  
    cout << "Length of the longest subarray with at most " << flips << " flips: " << longestOnes(nums, flips) << endl;
    
    // --< number of substrings containing all 3 characters a,b,c >--
    string s4 = "abcabc";
    int substringsCount = numberOfSubstrings(s4);
    cout << "Number of substrings containing all 3 characters a,b,c: " << substringsCount << endl;

    
    return 0;
}