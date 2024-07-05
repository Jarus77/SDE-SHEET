// https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    const int INTMAX =1e7;
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        
        
        vector<int>dp(n,INTMAX);
        
        dp[0]=0;
        dp[1]=abs(height[1]-height[0]);
        
        
        for(int i=2;i<n;i++){
            
            for(int j=1;j<=k;j++){
                
               
               if(i-j>=0) dp[i]=min(abs(height[i]-height[i-j])+dp[i-j],dp[i]);
                
            }
            
            
            
        }
        
        
        return dp[n-1];
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends
