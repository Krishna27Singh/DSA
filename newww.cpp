#include <iostream>\
using namespace std;

long getMaximumPrizes(string inputString) {
    long n = inputString.length();
    
    vector<long> suffixZ(n + 1, 0);
    
    for (int i = n - 1; i >= 0; i--) {
        suffixZ[i] = suffixZ[i + 1] + (inputString[i] == 'Z' ? 1 : 0);
    }
    
    long currentAMZ = 0;
    long countA = 0;
    long countAM = 0;
    long countMZ = 0;
    long maxGainM = 0;
    
    for (int i = 0; i < n; i++) {
        char c = inputString[i];
        
        long currentGainM = countA * suffixZ[i];
        if (currentGainM > maxGainM) {
            maxGainM = currentGainM;
        }
        
        if (c == 'A') {
            countA++;
        } 
        else if (c == 'M') {
            countAM += countA;
            countMZ += suffixZ[i + 1];
        } 
        else if (c == 'Z') {
            currentAMZ += countAM;
        }
    }
    
    long maxAdditional = max({countMZ, countAM, maxGainM});
    
    return currentAMZ + maxAdditional;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string inputString;
    getline(cin, inputString);

    long result = getMaximumPrizes(inputString);

    fout << result << "\n";

    fout.close();

    return 0;
}