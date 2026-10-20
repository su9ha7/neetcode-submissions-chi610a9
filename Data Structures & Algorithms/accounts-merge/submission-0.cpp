#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
    unordered_map<string, string> parent;

    // Find operation with Path Compression
    string find(string email) {
        if (parent[email] == email) return email;
        return parent[email] = find(parent[email]);
    }

    // Union operation
    void unionSets(string email1, string email2) {
        string root1 = find(email1);
        string root2 = find(email2);
        if (root1 != root2) {
            parent[root1] = root2;
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;

        // 1. Initialize parents and union emails within the same account
        for (const auto& acc : accounts) {
            string name = acc[0];
            string firstEmail = acc[1];

            for (int i = 1; i < acc.size(); ++i) {
                string email = acc[i];
                if (!parent.count(email)) {
                    parent[email] = email; // Initialize self-parent
                }
                emailToName[email] = name; // Map email to owner name
                
                // Union the first email with all other emails in this account
                unionSets(firstEmail, email);
            }
        }

        // 2. Group emails by their ultimate root leader
        unordered_map<string, vector<string>> mergedGroups;
        for (const auto& pair : parent) {
            string email = pair.first;
            string rootLeader = find(email);
            mergedGroups[rootLeader].push_back(email);
        }

        // 3. Format result (sort emails alphabetically & prepended with name)
        vector<vector<string>> result;
        for (auto& pair : mergedGroups) {
            vector<string>& emails = pair.second;
            sort(emails.begin(), emails.end()); // Requirement: sorted order

            vector<string> account;
            account.push_back(emailToName[pair.first]); // Insert owner name
            account.insert(account.end(), emails.begin(), emails.end());
            
            result.push_back(account);
        }

        return result;
    }
};
