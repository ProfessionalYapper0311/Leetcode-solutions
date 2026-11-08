class Solution {
public:
    void solve(string &digits, vector<string> &result, string &temp, int idx, unordered_map<char, string>&mp){

        if(idx >= digits.length()){
            result.push_back(temp);
            return;
        } //base case

        char ch = digits[idx]; //access the first digit, 0 was passed
        string str = mp[ch]; //access the string stored in ch

        for(int i=0; i<str.length(); i++){
            temp.push_back(str[i]);
            solve(digits, result, temp, idx+1, mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return {};
        }

        vector<string>result; //string vector
        string temp = ""; //empty string

        unordered_map<char, string>mp; //create the map to store the results
        mp['2'] = "abc"; //tip :- '' is for char, "" fopr string 
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        solve(digits, result, temp, 0, mp); //0 is idx, pass the map also

        return result;
    }
};