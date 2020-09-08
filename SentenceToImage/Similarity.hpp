#ifndef Similarity_hpp
#define Similarity_hpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "stringAlgorithm.hpp"
using namespace std;

class Similarity {
public:
    vector <pair<double, string>> similarString;
    vector <pair<double, string>>::iterator iter;
    //vector <pair<double, string>> similarRK;
    //vector <pair<double, string>> similarBM;
    Similarity(string *str);
    //void insertKMP();
    //void insertRK();
    //void insertBM();
};


#endif /* Similarity_hpp */
