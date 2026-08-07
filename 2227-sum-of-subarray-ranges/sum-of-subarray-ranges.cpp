class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int>ans(n);
        for( int i = n-1 ;i>=0 ;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]= st.empty() ? n : st.top();
            st.push(i);                                 // we need only the index and not values
        }
        return ans;
    }

    vector<int> prevSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int>ans(n);
        for( int i = 0 ;i<n ;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]= st.empty() ? -1 : st.top();         
            st.push(i);                                 // we need only the index and not values
        }
        return ans;
    }
    vector<int> nextgreaterEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int>ans(n);
        for( int i = n-1 ;i>=0 ;i--){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            ans[i]= st.empty() ? n : st.top();
            st.push(i);                                 // we need only the index and not values
        }
        return ans;
    }

    vector<int> prevgreaterEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int>ans(n);
        for( int i = 0 ;i<n ;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            ans[i]= st.empty() ? -1 : st.top();         
            st.push(i);                                 // we need only the index and not values
        }
        return ans;
    }


    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> prevS = prevSmallerEle(nums);
        vector<int> nextS = nextSmallerEle(nums);

        vector<int> prevG = prevgreaterEle(nums);
        vector<int> nextG = nextgreaterEle(nums);

        long long minSum = 0;
        long long maxSum = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prevS[i];
            long long right = nextS[i] - i;

            minSum += 1LL * nums[i] * left * right;
        }

        for (int i = 0; i < n; i++) {
            long long left = i - prevG[i];
            long long right = nextG[i] - i;

            maxSum += 1LL * nums[i] * left * right;
        }

        return maxSum - minSum;
    }
};