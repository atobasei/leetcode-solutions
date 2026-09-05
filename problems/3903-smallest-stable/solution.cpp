class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {


        vector<int> indecies;
        
        //calculate instability score for each index
        for(int i =0; i < nums.size(); i++){

            int min;
            int max;

            //check for min value before

            for (int j =0; j <= i; j++){
                //values between 0 and i
                if(j==0){
                    max = nums[j];
                }
                else{
                    if(nums[j] > max){
                        max = nums[j];
                    }
                }

            }

            //check for max value after

            for (int l =i; l < nums.size(); l++){
                //values between i and end
                if(l==i){
                    min = nums[l];
                }
                else{
                    if(nums[l] < min){
                        min = nums[l];
                    }
                }
            }



            // do max - min to find out if its stable
            int difference = max - min;
            if(difference <= k){
                return i;
                indecies.push_back(i);
                //add index in vector to stable vector
            }

        }

        //return the smallest stable index
        //loop through indecies and return lowest valye in nums

        //if indecies is empty return -1

            return -1;
 
    }
};
