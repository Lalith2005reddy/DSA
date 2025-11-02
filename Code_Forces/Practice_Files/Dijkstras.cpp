#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src){
    vector<int> dist(V,INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,src});

    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(d > dist[node]){continue;}

        for(auto &edge: adj[node]){
            int neighbor = edge.first;
            int wt = edge.second;

            if(dist[node] + wt < dist[neighbor]){
                dist[neighbor] = dist[node] + wt;
                pq.push({dist[neighbor], neighbor});
            }
        }

    }
    return dist;

}

int main(){
    int V = 5; // number of vertices
    vector<vector<pair<int,int>>> adj(V);

    // Undirected weighted graph
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    int src = 0;
    vector<int> dist = dijkstra(V, adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << dist[i] << "\n";
    }

    return 0;
}