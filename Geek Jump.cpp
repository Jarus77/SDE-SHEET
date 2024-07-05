//https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        
        
        if(n==1) return 0; 
        
        if(n==2) return abs(height[1]-height[0]);
        
        
        //vector<int> dp(n,-1);
        
        int prev2=0;
        int prev =abs(height[1]-height[0]);
        int curr=0;
        
        
        for(int i=2;i<n;i++){
            
          curr=  min(abs(height[i-1]-height[i])+prev,abs(height[i-2]-height[i])+prev2);
          
          prev2=prev;
          prev=curr;
            
            
        }
        
        
        return curr;
        
    
    
        
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends
