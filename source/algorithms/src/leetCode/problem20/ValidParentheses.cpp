#include "ValidParentheses.h"
#include <stack>
#include <cstdint>

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// ValidParentheses::ValidParentheses
///////////////////////////////////////////////////////////////////////////
ValidParentheses::ValidParentheses(FunctionVersion version)
    : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// ValidParentheses::isValid()
///////////////////////////////////////////////////////////////////////////
bool ValidParentheses::isValid(std::string s)
{
    // Initialize local variables
    bool failedStatus = false;

    // Execute the desired implementation of the ValidParentheses algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(s);
            break;
        // case OPTIMIZATION_ONE:
        //     return optimizedOne(s);
        //     break;
        // case OPTIMIZATION_TWO:
        //     return optimizedTwo(s);
        //     break;
        default:
            break;
    }

    // None of the algorithms were executed, return the failed vector
    return failedStatus;
}

bool checkSquareBracket(const char left, const char right)
{
    return left == '[' && right == ']';
}

bool checkCurlyBracket(const char left, const char right)
{
    return left == '{' && right == '}';
}

bool checkParentheses(const char left, const char right)
{
    return left == '(' && right == ')';
}

///////////////////////////////////////////////////////////////////////////
// ValidParentheses::bruteForce(): PASSED
// Time Complexity: O(N)
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////
bool ValidParentheses::bruteForce(std::string s)
{
    // Initialize local variable
    bool isValid = ((s.length() % 2) == 0);
    std::stack<char> openBrackets;
    uint32_t index = 0;

    // Need to swap to stack approach
    while (isValid && index < s.length())
    {
        if (s[index] == '(' || s[index] == '{' || s[index] == '[')
        {
            openBrackets.push(s[index]);
        }
        else if (openBrackets.size() == 0)
        {
            isValid = false;
        }
        else
        {
            const char leftBracket = openBrackets.top();
            openBrackets.pop();

            isValid = checkSquareBracket(leftBracket, s[index]) ||
                      checkCurlyBracket(leftBracket, s[index]) ||
                      checkParentheses(leftBracket, s[index]);
        }

        index++;
    }

    isValid &= index >= s.length() && openBrackets.size() == 0;

    return isValid;
}

///////////////////////////////////////////////////////////////////////////
// ValidParentheses::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
// bool ValidParentheses::optimizedOne(std::string s)
// {
//     // Initialize local variable
//     bool isValid = false;

//     return isValid;
// }
} // namespace alg
