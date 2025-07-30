Sure! Here's a step-by-step **workflow explanation** of how the code solves the 8-queens problem with reserved squares:

---

### 🧠 **Goal**  
Place 8 queens on an 8×8 chessboard such that:
- No two queens attack each other.
- Queens are only placed on **free squares** (denoted by `.`).
- Reserved squares (`*`) **cannot hold queens**, but queens can still attack over them.

---

### 🔧 **Key Variables**
```cpp
char board[8][8];       // Input board: each cell is '.' (free) or '*' (reserved)
bool col[8];            // col[i] = true if column i already has a queen
bool diag1[15];         // diag1[i] = true if main diagonal (↘️) is occupied
bool diag2[15];         // diag2[i] = true if anti-diagonal (↙️) is occupied
int ways = 0;           // Counter for valid queen placements
```

---

### 🔄 **Backtracking Function: `solve(row)`**
This function attempts to place a queen in `row`, trying all 8 columns.

#### Base Case:
```cpp
if (row == 8) {
    ways++;
    return;
}
```
- If we've placed queens in all 8 rows, that's a valid configuration → increment `ways`.

#### Try placing a queen in every column:
```cpp
for (int c = 0; c < 8; ++c)
```

Inside the loop:
```cpp
if (board[row][c] == '*' || col[c] || diag1[row - c + 7] || diag2[row + c])
    continue;
```
- Skip if:
  - The square is reserved (`*`)
  - A queen already exists in the same column (`col[c]`)
  - A queen already exists on the same diagonals (`diag1`, `diag2`)

If the spot is valid:
```cpp
col[c] = diag1[row - c + 7] = diag2[row + c] = true;
solve(row + 1);
col[c] = diag1[row - c + 7] = diag2[row + c] = false;
```
- **Place** the queen.
- **Recurse** to the next row.
- **Backtrack**: remove the queen and try the next column.

---

### 🧮 **Diagonal Indexing**
- Diagonal `↘` (main) → `row - col` → ranges from -7 to 7 → shift by +7 → `row - col + 7`
- Diagonal `↙` (anti) → `row + col` → ranges from 0 to 14

---

### 🧪 **Input**
```cpp
for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
        cin >> board[i][j];
```
Reads 8 lines of 8 characters each: either `.` or `*`.

---

### 📤 **Output**
```cpp
cout << ways << endl;
```
Prints the total number of valid placements of 8 queens following the rules.

---

### ✅ Example Input:
```
........
........
..*.....
........
........
.....**.
...*....
........
```

### ✅ Output:
```
65
```

Means there are **65 valid arrangements** of 8 queens that satisfy all constraints.

---

Let me know if you’d like to visualize the board during recursion or step through an example configuration!