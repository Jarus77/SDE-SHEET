from typing import List


class Solution:
    def printGraph(self, V : int, edges : List[List[int]]) -> List[List[int]]:
        # code here
        
        adjList=[[] for _ in range(V)]
        
        
        
        for edge in edges:
            
            u,v = edge
            
            adjList[u].append(v)
            adjList[v].append(u)
        
        


        return adjList
