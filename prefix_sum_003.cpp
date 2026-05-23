   //BEST TIME TO BUY AND SELL STOCK 


 #include<bits/stdc++.h>
 using namespace std;

 //ONLY 1 TRANSACTION ALLOWED
   int maxProfit(vector<int>& prices) {
        //find min price since 1 traction is allowed
        //subtract all othrs from the min price and find maxprofit

        int minPrice=INT_MAX;
        int maxprofit = 0;

        for(int i=0;i<prices.size();i++){
            minPrice=min(minPrice, prices[i]);

            maxprofit = max(maxprofit, prices[i]-minPrice);

        }

        return maxprofit;
    }

//BEST TIME TO BUY AND SELL STOCK - MULTIPLE TRANSACTIONS ALLOWED
   int maxProfit_multiple_transactions(vector<int>& arr) {
        int res=0;

        for(int i=1;i<arr.size();i++){
          if ( arr[i]>arr[i-1]) res= res+ arr[i]-arr[i-1];
        }
        return res;
    }

int main(){
    int n;  
    cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }

    cout<<maxProfit(prices)<<endl<<maxProfit_multiple_transactions(prices);
}