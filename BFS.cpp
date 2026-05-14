#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int startNode)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            cout << curr << " ";

            for (int neighbor : adj[curr])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }

    void DFSUtil(int curr, vector<bool> &visited)
    {
        visited[curr] = true;
        cout << curr << " ";

        for (int neighbor : adj[curr])
        {
            if (!visited[neighbor])
            {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int startNode)
    {
        vector<bool> visited(V, false);

        cout << "DFS Traversal: ";
        DFSUtil(startNode, visited);

        cout << endl;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "Starting from node 0:\n";

    g.BFS(0);
    g.DFS(0);

    return 0;
}

/*
============================================================================
                                THEORY
============================================================================

AIM:
To implement Breadth First Search (BFS) and Depth First Search (DFS)
graph traversal algorithms using C++.

----------------------------------------------------------------------------

WHAT IS GRAPH?
A graph is a collection of:
1. Vertices (Nodes)
2. Edges (Connections)

Example:
        0
       / \
      1   2
     / \
    3   4

----------------------------------------------------------------------------

BFS (Breadth First Search):
- Traverses graph level by level.
- Uses Queue (FIFO).
- Visits nearest nodes first.

Traversal:
0 → 1 → 2 → 3 → 4

Applications:
- Shortest path
- GPS systems
- Social networks

Time Complexity:
:contentReference[oaicite:0]{index=0}

----------------------------------------------------------------------------

DFS (Depth First Search):
- Traverses graph depth-wise.
- Uses Recursion or Stack.
- Goes deep before backtracking.

Traversal:
0 → 1 → 3 → 4 → 2

Applications:
- Cycle detection
- Maze solving
- Backtracking

Time Complexity:
:contentReference[oaicite:1]{index=1}

----------------------------------------------------------------------------

DIFFERENCE BETWEEN BFS AND DFS

BFS:
- Uses Queue
- Level-wise traversal
- Finds shortest path

DFS:
- Uses Stack/Recursion
- Depth-wise traversal
- Used in backtracking

----------------------------------------------------------------------------

OUTPUT:

Starting from node 0:

BFS Traversal: 0 1 2 3 4

DFS Traversal: 0 1 3 4 2

============================================================================
*/