#include <bits/stdc++.h>
using namespace std;
// tc = elogv

// Spanning tree has v-1 edges, where v is the number of nodes (vertices).

// From a complete graph, by removing maximum e - v + 1 edges,
//  we can construct a spanning tree.

// A complete graph can have maximum v^(v-2)=>pow(v,v-2) number of spanning trees.

// Thus, we can conclude that spanning trees are a subset of connected Graph G
//  and disconnected graphs do not have spanning tree.
class DSU
{
public:
    int *parent;
    int *rank;
    DSU(int v)
    {
        parent = new int[v];
        rank = new int[v];
        for (int i = 0; i < v; i++)
        {
            rank[i] = 1;
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (x == parent[x])
            return x;

        // concept of path compression used here
        parent[x] = find(parent[x]);

        return parent[x];
    }
    // Function to merge two nodes a and b.
    void union_(int a, int b)
    {
        int rep_x = find(a);
        int rep_y = find(b);
        if (rep_x == rep_y)
            return;
        else if (rank[rep_x] < rank[rep_y])
            parent[rep_x] = rep_y;
        else if (rank[rep_y] < rank[rep_x])
            parent[rep_y] = rep_x;
        else
        {
            parent[rep_x] = rep_y;
            rank[rep_y]++;
        }
    }

    // Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y)
    {
        if (find(x) == find(y))
            return true;
        return false;
    }
    // Function to determine number of connected components.(like number of islands)
    int findNumberOfConnectedComponents(int n)
    {
        unordered_set<int> set;
        for (int i = 1; i <= n; i++)
        {
            set.insert(find(i));
        }
        return set.size();
    }
};
struct edge
{
public:
    int src, dest, weight;
    edge(int u, int v, int w)
    {
        src = u;
        dest = v;
        weight = w;
    }
};
class graph
{
public:
    int V, E;

    vector<edge *> Edge;
    vector<edge *> output;

    graph(int v, int e)
    {
        V = v;
        E = e;

        Edge.resize(e);
        output.resize(v - 1);
    }
    void addedge(int src, int dest, int weight)
    {
        edge *temp = new edge(src, dest, weight);
        Edge.push_back(temp);
    }

    bool cmp(edge &a, edge &b)
    {
        return a.weight < b.weight;
    }
    int minimum_spanning_tree()
    {
        int res = 0;
        DSU dsu(V);
        sort(Edge.begin(), Edge.end(), cmp);
        int j = 0;
        for (int i = 0; i < E && j < V - 1; i++)
        {
            edge *x = Edge[i];
            if (dsu.find(x->src) != dsu.find(x->dest))
            {
                dsu.union_(x->src, x->dest);
                res += x->weight;
                output.push_back(x);
                j++;
            }
        }
        return res;
    }
};

