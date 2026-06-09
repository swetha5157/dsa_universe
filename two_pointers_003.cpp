/*
the largest subarray size whose sum<=k
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int sum=0;int ans=0;
    int i=0,j=0;
    while(i<n&& j<n){
        sum+=a[j];
        while(sum>k){
            sum-=a[i];
            i++;
        }
        ans=max(ans,j-i+1);
        j++;
    }

    cout<<"Size is "<<ans;
}