class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        std::sort(begin(arr2), end(arr2)); //sort the array
        int count = 0;
        //std::lower_bound(begin(arr2), end(arr2), arr1[i]) find the nearest element

        int n = arr2.size();

        for(int i=0; i<arr1.size(); i++){
            int j = std::lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin(); //sub with arr2.begin to get the index
            
            //edgecases
            if(j == 0){
                count += (abs(arr1[i] - arr2[0]) > d); 
            } //all elements are greater than arr[i]
            else if(j ==n ){
                count += (abs(arr1[i] - arr2[n-1]) > d);
            }//all elements are smaller than n
            else{
                count += ( abs(arr1[i] - arr2[j]) > d && abs(arr1[i] - arr2[j-1]) > d);
            }
        }
        return count;
    }
};
/*        int m1 = arr1.size();
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
    }*/
    //tc = O(m.n)