# BISHOPMV - Rating 914

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Bishop Moves

You have a chessboard of size $8 \times 8$, where the cells are numbered $(1, 1), (1, 2), \ldots, (1, 8), \ldots, (8, 1), \ldots, (8, 8).$

A bishop is a chess piece which travels along diagonals (between any $2$ cells in the same diagonal in a single move). A diagonal can be of $2$ types:

- a set of cells $(x, y)$ where $x + y$ is constant.
- a set of cells $(x, y)$ where $x - y$ is constant.

For example, $\{(1, 2), (2, 3), (3, 4), (4, 5), (5, 6), (6, 7), (7, 8)\}$ form a diagonal.

You are given $2$ cells $(X_1, Y_1)$ and $(X_2, Y_2)$. Can a bishop starting in the first cell reach the second? If it can, what is the minimum number of moves.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first and only line contains $4$ integers $X_1$, $Y_1$, $X_2$ and $Y_2$.
### Output Format

For each test case, output on a new line the minimum moves needed or $-1$ if impossible.

### Constraints
- $1 \le T \le 100$
- $1 \le X_1, Y_1, X_2, Y_2 \le 8$
- $(X_1, Y_1) \ne (X_2, Y_2)$
### Sample 1:
Input
Output

```
4
1 2 7 8
2 1 1 2
1 2 3 6
1 2 2 2

```

```
1
1
2
-1
```

### Explanation:

 **Test Case 1:**  $(1, 2)$ and $(7, 8)$ are on the same diagonal, and hence can be reached in $1$ move.

 **Test Case 3:**  The bishop can first go like $(1, 2) \rightarrow (4, 5) \rightarrow (3, 6)$, thus reaching in $2$ steps.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-16T18:03:37.311Z  

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

int minMoves(int x1, int x2, int y1, int y2)
{
    if (((x1 + y1) % 2) != (x2 + y2) % 2)
        return -1;
    else if (abs(x1 - x2) == abs(y1 - y2))
        return 1;
    else
        return 2;
}

void solve()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << minMoves(x1, x2, y1, y2) << endl;
    }
}

signed main()
{
    fast_io

    solve();

    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/BISHOPMV)