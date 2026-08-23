class Solution {
public:
    static bool compare(vector<int> a , vector<int> b ){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int arrow=1;
        sort(points.begin(),points.end(),compare);

        int arrowend = points[0][1];
        for(int i =1 ; i<n ;i++){
            if(points[i][0] > arrowend){
                arrow++;
                arrowend =points[i][1];

            }
        }
        return arrow;

    }
};