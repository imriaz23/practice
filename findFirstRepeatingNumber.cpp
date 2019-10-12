/*
AUTHOR : RIAZ QUADRI
TIME :2019-10-12 20:26:18

Given an array of n numbers ,give an algorithm for finding the first repeating element in the array which is repeated
For example : A=[3,2,1,2,2,3]
the first repeated element is 3 not(2)
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//easy approach time complexcity O(n^2)
int firstRepeatedNumber(vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = i + 1; i < array.size(); j++)
        {
            if (array[i] == array[j])
                return array[i];
        }
    }
}
//here sorting will not work as smaller number comes first which is not necessary to be the first repeated number

//but we can use hashing  again we have to take care as it can give wrong answar so we have to special hash function
int FirstRepeatedNumber(vector<int> array)
{
    unordered_map<int, int> hash;
    int result = INT_MIN;
    for (int i = 0; i < array.size(); i++)
    {
        if (hash.find(array[i]) == hash.end())
            hash[array[i]] = array[i];
        else
        {
            //if (hash[array[i]] < 0)
             //   continue;
            
                hash[array[i]] *= -1;
        }
    }
    for (auto i : hash)
        if (i.second < 0 && i.second > result)
            result = i.second;

    return result*-1;
}
int main(int argc, char const *argv[])
{
    vector<int> array{3, 2, 1, 2, 2, 3};
    cout << FirstRepeatedNumber(array);
    return 0;
}
