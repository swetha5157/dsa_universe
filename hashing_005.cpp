
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>f;unordered_map<char,int>se;

        for(char c:s) f[c]++;
        for(char c:t)se[c]++;

        for(auto e:f){
            int freq=e.second;
            if(se.find(e.first)==se.end()) return false;
            int freq1=se[e.first];

            if(freq!=freq1) return false;
        }
        return true;
    }
int main(){
    string s,t;
    cin>>s>>t;

    if(isAnagram(s,t)) cout<<"True";
    else cout<<"False";
}