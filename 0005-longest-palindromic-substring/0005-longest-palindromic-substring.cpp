class Solution {
public:

    int memo[1001][1001]; //memoize vector, const size is 1000 

    
    bool solve(string &s, int i, int j){
        //base case
        if (i>=j) return 1; //true

        //basic memo step
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        
        //palindrome step 2
        if(s[i] == s[j]){
            return memo[i][j] = solve(s, i+1, j-1);
        }
        else{
            return 0; //false, not necc but memo just in case?
        }
    }
    string longestPalindrome(string s) {
        int n = s.size();

        memset(memo, -1, sizeof(memo)); //assign -1 to memo

        int maxlen = INT_MIN; int sp = 0; //starting point and max len

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(solve(s, i, j) == true){ //sent string is a palindrome
                    if(j - i + 1 > maxlen){
                        maxlen = j-i+1; //maxlen of str as well as the ending point
                        sp = i; //starting point
                    }
                }
            }
        }

        return s.substr(sp, maxlen);
    }
};

//logic -> all possible substrings, 0, n and i, n, check for palindrome, update maxlen and sp accordingly
//memoize the solve funcw