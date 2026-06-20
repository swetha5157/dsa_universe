#include<bits/stdc++.h>
using namespace std;

// search in a 2d matrix, tc: O(log(m*n)), sc: O(1)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size();
    int c = matrix[0].size();

    int l = 0;
    int h = (r - 1) * c + (c - 1);
    while (l <= h)
    {
        int mid = (l + h) / 2;
        int midele = matrix[mid / c][mid % c];
        if (midele == target)
            return true;
        else if (midele < target)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return false;
}

// rotate 2d array by 90 degree aticlockwise
// approach: transpose the matrix and then reverse each column
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reverse each column
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
}

// rectangular matrix transpose, tc: O(n*m), sc: O(n*m)
vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res[j][i] = matrix[i][j];
        }
    }
    return res;
}
//  row with minimum 1's tc: O(n*m), sc: O(1)
int minRow(vector<vector<int>> &mat)
{
    // code here

    int r = mat.size();
    int c = mat[0].size();

    int curr;
    int minn = INT_MAX;
    int ind = -1;

    for (int i = 0; i < r; i++)
    {
        curr = 0;
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 1)
                curr++;
        }
        if (curr < minn)
        {
            minn = curr;
            ind = i + 1;
        }
    }
    return ind;

    /*
    Let's analyze it carefully.

Your current solution:

for each row
    count number of 1s

Time Complexity:

Rows = R
Cols = C

TC = O(R * C)
SC = O(1)
If you sort each row first

Suppose each row has C elements.

Sorting one row:

O(C log C)

Sorting all R rows:

O(R * C log C)

After sorting, you can find the first 1 using binary search:

lower_bound(row.begin(), row.end(), 1);

Per row:

O(log C)

For all rows:

O(R log C)

Total:

O(R * C log C + R log C)
≈ O(R * C log C)
Comparison
Method	Time Complexity
Direct counting	O(R × C)
Sort + Binary Search	O(R × C log C)

So sorting actually makes it worse.
    
    */
}

// if the matrix is already sorted row-wise and column-wise, we can use binary search to find the first occurrence of 1 in each row, tc: O(nlogm), sc: O(1)

/*
Function	Returns
lower_bound(x)	First element >= x
upper_bound(x)	First element > x
*/

int minRowSorted(vector<vector<int>> &mat)
{

    int r = mat.size();
    int c = mat[0].size();

    int minOnes = INT_MAX;
    int ans = -1;

    for (int i = 0; i < r; i++)
    {

        int firstOne =
            lower_bound(mat[i].begin(), mat[i].end(), 1) - mat[i].begin();

        int ones = c - firstOne;

        if (ones < minOnes)
        {
            minOnes = ones;
            ans = i + 1; // 1-based indexing
        }
    }

    return ans;
}

// rotate a sorted matrix by k times left
vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat)
{
    int r = mat.size();
    int c = mat[0].size();
    int original = k % c;
    for (int i = 0; i < r; i++)
    {
        rotateArr(mat[i], original);
    }
    return mat;
} // tc: O(n*m), sc: O(1) n*m for rotating the matrix, as we are rotating each row of the matrix by k%c times left, and we are using the reverse function to rotate the array in place, which takes O(n) time and O(1) space.
void reverse(vector<int> &arr, int s, int e)
{
    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
} // tc: O(n), sc: O(1)
// Function to rotate an array by d elements in counter-clockwise direction.
void rotateArr(vector<int> &arr, int d)
{
    int n = arr.size();
    int od = d % n;
    if (od == 0)
        return;
    reverse(arr, 0, od - 1);
    reverse(arr, od, n - 1);
    reverse(arr, 0, n - 1);

} // tc: O(n), sc: O(1)
// total tc: O(n*m), sc: O(1) for rotateMatrix and rotateArr
// this is the optimal solution for rotating a sorted matrix by k times left, as we are rotating each row of the matrix by k%c times left, and we are using the reverse function to rotate the array in place, which takes O(n) time and O(1) space.


// find zigzag diagonal traversla of matrix

/*
eg:
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
approach :- row+col is even - up right
row+col is odd - down left
edge cases - if col is last column, move down
if row is first row, move right
if row is last row, move right
if col is first column, move down

*/
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) return {};
        int r= mat.size();int c=mat[0].size();
        vector<int> res(r*c);
        int row=0,col=0;
        for(int i=0;i<r*c;i++){
            res[i]=mat[row][col];
            if((row+col)%2==0){ //even - up right
                // order of checking edge cases is important, 
                // as we need to check for last column and first row before checking for other edge cases, 
                //as if we check for other edge cases first then we might end up in an infinite loop.
                if(col==c-1) row++;
                else if(row==0) col++;
                else {col++;row--;}
            }else{
                //odd - down left
                if(row==r-1) col++;
                else  if(col==0) row++;
                else {col--;row++;}
            }
        }

        return res;
    }

// set zeroes in a matrix, tc: O(n*m), sc: O(1)
  void setZeroes(vector<vector<int>>& matrix) {
        //steps: if u find zero  mark the row 1st elemnet and cols first elemnt to 0
        // for first column if you find 0 store in a bool variable
        // from bottom right start filling with zeroes based on marking
     int r = matrix.size();
        int c = matrix[0].size();

        bool firstColZero = false;

        // Step 1: Mark rows and columns
        for(int i = 0; i < r; i++) {

            if(matrix[i][0] == 0)
                firstColZero = true;

            for(int j = 1; j < c; j++) {

                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0; // row marker
                    matrix[0][j] = 0; // column marker
                }
            }
        }

        // Step 2: Fill from bottom-right
        for(int i = r - 1; i >= 0; i--) {

            for(int j = c - 1; j >= 1; j--) {

                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }

            if(firstColZero)
                matrix[i][0] = 0;
        }
    }


// return index of max 1s in a row in a binary matrix, tc: O(rlogc), sc: O(1)
//indexing is 0 based
int maxRow(vector<vector<int>>& arr) {
     int r=arr.size();int c=arr[0].size();
        
         int maxOnes=0;
        int ans=-1;
        
        for(int i=0;i<r;i++){
            int firstIndexOfOne=lower_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
            
            int ones=c-firstIndexOfOne;
            
            if(ones>maxOnes){
            maxOnes=ones;
            ans=i;
            }
        }
        return ans;
}
int main(){

      // ---<Search in a 2D Matrix>---
    cout << "======= Search in a 2D Matrix ======= " << endl;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    int target = 5;
    bool found = searchMatrix(matrix, target);
    if (found)
    {
        cout << "The target " << target << " was found in the matrix." << endl;
    }
    else
    {
        cout << "The target " << target << " was not found in the matrix." << endl;
    }

    // ---<Rotate a 2D Matrix by 90 Degrees Anticlockwise>---
    cout << "======= Rotate a 2D Matrix by 90 Degrees Anticlockwise ======= " << endl;
    rotate(matrix);
    cout << "The matrix after rotating by 90 degrees anticlockwise is: " << endl;
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // ---<Rectangular Matrix Transpose>---
    cout << "======= Rectangular Matrix Transpose ======= " << endl;
    vector<vector<int>> transposedMatrix = transpose(matrix);
    cout << "The transposed matrix is: " << endl;
    for (const auto &row : transposedMatrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    // ---<Row with Minimum 1's>---
    cout << "======= Row with Minimum 1's ======= " << endl;
    vector<vector<int>> mat = {
        {1, 0, 0, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 1, 0, 1}};
    int minRowIndex = minRow(mat);
    // if array is sorted then use below function
    // int minRowIndex = minRowSorted(mat);
    if (minRowIndex != -1)
    {
        cout << "The row with the minimum number of 1's is: " << minRowIndex << endl;
    }
    else
    {
        cout << "No rows found." << endl;
    }

    // ---<Rotate a Sorted Matrix by K Times Left>---
    cout << "======= Rotate a Sorted Matrix by K Times Left ======= " << endl;
    int k = 2;
    vector<vector<int>> sortedMatrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};   
    vector<vector<int>> rotatedMatrix = rotateMatrix(k, sortedMatrix);
    cout << "The matrix after rotating by " << k << " times left is: " << endl;
    for (const auto &row : rotatedMatrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout<<endl;

    // ---<Zigzag Diagonal Traversal of Matrix>---
    cout << "======= Zigzag Diagonal Traversal of Matrix ======= " << endl;
    vector<vector<int>> mat = {{1,2,3},
                               {4,5,6},
                               {7,8,9}};
    vector<int> res = findDiagonalOrder(mat);
    for(int i: res) cout<<i<<" ";
    cout<<endl;

    // ---<Set Zeroes in a Matrix>---
    cout << "======= Set Zeroes in a Matrix ======= " << endl;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};
    setZeroes(matrix);
    cout << "The matrix after setting zeroes is: " << endl;
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout<<endl;

    // ---<Row with Maximum 1's>---
    cout << "======= Row with Maximum 1's ======= " << endl;
    vector<vector<int>> binaryMatrix = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}};
    int maxRowIndex = maxRow(binaryMatrix);
    if (maxRowIndex != -1)
    {
        cout << "The row with the maximum number of 1's is: " << maxRowIndex << endl;
    }
    else
    {
        cout << "No rows found." << endl;
    }
    return 0;
}