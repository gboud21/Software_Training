#ifndef PALINDROMNUMBER_H
#define PALINDROMNUMBER_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Palindrom Number
Given an integer x, return true if x is a palindrome, and false otherwise.

-2^31 <= x <= 2^31 - 1
*/

/* Scratch Pad:
Analysis:
Output: A boolean that is true if the number is a palindrome

Input: Single integer

Constraints:
-2^31 <= x <= 2^31 - 1

Questions:
Q: What is a palindrome?
A: A palindrom is any string/integer that is the same if read from left to right
as read right to left.

Q: Is a single digit considered a palindrome?
A: Yes.

Q: When reading a negative number, is the negative sign a part of the reading?
A: Yes.
*/

#include <iostream>

#include "AlgorithmTypes.h"

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace alg
{

class PalindromNumber
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    PalindromNumber(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] x - An integer
    // \return bool - TRUE if the input value is a palindrome, false otherwise
    ///////////////////////////////////////////////////////////////////////////
    bool palindromNumber(int x);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides the brute force implementation of the
    // PalindromNumber. It will use the "two-pointer" method by starting at each
    // bound of the number and then working its way inward.
    // \param [in] x - An integer
    // \return bool - TRUE if the input value is a palindrome, false otherwise
    ///////////////////////////////////////////////////////////////////////////
    bool bruteForce(int x);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function provides an optimized implementation of the
    // algorithm that uses an unordered_map to reduce code complexity.
    // Realistically, this approach will run slightly slower and use more memory
    // than the brute force approach; however, the benifit is that the function
    // requires less lines of code and therefore is easier to maintain than the
    // brute force approach
    // \param [in] x - An integer
    // \return bool - TRUE if the input value is a palindrome, false otherwise
    ///////////////////////////////////////////////////////////////////////////
    bool optimizedOne(int x);

    // Determines which private implementation of the PalindromNumber
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif