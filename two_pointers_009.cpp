#include<bits/stdc++.h>
using namespace std;

/*
A phrase is a palindrome if, after converting all uppercase 
letters into lowercase letters and removing all non-alphanumeric 
characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false
 otherwise.
*/

bool isPalindrome(string s) {
 
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
             if(!isalnum(s[i])){i++; continue;}
             if(!isalnum(s[j])){j--;continue;}
             if(tolower(s[i])!=tolower(s[j]))return false;
            else{ i++;j--;}
        }
        return true;
    }


/*
squares of sorted array
Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.
*/

vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int i=n-1;
        int l=0,r=n-1;
        while(l<=r && i>=0){
            if(abs(nums[l])<abs(nums[r])){
                ans[i]=nums[r]*nums[r];
                r--;
            } else {
                ans[i]=nums[l]*nums[l];
                l++;
            }
            i--;
        }
        return ans;
}

/// ---Container with most water--->
int maxArea(vector<int>& height){
    int n=height.size();
    int l=0,r=n-1;
    int maxx=0;
    while(l<r){
        int area= (r-l) * min(height[l],height[r]);
        maxx = max(maxx,area);
        if(height[l]<height[r]) l++;
        else r--;
    }
    return maxx;
}
 
// search in a 2d matrix 
// row is sorted and column is sorted
// tc: O(m+n), sc: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int r = matrix.size();
        int c = matrix[0].size();

        int row = 0;
        int col = c - 1;

        while(row < r && col >= 0) {
            if(matrix[row][col] == target)
                return true;

            if(matrix[row][col] > target)
                col--;      // move left
            else
                row++;      // move down
        }

        return false;
    }


// celebrity problem
// using two pointer elimination method
 int celebrity(vector<vector<int>>& mat) {
        // code here
        int top=0;int down=mat.size()-1;
        
        while(top<down){
            // if top knows down, top cant be celebrity
            if(mat[top][down]==1) top++;
            
            //otherwise if down kows top then down cant be a celebrity
            else if(mat[down][top]==1) down--;
            //both doesntknow each other
            else {
                top++;down--;
            }
        }
        
        if(top>down) return -1;
        
        // now the entire row should be 0 and entire col should be 1
        
        for(int i=0;i<mat.size();i++){
            if(top==i) continue; // diagonal no need to check
            if(mat[top][i]!=0 || mat[i][top]!=1) return -1;
        }
        return top;// atlast top and down point a single row only so return any of them
    }

    int main(){
    string s;
    cin>>s;
    if(isPalindrome(s)) cout<<"The string is a palindrome."<<endl;
    else cout<<"The string is not a palindrome."<<endl;

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> ans=sortedSquares(nums);
    cout<<"The squares of the sorted array are: ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    ///<---Container with most water--->
    int m;
    cin>>m;
    vector<int> height(m);
    for(int i=0;i<m;i++){
        cin>>height[i];
    }
    cout<<"The maximum area of water that can be contained is: "<<maxArea(height)<<endl;

    ///<---search in a 2d matrix--->
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    int target;
    cin >> target;

    if (searchMatrix(matrix, target)) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

     // -- Celebrity problem ---
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 1, 0}
    };
    int celeb = celebrity(mat);
    if (celeb != -1) {
        cout << "Celebrity is person " << celeb << endl;
    } else {
        cout << "No celebrity found at index " << celeb << endl;
    }
    return 0;
}