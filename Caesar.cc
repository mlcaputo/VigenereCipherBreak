#include "Caesar.h"
#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>

using namespace std;


string caesarEncrypt(string text, char shift)
{
    string result = "";
    int textLength = text.length();
    shift = toupper(shift);
    int shiftValue = int(shift) - 65;

    for(int i = 0; i < textLength; i++){
        if(int(text[i]) != 32){
            result += char(int(text[i] + shiftValue - 65) % 26 + 65);
        }
        else{
            result += text[i];
        }
    }

    return result;
}

string caesarDecrypt(string text, char shift)
{
    string result = "";
    int textLength = text.length();
    shift = toupper(shift);
    int shiftValue = int(shift) - 65;
    
    for(int i = 0; i < textLength; i++){
        if(int(text[i]) != 32){
            result += char(int(text[i] - shiftValue + 65) % 26 + 65);
        }
        else{
            result += text[i];
        }
    }
    
    return result;

}