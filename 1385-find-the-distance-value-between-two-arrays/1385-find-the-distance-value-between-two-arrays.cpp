class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int m1 = arr1.size();
        int m2 = arr2.size();
        int count = 0;
        for(int i = 0; i<m1; i++){
            bool valid = true;
            for(int j=0; j<m2; j++){
                if(abs(arr1[i] - arr2[j]) <= d){
                    valid = false;
                }
            }
            if(valid){
                count++;
            }
        }
        return count;
    }
};