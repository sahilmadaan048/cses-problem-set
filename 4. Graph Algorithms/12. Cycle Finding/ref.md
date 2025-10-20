Perfect — let’s go through this line-by-line 👇
This section of code is where the **negative cycle is detected and reconstructed** after running the **Bellman–Ford algorithm**.

---

### 🔹 Step 1: Detect a vertex inside a negative cycle

```cpp
for (auto &[u, vec] : mpp)
{
    for (auto &[v, w] : vec)
    {
        if (u <= n && v <= n && dist[u] + w < dist[v])
        {
            parent[v] = u;
            x = v; // vertex part of a negative cycle
            break;
        }
    }
    if (x != -1)
        break;
}
```

#### 💡 What’s happening:

* This is the **Nth relaxation step** of Bellman–Ford.
* Normally, after `n-1` relaxations, the shortest paths stabilize.
* If we can **still relax an edge** (`dist[u] + w < dist[v]`),
  it means there’s a **negative cycle** reachable from the source.

#### 🔍 Line-by-line:

* `for (auto &[u, vec] : mpp)` → iterate over all edges of the graph (`mpp` stores adjacency lists).
* `for (auto &[v, w] : vec)` → iterate over all outgoing edges from node `u` (`v` is destination, `w` is weight).
* `if (dist[u] + w < dist[v])` → we found an edge that can still be relaxed → indicates a negative cycle.
* `parent[v] = u;` → store the parent of `v` to later reconstruct the cycle.
* `x = v;` → mark `v` as a vertex inside the negative cycle.
* `break;` statements break out early once a negative cycle vertex is found.

---

### 🔹 Step 2: Check if a cycle was found

```cpp
if (x == -1)
    return false; // no negative cycle
```

If no vertex was marked (`x == -1`), then no negative cycle exists → return `false`.

---

### 🔹 Step 3: Move `x` inside the actual cycle

```cpp
for (int i = 0; i < n; i++)
    x = parent[x];
```

#### 💡 Why this is needed:

The vertex `x` we found may not be *exactly inside* the cycle — it might just be *reachable* from it.
By walking backward `n` times using the parent pointers, we **guarantee that `x` is inside the cycle**, since a cycle in a graph with `n` nodes must repeat within `n` steps.

---

### 🔹 Step 4: Reconstruct the actual cycle

```cpp
int start = x;
temp.push_back(start);
x = parent[start];

while (x != start)
{
    temp.push_back(x);
    x = parent[x];
}
temp.push_back(start);
reverse(temp.begin(), temp.end());
```

#### 💡 What’s happening:

* Start from `x` (which is confirmed inside the cycle).
* Keep following the `parent` links until you come back to the starting node.
* Push all those nodes into `temp` — this collects **one full cycle**.
* Add the start again at the end (so it clearly forms a loop, e.g., `2 3 4 2`).
* Finally, `reverse(temp.begin(), temp.end())` because we traced the cycle **backwards** using parent links — reversing gives the correct forward order.

---

### 🧠 Example Trace

Suppose we have edges:

```
2 → 3 (-1)
3 → 4 (-1)
4 → 2 (-1)
```

At the end of Bellman–Ford:

* `dist[2] + (-1) < dist[3]` → true ⇒ `x = 3`
* We backtrack 4 times → `x` ends up inside the cycle (say at node 2)
* Now we follow parents: `2 → 4 → 3 → 2`
* After reversing → `2 3 4 2`

`temp = {2, 3, 4, 2}` ✅

---

### 🔹 Step 5: Return `true`

Finally:

```cpp
return true;
```

→ The graph contains a negative cycle, and `temp` now holds its sequence of nodes.

---

### 🧩 Summary Table

| Section                                      | Purpose                                           |
| -------------------------------------------- | ------------------------------------------------- |
| First `for` loop                             | Detects an edge that indicates a negative cycle   |
| `x = v`                                      | Marks a vertex that lies on or leads to the cycle |
| `for (int i = 0; i < n; i++) x = parent[x];` | Moves `x` definitely inside the cycle             |
| `while (x != start)`                         | Collects all nodes in the cycle                   |
| `reverse(temp.begin(), temp.end())`          | Gives cycle in forward order                      |

---

Would you like me to show a **dry run** of this reconstruction (with actual parent array updates) for a small input example like `1→2→3→1`? It’ll make the idea crystal clear.
