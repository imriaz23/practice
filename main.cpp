#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int count1 = 0;
        int count2 = 0;
        string s1;
        string s2;
        cin >> s1 >> s2;
        for (int i = 0; i < s1.length(); i++)
        {
            for (int j = 0; j < s2.length(); j++)
            {

                if (s1[i] == s2[j])

                    count1++;
            }
        }
        for (int i = 0; i < s2.length(); i++)
        {
            for (int j = 0; j < s1.length(); j++)
            {
                if (s2[i] == s1[j])
                    count2++;
            }
        }
        cout << s1.length() + s2.length() - count1 - count2;
    }
    return 0;
}