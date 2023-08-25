// Given 3 numbers {1, 3, 5}, the task is to tell the total number of ways we can form a
// number N using the sum of the given three numbers. (allowing repetitions and
// different arrangements).
// https://www.geeksforgeeks.org/introduction-to-dynamic-programming-data-structures-and-algorithm-tutorials/

#include <iostream>

// recursive, complexity = O(3^n)
int solve(int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    else
        return solve(n - 1) + solve(n - 3) + solve(n - 5);
}

// Memoized , complexity = O(n)
const int MAX=20; 
//initialize all to 0 
int result[MAX]={};
int solveMemoized(int n) {
    if (n <0 ) return 0; 
    if (n ==0) return 1; 

    if (result[n]!=0) return result[n];

    result[n] = solveMemoized(n-1)+solveMemoized(n-3) + solveMemoized(n-5); 
    return result[n];
}


int main() {

    int num;
    std::cout << " Enter number :";
    std::cin >> num;

    //std::cout << " Number of ways to form " << num << " is = " << solve(num);

    std::cout << " Number of ways to form " << num << " is = " << solveMemoized(num);
}
