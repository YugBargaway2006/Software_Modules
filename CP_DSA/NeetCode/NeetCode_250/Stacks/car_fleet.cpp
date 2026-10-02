class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ct = 0;
        double mx = 0;
        int n = speed.size();
        vector<pair<int, int>> cars(n);
        for(int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.begin(), cars.end(), [&](const pair<int, int> a, const pair<int, int> b) {
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });



        vector<double> time(n);
        for(int i = 0; i < n; i++) {
            time[i] = (double)(target - cars[i].first) / cars[i].second;
        }

        // for(auto x : time) cerr << x << " "; cerr << endl;
        // for(auto x : cars) cerr << "(" << x.first << " " << x.second << ")"; cerr << endl;

        for(int i = n-1; i >= 0; i--) {
            if(mx < time[i]) {
                mx = time[i];
                ct++;
            }
        }
        return ct;
    }
};
