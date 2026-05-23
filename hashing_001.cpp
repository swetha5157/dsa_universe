#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n;
    cin>>q;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<int> query(q);
    for(int i=0;i<q;i++){
        cin>>query[i];
    }

    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[v[i]]++;
    }
    for(int i=0;i<q;i++){
        cout<<m[query[i]]<<" ";
    }
    

} 
