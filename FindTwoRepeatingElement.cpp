/*
AUTHOR : RIAZ QUADRI 
TIME : 2019-10-13 12:10:17

Find the two repeating elements in a given array.
EXAMPLE : [4,2,4,5,3,2,1]
Output : 4,2

*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
//easy approach just scan each element one by one and compare with every other element
//timecomplexcity: O(n^2),space complexcity: O(1)
vector<int> FindTwoRepeatedElements1(vector<int> array, int n)
{
    vector<int> ans;
    int count = 0;
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[i] == array[j])
            {
                ans.push_back(array[i]);
                count++;
            }
            if (count == 2)
                return ans;
        }
    }
}
//second appaoach is if we sort the input array then it will just take one scan to found the two repeated ellement
//time complexcity:O(nlogn) space complexcity:O(1)
vector<int> FindTwoRepeatedElements2(vector<int> &array, int n)
{
    vector<int> ans;
    int count = 0;
    sort(array.begin(), array.end());
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] == array[i + 1])
        {
            ans.push_back(array[i]);
            count++;
        }
        if (count == 2)
            return ans;
    }
}
//we can reduce the time complexcity to O(n) this is because if we use better look up datastructure
//we can find the repeated elementint o(1) time
vector<int> FindTwoRepeatedElements3(vector<int> array, int n)
{
    unordered_map<int, int> hash;
    vector<int> ans;
    int count = 0;
    for (int i = 0; i < array.size(); i++)
    {
        hash[array[i]]++;
        if (hash[array[i]] == 2)
        {
            ans.push_back(array[i]);
            count++;
        }
        if (count == 2)
            return ans;
    }
}
//we can reduce the space complexcity to O(1)
//IDEA is 1. XOR of all array elements and the number 1 to n will give x XOR y
//        2. in x XOR y the set bit 1 is different in x and y
//        3.if the k'th bit of X XOR Y is 1 then we can XOR all the input array element and the
//number 1 to n whose k'th bit is one.this will give one of X and Y
vector<int> FindTwoRepeatedElements4(vector<int> array, int n)
{
    vector<int> ans;
    int XOR = array[0];
    int x = 0;
    int y = 0;
    for (int i = 0; i < array.size(); i++)
    {
        XOR ^= array[i];
    }
    for (int i = 1; i <= n; i++)
    {
        XOR ^= i;
    }
    int rightMostSetBit = XOR & ~(XOR - 1);
    //divide the elements into two sets by comparing right most set bit
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] & rightMostSetBit)
            x ^= array[i];
        else
        {
            y ^= array[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & rightMostSetBit)
            x ^= i;
        else
        {
            y ^= i;
        }
    }
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> array{4, 2, 4, 5, 3, 2, 1};
    int n = 5;
    vector<int> duplicate;
    // duplicate = FindTwoRepeatedElements1(array, n);
    // duplicate = FindTwoRepeatedElements2(array, n);
    // duplicate = FindTwoRepeatedElements3(array, n);
    duplicate = FindTwoRepeatedElements4(array, n);
    for (auto itr : duplicate)
        cout << itr << " ";
    return 0;
}