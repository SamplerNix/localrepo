#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

// map crea
unordered_map<string, char> morseCodeMap = {
    {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'}, 
    {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'}, {"..", 'I'}, {".---", 'J'},
    {"-.-", 'K'}, {".-..", 'L'}, {"--", 'M'}, {"-.", 'N'}, {"---", 'O'},
    {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
    {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'}, {"-.--", 'Y'},
    {"--..", 'Z'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'},
    {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'},
    {"-----", '0'}
};

// Function jo 
string morseToText(string morseCode) {
    stringstream ss(morseCode);
    string word, result;

    //  divide kr rha hai morse
    while (getline(ss, word, '/')) {
        // Split each word into individual Morse characters
        stringstream wordStream(word);
        string morseLetter;
        
        while (getline(wordStream, morseLetter, ' ')) {
            if (morseCodeMap.find(morseLetter) != morseCodeMap.end()) {
                result += morseCodeMap[morseLetter];
            } else {
                result += '?'; // Handle invalid Morse code
            }
        }
        result += ' '; // Add space between words
    }
    
    return result;
}

int main() {
    string morseInput;

    // Prompt the user for Morse code input
    cout << "Enter Morse code (use spaces between letters and '/' between words): ";
    getline(cin, morseInput);

    // Convert Morse code to normal text
    string normalText = morseToText(morseInput);

    // Display the result
    cout << "Morse Code: " << morseInput << endl;
    cout << "Normal Text: " << normalText << endl;

    return 0;
}
