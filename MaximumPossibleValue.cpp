class Solution {
    
    
    
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        
        // code here
        
        
        
        
        long long sum=0;
        

        
        
        int min_stick=INT_MAX;
        long long total_stick=0;
        
        for(int i=0;i<N;i++){
            
            if(B[i]%2!=0) B[i]--;
            
            if(B[i]>=2){
                
                total_stick+=B[i];
                sum+=(A[i]*B[i]);
                min_stick=min(min_stick,A[i]);
                
                
            }
            
            
        }
        
        
        long long remaining=total_stick%4;
        
        
        sum-=(remaining*min_stick);
        
        
        
        return sum;
        
        
        
        
    }
};
