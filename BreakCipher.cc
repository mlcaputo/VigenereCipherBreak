#include "BreakCipher.h"
#include "Vigenere.h"
#define MAX 474552
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector){
    for (auto element : vector) {
        os << element;
    }
    return os;
}

vector<vector<char>> breakCipher(string cipherText){
    vector<vector<char>> results;
    vector<vector<char>> allPossibleKeys = generateAllPossibleKeys();

    for(int i = 0; i < MAX; i++){
        //cout << i << "\n";     
        string decipheredText = vigenereDecrypt(cipherText, allPossibleKeys[i]);
        //cout << i << "\n";

        if(isEnglish(decipheredText, allPossibleKeys[i]) == true){
            results.push_back(allPossibleKeys[i]);
            //cout << allPossibleKeys[i] << "\n\n";
        }
        //cout << i << "\n";
    }

    return results;
}

bool isEnglish(string text, vector<char> key){
    int subSetLength = text.length() - 3;
    int totalSubstrings = 0;
    vector<string> subStringHolder;

    for(int i = 0; i <= subSetLength; i++){
        string temp = text.substr(i, 3);
        subStringHolder.push_back(temp);
        totalSubstrings++;
    }

    //cout << subStringHolder[0] << "\n";

    int theCount = 0;
    int andCount = 0;
    int ingCount = 0;
    int herCount = 0;
    int hatCount = 0;

    for(int j = 0; j < subSetLength; j++){
        if(subStringHolder[j] == "THE"){
            theCount++;
        }
        else if(subStringHolder[j] == "AND"){
            andCount++;
        }
        else if(subStringHolder[j] == "ING"){
            ingCount++;
        }
        else if(subStringHolder[j] == "HER"){
            herCount++;
        }
        else if(subStringHolder[j] == "HAT"){
            hatCount++;
        }
        
    }

    double thePercent = (double(theCount) / double(totalSubstrings)) * 100.0;
    double andPercent = (double(andCount) / double(totalSubstrings)) * 100.0;
    double ingPercent = (double(ingCount) / double(totalSubstrings)) * 100.0;
    double herPercent = (double(herCount) / double(totalSubstrings)) * 100.0;
    double hatPercent = (double(hatCount) / double(totalSubstrings)) * 100.0;

    double totalPercent  = thePercent + andPercent + ingPercent + herPercent + hatPercent;
    double expectedTotalPercent = 3.508 + 1.594 + 1.147 + 0.822 + 0.651;
    double triUpperBound = expectedTotalPercent + 5.0;
    double triLowerBound = expectedTotalPercent - 5.0; 

    int eCount = 0;

    for(int i = 0; i < text.length(); i++){
        if(text[i] == 'E'){
            eCount++;
        }
    }

    double ePercent = (double(eCount) / double(text.length())) * 100.0;
    double eUpperBound = 12.576 + 5.0;
    double eLowerBound = 12.576 - 5.0;  


    if((totalPercent >= triLowerBound && totalPercent <= triUpperBound) && (ePercent >= eLowerBound && ePercent <= eUpperBound)){ 
        cout << "Key: " << key << "\n" << "Trigrams %: " << totalPercent << "  E %: " << ePercent << "\n\n";      
        return true;
    }

    return false;
} 


vector<vector<char>> generateAllPossibleKeys(){
    
    vector<vector<char>> allPossibleKeys;
    char pos1Letter;
    char pos2Letter;
    char pos3Letter;
    char pos4Letter;
    
    for(int i = 0; i < 26; i++){
        pos1Letter = char(65 + i);

        for(int j = 0; j < 26; j++){
            pos2Letter = char(65 + j);

            for(int k = 0; k < 26; k++){
                pos3Letter = char(65 + k);

                vector<char> temp;
                temp.push_back(pos1Letter);
                temp.push_back(pos2Letter);
                temp.push_back(pos3Letter);

                allPossibleKeys.push_back(temp);
            }
        }
    }

    for(int i = 0; i < 26; i++){
        pos1Letter = char(65 + i);

        for(int j = 0; j < 26; j++){
            pos2Letter = char(65 + j);

            for(int k = 0; k < 26; k++){
                pos3Letter = char(65 + k);

                for(int l = 0; l < 26; l++){
                    pos4Letter = char(65 + l);

                    vector<char> temp;
                    temp.push_back(pos1Letter);
                    temp.push_back(pos2Letter);
                    temp.push_back(pos3Letter);
                    temp.push_back(pos4Letter);

                    allPossibleKeys.push_back(temp);
                }
            }
        }
    }

    return allPossibleKeys;

}

