class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int arr[26] = {0};
        for (int i = 0; i < tasks.size(); i++) {
            arr[tasks[i] - 'A']++;
        }

        priority_queue<int> pq;
        queue<pair<int, int>> q; // freq, time it should be pushed back
        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) {
                pq.push(arr[i]);
            }
        }

        int ans = 0;
        while (!pq.empty() || !q.empty()) {
            if (!pq.empty()) {
                int x = pq.top();
                pq.pop();
                x--;
                ans++;

                if (x > 0) {
                    q.push({x, ans + n});
                }
            } else {
                ans++; // idle time
            }

            while (!q.empty() && q.front().second <= ans) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return ans;
    }
};
