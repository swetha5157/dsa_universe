#include<bits/stdc++.h>
using namespace std;

void pattern_a(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
//output
// * 
// * *
// * * * 
// * * * *

void pattern_b(int n){
    for(int i=0;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j <<" ";
        }
        cout<<endl;
    }
}
//output
// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4

void pattern_c(int n){
    for(int i=0;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i <<" ";
        }
        cout<<endl;
    }
}

//output
// 1 
// 2 2 
// 3 3 3 
// 4 4 4 4 

void pattern_d(int n){
    for(int i=0;i<=n;i++){
        for(int j=1;j<=n-i;j++){ // or int j=0;j<=n-i-1;j++
            cout<<"*" <<" ";
        }
        cout<<endl;
    }
}
//output
// * * * * 
// * * * 
// * * 
// *

void pattern_e(int n){
    for(int i=0;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<j <<" ";
        }
        cout<<endl;
    }
}

//output
// 1 2 3 4 
// 1 2 3 
// 1 2 
// 1 

void pattern_f(int n){
  for(int i=0;i<n;i++){
      //space printing for every i there are n-i-1 spaces
        for(int j=0;j<2*(n-i-1);j++){
            cout<<" ";
        }
      //star - 1st row 1 stars, 2nd row- 3 stars... so 2*i+1
       for(int j=0;j<2*i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

//output
//       * 
//     * * * 
//   * * * * * 
// * * * * * * * 

void pattern_g(int n){
  for(int i=0;i<n;i++){
      //space printing for every i there are n-i-1 spaces
        for(int j=0;j<2*i;j++){
            cout<<" ";
        }
      //star - 1st row 1 stars, 2nd row- 3 stars... so 2*i+1
       for(int j=0;j<=2*(n-i-1);j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
//op
// * * * * * * * 
//   * * * * * 
//     * * * 
//       * 


void pattern_h(int n){
  pattern_f(n);
  pattern_g(n);
}

//output
//       * 
//     * * * 
//   * * * * * 
// * * * * * * * 
// * * * * * * * 
//   * * * * * 
//     * * * 
//       * 


void pattern_i(int n){
    int st;
    for(int i=0;i<n;i++){
        if(i%2==0)
           st=1;
        else st=0;
        for(int j=0;j<=i;j++){
            cout<<st <<" ";
            st=1-st;
        }
        cout<<endl;
    }
}

//op
// 1 
// 0 1 
// 1 0 1 
// 0 1 0 1 


int main(){
    int a;
    cin>>a;
    // half pyramid patterns
    cout<<"Half Pyramid Patterns"<<endl;
    pattern_a(a);

    // half pyramid number patterns
    cout<<"Half Pyramid Number Patterns"<<endl;
    pattern_b(a);

    // half pyramid number patterns -2
    cout<<"Half Pyramid Number Patterns -2"<<endl;
    pattern_c(a);

    // inverted half pyramid patterns
    cout<<"Inverted Half Pyramid Patterns"<<endl;
    pattern_d(a);

    // inverted half pyramid number patterns
    cout<<"Inverted Half Pyramid Number Patterns"<<endl;
    pattern_e(a);

    // full pyramid patterns
    cout<<"Full Pyramid Patterns"<<endl;
    pattern_f(a);

    // inverted full pyramid patterns
    cout<<"Inverted Full Pyramid Patterns"<<endl;
    pattern_g(a);

    // full pyramid + inverted full pyramid patterns
    cout<<"Full Pyramid + Inverted Full Pyramid Patterns"<<endl;
    pattern_h(a);

    // 0-1 triangle pattern
    cout<<"0-1 Triangle Pattern"<<endl;
    pattern_i(a);
    
    
    
    return 0;
    
}