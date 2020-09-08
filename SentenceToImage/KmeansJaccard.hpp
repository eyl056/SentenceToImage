#ifndef KmeansJaccard_hpp
#define KmeansJaccard_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <functional>
#include "KmeansJaccard.hpp"
#include "Similarity.hpp"
using namespace std;

class Jaccard {
    vector<pair<double, string>> text;
public:
    string stringJaccard[5]={};
    const char* NONCHAR = ".,:;\"()";
    Jaccard(vector<pair<double, string>> text);
    void preprocess(string& text);
    double jaccard(string str1, string str2);
    void run(string alphabetString);
    void erasee(string& str);
    string STR(string str, int maxLength);
    void getVector();
};


#endif /* KmeansJaccard_hpp */
