def is_safe(board, row, col, n):
    # Check same column
    for i in range(row):
        if board[i] == col:
            return False

    # Check left diagonal
    for i, j in zip(range(row - 1, -1, -1),
                    range(col - 1, -1, -1)):
        if board[i] == j:
            return False

    # Check right diagonal
    for i, j in zip(range(row - 1, -1, -1),
                    range(col + 1, n)):
        if board[i] == j:
            return False

    return True


def solve_backtracking(n):
    board = [-1] * n

    def solve(row):
        if row == n:
            print("Backtracking Solution:", board)
            return True

        for col in range(n):
            if is_safe(board, row, col, n):
                board[row] = col

                if solve(row + 1):
                    return True

        return False

    solve(0)


def solve_branch_and_bound(n):
    board = [-1] * n

    cols = [False] * n
    diag1 = [False] * (2 * n)  # row + col
    diag2 = [False] * (2 * n)  # row - col + n - 1

    def solve(row):
        if row == n:
            print("Branch & Bound Solution:", board)
            return True

        for col in range(n):
            if (not cols[col] and
                not diag1[row + col] and
                not diag2[row - col + n - 1]):

                # Place queen
                board[row] = col
                cols[col] = True
                diag1[row + col] = True
                diag2[row - col + n - 1] = True

                if solve(row + 1):
                    return True

                # Backtrack
                cols[col] = False
                diag1[row + col] = False
                diag2[row - col + n - 1] = False

        return False

    solve(0)


n = int(input("Enter number of queens: "))

solve_backtracking(n)
solve_branch_and_bound(n)

"""
============================================================================
                                THEORY
============================================================================

AIM:
To solve N-Queens problem using:
1. Backtracking
2. Branch and Bound

----------------------------------------------------------------------------

WHAT IS N-QUEENS PROBLEM?

Place N queens on N×N chessboard such that:
- No two queens attack each other.

Queens attack:
1. Same row
2. Same column
3. Same diagonal

Example for N = 4:

 Q . . .
 . . Q .
 . Q . .
 . . . Q

----------------------------------------------------------------------------

WHAT IS BACKTRACKING?

Backtracking:
- Tries all possible solutions
- Rejects invalid solutions
- Goes back and tries another path

It is a recursive problem-solving technique.

----------------------------------------------------------------------------

WORKING OF BACKTRACKING

1. Place queen in safe position
2. Move to next row
3. If no safe position exists:
   BACKTRACK
4. Remove previous queen
5. Try another position

----------------------------------------------------------------------------

WHAT IS BRANCH AND BOUND?

Optimized version of backtracking.

Uses:
- Boolean arrays
- Fast conflict checking

Arrays used:
1. cols[]
2. diag1[]
3. diag2[]

This reduces repeated checking.

----------------------------------------------------------------------------

TIME COMPLEXITY:

Worst Case:
:contentReference[oaicite:0]{index=0}

Because many combinations are checked.

----------------------------------------------------------------------------

SPACE COMPLEXITY:
:contentReference[oaicite:1]{index=1}

----------------------------------------------------------------------------

ADVANTAGES:
1. Efficient pruning
2. Faster than brute force
3. Good AI problem example

----------------------------------------------------------------------------

APPLICATIONS:
1. AI search problems
2. Constraint satisfaction problems
3. Scheduling problems
4. Puzzle solving

----------------------------------------------------------------------------

OUTPUT EXAMPLE:

Enter number of queens: 4

Backtracking Solution:
[1, 3, 0, 2]

Branch & Bound Solution:
[1, 3, 0, 2]

Meaning:
Row 0 → Queen at column 1
Row 1 → Queen at column 3
Row 2 → Queen at column 0
Row 3 → Queen at column 2

----------------------------------------------------------------------------

VIVA QUESTIONS:

1. What is Backtracking?
Trying all possibilities and rejecting invalid ones.

2. What is pruning?
Removing branches that cannot give solution.

3. Difference between Backtracking and Branch & Bound?
Branch & Bound uses optimization and faster checking.

4. How many solutions exist for 8 queens?
92 solutions.

============================================================================
"""