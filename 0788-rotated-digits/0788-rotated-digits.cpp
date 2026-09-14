class Solution {
public:
    int rotatedDigits(int n) {
        int count=0;
        for(int i =1;i<=n;i++){
            int x=i;
            
            bool valid=true;
            bool changed = false;
            while(x>0){
                int num=x%10;
                if(num==3||num==7||num==4){
                    valid= false;
                    break;
                }
                if(num == 2 || num == 5 || num == 6 || num == 9) {
                   changed = true;
                }
               
                x/=10;
            }
            if(valid && changed){
                count++;
            }
        }
        return count;
        
    }
    
};