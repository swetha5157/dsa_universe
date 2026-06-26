#include <bits/stdc++.h>
using namespace std;

// insert at bottom of stack
/*
Everywhere in this problem, the bottommost element of the stack is shown first while priniting the stack.
*/
/*
DRY RUN
Input: stack = {1, 2, 3, 4, 5}, x = 6
STACK - st
5
4
3
2
1
// TEMPORARY STACK - s
1
2
3
4
5

// INSERTING 6 AT BOTTOM - st
6

// put remaining in st from s
5
4
3
2
1
6
Output: stack = {6, 1, 2, 3, 4,5}
*/
stack<int> insertAtBottom(stack<int> st, int x)
{
    stack<int> s;
    while (!st.empty())
    {
        s.push(st.top());
        st.pop();
    }
    st.push(x);
    while (!s.empty())
    {
        st.push(s.top());
        s.pop();
    }
    return st;
}

// how to reverse a stack
// hint: use recursion to pop all elements from the stack and then insert them at the bottom of the stack one by one

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;
    int x = st.top();
    st.pop();
    reverseStack(st);
    st = insertAtBottom(st, x);
}

// sort a stack using recursion
void helper(stack<int> &st, int x)
{
    if (st.empty() || st.top() < x)
    {
        st.push(x);
        return;
    }

    int ele = st.top();
    st.pop();
    helper(st, x);
    st.push(ele);
}
void sortStack(stack<int> &stt)
{
    // code here
    if (stt.empty())
        return;

    int temp = stt.top();
    stt.pop();
    sortStack(stt);
    helper(stt, temp);
}

// restrictive candy crush problem
// we need to remove k consecutive duplicates from the string
string reducedString(int k, string s)
{

    if (k == 1)
        return ""; // if k=1 then u no need any char occurence
    // code here
    stack<pair<char, int>> st;
    for (char c : s)
    {
        if (!st.empty() && st.top().first == c)
        {
            st.top().second++;

            if (st.top().second == k)
                st.pop();
        }
        else
            st.push({c, 1});
    }

    string ans = "";

    while (!st.empty())
    {
        int freq = st.top().second;
        char c = st.top().first;
        st.pop();

        while (freq > 0)
        {
            ans += c;
            freq--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// count minimum reversals to make an expression balanced
 int countMinReversals(string s) {
        int n=s.size();
        // code here
        if(n%2==1) return -1;
        
        
        stack<char>st;
        
        for(char c:s){
            if(c=='{') st.push(c);
            
            else{
                
                if(!st.empty() && st.top()=='{') st.pop();
                else st.push(c);
            }
        }
        
        int open=0,close=0;
        
        while(!st.empty()){
            if(st.top()=='{')open++;
            else close++;
            st.pop();
        }
        
        return (open+1)/2+(close+1)/2;

        /*
        DRY RUN
        Input: s = "}{{}}{{{"
        STACK - st after proceesing the string
        {
        {
        {
        }
        

        //open =0,close=0;
        { - open=1;
        { - open=2;
        { - open=3;
        } - close=1;

        // see as a string means - }{{{ 

        // 1st reversal - {{{{
        // 2nd reversal - {}{{
        //3rd reversal - {}{} - balanced

        // ans = (3+1)/2 + (1+1)/2 = 2 + 1 = 3
    
        */
    }

int main()
{

    // -- Insert at bottom of stack ---
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    stack<int> result = insertAtBottom(st, 6);

    cout << "Stack after inserting 6 at bottom: ";
    while (!result.empty())
    {
        cout << result.top() << " ";
        result.pop();
    }
    cout << endl;

    // -- Reverse a stack ---
    stack<int> st2;
    st2.push(1);
    st2.push(2);
    st2.push(3);
    st2.push(4);
    st2.push(5);
    reverseStack(st2);
    cout << "Stack after reversing: ";
    while (!st2.empty())
    {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;

    // -- Sort a stack using recursion ---
    stack<int> st3;
    st3.push(3);
    st3.push(1);
    st3.push(4);
    st3.push(2);
    sortStack(st3);
    cout << "Stack after sorting: ";
    while (!st3.empty())
    {
        cout << st3.top() << " ";
        st3.pop();
    }
    cout << endl;

    // -- restrictive candy crush problem ---
    string s = "aaabccddd";
    int k = 3;
    string ans = reducedString(k, s);
    cout << "Reduced string after removing " << k << " consecutive duplicates: " << ans << endl;

    // -- count minimum reversals to make an expression balanced ---
    string expr = "}{{}}{{{";
    int minReversals = countMinReversals(expr);
    if (minReversals == -1)
        cout << "The expression cannot be balanced." << endl;
    else
        cout << "Minimum reversals needed to balance the expression: " << minReversals << endl;
    return 0;
}