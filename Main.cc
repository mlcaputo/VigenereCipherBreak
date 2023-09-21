#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>
#include "Caesar.h"
#include "Vigenere.h"
#include "FileReader.h"
#include "GenerateKey.h"
#include "BreakCipher.h"

using namespace std;

// Printing all the elements of a vector
template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector){
    for (auto element : vector) {
        os << element;
    }
    return os;
}

int main(){

    // Reads in the sample text
    vector<string> textInputs = readFile("Sample.txt");
    int inputCount = textInputs.size();

    for(int i = 0; i < textInputs.size(); i++){
        string temp = textInputs[i];
        
        for(int i = 0; i < temp.length(); i++){
            temp[i] = toupper(temp[i]);
        }

        temp.erase(remove_if(temp.begin(), temp.end(), ::ispunct), temp.end());
        temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());

        textInputs[i] = temp;
    }

    /*
    vector<char> testKey;
    testKey.push_back('L');
    testKey.push_back('E');
    testKey.push_back('M');
    testKey.push_back('O');
    testKey.push_back('N');

    string testText = textInputs[0];
    cout << testText << "\n\n";
    testText = vigenereEncrypt(testText, testKey);
    cout << testText << "\n\n";
    testText = vigenereDecrypt(testText, testKey);
    cout << testText << "\n\n";
    */


    //Generates a key for each sample text
    vector<vector<char>> keys = generateAllKeys(inputCount);

    //Convert input texts to vigenere cipher texts
    vector<string> cipherTexts;
    for(int i = 0; i < inputCount; i++){
        string temp = vigenereEncrypt(textInputs[i], keys[i]);
        cipherTexts.push_back(temp);
    }

    //Break the cipher
    for(int i = 0; i < inputCount; i++){
        cout << "Example " << i + 1 << ": Key = " << keys[i] <<"\n";
        vector<vector<char>> answers = breakCipher(cipherTexts[i]);
        //for(vector<char> element: answers){
        //     cout << element << "\n";
        //}
        cout << "*********************************************************************************************************\n";
    }

    return 0;

}