// Fully observation based question hai ye.
/*
    Logic ye hoga ki hum agar 01 and 10 ko saath rakhenge to final string 0110 banega jaha par sirf 2 hi position par different hai.
    Nahi to 1010 ya 0101 mein 3 position par different aa jaayega.
    
    Isi liye hum log pair banane ka try karenge.
    Pair ke liye dono mein se minimum hi consider hoga.
    
    Ab baaki bache hue string ko ya to starting mein ya last meib rakhna jyaada suitable hoga.
    Usi ke liye har character par different mil hi jaayega.
*/

#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int diff = abs(x - y);
        int ans = min(x, y) * 2 + (diff * 2);
        
        // answer mein -1 karne ka logic ye hai ki hum starting ya ennding mein optimally aise rakh denge ki 0 uar 0 saath ho jaaye ya 1 aur 1 saath ho jaaye, isse ek index aur kam ho jaayega jaha par differ kar raha hai.
        if (diff > 0)
            ans -= 1;
        cout << ans << endl;
    }
}