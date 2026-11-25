# MINMXOR - Rating 1154

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Minimum XOR

You have $N$ integers - $A_1, A_2, \ldots, A_N$.

You have to make the Bitwise XOR of all the elements as minimum as possible.

You are allowed to remove at most one element. Note that this means that you can also choose to not remove any element.

What is the final minimum XOR that you can achieve after removing at most one element?

 **Note:**  In most programming languages, the XOR of two variables x and y can be computed using x ^ y.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains an integer $N$ — the number of elements. The next line contains $N$ space separated integers
### Output Format

For each test case, output on a new line the final minimum XOR of the elements.

### Constraints
- $1 \leq T \leq 10^5$
- $1 \leq N \leq 3 \cdot 10^5$
- $1 \leq A_i \leq 10^5$
- Sum of $N$ over all the testcases $\leq 3\cdot10^5$
### Sample 1:
Input
Output

```
3
4
2 4 3 6
2
4 4
5
1 3 5 17 9
```

```
0
0
14
```

### Explanation:

 **Testcase 1:**  The bitwise XOR of all elements $\{2, 4, 3, 6\}$ is $3$. If we remove the element $3$, the total XOR of the remaining elements becomes $0$ which is minimum possible XOR.

 **Testcase 2:**  The bitwise XOR of all elements $\{4, 4\}$ is $0$. This is already the minimum possible total XOR, and so we will not remove any element.

 **Testcase 3:**  The bitwise XOR of all elements $\{1, 3, 5, 17, 9\}$ is $31$. If we remove the element $17$, the total XOR of the remaining elements becomes $14$ which is minimum possible XOR.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-25T05:53:02.486Z  

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
    int n, mx = 0;
    cin >> n;
    vi v(n);
    fl(i, n)
    {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= v[i];
    }

    int res = ans;

    for (int i = 0; i < n; i++)
    {
        res = min(res, v[i] ^ ans);
    }

    cout << res << endl;
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

[View on CodeChef](https://www.codechef.com/problems/MINMXOR)