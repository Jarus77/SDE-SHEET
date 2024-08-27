//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    
    void dfs(int idx,vector<int>&visited,vector<vector<int>>&adj2){
        
        
        for(auto it:adj2[idx]){
            
            if(!visited[it]){
                
                 visited[it]=1;
                dfs(it,visited,adj2);
            }
            
            
        }
       
        
    }
    
    
    void dfs2(stack<int>&st,vector<vector<int>>&adj,int idx,vector<int>&visited2){
        
        
        for(auto it:adj[idx]){
            
            if(!visited2[it]){
                visited2[it]=1;
                 dfs2(st,adj,it,visited2);
            }
           
            
        }
        
        
        
        st.push(idx);
        
        
    }
    
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>&adj)
    {
        
        
        stack<int>st;
        vector<int>visited2(V,0);
        
        for(int i=0;i<V;i++){
            dfs2(st,adj,i,visited2);
        }
        
        
        //code here
        vector<vector<int>>adj2(V);
        
        
        for(int i=0;i<V;i++){
            
            for(auto it:adj[i]){
                adj2[it].push_back(i);
            }
            
        }
        
        
        
        vector<int>visited(V,0);
        int cnt=0;
        
        
        while(!st.empty()){
            
            int node=st.top();
            st.pop();
            
            if(!visited[node]){
                dfs(node,visited,adj2);
                cnt++;
            }
            
            
        }
        

        
        
        return cnt;
    
        
        
            
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
