class Solution {
    
    



    
 private:
 
 void function(string s1,string s2,vector<vector<int>>&adj){
     
     
    int i=0;int j=0;
    
    while(i<s1.size()&&j<s2.size()){
        
        if(s1[i]!=s2[j]){
            
            adj[s1[i]-'a'].push_back(s2[j]-'a');
            return;
            
        }
        i++;j++;
        
        
    }
    return;
     
 }
 
 
 void toposort(vector<bool>&visited,int idx,vector<vector<int>>&adj,stack<int>&st){
     
     
     for(auto it:adj[idx]){
         
         if(!visited[it]){
             visited[it]=true;
             toposort(visited,it,adj,st);
         }
         
     }
     
     st.push(idx);
     
 }



  public:
    string findOrder(string dict[], int n, int k) {
        // code here
        
        vector<vector<int>>adj(k);
        
        for(int i=0;i<n-1;i++){
            
            function(dict[i],dict[i+1],adj);
            
        }
        
        vector<bool>visited(k,false);
        stack<int>st;
        
        for(int i=0;i<k;i++){
            
            if(!visited[i]){
                toposort(visited,i,adj,st);
            }
            
        }
        
        string ans="";
        
        while(!st.empty()){
            
            ans+=(st.top()+'a');
            st.pop();
            
        }
        
        return ans;
        
        
    }
};
