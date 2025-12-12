#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// check vowel
bool isVowel(char c) {
    c = tolower(c);
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main() {
    ifstream file("../inputs/input2.txt");
    if(!file.is_open()) {
        cout << "Error: Cannot open input2.txt" << endl;
        return 1;
    }

    string s;
    getline(file, s);
    file.close();


    string rev = string(s.rbegin(), s.rend());
    cout << "After reverse: " << rev << endl;

    string removed = "";
    for(int i=0; i<rev.size(); i++) {
        if( (i % 3) == 2 ) continue;  
        removed += rev[i];
    }
    cout << "After removing every 3rd: " << removed << endl;

    string shifted = "";
    for(char c : removed) {
        shifted += char(c + 2);
    }
    cout << "After +2 shift: " << shifted << endl;
   
    int vowelCount = 0;
    for(char c : shifted) {
        if(isVowel(c)) vowelCount++;
    }

    cout << "Clue 2 (vowel count) = " << vowelCount << endl;

    return 0;
}
