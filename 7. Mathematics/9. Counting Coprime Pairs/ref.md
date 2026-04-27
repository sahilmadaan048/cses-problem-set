Totally fair — Möbius can feel like magic when first seen. Let’s build intuition first.

## We want:

Count pairs with

[
\gcd(a_i,a_j)=1
]

Example:

```text id="0nuygn"
[2,3,4,5]
```

All pairs:

```text id="91j0hq"
(2,3)
(2,4)
(2,5)
(3,4)
(3,5)
(4,5)
```

Only `(2,4)` is not coprime.

Answer = 5.

---

# Step 1: Start with all pairs

Number of pairs:

[
\binom n2
]

For 4 elements:

[
6
]

---

# Step 2: Remove bad pairs (gcd >1)

Bad pairs share some common divisor >1.

For example:

Divisible by 2:

```text id="9b1iyv"
2,4
```

One bad pair:

```text id="pmofw1"
C(2,2)=1
```

So maybe subtract that?

Seems okay here.

---

## But what if overlaps happen?

Take:

```text id="03z8q3"
[6,10,15]
```

Pairs:

* (6,10) gcd=2
* (6,15) gcd=3
* (10,15) gcd=5

No coprime pairs.

---

Now count bad pairs.

Pairs sharing factor 2:

```text id="vh3wqg"
(6,10)
```

1 pair

Sharing factor 3:

```text id="85tguj"
(6,15)
```

1 pair

Sharing factor 5:

```text id="b45x7n"
(10,15)
```

1 pair

Subtract all:

```text id="m4h04j"
3
```

works.

---

## But now try:

```text id="n6t8rs"
[6,12,18]
```

Every pair shares factors.

All 3 pairs bad.

---

Count bad pairs divisible by 2:

all 3 pairs.

Subtract 3.

Count bad pairs divisible by 3:

again all 3 pairs.

Subtract another 3.

Oops:

```text id="f49pk1"
subtracted 6
```

but only 3 bad pairs exist.

Double-counted.

---

# Inclusion-Exclusion fixes this

* subtract multiples of primes
* add back overlaps
* subtract triple overlaps
* etc.

That alternating mess is exactly what Möbius automates.

---

# Where does

[
\sum \mu(d)\binom{cnt[d]}2
]

come from?

For each divisor `d`:

Count pairs where both numbers divisible by `d`.

That is:

```text id="1twq7o"
C(cnt[d],2)
```

Then multiply by:

[
\mu(d)
]

which tells whether to:

* add
* subtract
* ignore

---

## Möbius values

For d:

### d=1

[
\mu(1)=1
]

add.

---

### d prime

Example 2,3,5:

[
\mu=-1
]

subtract.

---

### Product of two distinct primes

Example:

```text id="j1f6lu"
6 = 2×3
```

[
\mu(6)=+1
]

add back overlap.

---

### Square factor exists

Example:

```text id="nux50a"
12=2²×3
```

[
\mu(12)=0
]

ignore.

---

So Möbius is basically compressed inclusion-exclusion.

---

## For our first example

```text id="fuknsm"
[2,3,4,5]
```

Compute counts:

Divisible by 1:

```text id="nscys8"
4 numbers
C(4,2)=6
```

Contribution:

```text id="w6g8gc"
+6
```

---

Divisible by 2:

2,4

```text id="pw4q0u"
C(2,2)=1
```

μ(2)=-1

Contribution:

```text id="grvskm"
-1
```

---

Divisible by 3:

only one number → 0

Divisible by 5:

0

Others contribute 0.

Total:

```text id="k4w7h3"
6-1=5
```

Correct.

---

## Intuition Summary

It is just:

> Count all pairs
> subtract pairs sharing factors
> fix overcounting automatically using Möbius

Möbius is just a prepackaged inclusion-exclusion coefficient.

---

If you want, I can also show how competitive programmers derive that formula from scratch instead of memorizing it.
