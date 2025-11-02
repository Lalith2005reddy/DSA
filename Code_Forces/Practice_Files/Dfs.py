def dfs(node,adj,vis):
    vis[node] = True
    print(node,end= "->")
    for neig in adj[node]:
        if(vis[neig] == False):
            dfs(neig,adj,vis)

def main():
    adj = [
        [1,2],
        [0,3],
        [0,3,4],
        [1,2],
        [2]
    ]

    vis = [False] * len(adj)
    print("DFS Traversal: ", end=" ")
    dfs(0,adj,vis)

if __name__ == "__main__":
    main()
