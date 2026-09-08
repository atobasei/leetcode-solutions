class Solution {
public:
    int maxArea(vector<int>& height) {
        int area;
        //we want to maximize area
        //area = min(two columns) * index2 - index1

        //track initial area
        //two pointer
        int first, second;
        first =0;
        second = (height.size()-1);
        area = min(height[first], height[second]) * (second - first);
        int temp;

        while(first < (second+1)){

            int i_first = first;
            int i_second = second;

            if(height[first] > height[second]){
                temp = height[second];

            //we are iterating from second backwards
            for(int i =0; i < second; i++){
                //check if current index is greater
                if(height[second -(i+1)] > temp){
                    second = second -(i+1);
                        break;
                }
            }

            }
            //case if theyre the same or first is shorter
            else{
                temp = height[first];
                for(int i=first; i< ((height.size())-1); i++){
                    if(height[(i+1)] > temp){
                        first = (i+1);
                        break;
                    }
                }
                //iterate forwards until we find a higher point

            }
            //if theyre the same you must try both sides?? it shouldnt make a difference if my thinking is right

            if ((min(height[first], height[second]) * (second - first)) > area){
                area = (min(height[first], height[second]) * (second - first));
            }

            //also if nothing changed return
            if(i_first == first && i_second == second){
                return area;
            }
        }

        return area;
    }
};