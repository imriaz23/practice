/* first repeated character in a string 
AUTHOR :RIAZ QUADRI
DATE : 2019-09-13 21:18:39 */
#include <bits/stdc++.h>
using namespace std;
char findFirstRepeatedCharacter(string str)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < str.length(); i++) //sstoring in hashTable
        mp[str[i]]++;
    for (int i = 0; i < str.length(); i++)
    { //search for charater and checking repeated character

        if (mp.find(str[i])->first == str[i] && mp.find(str[i])->second == 2)
        {
            return str[i];
        }
    }
}
int main()
{
    string str;
    cin >> str;
    cout << findFirstRepeatedCharacter(str);
    return 0;
}
