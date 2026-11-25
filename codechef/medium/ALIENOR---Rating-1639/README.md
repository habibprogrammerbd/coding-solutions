# ALIENOR - Rating 1639

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### ALIEN-OR

You are given:

- positive integers $N$ and $K$ $(K \le N)$.
- an array $A$ of size $N$, where each element of the array is a binary string of length $K$;

For each $1\le j\lt 2^K$, your task is to find whether there exists a set of indices $\{i_1, i_2, \ldots, i_m\}$ $(1\le i_j, m \le N)$ such that:

- The decimal value of $(A_{i_1}$ $|$ $A_{i_2}$ $|$ $A_{i_3}$ $|$ $\ldots$ $|$ $A_{i_m})$ equals $j$, where $|$ denotes bitwise OR operation.

Print `YES` if a set of indices satisfying the given condition exists for  **all**  $1\le j\lt 2^K$. Otherwise, print `NO`.

### Input Format
- The first line contains an integer $T$ denoting the number of test cases.
- The first line of each test case contains two integers $N$ and $K$.
- The $i$-th of the next $N$ lines contains the binary string $A_i$.
### Output Format

For each test case, print `YES` if a set of indices satisfying the given condition exists for  **all**  $1\le j\lt 2^K$. Otherwise, print `NO`.

You may print each character of the string in uppercase or lowercase (for example, the strings `YES`, `yEs`, `yes`, and `yeS` will all be treated as identical).

### Constraints
- $1 \leq T \leq 50$
- $1 \leq N \leq 100$
- $1 \leq K \leq N$
- $|A_i| = K$
- $A_i \in \{0, 1\}$
- The sum of $N$ over all test cases won't exceed $500$.
### Sample 1:
Input
Output

```
3
2 2
01
10
4 3
000
010
011
100
6 3
000
001
010
011
100
101

```

```
YES
NO
YES
```

### Explanation:

 **Test case $1$:** 

- $j = 1$ : The set of indices $\{1\}$ satisfies the condition as decimal value of $A_1 = 1 = j$.
- $j = 2$ : The set of indices $\{2\}$ satisfies the condition as decimal value of $A_2 = 2 = j$.
- $j = 3$ : The set of indices $\{1, 2\}$ satisfies the condition as decimal value of $(A_1$ $|$ $A_2) = 3 = j$.

 **Test case $2$:**  The set of indices for $j = 2, 3, 4, 6, 7$ are $\{2\}, \{3\}, \{4\}, \{2,4\},$ and $\{3, 4\}$ respectively.
However, there doesn't exist any set of indices for $j=1$ and $j=5$. Hence output is `NO`.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-25T07:19:18.185Z  

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
void solve()
{
    int n, k;
    cin >> n >> k;

    vector<bool> v(k, false);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (count(s.begin(), s.end(), '1') == 1)
        {
            v[s.find('1')] = true;
        }
    }

    bool x = true;

    for (int i = 0; i < k; i++)
    {
        if (!v[i])
            x = false;
    }

    if (x)
        YES();
    else
        NO();
}

signed main()
{
    fast_io

        int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/ALIENOR)