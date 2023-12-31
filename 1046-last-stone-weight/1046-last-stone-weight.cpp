class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        //choose the 2 heaviest stones
        //if they are equal , destroy both
        //if not , destroy the heaviest one and the other one's weight is the difference
        //end it when there is only 1 stone left
        //eg : [2,7,4,1,8,1]

        priority_queue<int> pq; //max heap
        for (int i = 0; i < stones.size(); i++)
        {
            pq.push(stones[i]);
        }

        while(pq.size() > 1)
        {

            //get top 2 elements
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            //if they are not equal , push the difference
            if(x != y)
            {
                pq.push(abs(x-y));
            }
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};