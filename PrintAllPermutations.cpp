//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    private:
    
    void function(string& s,vector<bool>&visited,set<string>&ans,string S,int n){
        
        if(s.size()==n){
            ans.insert(s);
        }
        
        for(int i=0;i<n;i++){
            
            if(!visited[i]){
                
                s+=S[i];
                visited[i]=true;
                
                function(s,visited,ans,S,n);
                s.pop_back();
                visited[i]=false;
            }
            
            
        }
        
        
        
    }
    
    
    
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    string s="";
		    int n=S.size();
		    
		    vector<bool>visited(n,false);
		    set<string>ans;
		    vector<string>result;
		    
		    function(s,visited,ans,S,n);
		    
		    for(auto it:ans){
		        result.push_back(it);
		        
		    }
		    
		    return result;
		    
		    
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
