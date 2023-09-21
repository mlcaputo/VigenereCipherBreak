#include "Vigenere.h"
#include "Caesar.h"
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>
#include <string_view>

using namespace std;


string vigenereEncrypt(string text, vector<char> key)
{
    string output = "";
    int keyLength = key.size();
    int textLength = text.size();

    for (int i = 0; i < textLength; i++){
        string temp = ""; 
        temp += text[i]; 
        output += caesarEncrypt(temp, key[i % keyLength]);
    }

    return output;
 
}

string vigenereDecrypt(string text, vector<char> key)
{
    string output = "";
    int keyLength = key.size();
    int textLength = text.size();

    for (int i = 0; i < textLength; i++){
        string temp = ""; 
        temp += text[i]; 
        output += caesarDecrypt(temp, key[i % keyLength]);
    }

    return output;
}