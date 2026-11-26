class Solution {
public:
    bool canAliceWin(int n) {
        int takeStone = 10; 
        bool isAliceturn = true; 

        while(n >= takeStone){
            n -= takeStone;
            takeStone--;
            isAliceturn = !isAliceturn; //now bob turn
        }

        //ends on bob turn, bob can't move, alice win 
        return !isAliceturn;
    }
};

// alice takes 10, remove ten from n, then false, cause that's bob's turn