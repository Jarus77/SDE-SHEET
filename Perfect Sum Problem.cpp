//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

    
  
class Solution{
    
    private:
    
    int function(int arr[],int idx,int target,vector<vector<int>>&dp){
        
        // if(idx==0 && target==0) return 1;
        // if(idx==0 && target==arr[0]) return 1;
        
        // if(idx==0 && target!=arr[0]) return 0;
        int mod=1e9+7;
     
        if(idx<0 && target==0) return 1;
        if(idx<0 && target!=0) return 0;
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        
        
        int nottake=function(arr,idx-1,target,dp);
        int take=0;
        
        if(arr[idx]<=target){
            take=function(arr,idx-1,target-arr[idx],dp);
        }
        
        
        return dp[idx][target]=(take+nottake)%mod;
        
    }
    

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        
        return function(arr,n-1,sum,dp);
        
        
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
