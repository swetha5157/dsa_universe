#include<bits/stdc++.h>
using namespace std;

int kthlargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>, greater<int>> minh;
    for(int n:nums){
        minh.push(n);
        if(minh.size()>k)
            minh.pop();
    }
    return minh.top();
}
vector<int> klargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>, greater<int>> minh(nums.begin(), nums.begin()+k); // this means that we are creating a min heap with the first k elements of the array
    vector<int> ans;
    for(int i=k;i<nums.size();i++){
       if(nums[i]>minh.top()){
        minh.pop();
        minh.push(nums[i]);
       }
    }
    while(!minh.empty()){
        ans.push_back(minh.top());
        minh.pop();
    }
    reverse(ans.begin(), ans.end()); // since we want the k largest elements in descending order
    return ans;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int,int> mp;
  for(int v:nums) mp[v]++;

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;

    for(auto& p: mp){
        int n = p.first;
        int freq = p.second;
        minh.push({freq,n});
        if(minh.size()>k) minh.pop();
    }
  vector<int> ans;    
  while(!minh.empty()){
        ans.push_back(minh.top().second);
        minh.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int k;
    cin>>k;

    //--< Kth largest element in an array >--
    cout<<"Kth largest element is "<<kthlargest(a, k)<<endl;


    /// ---< K largest elements in an array >---
    vector<int> k_largest = klargest(a, k);
    cout<<"K largest elements are: ";
    for(int x: k_largest)
        cout<<x<<" ";
    cout<<endl;
    cout<<endl;

    /// ---<Top K frequent elements in an array >---
    vector<int> top_k_frequent = topKFrequent(a, k);
    cout<<"Top K frequent elements are: ";
    for(int x: top_k_frequent)
        cout<<x<<" ";
    cout<<endl;




    
}