# Overview
-While Binary Search is a useful algorithm when all of the data is contained within a single dataset, it cannot be directly used
 if that same data is spread across multiple data sets, for example multiple arrays. If however the data is still sorted, but is just
 overlapping, then a modified Binary Search can be used to solve the problem. The first possible solution is to simply take each of
 the datasets and combine them into a single array/list and then run Binary Search on the new data set. This however can be an expensive
 operation for large data sets. The following section will explain how to implement the modified Binary Search without combining data sets.

## Multiple Data set Binary Search Procedure
-The Multiple Data set Binary Search can be broken down into two scenarios that make this algorithm easier to understand. The first is what
 happens when the datasets contain the same number of elements; while the second is when each data set contains different numbers of elements.

Data Sets with Equal Lengths
-The Equal Lengths scenario is the simpler of the two scenarios. In this case, there are three conditons that can occur.
    1. Median of array1 is less than the median of array2.
        - In this scenario the target value has to be in the second half of array1, or the first half of array2.

        Figure 1:
                   Low           Median          High
            array1: |--------------|--------------|
            array2:         |--------------|--------------|
                           Low          Median           High
    2. Median of array1 is greater than the median of array2.
        - In this scenario the target value has to be in the first half of array1, or the second half of array2.

        Figure 2:
                               Low           Median          High
            array1:             |--------------|--------------|
            array2:  |--------------|--------------|
                    Low          Median           High
    3. Median of array1 is equal to median of array2.
        - In this scenario the target value has to be one of those two medians

        Figure 3:
                    Low           Median          High
            array1:  |--------------|--------------|
            array2:  |--------------|--------------|
                    Low          Median           High

Data Sets with Equal Lengths Template
-The following code template shows how to find the median of two sorted arrays with equal lengths

double equalLengths(std::vector<int>& nums1, std::vector<int>& nums2)
{
    // If both arrays are empty than an error has occurred
    if (nums1.size() == 0 && nums2.size() == 0)
    {
        return -1;
    }

    // Evaluate the special cases provided by the data sets
    // If there are only two elements left AND they are divided evenly between
    // the two arrays then return the average of the two values. This avoids an
    // infinite loop condition
    if (nums1.size() == 1 && nums2.size() == 1)
    {
        return (nums1[0] + nums2[0]) / 2
    }
    else if (nums1.size() == 2 && nums2.size() == 2)
    {
        // If there are four elements left AND they are divided evenly
        // between the two arrays then return the average of the maximum of the
        // first two values and the minimum of the second two values. This
        // avoids an infinite loop conditions
        return (std::max(nums1[0], nums2[0]) + std::min(nums1[1], nums2[1])) / 2
    }

    // Calculate the middle position of each array
    size_t nums1Middle = nums1.size() / 2;
    size_t nums2Middle = nums2.size() / 2;

    // Make a decision on what the next range to search is
    // If the median of the first array is less than the median of the second
    // array then examine the upper half of the first array and the lower half
    // of the second array
    if (nums1[nums1Middle] < nums2[nums2Middle])
    {
        return recursive(UPPER_HALF_OF_NUMS1, LOWER_HALF_OF_NUMS2)
    }
    else if (nums1[nums1Middle] > nums2[nums2Middle])
    {
        return recursive(LOWER_HALF_OF_NUMS1, UPPER_HALF_OF_NUMS2)
    }
    else
    {
        // Otherwise we have found a unique median
        return nums1[nums1Middle];
    }

    return median;
}

Data Sets with Unequal Lengths
-The Unequal Lengths scenario is more complex than the Equal Lengths scenario. In this scenario, there are both 
 more base conditions AND more decisions that need to be made on how to divide the data sets for each subsequent 
 search. However, the number of base conditions can be simplified by always guaranteing that the length of the
 first array is always less than the length of the second array. For each of the scenarios below, this assumption
 will be true (|array1| < |array2|). 
    1. Median of array1 is less than the median of array2.
        - In this scenario the target value has to be in the second half of array1, but only the X most significant 
          values from the second half of array2 can be dropped, where X is the size of the first half of array1.

        Figure 1:
                   Low  M  High
            array1: |---|---|
            array2:       |--------|--------|
                         Low     Median    High

        - So in the example above, imagine each '-' or '|' character is an individual position in the array. This 
          would mean that there are 5 values contained within each half of array1 and 10 values contained
          within each half of array2. Thus the two new datasets to search over would be the 5 values from the
          upper half of array1 and the (array2.size() - array1.size()/2) = 14 least significant values from array2.
    2. Median of array1 is greater than the median of array2.
        - In this scenario the target value has to be in the first half of array1, , but only the X least significant 
          values from the first half of array2 can be dropped, where X is the size of the second half of array1

        Figure 2:
                                Low  M  High
            array1:              |---|---|
            array2:  |--------|--------|
                    Low     Median    High
        - So in the example above, imagine each '-' or '|' character is an individual position in the array. This 
          would mean that there are 5 values contained within each half of array1 and 10 values contained
          within each half of array2. Thus the two new datasets to search over would be the 5 values from the
          lower half of array1 and the (array2.size() - array1.size()/2) = 14 most significant values from array2.
    3. Median of array1 is equal to median of array2.
        - In this scenario either of the above two scenarios can be executed. One just needs to be chosen.

Data Sets with Unequal Lengths Template
-The following code template shows how to find the median of two sorted arrays with unequal lengths

double MedianTwoSortedArrays::unequalLengths(std::vector<int>& nums1,
                                             std::vector<int>& nums2)
{
    // Remeber, when this function is called. It is guaranteed that nums1 has
    // less elements in it than nums2
    // If the first array does not contain any elements then we can return
    // immediately with either an error, or with the middle value of nums2
    if (nums1.size() == 0)
    {
        if (nums2.size() == 0)
        {
            return -1;
        }
        else
        {
            return nums2[nums2.size() / 2];
        }
    }

    // Evaluate the special cases provided by the data sets
    // If there are only two elements left AND they are divided evenly between
    // the two arrays then return the average of the two values. This avoids an
    // infinite loop condition
    if (nums1.size() == 1 && nums2.size() == 1)
    {
        return (nums1[0] + nums2[0]) / 2
    }

    // Calculate the middle position of each array
    size_t nums1Middle = nums1.size() / 2;
    size_t nums2Middle = nums2.size() / 2;

    // Base case evaluation for when there is only one element left in the first
    // array
    if (nums1.size() == 1)
    {
        // If the number of elements in the second array is even then
        if (nums2.size() % 2 == 0)
        {
            // If the value in the first array is less than the median of the
            // second array then the median is the median of the second array
            if (nums1[0] < nums2[nums2Middle])
            {
                return nums2[nums2Middle];
            }
            else if (nums1[0] > nums2[nums2Middle] &&
                     nums1[0] > nums2[nums2Middle + 1])
            {
                // Otherwise if the value in the first array is greater than the
                // median of the second array and the value above the median
                // than the median is the value in the first array
                return nums1[0];
            }
            else if (nums1[0] > nums2[nums2Middle + 1])
            {
                // Otherwise if the value in the first array is less than the
                // median of the second array and greater than the value above
                // the median than the median is the greater value in the second
                // array
                return nums2[nums2.size() / 2 + 1];
            }
        }
        else
        {
            // Otherwise there is an odd number of values in the second array
            if (nums1[0] > nums2[nums2Middle - 1])
            {
                // Otherwise if the value in the first array is less than the
                // median of the second array and greater than the value above
                // the median than the median is the average of the median and
                // the value less than the median from the second array
                return nums2[nums2.size() / 2 + 1];
            }
            else if (nums1[0] > nums2[nums2Middle - 1] &&
                     nums1[0] > nums2[nums2Middle])
            {
                return (nums1[0] + nums2[nums2.size() / 2]);
            }
            else if (nums1[0] > nums2[nums2Middle] &&
                     nums1[0] > nums2[nums2Middle + 1])
            {
                return (nums1[0] + nums2[(nums2.size() / 2) + 1]);
            }
            else
            {
                return (nums2[(nums2.size() / 2)] +
                        nums2[(nums2.size() / 2) + 1]);
            }
        }
    }
    else if (nums1.size() == 2)
    {
        if (nums2.size() == 2)
        { // If there are four elements left AND they are divided evenly
            // between the two arrays then return the average of the maximum of
            // the first two values and the minimum of the second two values.
            // This avoids an infinite loop conditions
            return (std::max(nums1[0], nums2[0]) +
                    std::min(nums1[1], nums2[1])) /
                   2
        }
        // If the number of elements in the second array is even then
        else if (nums2.size() % 2 == 0)
        {
            // If the value in the first array is less than the median of the
            // second array then the median is the median of the second array
            if (nums1[0] < nums2[nums2Middle])
            {
                return nums2[nums2Middle];
            }
            else if (nums1[0] > nums2[nums2Middle] &&
                     nums1[0] > nums2[nums2Middle + 1])
            {
                // Otherwise if the value in the first array is greater than the
                // median of the second array and the value above the median
                // than the median is the value in the first array
                return nums1[0];
            }
            else if (nums1[0] > nums2[nums2Middle + 1])
            {
                // Otherwise if the value in the first array is less than the
                // median of the second array and greater than the value above
                // the median than the median is the greater value in the second
                // array
                return nums2[nums2.size() / 2 + 1];
            }
        }
        else
        {
            // Otherwise there is an odd number of values in the second array
            if (nums1[0] > nums2[nums2Middle - 1])
            {
                // Otherwise if the value in the first array is less than the
                // median of the second array and greater than the value above
                // the median than the median is the average of the median and
                // the value less than the median from the second array
                return nums2[nums2.size() / 2 + 1];
            }
            else if (nums1[0] > nums2[nums2Middle - 1] &&
                     nums1[0] > nums2[nums2Middle])
            {
                return (nums1[0] + nums2[nums2.size() / 2]);
            }
            else if (nums1[0] > nums2[nums2Middle] &&
                     nums1[0] > nums2[nums2Middle + 1])
            {
                return (nums1[0] + nums2[(nums2.size() / 2) + 1]);
            }
            else
            {
                return (nums2[(nums2.size() / 2)] +
                        nums2[(nums2.size() / 2) + 1]);
            }
        }
    }
    else
    {
        // Calculate the middle position of each array
        size_t nums1Middle = nums1.size() / 2;
        size_t nums2Middle = nums2.size() / 2;

        // Make a decision on what the next range to search is
        // If the median of the first array is less than the median of the
        // second array then examine the upper half of the first array and the
        // lower half of the second array
        if (nums1[nums1Middle] < nums2[nums2Middle])
        {
            return recursive(UPPER_HALF_OF_NUMS1, LOWER_HALF_OF_NUMS2)
        }
        else if (nums1[nums1Middle] > nums2[nums2Middle])
        {
            return recursive(LOWER_HALF_OF_NUMS1, UPPER_HALF_OF_NUMS2)
        }
        else
        {
            // Otherwise we have found a unique median
            return nums1[nums1Middle];
        }
    }
    
    return median;
}