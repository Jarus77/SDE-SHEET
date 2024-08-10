class Solution{
    


public:
    int countBits(int N, long long int A[])
    {
        // code here
        
        int mod=1e9+7;
        
       
        int result=0;
        
        for(int i=0;i<32;i++){
            
             int counton=0;
             
            for(int j=0;j<N;j++){
                
                long long int val=A[j];
                
                if((val&(1LL<<i))) counton++;
                
            }
            
            
            int countoff=N-counton;
            
            long long diff=(long long)counton*countoff*2;
            
            result=(result+diff%mod)%mod;
            
            
        }
        
        return result;

        
    }
};
