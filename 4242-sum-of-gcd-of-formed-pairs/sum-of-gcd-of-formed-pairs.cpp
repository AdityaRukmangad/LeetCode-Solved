class Solution {
public:
    int gcd(int a ,int b){
        while(a>0 && b>0){
        if(a>b) 
        a=a%b;
        else
        b=b%a;
    }
    if(a==0) return b;
    else return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixgcd;
        int mx = -1;
        for(int i =0; i<n ; i++){
            if(nums[i]>mx){
            mx=nums[i];
            prefixgcd.push_back(nums[i]);
            }
            else
             prefixgcd.push_back(gcd(nums[i],mx));
        }
        sort(prefixgcd.begin(),prefixgcd.end());

        int i=0,j=n-1;
        long long ans=0;
        while(i<j){
            ans += gcd(prefixgcd[i],prefixgcd[j]);
            i++;
            j--;
        }
        return ans;

    }
};