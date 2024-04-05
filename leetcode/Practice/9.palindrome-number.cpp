/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

#include <cmath>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        int l = 1, r = pow(10, log10(x));
        cout << l << " " << r << endl;
        while (l < r)
        {
            if (x % l != x % r)
                return false;
            l *= 10;
            r /= 10;
        }
        return true;
    }
};
// @lc code=end
