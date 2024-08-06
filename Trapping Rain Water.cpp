//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    
    
     long long trappingWater(int arr[], int n) {
        if (n <= 2) return 0; // No space to trap water

        vector<int> leftMax(n), rightMax(n);
        
        // Initialize leftMax array
        leftMax[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], arr[i]);
        }

        // Initialize rightMax array
        rightMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }

        // Calculate the trapped water
        long long sum = 0;
        for (int i = 1; i < n - 1; ++i) {
            int waterLevel = min(leftMax[i], rightMax[i]);
            if (waterLevel > arr[i]) {
                sum += waterLevel - arr[i];
            }
        }

        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
