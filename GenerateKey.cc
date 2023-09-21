#include "GenerateKey.h"
#include <string>
#include <vector>
#include <stdlib.h> 
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

vector<char> generateKey(){
    int keyLowerBound = 3;
    int keyUpperBound = 4;
    int alfUpperBound = 26;
    vector<char> result;
    srand(time(0));

    int randNumKeySize = (rand() % (keyUpperBound - keyLowerBound + 1)) + keyLowerBound;

    for(int i = 0; i < randNumKeySize; i++){
        int randNumLetter = rand() % alfUpperBound;
        result.push_back(char(randNumLetter + 65));
    }
    
    return result;
}

vector<vector<char>> generateAllKeys(int keyCount){
    vector<vector<char>> result;
    srand(time(0));
    int keyLowerBound = 3;
    int keyUpperBound = 4;
    int alfUpperBound = 26;

    for(int i = 0; i < keyCount; i++){
        int randNumKeySize = (rand() % (keyUpperBound - keyLowerBound + 1)) + keyLowerBound;
        vector<char> temp;

        for(int i = 0; i < randNumKeySize; i++){
            int randNumLetter = rand() % alfUpperBound;
            temp.push_back(char(randNumLetter + 65));
        }
        result.push_back(temp);
    }

    return result;

}

