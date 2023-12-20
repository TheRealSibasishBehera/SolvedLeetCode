#include <unordered_map>
#include <vector>

class TimeMap
{
    // one string as key, a vector of pair of int and string
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> mp;

public:
    TimeMap() {}

    void set(std::string key, std::string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
    }

    std::string get(std::string key, int timestamp)
    {
        if (mp.find(key) == mp.end())
        {
            return "";
        }

        const std::vector<std::pair<int, std::string>> &v = mp[key];

        int l = 0;
        int r = v.size() - 1;
        int ans = -1;

        while (l <= r)
        {
            int middle = l + (r - l) / 2;

            if (v[middle].first == timestamp)
            {
                return v[middle].second;
            }
            else if (v[middle].first > timestamp)
            {
                r = middle - 1;
            }
            else
            {
                ans = middle;
                l = middle + 1;
            }
        }

        if (ans == -1)
        {
            return "";
        }
        else
        {
            return v[ans].second;
        }
    }
};
