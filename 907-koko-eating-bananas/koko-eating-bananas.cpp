class Solution {
public:

    long long maxhours(vector<int>& v, int speed){
        long long totalhour = 0;

        for(int banana : v){
            totalhour += (banana + speed - 1) / speed;
        }

        return totalhour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max_pile = *max_element(piles.begin(), piles.end());

        int low = 1, high = max_pile;
        int ans = max_pile;

        while(low <= high){
            int mid = low + (high - low) / 2;

            long long totalhour = maxhours(piles, mid);

            if(totalhour <= h){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};