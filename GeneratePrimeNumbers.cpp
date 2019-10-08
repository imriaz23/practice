#include <iostream>
#include <vector>
using namespace std;
//Sieve of Eratosthenes
vector<int> sieve(int n)
{ //mark all number as prime numbers
    bool isprime[n];
    vector<int> ans;
    for (int i = 0; i <= n; i++)
        isprime[i] = true;
    isprime[0] = false;
    isprime[1] = false;
    //mark multiple of prime number as composite number
    for (int i = 2; i * i <= n; i++)
    {
        if (isprime[i] == true)
        {
            for (int j = i * i; j <= n; j = j + i)
                isprime[j] = false;
        }
    } //access to required prime number
    for (int i = 0; i <= n; i++)
    {
        if (isprime[i] == true)
            ans.push_back(i);
    }
    return ans;
}
int main()
{
    vector<int> primes = sieve(19);
    for (auto i : primes)
    {
        cout << i << " ";
    }
    return 0;
}