/**
 * Problem: Project Scheduling / Weighted Interval Scheduling
 * Approach: Memoization (Top-Down DP) + Binary Search
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a Project
struct Project {
    int id;
    int start, end, reward;
};

// Comparator to sort projects by their ending days
bool compareProjects(const Project& a, const Project& b) {
    return a.end < b.end;
}

int n;
vector<Project> projects;
vector<long long> memo; // Memoization table

// Binary Search to find the index of the latest project that finishes
// before the current project starts.
// Returns -1 if no such project exists.
int findLatestNonConflicting(int index) {
    int low = 0;
    int high = index - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // We need a project that ends strictly before the current one starts
        if (projects[mid].end < projects[index].start) {
            ans = mid;      // Found a candidate, try to find a later one
            low = mid + 1;
        } else {
            high = mid - 1; // This project conflicts, look earlier
        }
    }
    return ans;
}

// Recursive function with memoization
long long solve(int i) {
    // Base case: If no projects are left to consider
    if (i < 0) return 0;

    // Return cached value if already computed
    if (memo[i] != -1) return memo[i];

    // Option 1: Exclude the current project
    // Profit is equal to the best we can do with the previous i-1 projects
    long long excludeProfit = solve(i - 1);

    // Option 2: Include the current project
    // Profit is current reward + best we can do with compatible projects before this
    int prevCompatibleIndex = findLatestNonConflicting(i);
    long long includeProfit = projects[i].reward + solve(prevCompatibleIndex);

    // Store the maximum of the two options and return
    return memo[i] = max(includeProfit, excludeProfit);
}

int main() {
    // Optimize I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> n) {
        projects.resize(n);
        memo.assign(n, -1); // Initialize memo table with -1

        for (int i = 0; i < n; i++) {
            projects[i].id = i;
            cin >> projects[i].start >> projects[i].end >> projects[i].reward;
        }

        // Step 1: Sort projects by end time
        sort(projects.begin(), projects.end(), compareProjects);

        // Step 2: Call the recursive solver for the last index (n-1)
        cout << solve(n - 1) << endl;
    }

    return 0;
}