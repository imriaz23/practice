#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int mid;
    int length = s.length();
    mid = length / 2;

    int j;
    for (int i = 0; i < mid; i++)
    {
        if (s[i] == s[length - 1 - i])
            j++;
    }
    if (j == mid)
        cout << "YES";
    else
        cout << "NO";
}
