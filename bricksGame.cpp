#include <iostream>
using namespace std;
int main()
{
    bool last;
    long long n;
    cin >> n;
    while (n > 0)
    {
        last = false;
        n--;
        last = true;
        n -= 2;
    }
    if (last == false)
        cout << "Patlu";
    else
        cout << "Motu";
    return 0;
}