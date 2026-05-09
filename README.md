<div align="center">

```
██████╗ ██████╗ ████████╗
██╔══██╗██╔══██╗╚══██╔══╝
██████╔╝██████╔╝   ██║   
██╔══██╗██╔══██╗   ██║   
██║  ██║██████╔╝   ██║   
╚═╝  ╚═╝╚═════╝    ╚═╝   
```

# 🔴⚫ Red-Black Tree in C

**A complete, colorful, menu-driven Red-Black Tree built from scratch in C**  
Implements all core RB operations with vivid ANSI terminal colors, live before/after balancing views, and sideways tree visualization — following CLRS Chapter 13.

[![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Standard](https://img.shields.io/badge/Standard-C99-orange?style=for-the-badge)](https://en.wikipedia.org/wiki/C99)
[![Build](https://img.shields.io/badge/Build-Makefile-brightgreen?style=for-the-badge&logo=gnu)](https://www.gnu.org/software/make/)
[![Reference](https://img.shields.io/badge/Reference-CLRS_Ch.13-red?style=for-the-badge)](https://en.wikipedia.org/wiki/Introduction_to_Algorithms)


</div>

---

## ✨ What Makes This Special

This isn't just another tree implementation — every single operation outputs **fully colored terminal feedback** that makes the data structure come alive:

| Color | Meaning |
|-------|---------|
| 🔴 **Bold Red** | RED nodes, error messages, delete prompts |
| ⚪ **Bold White** | BLACK nodes |
| 🟢 **Green** | Success messages, insert prompts |
| 🔵 **Blue** | Tree state *before* balancing |
| 🟣 **Magenta** | Tree state *after* balancing |
| 🩵 **Cyan** | Menu borders, continue prompts |
| 🟡 **Yellow** | Menu options |

Every **insertion** shows the tree **before** rotations and **after** — so you can watch the RB fixup happen in real time.

---

## 🧠 How a Red-Black Tree Works

A **Red-Black Tree** is a self-balancing Binary Search Tree. Each node stores an extra bit — its **color** (RED or BLACK). Five strict rules on colors guarantee the tree never goes out of balance.

### The 5 RB Properties

```
┌──────────┬────────────────────────────────────────────────────────────┐
│  Rule 1  │  Every node is either RED or BLACK                         │
│  Rule 2  │  The ROOT is always BLACK                                  │
│  Rule 3  │  Every leaf (NIL sentinel) is BLACK                        │
│  Rule 4  │  A RED node's children must BOTH be BLACK                  │
│          │  (no two consecutive RED nodes on any path)                │
│  Rule 5  │  All paths from any node to its descendant NIL leaves      │
│          │  contain the same number of BLACK nodes (same black-height)│
└──────────┴────────────────────────────────────────────────────────────┘
```

These rules together guarantee the tree height is always **≤ 2·log₂(n+1)** — making every operation **O(log n)** even in the worst case.

### Tree Visualization

This program prints trees **sideways** (right subtree at top, root in centre, left subtree at bottom). Each node shows its value and color:

```
                  30(B)          ← rightmost = largest
         20(R)
                  15(B)
10(B)                            ← root
                   7(B)
          5(R)
                   3(B)          ← leftmost = smallest
```

In the actual terminal, `30(B)` prints in **bold white** and `20(R)` prints in **bold red**.

---

## 📁 Project Structure

```
Red-Black-Tree/
│
├── rbt.h           ← 📋 ANSI color macros, Node struct, extern globals, all prototypes
├── main.c          ← 🎮 Colorful 9-option interactive menu driver
│
├── rbt_utils.c     ← 🔧 NIL sentinel, newNode(), printNode()
├── rotate.c        ← 🔄 leftRotate() and rightRotate() primitives
│
├── insert.c        ← ➕ rbInsert() + rbInsertFixup() — CLRS Cases 1, 2, 3 + mirrors
├── delete.c        ← ➖ rbTransplant() + rbDeleteFixup() + rbDelete() + deleteKey()
├── deletemin.c     ← ⬇️  deleteMinNode() — auto-find and delete smallest key
├── deletemax.c     ← ⬆️  deleteMaxNode() — auto-find and delete largest key
│
├── search.c        ← 🔍 rbSearch() — iterative O(log n) key lookup
├── findmin.c       ← 🔽 rbMinimum() — leftmost node in a subtree
├── findmax.c       ← 🔼 rbMaximum() — rightmost node in a subtree
├── display.c       ← 🖼️  printTree() + displayTree() — sideways colored output
│
└── Makefile        ← 🏗️  gcc, C99, -Wall -Wextra -g
```

---

## 🏗️ Build & Run

### Requirements

- **GCC** (any version supporting C99)
- **make**
- Linux / macOS / Windows (WSL or Git Bash — needs ANSI color support)

### One-Command Build & Run

```bash
git clone https://github.com/KishoreKK275/Red-Black-Tree.git
cd Red-Black-Tree
make run
```

### Step by Step

```bash
make                  # compiles → produces ./red_black_tree
./red_black_tree      # run the program
make clean            # remove all .o files and executable
make run              # compiles → produces ./red_black_tree → run the program
```

### Without make (manual)

```bash
gcc -Wall -Wextra -g -std=c99 \
    main.c rbt_utils.c rotate.c insert.c display.c \
    search.c findmin.c findmax.c delete.c deletemin.c deletemax.c \
    -o red_black_tree

./red_black_tree
```

> **Windows users:** If colors don't display, use **Windows Terminal**, **Git Bash**, or **WSL** — all support ANSI escape codes.

---

## 🎮 The 9 Operations — Complete Guide

When you run the program, you see this colorful menu:

```
=========================================
        RED BLACK TREE MENU
=========================================
 1. Create a tree
 2. Display
 3. Search a node
 4. Find Maximum node in Tree
 5. Find Minimum node in Tree
 6. Deletion
 7. Delete Minimum node
 8. Delete Maximum Node
 9. Exit
-----------------------------------------
Enter the choice:
```

---

### `1` — Insert (Create Tree)

Enter integers one at a time. The program asks `Do u want to continue (y/n)` after each insert.

**What happens internally:**
1. New node is always inserted as **RED**
2. BST walk finds the correct position
3. If this is the **2nd or later** node, the tree is shown **BEFORE** balancing (in blue)
4. `rbInsertFixup` runs — rotates and recolours as needed
5. Tree is shown **AFTER** balancing (in magenta)

**Sample output inserting 10, then 20:**
```
Enter the element: 10
Do u want to continue (y/n): y
Enter the element: 20

Before Balancing Red Black Tree is:
Red-Black Tree Structure:

      20(R)
10(B)

Now Tree is balance
Red-Black Tree Structure:

      20(B)
10(B)

Do u want to continue (y/n): n
```

> Duplicates are rejected: `Duplicate not allowed` (in red).

---

### `2` — Display

Prints the entire tree sideways. RED nodes in **bold red**, BLACK nodes in **bold white**.

```
Red-Black Tree Structure:

            30(B)
      20(R)
            15(B)
10(B)
      5(B)
```

Read it: the **root is on the left margin**, the **largest is at the top**, the **smallest is at the bottom**.

---

### `3` — Search

Enter any integer. The program walks left/right through the BST (O(log n)):

```
Enter the element which u want to search from the red black tree: 20
Node is found -> 20(R)
```

```
Enter the element which u want to search from the red black tree: 99
Node (99) not found in the tree.
```

---

### `4` — Find Maximum

Walks right from root until it can go no further. Prints the rightmost (largest) node.

```
Maximum node in the given Red Black Tree is 30(B)
```

---

### `5` — Find Minimum

Walks left from root until it can go no further. Prints the leftmost (smallest) node.

```
Minimum node in the given Red Black Tree is 5(B)
```

---

### `6` — Delete a Node by Key

The most complex operation. Enter the value to delete:

```
Enter the node which u want to delete: 10
```

**Three cases depending on children:**

| Node has | What happens |
|----------|-------------|
| No left child | Right child slides up directly |
| No right child | Left child slides up directly |
| **Two children** | In-order successor (smallest in right subtree) replaces it |

When a node has two children, the **successor's value is printed**:
```
Successor data: 15
```

After deletion, the tree is rebalanced via `rbDeleteFixup` and then displayed.

```
Tree After deleting the node:
Red-Black Tree Structure:

      30(B)
15(B)
      5(B)
```

---

### `7` — Delete Minimum

Automatically finds and deletes the leftmost (smallest) node. Shows tree **before and after**:

```
Tree Before deleting the minimum node:
Red-Black Tree Structure:
...

Tree After deleting the minimum node:
Red-Black Tree Structure:
...
```

---

### `8` — Delete Maximum

Automatically finds and deletes the rightmost (largest) node. Shows tree **before and after**.

---

### `9` — Exit

```
Exiting Red Black Tree Program...
```

---

## 🔬 Algorithm Details

### NIL Sentinel

Instead of using `NULL` pointers for leaf nodes, a single shared **NIL sentinel** node is allocated at startup:
- Always colored **BLACK**
- All leaf pointers and the initial root point to it
- Eliminates redundant NULL checks — this is the standard CLRS approach

### Insert Fixup — 3 Cases + Mirrors

After insertion, the new RED node may violate Rule 4 (red parent). `rbInsertFixup` walks up the tree:

```
Case 1 │ Uncle is RED
       │ → Recolour parent + uncle to BLACK, grandparent to RED
       │ → Move z up to grandparent, continue
───────┼──────────────────────────────────────────────────────
Case 2 │ Uncle is BLACK, z is an INNER grandchild (zig-zag)
       │ → Rotate z's parent → converts to Case 3
───────┼──────────────────────────────────────────────────────
Case 3 │ Uncle is BLACK, z is an OUTER grandchild (zig-zig)
       │ → Recolour + rotate grandparent → DONE
```

Each case has a **mirror** for when the parent is a right child.

### Delete Fixup — 4 Cases + Mirrors

Removing a BLACK node creates an "extra black" on one path — violating Rule 5. `rbDeleteFixup` eliminates this:

```
Case 1 │ Sibling w is RED
       │ → Rotate + recolour → falls into Case 2/3/4
───────┼──────────────────────────────────────────────────────
Case 2 │ Sibling's both children are BLACK
       │ → Recolour w RED → move extra black up to parent
───────┼──────────────────────────────────────────────────────
Case 3 │ Sibling's far child is BLACK (near child RED)
       │ → Rotate + recolour → converts to Case 4
───────┼──────────────────────────────────────────────────────
Case 4 │ Sibling's far child is RED
       │ → Rotate + recolour → DONE
```

### Rotations

```
LEFT ROTATE at x:                RIGHT ROTATE at x:

      x                                  x
     / \          ──►                   / \           ──►
    A   y                              y   C
       / \                            / \
      B   C                          A   B

             y                                 y
            / \                               / \
           x   C                             A   x
          / \                                   / \
         A   B                                 B   C
```

---

## ⏱️ Complexity Reference

| Operation | Time | Space |
|-----------|------|-------|
| Insert | O(log n) | O(1) extra |
| Delete | O(log n) | O(1) extra |
| Search | O(log n) | O(1) |
| Find Min / Max | O(log n) | O(1) |
| Display | O(n) | O(n) recursion |

> Height guarantee: **h ≤ 2·log₂(n+1)** — always balanced.

---

## 🎯 Suggested Test Session

Try this sequence right after running to see all features:

```
1 → Insert: 50, 30, 70, 20, 40, 60, 80, 10, 25
    (watch the colourful before/after on each insert)

2 → Display the complete tree

5 → Find minimum → should be 10
4 → Find maximum → should be 80

3 → Search 40 → found
3 → Search 99 → not found

6 → Delete 50 (root, two children → successor shown)
7 → Delete minimum (10)
8 → Delete maximum (80)

2 → Display final tree
9 → Exit
```

---

## 📚 Reference

> **Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein**  
> *Introduction to Algorithms* (CLRS) — **Chapter 13: Red-Black Trees**  
> MIT Press, 4th Edition

---

## 🔮 Future Scope

- [ ] Pre-order and post-order traversal options
- [ ] Black-height verifier
- [ ] Export tree to Graphviz DOT format
- [ ] Count total nodes
- [ ] Find in-order successor / predecessor of any key
- [ ] Range query — find all keys between A and B

---

## 👤 Author

**Kishore Kasireddy**  
📧 [kishorekasireddi4@gmail.com](mailto:kishorekasireddi4@gmail.com)  
🔗 [LinkedIn](https://linkedin.com/in/kishore-kasireddy)  
🐙 [GitHub](https://github.com/KishoreKK275)

---

<div align="center">

**⭐ Star this repo if it helped you understand Red-Black Trees!**

*Built with ❤️ and a lot of rotations*

</div>
