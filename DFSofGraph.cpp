from collections import deque

class Solution:
    
    #Function to return a list containing the DFS traversal of the graph.
    def dfsOfGraph(self, adj):
        # code here

        n=len(adj)
        dfsList=[]
        visited=[False]*n
        
        self.dfs(0,visited,adj,dfsList)
        
        return dfsList
    
    def dfs(self,node,visited,adj,dfsList):
        
        visited[node]=True
        dfsList.append(node)
        
        
        for neighbour in adj[node]:
            
            if not visited[neighbour]:
                self.dfs(neighbour,visited,adj,dfsList)
        
        
    
