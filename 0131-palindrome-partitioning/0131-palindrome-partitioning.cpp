class Solution {
public:
int n;
    bool isPalindrome(string &s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrack(vector<vector<string>> &result, vector<string> &temp, string &s, int idx){
        if(idx == n){
            result.push_back(temp);
            return;
        }

        for(int i = idx; i<n; i++){ //i= 0, 1, 2, 3 ... then idx to i, for e.g idx = 0, i = 1

            if(isPalindrome(s, idx, i)){ //condition check

                temp.push_back(s.substr(idx, i-idx+1)); //idx to i size palindrome chara
                backtrack(result, temp, s, i+1); //explore then , from i + 1
                temp.pop_back(); //pop back
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        n = s.length();

        backtrack(result, temp, s, 0);

        return result;
    }
};