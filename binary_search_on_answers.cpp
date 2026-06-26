#include<bits/stdc++.h>
using namespace std;
// reusable functions common
 int findMin(vector<int> & arr){
        int minn=INT_MAX;
        for(int i=0;i<arr.size();i++){
            minn=min(minn,arr[i]);
        }
        return minn;
    }
int findMax(vector<int> & arr){
        int maxx=INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxx=max(maxx,arr[i]);
        }
        return maxx;
    } 

// koko eating bananas
// we need to return the minimum number of bananas/hr that koko needs to eat all the bananas in h hours
//given an array of piles and h is for saying that koko needs to eat all the bananas in h hours
// tc:
  
    long long totHours(vector<int>&arr,int h){
        long long ans=0;
        for(int i:arr){
            ans += ceil((double)i/(double)h);
        }
        return ans;
    } // tc: O(n) where n is the number of piles
    int minEatingSpeed(vector<int>& piles, int h) {
         int l=1; int hi=findMax(piles); int final=0;
         while(l<=hi){
            int mid=(l+hi)/2;
            long long tot=totHours(piles,mid);
            if(tot>h) l=mid+1;
            else{
                final=mid;
                hi=mid-1;
            }
         }
         return final;
    }// tc: O(n log m) where n is the number of piles and m is the maximum number of bananas in a pile
//tc breqakdown : O(n) for finding the maximum number of bananas in a pile + O(log m) for binary search where m is the maximum number of bananas in a pile + O(n) for calculating the total hours needed to eat all the bananas at a given speed. So overall tc is O(n log m).



// min days to make m bouquets
// we need to return the minimum number of days needed to make m bouquets given an array of

    int findMax(vector<int> & arr){
        int maxx=INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxx=max(maxx,arr[i]);
        }
        return maxx;
    }
    int calculateDays(vector<int>& arr, int mid,int k){
        int cnt=0;int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=mid)cnt++;
            else{
                ans= ans+ floor((double)cnt/k);
                cnt=0;
            }
        }
        ans += cnt / k;
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size()) return -1; // if 3*2 = 6 flowers are not there then no use of checking anything so return -1
        int l=findMin(bloomDay);
        int h=findMax(bloomDay);
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            
            int fin=calculateDays(bloomDay,mid,k);
            if(fin>=m){
                ans=mid;
                h=mid-1;
            }else l=mid+1;
        }
        return ans;
    }

// find the smallest divisor given the threshold
 int calculateTotal(vector<int>& arr, int mid){
        int tot=0;
        for(int i=0;i<arr.size();i++){
            tot=tot+ ceil((double)arr[i]/mid); //double only return as decimal place so ceil will promote to next integer
        }
        return tot;
    }
 int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1, h=findMax(nums);
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            int res=calculateTotal(nums,mid);
            if(res<=threshold){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }

// min capacity to ship packages within d days
 int calculateDays(vector<int>&arr,int mid){
        int load=0; int days=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]+load>mid) {
                days++; load=arr[i];
            }else{
                load+=arr[i];
            }
        }
        return days;
    }
    int leastWeightCapacity(vector<int>& arr, int D) {
        // code here
        int l=findMax(arr); int ans=0;
        int h=accumulate(arr.begin(),arr.end(),0);
        while(l<=h){
            int mid=(l+h)/2;
            int days=calculateDays(arr,mid);
            if(days<=D) {
                ans=mid;
                h=mid-1;
            }else l=mid+1;
        }
        return ans;
    }

//find kth positive missing number
int findKthPositive(vector<int>& arr, int k) {
        int n= arr.size();
        vector<int>missing(n);
        for(int i=0;i<arr.size();i++){
            missing[i]=arr[i]-(i+1);
        }
        int l=0;int h=missing.size()-1;

        while(l<=h){
            int mid=(l+h)/2;
            if(missing[mid]<k) l=mid+1;
            else h=mid-1;
        }

        if(h==-1) return k;

        return arr[h]+(k-missing[h]);
    } //tc: o(log n) sc:o(n)
// optimal approach 
//tc: O(log n) sc: O(1)
int findKthPositiveOptimal(vector<int>& arr, int k) {
        int n= arr.size();
        
        int l=0;int h=n-1;

        while(l<=h){
            int mid=(l+h)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k) l=mid+1;
            else h=mid-1;
        }

        return k+h+1; //l=h+1
    }

// nth root of a number
// return 1 if ==m 
    //return 0 if <m
    //return 2 if>m
    int f(int mid,int n,int m){
        long long ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*mid;
            if(ans>m) return 2;
        }
        if(ans==m) return 1;
        return 0;
    }
    int nthRoot(int n, int m) {
        if(m==0) return 0;
        int l=1,h=m;
        while(l<=h){
            int mid=(l+h)/2;
            int ans=f(mid,n,m);
            if(ans==1) return mid;
            else if(ans==0) l=mid+1;
            else h=mid-1;
        }
        return -1;
    } //tc: O(n*log m) , n for the power loop  and log m for binary searchsc: O(1)



    int main(){

    // ---< Koko eating bananas >---
    int n;
    cin>>n;
    vector<int> piles(n);
    for(int i=0;i<n;i++) cin>>piles[i];
    int h;
    cin>>h;
    cout<<"Minimum eating speed is "<<minEatingSpeed(piles, h)<<endl;

    // ---< Min days to make m bouquets >---
    int m, k;
    cin>>m>>k;
    vector<int> bloomDay(n);
    for(int i=0;i<n;i++) cin>>bloomDay[i];
    cout<<"Minimum days to make "<<m<<" bouquets is "<<minDays(bloomDay,
    m, k)<<endl;

    // ---< Find the smallest divisor given the threshold >---
    int threshold;
    cin>>threshold;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<"Smallest divisor is "<<smallestDivisor(nums, threshold)<<endl;

    // ---< Min capacity to ship packages within d days >---
    int D;
    cin>>D;
    vector<int> weights(n);
    for(int i=0;i<n;i++) cin>>weights[i];
    cout<<"Minimum capacity to ship packages within "<<D<<" days is "<<leastWeightCapacity(weights, D)<<endl;

    // ---< Find kth positive missing number >---
    int k1;
    cin>>k1;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Kth positive missing number is "<<findKthPositive(arr, k1)<<endl;
    cout<<"Kth positive missing number (optimal approach) is "<<findKthPositiveOptimal(arr, k1)<<endl;
    return 0;
}