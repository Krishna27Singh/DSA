#include <iostream>
#include <string>
#include <map>

using namespace std;

void displayCarParkingDetails(int n, string strs[]) {
    map<string, int> rates = {
        {"S4", 120}, {"SE", 120}, {"SS", 100}, {"SD", 80},
        {"SW", 90}, {"DTS", 130}, {"CTS", 150}, {"HTBK", 50}
    };
    
    string codes[] = {"HTBK", "DTS", "CTS", "S4", "SE", "SS", "SD", "SW"};

    for (int i = 0; i < n; ++i) {
        string s = strs[i];
        
        string sd = s.substr(s.length() - 4);
        int d = stoi(sd);
        
        string r = s.substr(0, s.length() - 4);
        string p = "";
        int rt = 0;
        
        for (int j = 0; j < 8; ++j) {
            string code = codes[j];
            if (r.length() >= code.length() && 
                r.compare(r.length() - code.length(), code.length(), code) == 0) {
                
                p = r.substr(0, r.length() - code.length());
                rt = rates[code];
                break;
            }
        }
        
        long long fee = (long long)d * rt;
        cout << p << " " << fee << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        string* strs = new string[n]; 
        for (int i = 0; i < n; ++i) {
            cin >> strs[i];
        }
        
        displayCarParkingDetails(n, strs);
        
        delete[] strs; 
    }
    return 0;
}