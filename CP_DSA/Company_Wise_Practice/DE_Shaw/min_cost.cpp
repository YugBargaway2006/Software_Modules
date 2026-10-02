#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    
    long long c;
    cin >> c;

    // 1. Sort and remove any overlapping police stations
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    // 2. Extract and sort the available gaps between stations
    vector<long long> gaps;
    for (size_t i = 0; i < p.size() - 1; ++i) {
        long long gap = p[i+1] - p[i] - 1;
        if (gap > 0) {
            gaps.push_back(gap);
        }
    }
    sort(gaps.begin(), gaps.end());

    // 3. Prefix sums for O(1) gap summations
    int m = gaps.size();
    vector<long long> pref(m + 1, 0);
    for (int i = 0; i < m; ++i) {
        pref[i+1] = pref[i] + gaps[i];
    }

    // Lambda function to count properties available up to distance D
    auto points_up_to = [&](long long D) {
        // Find how many gaps are completely enveloped by 2 * D
        auto it = upper_bound(gaps.begin(), gaps.end(), 2 * D);
        int pos = distance(gaps.begin(), it);
        
        // Properties on the infinite left and right rays
        long long res = 2 * D; 
        
        // Properties fully inside small gaps + properties partially filling large gaps
        res += pref[pos] + (long long)(m - pos) * 2 * D; 
        return res;
    };

    // 4. Binary search for the maximum distance required
    long long low = 1, high = c, ansD = c;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (points_up_to(mid) >= c) {
            ansD = mid;
            high = mid - 1; // Try to find a smaller maximum distance
        } else {
            low = mid + 1;
        }
    }

    // 5. Calculate cost for all properties strictly less than ansD
    long long d = ansD - 1;
    long long total_cost = d * (d + 1); // Cost from the two infinite rays
    long long total_points = 2 * d;     // Count from the two infinite rays

    for (long long gap : gaps) {
        if (2 * d <= gap) {
            // Gap is larger than our spread, take 2*d items
            total_cost += d * (d + 1);
            total_points += 2 * d;
        } else {
            // Gap is fully consumed
            long long k = gap / 2;
            if (gap % 2 == 0) {
                total_cost += k * (k + 1);
            } else {
                total_cost += (k + 1) * (k + 1);
            }
            total_points += gap;
        }
    }

    // 6. Fill the remainder with properties precisely at distance ansD
    long long rem = c - total_points;
    total_cost += rem * ansD;

    cout << total_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}