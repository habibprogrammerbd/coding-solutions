# PERMOR - Rating 1196

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### OR Permutation

Given an integer $N$, find a permutation of size $N$ such that:

- $A_i \neq A_{i-1}$ $|$ $A_{i-2}$ for all $3\le i \le N$, where $|$ denotes the bitwise or operation.

It is guaranteed that such permutation always exists. If multiple such permutations exist, you may print any.
Note that a permutation of size $N$ consists of all integers from $1$ to $N$ exactly once.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists a single integer $N$ — the size of the permutation.
### Output Format

For each test case, output on a new line, $N$ space-separated integers denoting the permutation satisfying the given conditions.

It is guaranteed that such permutation always exists. If multiple such permutations exist, you may print any.

### Constraints
- $1 \leq T \leq 10^5$
- $3 \leq N \leq 10^5$
- The sum of $N$ over all test cases won't exceed $10^6$.
### Sample 1:
Input
Output

```
3
3
4
5

```

```
1 3 2
1 2 4 3
2 1 5 3 4

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-22T15:57:35.730Z  

```c_cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
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
#define fr(i, n) for (int i = (n); i >= 1; i--)

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

    fr(i,n) cout << i << " " ;

    cout << endl;
}

signed main()
{
    fast_io

    
    int t;
    cin >> t;
    while (t--) {
    solve();
    }
 
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/PERMOR)