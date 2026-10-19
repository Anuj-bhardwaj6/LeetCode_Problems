class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if(dividend ==INT_MIN && divisor==-1) return INT_MAX;
        bool sign=true;
        if(dividend>0 && divisor <0) sign=false;
        if(dividend <0 && divisor >0) sign=false;
        long n=abs((long)dividend);
        long d=abs((long)divisor);
        long ans=0;
        while(n>=d){
            int count=0;
            while((d<<(count+1))<=n){
                count++;
            }
            ans+=(1<<count);
            n-=(d<<(count));
        }
        if(ans>=(1L<<31) && sign) return INT_MAX;
        else if(ans>(1L<<31) && !sign) return INT_MIN;
        ans=sign ? ans :-ans;
        return ans;
    }
};