class Solution {
public:
    bool isPalindrome(int x) {
        int dummy=x;
        long long rev=0;
        while(x>0){
            rev=(rev*10)+x%10;
            x=x/10;
        }
        return rev==dummy;
        
    }
};