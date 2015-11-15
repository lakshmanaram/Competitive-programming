#include<iostream>
using namespace std;
bool arr[1000001];
void markMultiples(int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[num] = true;
        ++i;
    }
}
void SieveOfEratosthenes(int n)
{
    if (n >= 2)
    {
        fill(arr,arr+1000001,false);
        for (int i=2; i<n; ++i)
        {
            if ( arr[i] == false )
            {
                markMultiples(i, n);
            }
        }
    }
}
bool isprime(int a)
{
    if(arr[a]==false)
        return true;
    return false;
}
int main()
{
    SieveOfEratosthenes(1000001);
    long n,i=4;
    cin>>n;
    while(true)
    {
        if(!isprime(i)&&!isprime(n-i))
        {
            cout<<i<<" "<<n-i;
            break;
        }
        i++;
    }
    return 0;
}