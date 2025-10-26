Sure 🙂 Let’s break the code down step by step so you fully understand what’s happening.

---

## 🔍 Problem Recap

We need to compute:
[
C(a, b) = \frac{a!}{b! \cdot (a-b)!} \mod 10^9+7
]

for up to ( n = 10^5 ) queries, where ( a, b \le 10^6 ).

Directly computing factorials every time would be **too slow**, so we precompute them once and reuse.

---

## 🧠 Key Idea — Modular Inverses

Because we’re working **mod 1e9+7 (a prime number)**, we can’t divide directly.

We use **Fermat’s Little Theorem**:
[
x^{-1} \equiv x^{MOD-2} \pmod{MOD}
]
That means to divide by something modulo (MOD), we multiply by its modular inverse.

So:
[
C(a,b) = fact[a] \times inv(fact[b]) \times inv(fact[a-b]) \pmod{MOD}
]

---

## 🧩 Step-by-Step Explanation of the Code

```cpp
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
```

* We include all standard headers.
* Define `MOD = 1e9 + 7`.

---

### 1️⃣ Function to Compute Power (Fast Exponentiation)

```cpp
long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}
```

* Computes ( a^e \mod MOD ) efficiently in **O(log e)** time.
* Used to compute modular inverses via ( a^{MOD-2} \mod MOD ).

---

### 2️⃣ Precomputing Factorials and Inverse Factorials

```cpp
const int MAXN = 1e6;
vector<long long> fact(MAXN + 1), ifact(MAXN + 1);
fact[0] = 1;
for (int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
```

* `fact[i]` stores ( i! \mod MOD ).
* We build this iteratively — each factorial is the previous factorial × `i`.

---

### 3️⃣ Precomputing Inverse Factorials

```cpp
ifact[MAXN] = modpow(fact[MAXN], MOD - 2);
for (int i = MAXN; i >= 1; i--) ifact[i - 1] = ifact[i] * i % MOD;
```

* First, we compute the modular inverse of `fact[MAXN]` using Fermat’s theorem.
* Then, we compute all smaller inverse factorials efficiently:
  [
  ifact[i-1] = ifact[i] \times i \pmod{MOD}
  ]
  (since ((i-1)!^{-1} = i!^{-1} \times i))

This fills `ifact[i]` for all i in O(MAXN).

---

### 4️⃣ Answering Queries

```cpp
while (n--) {
    int a, b;
    cin >> a >> b;
    if (b < 0 || b > a) {
        cout << 0 << '\n';
        continue;
    }
    long long res = fact[a] * ifact[b] % MOD * ifact[a - b] % MOD;
    cout << res << '\n';
}
```

For each query:

1. We read `a` and `b`.
2. If `b` is invalid, print `0`.
3. Compute:
   [
   C(a,b) = fact[a] \times ifact[b] \times ifact[a-b] \pmod{MOD}
   ]
4. Output the result.

---

## ⚙️ Complexity Analysis

* **Precomputation:** ( O(10^6) )
* **Each Query:** ( O(1) )
* **Memory:** Two arrays of size ( 10^6 ) (~16 MB total)

This is **fast enough** for ( n = 10^5 ) queries easily.

---

## ✅ Example

Input:

```
3
5 3
8 1
9 5
```

Step-by-step:

* ( C(5,3) = 10 )
* ( C(8,1) = 8 )
* ( C(9,5) = 126 )

Output:

```
10
8
126
```

---

Would you like me to show a small dry run (like how `fact` and `ifact` get built for small numbers)?
