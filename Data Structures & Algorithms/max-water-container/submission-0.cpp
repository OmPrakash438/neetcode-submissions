class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;

        int area = INT_MIN;
        while(l < r){
            int currArea = min(heights[l], heights[r]) * (r - l);
            area = max(area, currArea);

            if(heights[l] < heights[r]) l++;
            else if(heights[l] > heights[r]) r--;
            else{
                if(heights[l+1] > heights[r-1]) l++;
                else r--;
            }
        }

        return area;
    }
};
