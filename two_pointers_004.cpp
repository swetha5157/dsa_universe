/*
largest valid substring such that where any pair of chars have diff <=k
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int  n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    multiset<char> g;  // Multiset to keep track of characters in the current window
    int  p = 0;  // Maximum valid substring length

    // Sliding window using two pointers
    for (int i = 0, j = 0; j < n; j++) {
        g.insert(s[j]);  // Insert the current character into the multiset

        // Calculate the difference between the largest and smallest characters
        int  diff = *g.rbegin() - *g.begin();  // ASCII difference

        // Shrink the window while the difference exceeds k
        while (diff > k) {
            g.erase(g.find(s[i]));  // Remove the leftmost character from the multiset
            i++;  // Move the left pointer
            if (!g.empty()) {
                diff = *g.rbegin() - *g.begin();  // Update the difference
            }
        }

        // Calculate the length of the current valid substring
        int  length = j - i + 1;
        p = max(p, length);
    }

    cout << p << endl;  // Output the maximum length
    return 0;
}
