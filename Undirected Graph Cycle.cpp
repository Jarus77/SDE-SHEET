


// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


// detect a cycle in undirected graph.
// Concept :
// If you have visited a node that is already visited and that node is not the parent node, it means other node at the same level has visited that node, indicates a cycle.

// DS used
// queue<pair<node,parent>>
// vector<bool> visited


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    
  private:
    
  bool detectCycle(int src, vector<int>adj[],vector<bool>&visited){
      
      queue<pair<int,int>> q;
      
      q.push({src,-1});
      visited[src]=true;
      
   
    while(!q.empty()){
       
       
       int node =q.front().first;
       int parent=q.front().second;
       
       q.pop();
       
       for(auto i: adj[node]){
           
           if(visited[i]==true && parent!=i) return true; 
           
           if(visited[i]==false) {
               
               q.push({i,node});
               visited[i]=true;
               
               
           }
       }
      
   }
      
  }  
    

    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<bool>visited(V,false);
        
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                
                if(detectCycle(i,adj,visited)) return true;
                
            }
            
        }
        
    
    
    
    
    
   
   return false;
    


    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
