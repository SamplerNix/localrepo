#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

// Define the Morse code dictionary
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

// Function to convert Morse code to normal text
string morseToText(string morseCode) {
    stringstream ss(morseCode);
    string word, result;

    // Split the Morse code into words
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
    // Example Morse code input
    string morseInput = ".- --- ... / -.-. --- -.. .";

    cout << "Morse Code: " << morseInput << endl;
    string normalText = morseToText(morseInput);
    cout << "Normal Text: " << normalText << endl;

    return 0;
}
