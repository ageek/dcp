// dcp001
// This problem was recently asked by Google.
// Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
// For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
// Bonus: Can you do this in one pass?

#include<iostream>
#include<vector>
#include<unordered_set>

int main() {
    std::vector<int> vec = {10, 15, 3, 7, 2, 14};
    int sum =17;

    // Set can be used but, Set is implemented as a balanced tree so set operations complexity = O(log n)
    // whereas unordered_set is implemented as hash table, so set operations complexity is = O(1)
    std::unordered_set<int> uo_set ;

    // one pass: O(n)
    for (auto x: vec) {
        if (uo_set.find(x) != uo_set.end()) 
            std::cout << "Found :" << sum << "=" <<  x << "+" << (sum-x) << std::endl;
        else 
            uo_set.insert(sum-x);
    }
}