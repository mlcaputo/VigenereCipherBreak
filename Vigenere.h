#ifndef VIGENERE_H
#define VIGENERE_H
#include <string>
#include <vector>

std::string vigenereEncrypt(std::string text, std::vector<char> shift);

std::string vigenereDecrypt(std::string text, std::vector<char> shift);


#endif