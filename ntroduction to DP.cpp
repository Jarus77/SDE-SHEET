//https://bit.ly/3UWkWrS

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    

private:
const int MOD = 1e9 + 7;


long long int  topdownhelper(int n,vector<long long int>&dp){
    
    if(n<=1){
        
        return n;
        
    }
    
    
    if(dp[n-1]==-1){
        
       dp[n-1]= topdownhelper(n-1,dp);
        
    }
    
    if(dp[n-2]==-1){
        
       dp[n-2]= topdownhelper(n-2,dp);
    }
    
    dp[n]= (dp[n-1]+dp[n-2])%MOD;
    
    
    return dp[n];

    
    
    
}



    
  public:
    long long int topDown(int n) {
        // code here
        vector<long long int> dp(n+1,-1);
        
        long long ans =topdownhelper(n,dp);
        
        return ans;
        
        
        
        
    }
    long long int bottomUp(int n) {
        // code here
        
    if(n<=1){
         return n;
     }
    
     int prev2=0;
     int prev1=1;
     

     
     long long curr;
        
     for(int i=2;i<=n;i++){
         
         curr =(prev2+prev1)%MOD;
         prev2=prev1;
         prev1=curr;
         
     }
        
      return curr;  
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends
