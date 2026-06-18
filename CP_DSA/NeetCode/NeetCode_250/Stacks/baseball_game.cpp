class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> records;
        for(auto& op : operations) {
            if(op == "+") {
                records.push_back(records[records.size()-1] + records[records.size()-2]);
            } else if(op == "D") {
                records.push_back(2*records[records.size()-1]);
            } else if(op == "C") {
                records.pop_back();
            } else {
                records.push_back(stoi(op));
            }
        }

        int ans = accumulate(records.begin(), records.end(), 0);
        return ans;
    }
};