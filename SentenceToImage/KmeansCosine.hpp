#ifndef KmeansCosine_hpp
#define KmeansCosine_hpp

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
#include "KmeansCosine.hpp"
using namespace std;
const int MAX_STOPWORDS = 200;
const int MAX_TOKENS = 400;
const int MAX_FILES = 300;

class Cosine {
    vector<pair<double, string>> stringsentence;
public:
    string stringCosine[5]={"",};
    Cosine(vector<pair<double, string>> stringsentence);
    void preprocess(string& stringsentence);
    void run(string alphabetString);
    const char* NONCHAR = ".,:;\"()";
    void getVector();
    string* tokenize(string stringsentence, int& size);
    bool inArray(string str, string* strArray, int strArraySize);
    int frequency(string token, string* tokens, int tokensSize);
    int dotProduct(int* v1, int* v2, int size);
    double sqrtt(int* v, int size);
    double Similarity(string* t1, int t1Size, string* t2, int t2Size);
};

#endif /* KmeansCosine_hpp */
