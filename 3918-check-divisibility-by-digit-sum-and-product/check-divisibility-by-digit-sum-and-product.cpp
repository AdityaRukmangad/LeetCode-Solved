class Solution {
public:
    int digitproduct(int n ){
        string s = to_string(n);
        int product=1;
        for(int i =0;i<s.size();i++){
            product *= s[i]-'0';
        }
        return product;
    }
    int digitsum(int n ){
        string s = to_string(n);
        int sum=0;
        for(int i =0;i<s.size();i++){
            sum += s[i]-'0';
        }
        return sum;
    }
    bool checkDivisibility(int n) {
        int divisor =digitproduct(n)+digitsum(n);
        if (divisor == 0) return false;
        return n%(divisor)==0;
    }
};