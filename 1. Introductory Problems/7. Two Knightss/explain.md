This C++ function `calculateWays(int K)` calculates the number of **ways to place two knights on a `K x K` chessboard such that they do not attack each other**.

Let’s break it down line by line:

---

### 🧠 Concept:

- Two knights **can attack each other** if they are placed in certain relative positions (L-shaped move in 8 directions).
- The goal is to count **all possible unique placements** of two knights and subtract the **ones where they can attack each other**.

---

### 🔍 Step-by-step Explanation:

```cpp
long totalWays = ((long) K * K * (K * K - 1)) / 2;
```

- This calculates the **total number of ways to choose 2 squares** out of `K * K` to place the knights.
- Formula: **nC2 = (n*(n-1))/2** where `n = K*K`
- This gives all **distinct pairs** of squares for the knights (order doesn't matter).

---

```cpp
long attackingWays = 4 * (K - 1) * (K - 2);
```

- This calculates the number of ways the two knights **can attack each other**.
- On a `K x K` board, a pair of knights can attack each other in **2x3** or **3x2** L-shapes.
- There are:
  - `(K - 1) * (K - 2)` positions for 2x3 rectangles.
  - Same number for 3x2 rectangles.
- Each such rectangle allows **2 knight attacks**, so total is `4 * (K - 1) * (K - 2)`

---

```cpp
long ans = totalWays - attackingWays;
```

- Subtracting the **attacking arrangements** from the **total arrangements** gives the number of **non-attacking arrangements**.

---

```cpp
return ans;
```

- Return the final answer.

---

### ✅ Example:

Let’s try `K = 3`:
- `totalWays = (9 * 8) / 2 = 36`
- `attackingWays = 4 * (2) * (1) = 8`
- `ans = 36 - 8 = 28` → So, 28 ways to place two knights on a 3x3 board without attacking each other.

---

Let me know if you want a dry run for a specific value of `K`!