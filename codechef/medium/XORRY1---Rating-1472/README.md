# XORRY1 - Rating 1472

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Xorry 1

You are given an integer $X$. Two integers ($A$, $B$) are said to be an Xorry pair, if the following conditions are satisfied:

- $A \oplus B = X$
- $0 \leq A \leq B \leq X$
- Among all the pairs which satisfy the above two conditions, $(B - A)$ is as small as possible

For example, suppose $X = 6$.
Then, the pair $(0, 6)$ satisfies the first two conditions. But, the pair $(2, 4)$ also satisfies the first two conditions. And since, $(6 - 0)$ is larger than $(4 - 2)$, the pair $(0, 6)$ does not have the smallest possible difference, and so, it is not an Xorry pair.
You can verify that the pairs $(2, 4)$ and $(3, 5)$ are the only two Xorry pairs for $X = 6$. This is explained further in the sample explanation below.

Output any one Xorry pair for a given X.

Note that $\oplus$ refers to bitwise XOR.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of a single line which contains a single integer, $X$.
### Output Format

For each test case, output on a new line, two space separated integers, $A$ and $B$, where $(A, B)$ is an Xorry pair, for that particular $X$.

If there are multiple Xorry pairs, output any one of them.

### Constraints
- $1 \leq T \leq 10^5$
- $1 \leq X \leq 10^9$
### Sample 1:
Input
Output

```
5
1
2
3
4
6

```

```
0 1
0 2
1 2
0 4
2 4

```

### Explanation:

 **Test case 1:**  $X = 1$. The only pair of integers which satisfies the first two conditions is $A = 0$, and $B = 1$.
This satisfies the first two conditions, since $0 \oplus 1 = 1$, and $0 \leq 1 \leq 1$.
Since there is only one pair which satisfies the first two conditions, this is also the pair with the smallest $(B - A)$, and hence is the only Xorry pair.
So, the only answer for this testcase is $(0, 1)$.

 **Test case 2:**  $X = 2 = (10)_2$. The only pair of integers which satisfies the first two conditions $A = 0$, and $B = 2$.
This satisfies the first two conditions, since $(00)_2 \oplus (10)_2 = (10)_2 = 2$, and $0 \leq 2 \leq 2$.
Since there is only one pair which satisfies the first two conditions, this is also the pair with the smallest $(B - A)$, and hence is the only Xorry pair.
So, the only answer for this testcase is $(0, 2)$.

Note that $(10)_2$ refers to the binary representation of $2$.

 **Test case 3:**  $X = 3 = (11)_2$. There are two pairs which satisfy the first two conditions:

- $A = 0$, and $B = 3$
- $A = 1$, and $B = 2$ $(1, 2)$ satisfies both the conditions, since $(01)_2 \oplus (10)_2 = (11)_2 = 3$, and $1 \leq 2 \leq 3$. Among these two pairs, $(B-A)$ is smallest only in the second pair. Hence the only Xorry pair is $A = 1$, and $B = 2$. So, the only answer for this testcase is $(1, 2)$.

 **Test case 4:**  $X = 4 = (100)_2$. The only pair of integers which satisfies the first two conditions is $A = 0$, and $B = 4$.
This satisfies the first two conditions, since $(000)_2 \oplus (100)_2 = (100)_2 = 4$, and $0 \leq 4 \leq 4$.
Since there is only one pair which satisfies the first two conditions, this is also the pair with the smallest $(B - A)$, and hence is the only Xorry pair.
So, the only answer for this testcase is $(0, 4)$.

 **Test case 5:**  $X = 6 = (110)_2$. There are three pairs which satisfy the first two conditions:

- $A = 0$, and $B = 6$
- $A = 2$, and $B = 4$
- $A = 3$, and $B = 5$ $(3, 5)$ satisfies both the conditions, since $(011)_2 \oplus (101)_2 = (110)_2 = 6$, and $3 \leq 5 \leq 6$. But among these three pairs, $(B-A)$ is smallest only in the last two pairs, which have $(B-A)$ as $2$, whereas the first pair has $(B-A)$ as $6$. Hence the only Xorry pairs are $A = 2$, and $B = 4$, and $A = 3$, and $B = 5$. So, the two possible answers for this testcase are $(2, 4)$, or $(3, 5)$. You need to output any one of these two pairs.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-24T10:10:53.403Z  

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

    cout << (n ^ (1LL << __lg(n))) << " " << (1LL << __lg(n)) << endl;
}

signed main()
{
    fast_io

        int t;
    cin >> t;
    while (t--)
    {
        solve();
        // cout << "*****************************************" << endl;
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/XORRY1)