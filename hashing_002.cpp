// Question: Minimum operations to make all array elements equal
// Given an array of integers, you can perform the following operation any number of times:addition, subtraction, multiplication or division


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    unordered_map<int,int> m;
    int maxFreq=0;
    int value=0;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }

    for(auto i:m){
        if(i.second > maxFreq){
            maxFreq=i.second;
            value=i.first;
        }
    }

    cout<<"Min operations: "<< n-maxFreq<<endl;
    cout<<"Value is: "<<value;

}