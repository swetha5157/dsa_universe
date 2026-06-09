/*
no of subarrays whose count of distinct number <=k
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int cnt=0;
    unordered_map<int,int>mp;
    int i=0,j=0;
    while (i<n && j<n)
    {
        mp[a[j]]++;
        int distinctsize=mp.size();
        while(distinctsize>k){
            mp[a[i]]--;
            if(mp[a[i]]==0) mp.erase(a[i]);
            i++;
            distinctsize=mp.size();
        }

        cnt +=(j-i+1);
        cout<<"Count at iteration "<<i<<" "<<j<<" is "<<cnt<<endl;
        j++;
    }
    
    cout<<"Count of dsistinct number count " <<k<<" is "<<cnt;
}
