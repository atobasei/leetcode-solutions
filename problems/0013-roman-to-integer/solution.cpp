class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> values;
        values["I"] = 1;
        values["V"]=5;
        values["X"]=10;
        values["L"]=50;
        values["C"]=100;
        values["D"]=500;
        values["M"]=1000;
        values["IV"]=4;
        values["IX"]=9;
        values["XL"]=40;
        values["XC"]=90;
        values["CD"]=400;
        values["CM"]=900;

        //each character is some value exept IV and IX which are 4 and 9
        //so for each string go character by character, if the character is I make sure the next character is not V or X

        //loop through charactwer with a running total, then return that value
        string c;
        char next;
        int total =0;
        int current =0;
        for(int i =0; i < s.size(); i++){
            c = s[i];

            //only if next character exists
            if(i != (s.size()-1)){
            next = s[i+1];

            if (c== "I" &&  next == 'V' ){
                //IV
                current = values["IV"];
                i++;
                total +=current;
                continue;
            }
            else if(c== "I" &&  next == 'X'){
                //IX
                current = values["IX"];
                i++;
                total +=current;
                continue;
            }
            //X and L and C
             if (c== "X" &&  next == 'L' ){
                //XL
                current = values["XL"];
                i++;
                total +=current;
                continue;
            }
            else if(c== "X" &&  next == 'C'){
                //XC
                current = values["XC"];
                i++;
                total +=current;
                continue;
            }
             if (c== "C" &&  next == 'D' ){
                //CD
                current = values["CD"];
                i++;
                total +=current;
                continue;
            }
            else if(c== "C" &&  next == 'M'){
                //CM
                current = values["CM"];
                i++;
                total +=current;
                continue;
            }
            }
            current = values[c];      
            total +=current;

        }
        return total;
    }
};
