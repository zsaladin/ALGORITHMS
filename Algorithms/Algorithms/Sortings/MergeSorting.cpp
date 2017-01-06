//
//  MergeSorting.cpp
//  Algorithms
//
//  Created by Dae Hee Kim on 2017. 1. 6..
//  Copyright © 2017년 Dae Hee Kim. All rights reserved.
//

#include "MergeSorting.hpp"

#include <limits>

std::vector<int> MergeSort(const std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return vec;
    
    std::vector<int> seperated0(vec.begin(), vec.begin() + vec.size() * 0.5f);
    std::vector<int> seperated1(vec.begin() + vec.size() * 0.5f, vec.end());
    
    std::vector<int> result0 = MergeSort(seperated0);
    std::vector<int> result1 = MergeSort(seperated1);
    
    result0.push_back(std::numeric_limits<int>::max());
    result1.push_back(std::numeric_limits<int>::max());
    
    std::vector<int> result;
    
    int index0 = 0, index1 = 0;
    while (index0 + index1 < vec.size())
    {
        int value = result0[index0] < result1[index1] ? result0[index0++] : result1[index1++];
        result.push_back(value);
    }

    
    return result;
}
