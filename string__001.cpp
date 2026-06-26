/*
// Frequency count — use int[26] not map
int freq[26] = {};
for (char c : s) freq[c - 'a']++;

// Check anagram
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    int cnt[26] = {};
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i]-'a']++;
        cnt[t[i]-'a']--;
    }
    for (int x : cnt) if (x != 0) return false;
    return true;
}

// Useful string operations
s.substr(start, len)   // extract substring
s.find("abc")          // returns pos or string::npos
to_string(42)          // int → string
stoi("42")             // string → int
tolower(c), toupper(c) // char case
reverse(s.begin(), s.end())
*/