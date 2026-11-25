# DBLDROP

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Double and Drop (Easy)

You are given an array $A$ of $N$ positive integers.

You may perform the following operation  **at most once** :

- Choose an index $i$ ($1 \le i \le N$) and set $A_i := 2 \cdot A_i$.

After that, let $f(A)$ be the maximum possible value of $\text{sum}(A) - \max(A)$, that is, the sum of all its elements except one copy of the largest one.

Given an array of $N$ elements, find $f(A)$.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains a single integer $N$ — the length of the array. The second line contains $N$ space-separated integers $A_1, A_2, \ldots, A_N$.
### Output Format

For each test case, output on a new line the maximum possible score $f(A)$.

### Constraints
- $1 \leq T \leq 1000$
- $2 \leq N \leq 5000$
- $1 \leq A_i \leq 10^9$
- The sum of $N$ over all test cases does not exceed $5000$.
### Sample 1:
Input
Output

```
4
3
1 2 3
2
5 5
3
1 6 10
5
7 3 9 2 9

```

```
4
5
11
24

```

### Explanation:

 **Test case $1$:**  Doubling $A_1$ gives $[2, 2, 3]$, with score $7 - 3 = 4$. Doubling $A_2$ gives $[1, 4, 3]$, with score $8 - 4 = 4$ as well. No choice does better.

 **Test case $2$:**  Without the operation, the score is $10 - 5 = 5$. Doubling either element gives score $15 - 10 = 5$.

 **Test case $3$:**  Doubling $A_2$ gives $[1, 12, 10]$. The maximum changes, but the score is $23 - 12 = 11$, which is optimal.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-25T15:24:26.464Z  

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
    int n;
    cin >> n;

    vi v(n);
    fl(i, n) cin >> v[i];

    int mx = *max_element(v.begin(), v.end());

    int sum = accumulate(v.begin(), v.end(), 0);

    int x = sum - mx;

    fl(i, n)
    {
        int z = max(mx, 2 * v[i]);
        int y = sum + v[i];

        x = max(x, y - z);
    }

    cout << x << endl;
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

[View on CodeChef](https://www.codechef.com/problems/DBLDROP)