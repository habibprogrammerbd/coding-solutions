# SQUASH

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Squash

You are given a string $S$ of length $N$ consisting only of the characters `A` and `B`, and an integer $K$.

In one operation, you may choose two adjacent  **equal**  characters of $S$ and delete exactly one of them.

Determine whether it is possible to obtain a string of length exactly $K$ after performing zero or more operations.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains two space-separated integers $N$ and $K$. The second line contains the string $S$.
### Output Format

For each test case, output on a new line `YES` if a string of length $K$ can be obtained, and `NO` otherwise.

Each letter of `YES` and `NO` may be printed in either uppercase or lowercase.

### Constraints
- $1 \leq T \leq 100$
- $1 \leq K \leq N \leq 100$
- $S$ consists only of the characters A and B.
### Sample 1:
Input
Output

```
5
10 3
BBBAAAAAAB
4 3
ABAB
5 1
AAAAA
6 6
ABBAAB
9 4
ABBBAABAA

```

```
YES
NO
YES
YES
NO

```

### Explanation:

 **Test case $1$:**  `BBBAAAAAAB` can be reduced to `BAB`, which has length $3$. One valid sequence is as follows:

- Choose one of the first two characters and delete them. The string becomes BBAAAAAAB.
- Again choose one of the first two characters and delete them. The string becomes BAAAAAAB.
- Now repeatedly choose two adjacent A's and delete one of them. The string will eventually become BAB.

 **Test case 2:**  No two adjacent characters of `ABAB` are equal, so no operation can be performed and the length stays $4$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-18T15:23:47.040Z  

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

    string s;
    cin >> s;

    int i = 0;
    bool x = false;
    while (s.size() > k && i < (int)s.size() - 1)
    {
        char c = s[i];

        if (c == s[i + 1])
        {
            s.erase(i, 1);
            if (i > 0)
                i--;
        }
        else
            i++;

        // if (k == s.size())
        // {
        //     x = true;
        //     break;
        // }
    }

    if (k == s.size())
        cout << "YES\n";
    else
        cout << "NO\n";
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

[View on CodeChef](https://www.codechef.com/problems/SQUASH)