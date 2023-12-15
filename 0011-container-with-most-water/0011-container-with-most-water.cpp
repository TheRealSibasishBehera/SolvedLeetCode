class Solution {
public:
int area(int index1, int index2,vector<int>&height){
    return min(height[index1],height[index2])*(index2-index1);
}

//classic 2 pointer
// basic intuition is that we want to maximize the area
// so we will try to maximize the width and height
// so we will start from the ends and try to maximize the width
// and then we will try to maximize the height
// so we will move the pointer which has the smaller height
// because if we move the pointer with the larger height
// then the height will decrease and the width will decrease
// so we will move the pointer with the smaller height
// and try to maximize the height
// and we will keep track of the max area
// and return it
int maxArea(vector<int> &height)
{
    int i = 0;
    int j = height.size() - 1;
    int ans = 0;
    while(i<j){
        int areax= area(i,j,height);
        ans = max(ans,areax);
        if(height[i]<height[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return ans;
}
};