class Solution {
public:
typedef long long ll; 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<ll,int>, vector<pair<ll, int>>, greater<pair<ll, int>>> minh; //min heap

        //coordinates have only 2 points so i, j == 2; [[1, 2], [3, 4]]
        for(int i=0; i<points.size(); i++){
            ll x = points[i][0]; //since k = 0,0 just x^2 + y^2 suffice
            ll y = points[i][1];
            ll dist = (x*x) + (y*y); //sqrt((x-0)^2 + (y-0)^2)
            minh.push({dist, i}); //[dist, index];
        }
        vector<vector<int>> res;
        while(k--){
            res.push_back(points[minh.top().second]);  
            minh.pop();
        }
        return res;
    }
};