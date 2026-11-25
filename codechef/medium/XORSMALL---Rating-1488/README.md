# XORSMALL - Rating 1488

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### XOR Smaller

You are given an array $A$ containing $N$ elements. Count the number of positive integers $X$ satisfying the following condition :

- $(X \oplus A_i) < A_i$ for all $1 \le i \le N$, where $\oplus$ represents the Bitwise XOR operator.

It can be proven that the answer is always finite under the given constraints.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input. The first line contains $N$ - the size of the array The second line contains $N$ integers - $A_1, A_2,..., A_N$.
### Output Format

For each test case, output on a new line the number of valid positive integers $X$.

### Constraints
- $1 \le T \le 10^4$
- $1 \le N \le 2 \cdot 10^5$
- $1 \le A_i \lt 2^{30}$
- The sum of $N$ over all test cases does not exceed $2 \cdot 10^5$
### Sample 1:
Input
Output

```
3
2
1 3
4
10 3 5 18
1
5

```

```
1
0
5
```

### Explanation:

 **Test 1**  : The only number satisfying the constraint is $1$.

- $1 \oplus 1 = 0 < 1$
- $1 \oplus 3 = 2 < 3$

 **Test Case 2**  : It can be proven that there is no valid number.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-25T06:18:12.100Z  

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
    fl(i,n) cin >> v[i];



    int ans = v[0];


    for (int i = 0; i < n; i++)
    {
        ans&= v[i];
    }
    
    cout << ans  <<  endl;
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

[View on CodeChef](https://www.codechef.com/problems/XORSMALL)