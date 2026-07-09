# Overview
-Binary Search is really an search algorithm for finding an item/data point within a sorted list. It works by repeatedly narrowing the set of data
 by dividing it in half until there is only one item remaining. 
-This document describes the conditions which must be met for a problem to be a candidate to use the Binary Search algorithm; as well as,
 how to implement the Binary Search algorithm
-Time complexity = O(log(N))
-Space Complexity = O(1)
-It is important to note that this algorithm can be implemented in either a loop or by using recursion. A template for both cases is provided
 below. Depending on the target environment one choice may be preferable to the other.

## Conditions
-For a problem to be elgible to use the Binary Search algorithm, the following conditions must be satisified
    1. The input data must be a sorted Array, List or something similar. The key point is that it must be sorted
    2. The problem involves finding a single element within the data set

## Procedure
-This section describes the steps required to implement Binary Search. For this example, imagine there is an array of integers sorted in 
 ascending order from 0 --> 99 so that the array has exactly 100 entries. In this example it the array is 0-based, meaning that the first
 entry in the array is found at position 0.
 myArray = {0, 1, 2, 3, 4, ...., 97, 98, 99}
            ^                            ^
            |                            |
        position 0                  position 99
 In this example the goal is to find a specific number in the least amount of steps possible. For the purposes of this example, 
 let's say the value we want to find, the target value, is 66.
-To find where 66 is in the array, we will take the current range of valid numbers, divide it in half and then compare the current
 index's value to the target value to determine if it is higher or lower than our current value. We will use the following steps to
 implement this logic.
    1. Set the upper and lower bounds of the data's range
        a. min = 0
        b. max = (myArray.size() - 1) <---> 99
    2. Divide the data's current range in half to find the value in the center
        a. inspectionPosition = (max + min) / 2
        b. centerValue = myArray[inspectionPosition]
    3. Compare the value in the center of the range and make a decision on what to do next
        a. If centerValue == targetValue then we are done!
        b. If centerValue < targetValue then we now know that the target value is not located in the upper half of the dataset.
           Thus we can update the value of max and then go back to step 2. We set the value to one less than the inspectionPosition
           because we have already ruled out that value.
            i. max = inspectionPosition -1
        c. If centerValue > targetValue then we now know that the target value is not located in the lower half of the dataset.
           Thus we can update the value of min and go back to step 2. We set the value to one less than the inspectionPosition
           because we have already ruled out that value.
           ii. min = inspectionPosition - 1

## Templates
### Binary Search Template using Loops
-In general, the recursion case is preferable for Binary Search, unless you are in a Safety Critical environment where it is more
 preferable to use loops due to the ability to ensure that the call stack will not grow infinitely and by extension to reduce cyclical
 compelxity allowing Static Analysis tools to more easily analyze the code. 
-Template
return_type findValue(array nums, target_type targetValue)
{
    int min = RANGE_LOWER_BOUNDARY;
    int max = RANGE_UPPER_BOUNDARY;
    bool isFound = false;
    int targetPosition = -1;

    while (isFound == false)
    {
        int inspectionPosition = (max + min) / 2;
        int centerValue = nums[inspectionPosition];

        if (centerValue == targetValue)
        {
            targetPosition = inspectionPosition;
            isFound = true;
        }
        else if(max - min == 1)
        {
            isFound = true;
        }
        else if (centerValue < targetValue)
        {
            min = inspectionPosition + 1;
        }
        else
        {
            max = inspectionPosition - 1;
        }
    }

    return targetPosition;
}

-Example
int findValue(std::vector<int> nums, int targetValue)
{
    int min = 0;
    int max = nums.size() - 1;
    bool isFound = false;
    int targetPosition = -1;

    while (isFound == false)
    {
        int inspectionPosition = (max + min) / 2;
        int centerValue = nums[inspectionPosition];

        if (centerValue == targetValue)
        {
            targetPosition = inspectionPosition;
            isFound = true;
        }
        else if(max - min == 1)
        {
            isFound = true;
        }
        else if (centerValue < targetValue)
        {
            min = inspectionPosition + 1;
        }
        else
        {
            max = inspectionPosition - 1;
        }
    }

    return targetPosition;
}

### Binary Search Template using Recursion
int findValue(std::vector<int> nums, int targetValue)
{
    int min = 0;
    int max = nums.size() - 1;

    return recursiveFindValue(nums, targetValue, min, max);
}

int recursiveFindValue(std::vector<int>& nums, int targetValue, int min,
                       int max)
{
    int inspectionPosition = (max + min) / 2;

    if (nums[inspectionPosition] == targetValue)
    {
        return inspectionPosition;
    }
    else if (max - min == 1)
    {
        // Failed to find the value, return an error
        return -1;
    }
    else if (nums[inspectionPosition] < targetValue)
    {
        return recursiveFindValue(nums, targetValue, inspectionPosition, max);
    }
    else
    {
        return recursiveFindValue(nums, targetValue, min, inspectionPosition);
    }
}