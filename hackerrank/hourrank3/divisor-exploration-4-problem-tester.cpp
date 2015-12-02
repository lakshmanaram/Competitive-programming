#include <bits/stdc++.h>

using namespace std;

#define long long long

const int N = 1000100;
const int B = 20;

int d[N];
map<long, int> smallest;

long mul(long a, long b, long mod) {
    long ans = 0;
    while (b) {
        if (b & 1)
            ans = (ans + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ans;
}

long binByMod(long a, long to, long mod) {
    long ans = 1;
    while (to) {
        if (to & 1)
            ans = mul(ans, a, mod);
        a = mul(a, a, mod);
        to >>= 1;
    }
    return ans;
}

long bin(long a, long b) {
    long c = 1;
    while (b) {
        if (b & 1) {
            c *= a;
        }
        a *= a;
        b >>= 1;
    }
    return c;
}

void pre() {
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i)
            ++d[j];

    int t = 1003;
    int a[] = {3, 6, 10, 15};
    int b[] = {2, 3, 4, 5};
    for (long i = N - 1; i >= 1; --i) 
        if (d[i] * log(i) * 0.5 < log(5e18)) {
            if (d[i] % 2 == 1) {
                while (t * t > i)
                    --t;
                assert(t * t == i);
                smallest[bin(t, d[i])] = i;
            } else {
                smallest[bin(i, d[i] / 2)] = i;
            }

        if (d[i] == 2) {
            for (int j = 0; j < 4; ++j)
                if (a[j] * log(i) < log(5e18))
                    smallest[bin(i, a[j])] = bin(i, b[j]);
        }
    }
}

long randomLong() {
    long ans = 0;
    for (int i = 0; i < 4; ++i)
        ans = (ans << 16) ^ rand();
    return ans;
}

bool isPrime(long n) {
    if (n % 2 == 0 && n != 2)
        return false;
    for (int i = 0; i < B; ++i) {
        long a = (randomLong() % (n - 1));
        if (a < 0)
            a += n - 1;
        a += 1;

        a = binByMod(a, (n - 1) / 2, n);
        if (a != n - 1 && a != 1)
            return false;
    }

    return true;        
}

long smallestDivisor(long n) {
    for (long i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return i;
    return n;
}

long get(long n) {
    if (smallest.count(n)) {
        return smallest[n];
    }

    if (isPrime(n)) { //d = 2
        return n;
    }

    // d = 3 covered

    // d = 4 , n = pq
    long r = sqrt(n) - 1;
    if (r < 0)
        r = 0;
    while (r * r < n)
        ++r;

    if (r * r == n) {
        long a = smallestDivisor(r);
        if (a != r && a != r / a && isPrime(r / a))
            return r;
    }

    // d = 5 covered 
    // d >= 6 too
    return -1;
}

void test() {
    vector<long> a = {2, 3, 11, 31, 107, 1000000007, 1000000009};
    vector<long> b = {4, 6, 8, 9, 25, 49, 123456789, 3000000027};
    for (long x : a)
        cout << isPrime(x) << " ";
    cout << endl;
    for (long x : b)
        cout << isPrime(x) << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);

    pre();
    int t;
    cin >> t;

    while (t--) {
        long n;
        cin >> n;
        cout << get(n) << "\n";
    }

    return 0;
}