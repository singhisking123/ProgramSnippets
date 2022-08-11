#include <bits/stdc++.h>
using namespace std;

// can't be used for negative edge lengths
vector<int> dijkistra(vector<vector<pair<int,int>>> graph, int V, int src)
{
    vector<int> dist(V, INT_MAX);
    //condiering source 0
    dist[0] = 0;
    // storing {distance,vertex};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int u, v, w;
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        u = p.second;
        for (auto &to : graph[u])
        {
            v = to.first, w = to.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}