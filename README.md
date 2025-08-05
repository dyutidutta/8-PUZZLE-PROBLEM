
# 8-Puzzle Problem using BFS and DFS in C++

## Problem Statement

The **8-Puzzle Problem** is a classic problem in artificial intelligence and graph theory. It consists of a 3x3 grid with tiles numbered 1 through 8 and one empty space (represented as `0`). The goal is to move the tiles into the correct position by sliding them one at a time into the empty space, ultimately reaching a predefined goal state.

## Objectives

- Implement **Breadth-First Search (BFS)** to check if a solution exists by exploring states level by level.
- Implement **Depth-First Search (DFS)** to determine if the goal state can be reached via depth exploration.


---

## Data Structures Used

| Component         | Data Structure            | Purpose                                          |
|-------------------|---------------------------|--------------------------------------------------|
| Puzzle State      | `vector<vector<int>>`     | 3x3 matrix to represent the puzzle.              |
| Visited Set       | `unordered_set<string>`   | Stores string representations of visited states. |
| Frontier (BFS)    | `queue<Matrix>`           | Stores states to explore next in BFS.            |
| Frontier (DFS)    | `stack<Matrix>`           | Stores states to explore next in DFS.            |
| State Generation  | `list<Matrix>`            | Stores all valid next states.                    |

---

## Algorithm: Breadth-First Search (BFS)

```cpp
void bfs(Matrix prob, Matrix sol)
{
    queue<Matrix> q;
    unordered_set<string> closed;

    q.push(prob);
    closed.insert(matrixToString(prob));

    while (!q.empty())
    {
        Matrix A = q.front();
        q.pop();

        if (A == sol)
        {
            cout << "Success!" << endl;
            return;
        }

        list<Matrix> states = genmove(A);
        for (auto state : states)
        {
            string str = matrixToString(state);
            if (closed.find(str) == closed.end())
            {
                closed.insert(str);
                q.push(state);
            }
        }
    }

    cout << "Failed!" << endl;
}
```

---

## Algorithm: Depth-First Search (DFS)

```cpp
void dfs(Matrix prob, Matrix sol)
{
    stack<Matrix> s;
    unordered_set<string> closed;

    s.push(prob);
    closed.insert(matrixToString(prob));

    while (!s.empty())
    {
        Matrix A = s.top();
        s.pop();

        if (A == sol)
        {
            cout << "Success!" << endl;
            return;
        }

        list<Matrix> states = genmove(A);
        for (auto state : states)
        {
            string str = matrixToString(state);
            if (closed.find(str) == closed.end())
            {
                closed.insert(str);
                s.push(state);
            }
        }
    }

    cout << "Failed!" << endl;
}
```

---

## State Generation

```cpp
list<Matrix> genmove(Matrix state)
{
    list<Matrix> nextStates;
    int a, b;

    // Locate blank space (0)
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (state[i][j] == 0)
            {
                a = i;
                b = j;
            }

    // Try all 4 directions: up, down, left, right
    if (a - 1 >= 0) { Matrix A1 = state; swap(A1[a][b], A1[a - 1][b]); nextStates.push_back(A1); }
    if (a + 1 < 3) { Matrix A2 = state; swap(A2[a][b], A2[a + 1][b]); nextStates.push_back(A2); }
    if (b - 1 >= 0) { Matrix A3 = state; swap(A3[a][b], A3[a][b - 1]); nextStates.push_back(A3); }
    if (b + 1 < 3) { Matrix A4 = state; swap(A4[a][b], A4[a][b + 1]); nextStates.push_back(A4); }

    return nextStates;
}
```

---

## Utility Function

```cpp
string matrixToString(Matrix mat)
{
    string s;
    for (auto row : mat)
        for (int val : row)
            s += to_string(val);
    return s;
}
```

Converts a 3x3 matrix into a flat string for hashing and lookup in `unordered_set`.

---

## Use Cases

- **AI Research & Teaching**: Introduces concepts of uninformed search, state space, and heuristics.
- **Pathfinding**: Demonstrates basic BFS and DFS applications in graph traversal.
- **Game Solvers**: Foundation for solving board-based problems (Sudoku, Rubik’s cube).
- **Interview Preparation**: Common example in system design and AI interviews.

---

## Sample Outputs

**Initial (Start) State:**

```
1 2 3
4 5 6
8 7 0
```

**Goal (Solution) State:**

```
1 2 3
4 5 6
7 8 0
```
### BFS Output:
```
Failed!
```

**Initial (Start) State:**

```
1 2 3
4 5 6
0 7 8
```

**Goal (Solution) State:**

```
1 2 3
4 5 6
7 8 0
```
### DFS Output:
```
Success!
```



## Files

| Filename                 | Description                                  |
|--------------------------|----------------------------------------------|
| `8_PUZZLE_BFS.cpp`       | BFS-based 8-puzzle solver                    |
| `8_PUZZLE_DFS.cpp`       | DFS-based 8-puzzle solver                    |
| `README.md`              | Explanation and documentation                |


