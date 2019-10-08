#include <iostream>
using namespace std;
int main()
{
    long long l;
    cin >> l;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long w, h;
        cin >> w >> h;
        if (w < l)
            cout << "UPLOAD ANOTHER" << endl;
        else if (w >= l && h >= l && w == h)
            cout << "ACCEPTED" << endl;
        else
            cout << "CROP IT" << endl;
    }

    return 0;
}