from collections import deque
from typing import List

class Solution:
    # Function to return Breadth First Traversal of given graph.
    def bfsOfGraph(self, adj: List[List[int]]) -> List[int]:
        # code here

        q=deque()
        bfsTraversal=[]
        visited=[False]*len(adj)
        
        q.append(0)
        visited[0]=True
        
        while q:
            
            node=q.popleft()
            bfsTraversal.append(node)
            for neighbour in adj[node]:
                
                if not visited[neighbour]:
                    q.append(neighbour)
                    
                    visited[neighbour]=True
        
        return bfsTraversal
