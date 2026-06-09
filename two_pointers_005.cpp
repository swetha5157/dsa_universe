#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int st=0;int end=n-1;
    int p1sum=0, p2sum=0; int turn = 1; bool reversed=false;
    while(st<=end){
        int curr=-1;
        if(turn%2!=0){
                 if(reversed==false){
                    p1sum+=a[st];
                    curr=a[st];
                    st++;
                 }else{
                    p1sum+=a[end];
                    curr=a[end];
                    end--;
                 } 
        }else{
            if(reversed==false){
                p2sum+=a[st];
                curr=a[st];
                st++;
            }else{
                p2sum+=a[end];
                curr=a[end];
                end--;
            }
        }

        if(curr %2 ==0 ) 
        if(reversed==false) reversed=true;
        else reversed=false;
        turn++;
    
    }
            cout<<"p1sum "<<p1sum<<" p2sum "<<p2sum<<endl;

}