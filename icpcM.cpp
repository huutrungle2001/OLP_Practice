#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    long long max=0,sumn;
    long long a[10001],sum[10001];
    cin >> n;
    sum[0] = 0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for (int i=1;i<=n;i++)
    {
        sum[i-1] = 0;
        for (k=i;k<=n;k++)
        {
            sum[k] = sum[k-1] + a[k];
        }
        sumn = 0;
        for (int j=i;j<=n;j++)
        {
            sumn = sumn + sum[j];
            if (max < sumn)
            {
                max = sumn;
            }
        }
    }
    cout << max;
}
