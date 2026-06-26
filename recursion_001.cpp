#include <bits/stdc++.h>
using namespace std;

// print n to 1 using recursion
// tail recursion, tc: O(n), sc: O(n) due to recursive stack space
// tail recursion is also called as backtracking
void printReverseN(int i, int n)
{
    if (i > n)
        return;
    printReverseN(i + 1, n);
    cout << i << " ";
}

// print n to 1 using recursion
// head recursion, tc: O(n), sc: O(n) due to recursive stack space
// head recursion is also called as forward tracking
void printReverseNHead(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    printReverseNHead(n - 1);
}

// print 1 to n backward tracking
void printN(int i, int n)
{
    if (i > n)
        return;
    cout << i << " ";
    printN(i + 1, n);
}

// print 1 to n forward tracking
void printNHead(int n)
{
    if (n == 0)
        return;
    printNHead(n - 1);
    cout << n << " ";
}

// print factorial of n
// this is backward tracking
int factorial(int n)
{
    if (n == 1)
        return n;
    return n * factorial(n - 1);
}

// print nth fibonacci number using recursion
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// print whole fibonacci series from 0 to n using recursion
void fibonacciSeries(int n)
{
    if (n == 0)
    {
        cout << 0 << " ";
        return;
    }
    if (n == 1)
    {
        cout << 0 << " " << 1 << " ";
        return;
    }
    fibonacciSeries(n - 1);
    cout << fibonacci(n) << " ";
}

// power or x,n using recursion, tc: O(n), sc: O(n) due to recursive stack space
int power(int x, int n)
{
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}

// when n is negative, we can use the property that x^(-n) = 1/(x^n)
float powerNegative(int x, int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 1 / powerNegative(x, -n);
    return x * powerNegative(x, n - 1);
} // tc: O(n), sc: O(n) due to recursive stack space

// optimal solution for power of x,n using recursion, tc: O(logn), sc: O(logn) due to recursive stack space
double powerOptimal(double x, int n)
{
    /*
    approach: we can use the property that x^n = (x^(n/2))^2 when n is even, and x^n = x * (x^(n/2))^2 when n is odd.
     This way we can reduce the number of multiplications needed to calculate x^n, which gives us a logarithmic time complexity.
    pow(2,10)
    |
    pow(2,5)
    |
    pow(2,2)
    |
pow(2,1)
    |
pow(2,0) = 1
    */
    if (n == 0)
        return 1;

    if (n == 0)
        return 1;

    if (n < 0)
    {
        x = 1.0 / x;
        n = -n;
    }

    double temp = powerOptimal(x, n / 2);

    if (n % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}
int main()
{
    cout << "======= Print n to 1 using Recursion ======= " << endl;
    int n = 5;
    printReverseN(1, n);
    cout << endl;

    cout << "======= Print n to 1 using Recursion (Head) ======= " << endl;
    printReverseNHead(n);
    cout << endl;

    cout << "======= Print 1 to n ======= " << endl;
    printN(1, n);
    cout << endl;

    cout << "======= Print 1 to n (Head) ======= " << endl;
    printNHead(n);
    cout << endl;

    cout << "======= Factorial of n using Recursion ======= " << endl;
    cout << "Factorial of " << n << " is: " << factorial(n) << endl;

    cout << "======= Fibonacci Series using Recursion ======= " << endl;
    cout << "Fibonacci of " << n << " is: " << fibonacci(n) << endl;

    cout << "Fibonacci Series up to " << n << " is: ";
    fibonacciSeries(n);
    cout << endl;

    cout << "======= Power of x,n using Recursion ======= " << endl;
    cout << "Power of 2 raised to 3 is: " << power(2, 3) << endl;
    cout << "Power of 2 raised to -3 is: " << powerNegative(2, -3) << endl;
    cout << "Power of 2 raised to 10 is: " << powerOptimal(2, 10) << endl;
    cout << "Power of 2 raised to -2 is: " << powerOptimal(2, -2) << endl;
    cout << endl;
}