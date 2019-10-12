/*
Author : RIAZ QUADRI
Time :2019-10-08 14:17:08
Given an array of integers,return indices of the two numbers
such that thay add up to specific target.

you may assume that each input would be exactly one solution,and you may not use same element twice.

Example :
    Given nums :=[2,7,11,15],
    target :=9
    because nums[0]+nums[1]=2+7=9
    
    return [0,1]

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//easy apparoach  but high complexcity O(n^2)
pair<int, int> twoSum(vector<int> array, int target)
{

    for (int i = 0; i < array.size(); i++)
    {
        for (int j = i + 1; i < array.size(); i++)
        {
            if (array[i] + array[j] == target)
                return make_pair(i, j);
        }
    }
}
/*
lets's optimise it .
how do we optimise ? 
easy just look at the second scan as it is used for searching which takes n time that is the reason we get 
O(n^2) complexcity
we can reduce it to O(1) by using better search tool which is HASHING
*/

pair<int, int> twosum(vector<int> array, int target)
{
    unordered_map<int, int> hash; //here we map value to indices
    //just one scan for insert value to hash but before inserting check whether other one is present or not
    for (int i = 0; i < array.size(); i++)
    {
        if (hash.find(target - array[i]) == hash.end())
            hash[array[i]] = i;
        else
            return make_pair(hash[target - array[i]], i);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 3};

    cout << endl;
    pair<int, int> indeixes = twosum(nums, 5);
    cout << indeixes.first << " " << indeixes.second;

    return 0;
}
