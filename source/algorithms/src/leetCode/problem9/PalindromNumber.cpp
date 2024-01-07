#include "PalindromNumber.h"

#include <unordered_map>

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// PalindromNumber::PalindromNumber
///////////////////////////////////////////////////////////////////////////
PalindromNumber::PalindromNumber(FunctionVersion version)
    : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// PalindromNumber::palindromNumber()
///////////////////////////////////////////////////////////////////////////
bool PalindromNumber::palindromNumber(int x)
{
    // Initialize local variables
    int failedStatus = -1;

    // Execute the desired implementation of the PalindromNumber algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(s);
            break;
        case OPTIMIZATION_ONE:
            return optimizedOne(s);
            break;
        // case OPTIMIZATION_TWO:
        //     return optimizedTwo(s);
        //     break;
        default:
            break;
    }

    // None of the algorithms were executed, return the failed vector
    return failedStatus;
}

///////////////////////////////////////////////////////////////////////////
// PalindromNumber::bruteForce(): PASSED
// Time Complexity: O(N)
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////
bool PalindromNumber::bruteForce(int x)
{
    // Initialize local variable
    bool isPalindrome = false;

    if (x < 0)
    {
        return isPalindrome;
    }
    else if (x < 10)
    {
        isPalindrome = true;
    }
    else
    {
    }

    return isPalindrome;
}

///////////////////////////////////////////////////////////////////////////
// PalindromNumber::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////
bool PalindromNumber::optimizedOne(int x)
{
    // Initialize local variable
    bool isPalindrome = false;

    return isPalindrome;
}
} // namespace alg
