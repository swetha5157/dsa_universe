/// -----<The most frequent even number in an array >-----




#include<bits/stdc++.h>
using namespace std;

int mostFrequentEven(vector<int>& nums) {
   unordered_map<int,int> mp;

        for(int n : nums){
            if(n % 2 == 0){
                mp[n]++;
            }
        }

        int ans = -1;
        int maxFreq = 0;

        for(auto it : mp){
            int num = it.first;
            int freq = it.second;

            if(freq > maxFreq){
                maxFreq = freq;
                ans = num;
            }
            else if(freq == maxFreq){
                ans = min(ans, num);
            }
        }

        return ans;
    }


/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

int logestConsecutiveSubsequence(vector<int>& nums){
        int n=nums.size();
        if(n==0) return 0;
        int maxlen=1;
        unordered_set<int> s(nums.begin(), nums.end());

        for(int n:nums){
            if(!s.count(n-1)){ //why we check for n-1 because we want to start counting from the smallest number in the sequence
                int curr=n;int currlen=1;
                while(s.count(curr+1)){
                    //if we find the next number in the sequence we increment the current number and the current length of the sequence
                    curr++;currlen++;
                }
                maxlen=max(maxlen, currlen);
            }
        }
        return maxlen;
}


// ---< valid sudoku >---
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> row[9],col[9],box[9];
        for(int i = 0; i<9; i++){   
            for(int j = 0;j<9; j++){
                char c=board[i][j];
                if(c=='.')continue;
                int boxind= (i/3)*3+(j/3);
                if(row[i].count(c) || col[j].count(c) ||box[boxind].count(c)) return false;
                row[i].insert(c);
                col[j].insert(c);
                box[boxind].insert(c);
            }
        }
            return true;
    }

    int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"The most frequent even number is: "<<mostFrequentEven(nums)<<endl;

    ///--< longest consecutive subsequence >--
    cout<<"The length of the longest consecutive subsequence is: "<<logestConsecutiveSubsequence(nums)<<endl;


    //// ---< valid sudoku >---
    vector<vector<char>> board(9, vector<char>(9)); // why col is vector of char because the input is a 2D array of characters, normal 9 is not enough to store the input since we have to store the characters as well
    cout<<"Enter the 9x9 Sudoku board (use '.' for empty cells): "<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
        }
    }
    cout<<"Is the Sudoku board valid? "<<(isValidSudoku(board) ? "Yes" : "No")<<endl;

}
