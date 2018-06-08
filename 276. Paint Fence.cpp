class Solution {
public:
    int numWays(int n, int k) {
        int a1=k, a2 = k*k, a3;
        if(k==0 || n ==0) return 0;
        if(n==1) return k;
        if(n==2) return k*k;
        
        for(int i =3; i<=n; i++){
            a3 = (k-1)*(a2+a1);
            a1 = a2;
            a2 = a3;            
        }
        return a3;
    }
};
