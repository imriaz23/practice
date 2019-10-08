/*Given an array nums containing n+1 integers whhere is integer is between 1 to n(inclusive) .
Assume that there is only one duplicate,find the duplicate one

example 1:
input :[1,3,4,2,2]
output: 2

NOTE :
    array is read only
    you must use constant extra space O(1)
    there is only one duplicate number in array but it could be repeated more than once

 */

#include <iostream>
#include <vector>

using namespace std;

int duplicate(vector<int> nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    int ptr1 = nums[0];
    int ptr2 = fast;
    while (ptr1 != ptr2)
    {
        ptr1 = nums[ptr1];
        ptr2 = nums[ptr2];
    }
    return ptr1;
}
int main()
{

    vector<int> nums;
    int in;
    for (int i = 0; i < 5; i++)
    {
        cin >> in;
        nums.push_back(in);
    }
    cout << duplicate(nums);
    return 0;
}
