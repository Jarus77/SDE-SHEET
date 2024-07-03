// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    
    bool checkCycle(int i,vector<bool>&visited,vector<bool>&dfsvisited,vector<int> adj[]){
        
            visited[i]=true;
            dfsvisited[i]=true;
        
        
            
        for(auto it:adj[i]){
            
            
            
            
            if(!visited[it]){
                
                if(checkCycle(it,visited,dfsvisited,adj)) return true;
                dfsvisited[it]=false;
                
                
                
            }
            
            else if(dfsvisited[it]) return true;
            
            
        }
        
        dfsvisited[i]=false;
        
        return false;
            
        
        

        
        
    }
    
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
    
    vector<bool> visited(V,false);
    vector<bool>dfsvisited(V,false);
    
    
    for(int i=0;i<V;i++){
        
        if(!visited[i]){
       
            if(checkCycle(i,visited,dfsvisited,adj)) return true;
               
            
        }
        
    }
    

        
    return false;        
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
