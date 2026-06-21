 
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

#include<bits/stdc++.h>
using namespace std;
 
int singleNumber(vector<int>& nums) {
        int xxor=0;

        for(int i=0;i<nums.size();i++){
            xxor^=nums[i]; 
        }
    return xxor;
}

// gcd of a number
int gcdRecursive(int a, int b){
    
    if(b==0) return a;
    return gcdRecursive(b,a%b);
}

//gcd normal
int gcd(int a, int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

//print divisors of a number
int* printDivisors(int n, int &size){
    vector<int> large, small;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            small.push_back(i); //eg: if n=36, small = {1,2,3,4,6}
            if( i != n/i) 
                large.push_back(n/i);//eg: if n=36, large = {36,18,12,9}
        }
    }
    size= small.size() + large.size();
    int* res = new int[size];
    for(int i=0;i<small.size();i++){
        res[i]=small[i];
    }
    for(int i=0;i<large.size();i++){
        res[small.size()+i]=large[i];
    }
    return res;
    //total tc: O(sqrt(n)+size) 
    //total sc: O(sqrt(n))
}

//prime or not
bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

//armstrong number or not
bool isArmstrong(int n){
    int sum=0;
    int temp=n;
    // cout<<temp<<endl;
    while(temp>0){
        int digit = temp%10;
        sum += (int)round(pow(digit,3));
        // cout<<sum<<" "<<digit<<" "<<temp<<endl;
        temp/=10;
    }
    // cout<<sum<<" "<<n<<endl;
    return sum==n;
}

// check number is palindrome or not
// negative numbers are included, omit its sign and check for palindrome
bool isPalindrome(int n){
    n = abs(n); // or n=-n;
    int rev=0;
    int temp=n;
    while(temp>0){
        int digit = temp%10;
        rev = rev*10 + digit;
        temp/=10;
    }
    return rev==n;
}

// sqrt of a number
//normal method
int mySqrt(int x) {
    int floorval=0;
    for(int i=1;i*i<=x;i++){
        if(i*i==x) return i;
        floorval=i;
    }
    return floorval;
} // total tc: O(sqrt(n))

// binary search method
int mySqrtBinary(int x) {
    if(x==0 || x==1) return x; 
    //why? because 0 and 1 are perfect squares of themselves, so we can directly return them without further calculations.

    int low=1, high=x/2, ans=0;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(mid*mid==x) return mid;
        else if(mid*mid<x){
            low=mid+1;
            ans=mid;
        } else {
            high=mid-1;
        }
    }
    return ans;
} // total tc: O(log(n))

// perfect number or not
bool isPerfect(int n){
    if(n<=1) return false;
    int sum=1; // 1 is a proper divisor of every number
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            sum+=i;
            if(i!=n/i) sum+=n/i; // to avoid adding the square root twice in case of perfect squares
        }
    }
    return sum==n;
}

// find min angle between hour and minute hand of a clock
// given 12 hour format
double angleClock(int hour, int minutes) {
        // if 24 hour format is given, we can take hour = hour%12 to convert it to 12 hour format, rest all same

        double ha= (hour*30.0)+(minutes*0.5); // 30 degrees per hour + 0.5 degrees per minute
        double ma=minutes*6.0;// 6 degrees per minute

        double diff= abs(ha-ma);

        return min(diff, 360.0-diff);

}

int main(){
    cout<< "===== Single Number "<< endl;
    vector<int> nums = {4,1,2,1,2};
    cout << singleNumber(nums) << endl; // Output: 4

    cout<< "===== GCD "<< endl;
    cout << gcd(12, 18) << endl; // Output: 6
    cout << gcdRecursive(12, 18) << endl; // Output: 6


    cout<< "===== Print Divisors "<< endl;


    int size;
    int* divisors = printDivisors(36, size);
    cout << "Divisors of 36: ";
    for(int i=0; i<size; i++){
        cout << divisors[i] << " ";
    }
    cout << endl;
    delete[] divisors;

    cout<< "===== Prime Number "<< endl;
    int num = 29;
    if(isPrime(num)){
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }

    cout<< "===== Armstrong Number "<< endl;
    int armstrongNum = 153;
    if(isArmstrong(armstrongNum)){
        cout << armstrongNum << " is an Armstrong number." << endl;
    } else {
        cout << armstrongNum << " is not an Armstrong number." << endl;
    }

    cout<< "===== Palindrome Number "<< endl;
    int palindromeNum = 121;
    if(isPalindrome(palindromeNum)){
        cout << palindromeNum << " is a palindrome number." << endl;
    } else {
        cout << palindromeNum << " is not a palindrome number." << endl;
    }

    cout<< "===== Square Root "<< endl;
    int x = 16;
    cout << "Square root of " << x << " is: " << mySqrt(x) << endl; // Output: 4
    cout << "Square root of " << x << " using binary search is: " << mySqrtBinary(x) << endl; // Output: 4
    cout<< "===== Perfect Number "<< endl;
    int perfectNum = 28;
    if(isPerfect(perfectNum)){
        cout << perfectNum << " is a perfect number." << endl;
    } else {
        cout << perfectNum << " is not a perfect number." << endl;
    }
  
  
    cout<< "===== Clock Angle "<< endl;
    int hour = 3, minutes = 30;
    cout << "Angle between hour and minute hand at " << hour << ":" << minutes << " is: " << angleClock(hour, minutes) << " degrees." << endl;
    return 0;

}
