# HALFPIE

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Half-Price Pie

Chef runs a bakery. Every day for the next $N$ days, he bakes exactly one salted caramel pie and sells it.
The price of the pie on day $i$ is $A_i$. All prices are  **even**.

Chef will run a discount on  **exactly two consecutive**  days: on those two days, the price of the pie is halved.

Find the maximum total amount Chef can earn over the $N$ days, if he chooses the two days to halve price appropriately.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains a single integer $N$, the number of days. The second line contains $N$ space-separated integers $A_1, A_2, \ldots, A_N$, denoting the prices of the pie.
### Output Format

For each test case, output on a new line the maximum total amount Chef can earn.

### Constraints
- $1 \leq T \leq 100$
- $2 \leq N \leq 100$
- $2 \leq A_i \leq 100$
- Each $A_i$ is even.
### Sample 1:
Input
Output

```
4
2
10 6
6
12 4 4 30 2 50
5
2 4 10 8 6
4
10 8 6 2

```

```
8
98
27
22

```

### Explanation:

 **Test case $1$:**  There are only two days, so Chef must discount the pie on both days. His earnings will equal $5 + 3 = 8$.

 **Test case $2$:**  Discounting days $2$ and $3$ (prices $4$ and $4$) gives $12 + 2 + 2 + 30 + 2 + 50 = 98$.

 **Test case $4$:**  Discounting the last two days gives $10 + 8 + 3 + 1 = 22$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-18T15:09:39.723Z  

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
    // int n;

    // cin >> n;

    // vi v(n);
    // fl(i, n) cin >> v[i];

    // auto mn = min_element(v.begin(), v.end());
    // int min_idx = mn - v.begin();
    // mn--;
    // if (min_idx == 0)
    // {
    //     v[0] = v[0] / 2;
    //     v[1] = v[1] / 2;
    // //     cout << accumulate(v.begin(), v.end(), 0) << endl;
    // }
    // else if (min_idx == n - 1)
    // {
    //     v[n - 1] = v[n - 1] / 2;
    //     v[n - 2] = v[n - 2] / 2;
    //     cout << accumulate(v.begin(), v.end(), 0) << endl;
    // }
    // else
    // {
    //     int m = min(v[min_idx + 1], v[min_idx - 1]);

    //     if (m == v[min_idx + 1])
    //     {
    //         v[min_idx + 1] = v[min_idx + 1] / 2;
    //         v[min_idx] = v[min_idx] / 2;
    //         cout << accumulate(v.begin(), v.end(), 0) << endl;
    //     }
    //     else
    //     {
    //         v[min_idx - 1] = v[min_idx - 1] / 2;
    //         v[min_idx] = v[min_idx] / 2;
    //         cout << accumulate(v.begin(), v.end(), 0) << endl;
    //     }
    // }

#
    int n;
    cin >> n;

    vector<int> v(n);
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    int mn = v[0] + v[1];

    for (int i = 1; i < n - 1; i++)
    {

        mn = min(mn, v[i] + v[i + 1]);
    }
    cout << sum - (mn / 2) << '\n';
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

[View on CodeChef](https://www.codechef.com/problems/HALFPIE)