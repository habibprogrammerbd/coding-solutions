# PAWNRUSH

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Pawn Rush

Chef is practising chess endgames. A white pawn stands on row $R$ of an otherwise empty $8 \times 8$ chessboard. The rows are numbered $1$ to $8$ from White's side, so the pawn moves towards row $8$.

In one move, the pawn moves forward by one row. However, a pawn standing on row $2$ (its starting row) may instead move forward by  **two**  rows in that move.

Find the minimum number of moves the pawn needs to reach row $8$.

### Input Format
- The first and only line of input contains a single integer $R$ — the row the pawn stands on.
### Output Format

Output a single integer — the minimum number of moves the pawn needs to reach row $8$.

### Constraints
- $2 \leq R \leq 7$
### Sample 1:
Input
Output

```
7

```

```
1

```

### Explanation:

The pawn moves from row $7$ to row $8$ in one move.

### Sample 2:
Input
Output

```
2

```

```
5

```

### Explanation:

The pawn first moves two rows, from row $2$ to row $4$, and then one row at a time to rows $5$, $6$, $7$ and $8$. That is $5$ moves in total.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-25T14:34:49.536Z  

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
    if(n == 2) cout << 5 << endl;
    else cout << 8 - n << endl;
}

signed main()
{
    fast_io

    solve();
    
 
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/PAWNRUSH)