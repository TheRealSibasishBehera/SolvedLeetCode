class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    //no of days u have to wait to get a warmer temp
        
        
    //basic approach takes o n2
        
    //use a stack
    
        
    //observation is if u get a val higher than something , 
    //u can omit something , its no use , hard to explain 
    stack<int> st;
    int n = temperatures.size();
    vector<int> ans(temperatures.size(), 0);
    for (int i = 0; i < n ; i++)
    {
        // lets find days which are colder that current day
        //[73,74,75,71,69,72,76,73]
        // stack
        // 0
        // next it will go to 74 
        // top is less , tops ans should be diff(indexs)
        // now push 1 
        // go to 75 top is less , tops ans should be diff(indexs)
        // now push 2
        // go to 71 top is greater ,skip , push 3
        //
        while(!st.empty() && temperatures[st.top()]<temperatures[i]){
            int idx=st.top();
            st.pop();
            ans[idx]=i-idx;
        } 
        st.push(i);
    }

    return ans;
    }
};