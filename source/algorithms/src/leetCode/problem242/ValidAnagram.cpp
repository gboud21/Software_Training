#include "ValidAnagram.h"

#include <cstdint>
#include <unordered_map>

namespace alg
{
///////////////////////////////////////////////////////////////////////////
// ValidAnagram::ValidAnagram
///////////////////////////////////////////////////////////////////////////
ValidAnagram::ValidAnagram(FunctionVersion version) : m_functionVersion(version)
{
}

///////////////////////////////////////////////////////////////////////////
// ValidAnagram::isValid()
///////////////////////////////////////////////////////////////////////////
bool ValidAnagram::isAnagram(std::string s, std::string t)
{
    // Initialize local variables
    bool status = false;

    // Execute the desired implementation of the ValidAnagram algorithm
    switch (m_functionVersion)
    {
        case BRUTE_FORCE:
            // Execute the Brute Force Algorithm
            return bruteForce(s, t);
            break;
        // case OPTIMIZATION_ONE:
        //     return optimizedOne(root);
        //     break;
        // case OPTIMIZATION_TWO:
        //     return optimizedTwo(s);
        //     break;
        default:
            break;
    }

    // None of the algorithms were executed, return the failed std::vector
    return status;
}

///////////////////////////////////////////////////////////////////////////
// ValidAnagram::bruteForce(): PASSED
// Time Complexity: O(Nlog(N))
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
bool ValidAnagram::bruteForce(std::string s, std::string t)
{
    bool isValid = false;

    if (s.length() == t.length())
    {
        // Map to contain all of the letters in s
        std::unordered_map<char, uint32_t> letterMap;

        // Add all of the letters in the string to the map
        for (size_t index = 0; index < s.length(); index++)
        {
            letterMap[s[index]] += 1;
        }

        // Try to decrement all of the characters from t from the map. If a
        // character is not found or is already 0 then the strings are not
        // anagrams
        isValid = true;
        for (size_t index = 0; index < t.length() && isValid; index++)
        {
            std::unordered_map<char, uint32_t>::iterator it =
                letterMap.find(t[index]);

            if (it == letterMap.end() || it->second == 0)
            {
                isValid = false;
            }
            else
            {
                it->second--;
            }
        }
    }

    return isValid;
}

///////////////////////////////////////////////////////////////////////////
// ValidAnagram::optimizedOne():
// Time Complexity: O(N)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////
// bool ValidAnagram::optimizedOne(std::string s, std::string t)
// {
//     // Initialize local variable

//     return root;
// }
} // namespace alg
