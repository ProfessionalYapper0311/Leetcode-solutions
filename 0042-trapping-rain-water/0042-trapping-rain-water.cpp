class Solution {
public:

vector<int>getleftmax(vector<int>& height, int &n){
    vector<int>left_max(n);
    left_max[0] = height[0];

    for(int i=1; i<n; i++){
        left_max[i] = max(left_max[i-1], height[i]);
    }
    return left_max;
}

vector<int>getrightmax(vector<int>& height, int &n){
    vector<int>right_max(n);
    right_max[n-1] = height[n-1];

    for(int i=n-2; i>=0; i--){
        right_max[i] = max(right_max[i+1], height[i]);
    }
    return right_max;
}

    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>left_max = getleftmax(height, n);
        vector<int>right_max = getrightmax(height, n);

        int sum = 0;
        for(int i=0; i<n; i++){
            int width = 1;
            int Height = min(left_max[i], right_max[i]) - height[i];
            sum += (width * Height);
        }
        return sum;
    }
};