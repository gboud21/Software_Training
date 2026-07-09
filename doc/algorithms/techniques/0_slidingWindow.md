# Overview
- The Sliding Window problem type is any problem that analyzes a small portion of a larger data set (subarrays or substrings) and shifts the edges of the window to the left or right to find the final solution to the problem. The purpose is to show that you can optimize a nested loop problem O(n^2)
- This document describes the conditions which must be met for a problem to be considered a Sliding Window problem; as well as, how to solve the Sliding Window problem

## Conditions
-For a problem to be considered a Sliding Window problem, at least two out of the next three conditions must be satisfied
    1. The input of the problem must be either an Array, String or something similar
    2. The problem involves find a Subsequence or a Substring within the input data
    3. We have a given Window Size (k), or we have to find the Window Size

## Common Problems
- There are two types of Sliding Window Problems
    1. Fixed Size Window
        -k is given by the problem
    2. Variable Size Window
        -k is not given by the problem

- Common Problems include
    - Longest Substring without repeating characters
    - Minimum Size Subarray Sum

### Fixed Size Window
- Finding the maximum sum of k consecutive elements

### Variable/Dynamic Size 
- Finding the shortest subarray with sum >= X

#### Template
-The following template can be used in any Variable Size Sliding Window problem

function()
{
    while (j < size)
    {
        // Calculation happen's here

        if (condition < k)
        {
            j++;
        }
        else if (condition == k)
        {
            // ans <-- Calculation
            j++;
        }
        else
        {
            while (condition > k)
            {
                // remove calculation for i
                i++;
            }
            j++;
        }
    }

    return ans;
}