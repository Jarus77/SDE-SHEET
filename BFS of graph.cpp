

//https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    
    // BFS implies traversing all the nodes at a given level before moving to next level
    
    

  public:
  
    // Function to return Breadth First Traversal of given graph.
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
      
        // Code here
        
        
        
        vector<int> ans;
        queue<int> q;
        //map<int,bool> visited;
        
        vector<bool> visited(V,false);
        
        
  
        
        q.push(0);
        ans.push_back(0);
        
        visited[0]=true;
        
        
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
                
            for(auto i:  adj[node]){
                
                if(visited[i]==true) continue;
                
                q.push(i);
                ans.push_back(i);
                visited[i]=true;
                
                
            }
        }
        
        
        return ans;
        
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
