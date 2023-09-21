#include "FileReader.h"
#include <string>
#include <vector>
#include <fstream> 
using namespace std;

vector<string> readFile(string name){
    vector<string> output;
    string fileStream;

    ifstream file(name);

    while(getline(file, fileStream)){
        output.push_back(fileStream);
    }

    return output;

}

