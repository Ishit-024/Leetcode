class Solution {
public:
    int countPrimes(int n){
        if(n==2){
            return 0;
        }
        else if(n==3){
            return 1;
        }
       vector<int>isprime(n+1,true);
       for(int i=2;i*i<=n;i++){
        if(isprime[i]==true){
            for(int j=i*2;j<=n;j=j+i){
                isprime[j]=false;
            }
        }
       }
       int count=0;
       for(int i=2;i<n;i++){
        if(isprime[i]==true){
            count++;
        }
       }
       return count;
    }
};