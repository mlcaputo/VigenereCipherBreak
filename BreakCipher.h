#ifndef BREAKCIPHER_H
#define BREAKCIPHER_H
#include <vector>
#include <string>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<std::vector<char>> breakCipher(std::string cipherText); 

bool isEnglish(std::string text, std::vector<char> key);

std::vector<std::vector<char>> generateAllPossibleKeys();

#endif