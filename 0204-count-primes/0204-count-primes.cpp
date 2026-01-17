class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<char> primes(n,true);
        primes[0] = primes[1] = false;
        for(int p=2;p*p<n;p++){
            if(primes[p]==1){
                for(int i=p*p;i<n;i+=p){
                    primes[i]=false;
                }
            }
        }
        int count = 0;
        for(int i=2;i<n;i++){
            if(primes[i]==true) count++;
        }
        return count;
    }
};