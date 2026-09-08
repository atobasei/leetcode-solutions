#include<string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //iterate through each array all together one character at a time
        //check each character against an arbitrary one (first array)
        //once theres a nonequal return the string so far (so start it empty)
        //else if you go through all arrays push that character onto your string

        string final ="";
        char current;
        current = strs[0][0];
        int i =0;
        
        //loop until shortest word length has been met as that is longest possible shared string
        while(true){
            //check current character in each array
            if(!strs[0][i]){
                return final;
            }
            current = strs[0][i];
            //if it doesnt exist that means string length is exhausted return current


            for(int j =0; j < strs.size(); j++){
                //value at j,i should equal
                if(!strs[j][i]){
                    return final;
                }
                if(strs[j][i] != current){
                    return final;
                }
            }
            i++;
            final.push_back(current);
            }

            return final;
    }
};