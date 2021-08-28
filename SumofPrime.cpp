#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
loop:
    int n;
    cin >> n;
    if (n == 0)
        return 0;
    else
    {
        vector<int> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i <= n; i++)
        {
            if (isPrime[i] == true)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> Prime;
        int count = 0;
        for (int i = 2; i <= n; i++)
        {
            if (isPrime[i])
                Prime.push_back(i);
        }
        int size = Prime.size();
        for (int i = 0; i < size; i++)
        {
            int sum = 0;
            for (int j = i; j < size; j++)
            {
                sum += Prime[j];
                if (sum == n)
                {
                    count++;
                    goto end;
                }
            }
        end:;
        }
        cout << count << "\n";
        goto loop;
    }
}