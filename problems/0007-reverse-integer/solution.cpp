#include <climits>
class Solution {
public:
    int reverse(int x) {
        
        //check if negative sign if so set negative to true and pop it off our string
        bool negative = false;
        string number;
        long result;
        long x_long = x;
        if(x_long < 0){
            negative = true;
            x_long = ((-1)*x_long);
        }
        
        number = std::to_string(x_long);
        //change to string

        //iterate through string reversing characters
        int temp;
        for(int i=0; i < (number.size()/2); i++){
            std::swap(number[i], number[number.size()-1-i]);
        }
      
        result = std::stol(number);
        

    if(result > 2147483647){
        return 0;
    }
    //do negative check after range checl
    if(negative == true){
            result = result * -1;
    }

    int i_result = static_cast<int>(result);
    return i_result;
    }
};
