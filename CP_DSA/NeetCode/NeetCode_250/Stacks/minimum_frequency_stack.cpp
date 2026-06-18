class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;

    int maxFreq;

    FreqStack() {
        maxFreq = 0;
    }

    void push(int val) {
        int f = ++freq[val];

        group[f].push(val);

        maxFreq = max(maxFreq, f);
    }

    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();

        freq[val]--;

        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};