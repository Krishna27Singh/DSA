
#include <iostream>
#include<map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<pair<long long, long long> > monsters(n);
        map<long long, int> x_count, y_count;
        
        for (int i = 0; i < n; i++) {
            cin >> monsters[i].first >> monsters[i].second;
            x_count[monsters[i].first]++;
            y_count[monsters[i].second]++;
        }
        
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        
        vector<long long> x_coords, y_coords;
        for (const auto& p : x_count) x_coords.push_back(p.first);
        for (const auto& p : y_count) y_coords.push_back(p.first);
        
        long long min_x = x_coords[0], max_x = x_coords.back();
        long long min_y = y_coords[0], max_y = y_coords.back();
        
        long long initial_area = (max_x - min_x + 1) * (max_y - min_y + 1);
        long long min_area = initial_area;
        
        // Try removing monsters on boundaries
        for (int i = 0; i < n; i++) {
            long long x = monsters[i].first, y = monsters[i].second;
            
            long long new_min_x = min_x, new_max_x = max_x;
            long long new_min_y = min_y, new_max_y = max_y;
            
            bool changed = false;
            
            // Check if removing this monster changes the bounding rectangle
            if (x == min_x && x_count[x] == 1 && x_coords.size() > 1) {
                new_min_x = x_coords[1];
                changed = true;
            }
            
            if (x == max_x && x_count[x] == 1 && x_coords.size() > 1) {
                new_max_x = x_coords[x_coords.size() - 2];
                changed = true;
            }
            
            if (y == min_y && y_count[y] == 1 && y_coords.size() > 1) {
                new_min_y = y_coords[1];
                changed = true;
            }
            
            if (y == max_y && y_count[y] == 1 && y_coords.size() > 1) {
                new_max_y = y_coords[y_coords.size() - 2];
                changed = true;
            }
            
            if (!changed) continue;
            
            long long width = new_max_x - new_min_x + 1;
            long long height = new_max_y - new_min_y + 1;
            long long total_cells = width * height;
            
            if (total_cells > n - 1) {
                // Can place monster within the bounding rectangle
                min_area = min(min_area, width * height);
            } else {
                // Must extend the bounding rectangle
                long long extend_horizontal = (width + 1) * height;
                long long extend_vertical = width * (height + 1);
                min_area = min(min_area, min(extend_horizontal, extend_vertical));
            }
        }
        
        cout << min_area << "\n";
    }
    
    return 0;
}
