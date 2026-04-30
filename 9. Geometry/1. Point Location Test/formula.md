# 🎯 The Goal

Given three points:

* A(x₁, y₁)
* B(x₂, y₂)
* C(x₃, y₃)

We want to know:

> When moving from **A → B**, is point C to the LEFT or RIGHT?

---

# Step 1️⃣ Convert Points to Vectors

Instead of thinking in absolute coordinates, shift origin to A.

Define vectors:

[
\vec{AB} = (x₂ - x₁,, y₂ - y₁)
]

[
\vec{AC} = (x₃ - x₁,, y₃ - y₁)
]

Now the problem becomes:

> Is vector AC to the left or right of vector AB?

---

# Step 2️⃣ What Measures "Left or Right"?

In 2D, the tool that measures turning direction between two vectors is the **cross product**.

For 2D vectors:

[
\vec{u} = (u₁, u₂)
]
[
\vec{v} = (v₁, v₂)
]

The 2D cross product is defined as:

[
u₁v₂ - u₂v₁
]

---

# Step 3️⃣ Why This Formula?

In 3D, cross product gives a vector perpendicular to both.

In 2D, we embed vectors into 3D:

[
(u₁, u₂, 0)
]
[
(v₁, v₂, 0)
]

Their 3D cross product is:

[
(0, 0, u₁v₂ - u₂v₁)
]

Only the **z-component** exists.

That scalar value:

[
u₁v₂ - u₂v₁
]

is what we use.

---

# Step 4️⃣ What Does It Represent Geometrically?

It equals:

[
|\vec{u}| \cdot |\vec{v}| \cdot \sin(\theta)
]

Where θ is angle from u to v.

So:

* If θ is counter-clockwise → sin(θ) > 0 → positive
* If θ is clockwise → sin(θ) < 0 → negative
* If θ = 0 or 180 → sin(θ)=0 → collinear

So sign tells direction of rotation.

---

# Step 5️⃣ Apply to Points

Plug in:

[
\vec{AB} = (x₂-x₁, y₂-y₁)
]
[
\vec{AC} = (x₃-x₁, y₃-y₁)
]

Cross product:

[
(x₂-x₁)(y₃-y₁) - (y₂-y₁)(x₃-x₁)
]

That’s the orientation formula.

---

# Step 6️⃣ Why Does Sign Mean Left/Right?

Visualize standard coordinate system:

* x-axis right
* y-axis up

If cross > 0:

Vector AC is obtained by rotating AB counter-clockwise
→ C lies on LEFT side.

If cross < 0:

Rotation is clockwise
→ C lies on RIGHT side.

---

# Step 7️⃣ Another Interpretation (Very Important)

Cross product = **2 × signed area of triangle ABC**

The signed area formula of triangle:

[
Area = \frac{1}{2}
\begin{vmatrix}
x₁ & y₁ & 1 \
x₂ & y₂ & 1 \
x₃ & y₃ & 1
\end{vmatrix}
]

Expanding determinant gives exactly:

[
(x₂-x₁)(y₃-y₁) - (y₂-y₁)(x₃-x₁)
]

So:

* Positive area → points are counter-clockwise
* Negative area → clockwise
* Zero → collinear

That’s why it works.

---

# 🔥 Intuition Summary

The formula:

```
(x2-x1)*(y3-y1) - (y2-y1)*(x3-x1)
```

is:

* Determinant
* Signed triangle area
* 2D cross product
* |AB||AC|sinθ

All the same thing.

---

# 🧠 Why Slopes Are Bad

Slope method:

[
(y₂-y₁)/(x₂-x₁)
]

Problems:

* Division by zero
* Floating point precision
* Harder logic

Cross product:

* Pure integer math
* No division
* Works for vertical lines
* O(1)

---

# 🎯 The Big Idea

Whenever you see:

* Turn direction
* Polygon area
* Convex hull
* Segment intersection

Think:

> Determinant / Cross Product
