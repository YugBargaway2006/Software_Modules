#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

using namespace std;

// Class to track the internal state of a single merchant
class MerchantState {
public:
    string merchant_id;
    string category;
    int total_charges = 0;
    int total_disputes = 0;
    bool is_fraudulent = false;

    MerchantState() = default;
    MerchantState(string id, string cat) : merchant_id(id), category(cat) {}

    // Helper to calculate current fraud rate safely
    double get_fraud_rate() const {
        if (total_charges == 0) return 0.0;
        return (double)total_disputes / total_charges;
    }
};

// Class to track individual transaction attributes
class TransactionState {
public:
    string txn_id;
    string merchant_id;
    bool is_disputed = false;

    TransactionState() = default;
    TransactionState(string t_id, string m_id) : txn_id(t_id), merchant_id(m_id) {}
};

class FraudEngine {
private:
    // State storage
    unordered_map<string, MerchantState> merchants;       // merchant_id -> MerchantState
    unordered_map<string, TransactionState> transactions; // txn_id -> TransactionState
    unordered_map<string, double> category_thresholds;   // category_name -> threshold_value
    
    const double DEFAULT_THRESHOLD = 0.05;

    // Helper to fetch threshold for a specific category
    double get_threshold(const string& category) {
        if (category_thresholds.find(category) != category_thresholds.end()) {
            return category_thresholds[category];
        }
        return DEFAULT_THRESHOLD;
    }

    // Helper to re-evaluate fraud status and return state change logs if any
    string evaluate_merchant_status(MerchantState& merchant) {
        double current_threshold = get_threshold(merchant.category);
        double current_rate = merchant.get_fraud_rate();
        
        // Handle floating point precision safely using a small epsilon if needed,
        // or direct comparison based on problem rules.
        bool should_be_fraud = (current_rate >= current_threshold);

        if (should_be_fraud && !merchant.is_fraudulent) {
            merchant.is_fraudulent = true;
            return merchant.merchant_id + ", FRAUD";
        } else if (!should_be_fraud && merchant.is_fraudulent) {
            merchant.is_fraudulent = false;
            return merchant.merchant_id + ", CLEAR";
        }
        
        return ""; // No state change
    }

    // Helper to evaluate merchant status and return true if state changes
    bool update_merchant_status(const string& merchant_id) {
        bool previous_state = merchants[merchant_id].is_fraudulent;
        string category = merchants[merchant_id].category;
        if(merchants[merchant_id].get_fraud_rate() >= get_threshold(category)) {
            merchants[merchant_id].is_fraudulent = true;
        } else {
            merchants[merchant_id].is_fraudulent = false;
        }
        bool current_state = merchants[merchant_id].is_fraudulent;

        return (previous_state != current_state) ? true : false;
    }

    // Helper to append alert
    void append_alert(vector<string>& alerts, const string& merchant_id) {
        string alert_signal = merchant_id + ", ";
        bool current_state = merchants[merchant_id].is_fraudulent;
        alert_signal += (current_state) ? "FRAUD" : "CLEAR";
        alerts.push_back(alert_signal);
    }

public:
    vector<string> processEvents(const vector<vector<string>>& events) {
        vector<string> alerts;

        for (const auto& event : events) {
            const string& eventType = event[0];

            if (eventType == "SET_THRESHOLD") {
                const string& category = event[1];
                double threshold = stod(event[2]);
                
                category_thresholds[category] = threshold;
                // Note: Re-evaluating ALL merchants in this category might be required 
                // if threshold changes dynamically mid-stream. Check specific constraints!

            } else if (eventType == "CHARGE") {
                const string& txn_id = event[1];
                const string& merchant_id = event[2];
                const string& category = event[3];
                // int amount = stoi(event[4]); // Included if amount is needed for weighted calculations

                // TODO: 1. If merchant doesn't exist in map, initialize them
                if(merchants.count(merchant_id) == 0) {
                    auto new_merchant = MerchantState(merchant_id, category);
                    merchants[merchant_id] = new_merchant;
                }

                // TODO: 2. Record the transaction in the transactions map
                auto new_transaction = TransactionState(txn_id, merchant_id);
                transactions[txn_id] = new_transaction;

                // TODO: 3. Increment merchant's total charges
                merchants[merchant_id].total_charges += 1;

                // TODO: 4. Evaluate merchant status and append alert if state changes
                bool state_changed = update_merchant_status(merchant_id);
                if(state_changed) {
                    append_alert(alerts, merchant_id);
                }

            } else if (eventType == "DISPUTE") {
                const string& txn_id = event[1];

                // TODO: 1. Check if transaction exists. If not, ignore.
                if(transactions.count(txn_id) == 0) {
                    continue;
                }

                // TODO: 2. Check if transaction is already disputed (Idempotency). If yes, ignore.
                if(transactions[txn_id].is_disputed) {
                    continue;
                }

                // TODO: 3. Mark transaction as disputed
                transactions[txn_id].is_disputed = true;

                // TODO: 4. Find associated merchant and increment total_disputes
                auto merchant_id = transactions[txn_id].merchant_id;
                merchants[merchant_id].total_disputes += 1;

                // TODO: 5. Evaluate merchant status and append alert if state changes
                bool state_changed = update_merchant_status(merchant_id);
                if(state_changed) {
                    append_alert(alerts, merchant_id);
                }

            } else if (eventType == "RESOLVE") {
                const string& txn_id = event[1];

                // TODO: 1. Check if transaction exists and is currently disputed. If not, ignore.
                if(transactions.count(txn_id) == 0 || !transactions[txn_id].is_disputed) {
                    continue;
                }

                // TODO: 2. Mark transaction as NOT disputed
                transactions[txn_id].is_disputed = false;

                // TODO: 3. Find associated merchant and decrement total_disputes
                auto merchant_id = transactions[txn_id].merchant_id;
                merchants[merchant_id].total_disputes -= 1;

                // TODO: 4. Evaluate merchant status and append alert if state changes
                bool state_changed = update_merchant_status(merchant_id);
                if(state_changed) {
                    append_alert(alerts, merchant_id);
                }
            }
        }

        return alerts;
    }
};

// Simple driver for local testing
int main() {
    vector<vector<string>> sample_events = {
        {"SET_THRESHOLD", "electronics", "0.4"},
        {"CHARGE", "t1", "m_apple", "electronics", "1000"},
        {"CHARGE", "t2", "m_apple", "electronics", "1000"},
        {"CHARGE", "t3", "m_apple", "electronics", "1000"},
        {"DISPUTE", "t1"},
        {"DISPUTE", "t2"},
        {"DISPUTE", "t2"}, // Duplicate
        {"CHARGE", "t4", "m_bookstore", "books", "20"},
        {"DISPUTE", "t4"},
        {"RESOLVE", "t1"}
    };

    FraudEngine engine;
    vector<string> output = engine.processEvents(sample_events);

    cout << "--- Generated Alerts ---" << endl;
    for (const string& alert : output) {
        cout << alert << endl;
    }

    return 0;
}