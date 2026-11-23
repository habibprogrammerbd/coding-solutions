# PALIXOR - Rating 2014

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

### NASA

*I'ma need space, I'ma, I'ma need
You know I'm a star; space, I'ma need space
I'ma need space, I'ma, I'ma need space (N-A-S-A)*

Given an array $A$ of size $N$.
Find total number of pairs in the array $(i, j)$ $(1\le i\le j \le N)$ such that:

- $A_i \oplus A_j$ is a palindrome (in decimal representation), where $\oplus$ denotes the bitwise xor operator.
### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input. The first line of each test case contains one integer $N$ - the size of the array. The next line contains $N$ space-seperated integers as array elements.
### Output Format

For each test case, output on a new line, the number of pairs satisfying the given condition.

### Constraints
- $1 \leq T \leq 10^{2}$
- $1 \leq N \leq 10^{5}$
- $0 \leq A_i \lt 2^{15}$
- The sum of N over all test cases does not exceed $2\cdot 10^{5}$.
### Sample 1:
Input
Output

```
2
4
13 27 12 26
3
2 2 2
```

```
8
6
```

### Explanation:

 **Test case $1$:**  The pairs which form palindrome are :

- $13 \oplus 13 = 0$
- $13 \oplus 27 = 22$
- $13 \oplus 12 = 1$
- $27 \oplus 27 = 0$
- $27 \oplus 26 = 1$
- $12 \oplus 12 = 0$
- $12 \oplus 26 = 22$
- $26 \oplus 26 = 0$

 **Test case $2$:**  All the pairs form palindrome.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-23T08:45:23.430Z  

```c_cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ---------------- Macros ----------------
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define pb push_back
#define mkp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define endl '\n'
#define fl(i, n) for (int i = 0; i < (n); i++)
#define fr(i, n) for (int i = (n) - 1; i >= 0; i--)

// ---------------- Typedefs ----------------
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pll> vpll;
#define vvi vector<vector<int>>

// ---------------- Debug (local only) ----------------
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x) << '\n'
#else
#define debug(x)
#endif

// ---------------- PBDS ----------------
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// -----------------YES and NO-------------
inline void YES() { cout << "YES\n"; }
inline void NO() { cout << "NO\n"; }

// ---------------- Solve ----------------
const int maxN = (1LL << 15);

vector<int> allisPal;

bool isPal(int n)
{
    string s = to_string(n);
    string t = s;
    reverse(all(t));

    return t == s;
}

void maxNallPal()
{
    for (int i = 0; i <= maxN; i++)
    {
        if (isPal(i))
        {
            allisPal.push_back(i);
        }
    }
}

int mainisPal(vector<int> &v, unordered_map<int, int> &mp)
{
    int ans = 0;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < allisPal.size(); j++)
        {
            int x = v[i] ^ allisPal[j];

            if (mp.find(x) != mp.end())
            {
                ans += mp[x];
            }
        }
    }

    return (ans + v.size()) / 2;
}

void solve()
{
    int n;
    cin >> n;
    vi v(n);
    unordered_map<int, int> mp;
    fl(i, n)
    {
        cin >> v[i];
        mp[v[i]]++;
    }

    cout << mainisPal(v, mp) << endl;
}

signed main()
{
    fast_io

        int t;
    cin >> t;
    maxNallPal();
    while (t--)
    {
        solve();
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/PALIXOR)