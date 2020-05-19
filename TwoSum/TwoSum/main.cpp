//
//  main.cpp
//  TwoSum
//
//  Created by Jacqueline Dagdigian on 5/18/20.
//  Copyright © 2020 Jacqueline Dagdigian. All rights reserved.
//
/*
     Given an array of integers, return indices of the two numbers such that they add up to a specific target.
     You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>&, int);

int main(int argc, const char * argv[])
{
    vector<int> testArray{4, 5, 8, 12, 2, 3};
    vector<int> targets{9, 11, 15, 1, 4, -1};

    for(int i = 0; i < targets.size(); i++)
    {
        try{
            cout << "Test Case " << (i+1) << ":\nTarget: " << targets[i] << "\nResult: "
                << twoSum(testArray, targets[i])[0] << ", " << twoSum(testArray, targets[i])[1] << "\n\n";
        }
        catch(char const* e)
        {
           cout << e << endl << endl;
       }
    }
    
    return 0;
}

 vector<int> twoSum(vector<int>& nums, int target)
{
    int index1 = -1;
    int index2 = -1;
    unordered_map<int, int> umap;

    for(int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums.at(i);

        if(umap.find(complement) != umap.end())
        {
            index1 = i;
            index2 = umap.at(complement);
            return {index1, index2};
        }

        umap.emplace(nums.at(i), i);
    }

    throw "No result found.";
 }
