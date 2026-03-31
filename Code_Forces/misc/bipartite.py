from collections import deque
import sys

class Solution:
    def isBipartite(self,V,edges):
        adj = [[] for _ in range(V)]
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        color = [-1] * V

        for start in range(V):
            if color[start] != -1:
                continue
            q = deque()
            q.append(start)
            color[start] = 0

            while q:
                node = q.popleft()
                
                for nei in adj[node]:
                    if(color[nei] == color[node]):
                        return False
                    elif color[nei] == -1:
                        color[nei] = 1 - color[node]
                        q.append(nei)
        return True
    
def main():
    input = sys.stdin.readline
    t = int(input())

    sol = Solution()

    for _ in range(t):
        V, E = map(int, input().split())
        edges = []

        for _ in range(E):
            u,v = map(int, input().split())
            edges.append((u,v))

        print("true" if sol.isBipartite(V,edges) else "false")

if __name__ == "__main__":
    main()