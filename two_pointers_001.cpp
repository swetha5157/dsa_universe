/*
Count of subarrays with sum<=k given that the lelemnets of the array are positive
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

    int sum=0;int cnt=0;

    int i=0,j=0;
    while (i<n && j<n)
    {
        sum+=a[j];
        while(sum>k){
            sum-=a[i];
            i++;
        }

        cnt +=(j-i+1);
        cout<<"Count at iteration "<<i<<" "<<j<<" is "<<cnt<<endl;
        j++;
    }
    
    cout<<"Count of subarrays with sum " <<k<<" is "<<cnt;
}