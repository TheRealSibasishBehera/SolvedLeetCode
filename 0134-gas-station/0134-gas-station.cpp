class Solution
{
public:
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    //greddy solution
    // time complexity O(n)
    int sumgas = 0;
    int sumcost = 0;
    vector<int> diff(gas.size());
    for (int i = 0; i < cost.size(); i++)
    {
        sumgas += gas[i];
        sumcost += cost[i];
        diff[i] = gas[i] - cost[i];
    }

    if(sumgas<sumcost) return -1;
    
    int total = 0;
    int flag = 0;
    for (int i = 0; i < cost.size(); i++)
    {
        total += diff[i];
        if (total < 0)
        {
            total = 0;
            flag = i + 1;
        }
    }

    return flag;
    
 
}};
