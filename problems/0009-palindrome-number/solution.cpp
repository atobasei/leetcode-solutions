#include<string>

class Solution {
public:
    bool isPalindrome(int x) {
        //loop through string and check if first and last character is the same, then second, so on so on, stop once youve exceeded half the length of the int

        std::string str = std::to_string(x);
        int length = str.size();

        for(int i =0; i < ((str.size()/2)+1); i++){
            //cout << str[i];
            if(str[i] != str[(length-1-i)]){
                return false;
            }
        }

        return true;
    }
};