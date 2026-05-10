class Solution {
public:
    bool isPalindrome(int x) {
         if (x < 0)
        return false;

    int original = x;
    long long int reversed = 0;

    while (x > 0) {
        int digit = x % 10;              // Get last digit
        reversed = reversed * 10 + digit;
        x = x / 10;                     // Remove last digit
    }

    return original == reversed;
    }
};