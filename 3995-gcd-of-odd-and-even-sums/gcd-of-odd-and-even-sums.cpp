class Solution {
public:
    int gcd(int a ,int b){
        while(a>0 && b>0){
            if(a>b)
            a=a%b;
            else 
            b=b%a;
            }
            if(a==0)
            return b;
            else return a;
    }
    int gcdOfOddEvenSums(int n) {
        int sumodd =0;
        int curr_odd =1;
        for(int i=0 ; i<n ;i++){
            sumodd +=curr_odd;
            curr_odd+=2;
        }
        int sumeven =0;
        int curr_even =2;
        for(int i=0 ; i<n ;i++){
            sumeven +=curr_even;
            curr_even+=2;
        }
        return gcd(sumodd,sumeven);

    }
};