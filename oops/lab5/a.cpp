#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // reading from file

    // ifstream file("test.txt");
    // string line;
    // while (getline(file, line)) {
    //     cout << line << endl;
    // }
    // char ch;
    // while (file.get(ch)) {
    //     cout << ch;
    // }
    // string word;
    // while (file >> word) {
    //     cout << word << endl;
    // }
    // file.close();

    // writing to file
    // ofstream file("data.txt"); 
    // // fstream file("data.txt", ios::out);
    // file << "Hello World\n";
    // file << 25 << endl;
    // file.close();

    // appending to file
    // ofstream file("test.txt", ios::app);
    // file << "New line added\n";
    // file.close();

    // write at specific line 
    ifstream in("data.txt");
    vector<string> lines;
    string line;
    while (getline(in, line)) {
        lines.push_back(line);
    }
    in.close();
    int target = 2;
    lines[target - 1] = "Modified line";
    ofstream out("data.txt");
    for (auto &l : lines) {
        out << l << endl;
    }
    out.close();

    return 0;
}