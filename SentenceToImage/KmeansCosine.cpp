#include "KmeansCosine.hpp"
#include "KmeansJaccard.hpp"
#include "Similarity.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

Cosine::Cosine(vector <pair<double, string>> stringsentence)
{
    // vector<pair<double, string>> stringsentence
    this->stringsentence = stringsentence;
}

void Cosine::preprocess(string & stringsentence)
{
    for (int i = 0; NONCHAR[i]; ++i) {
        stringsentence.erase(remove(stringsentence.begin(), stringsentence.end(), NONCHAR[i]), stringsentence.end());
    }
}

string* Cosine::tokenize(string stringsentence, int& size) {
    string* tokens = new string[MAX_TOKENS];
    stringstream stream(stringsentence);
    size = 0;
    while (stream.good() && size < MAX_TOKENS) {
        stream >> tokens[size++];
    }
    return tokens;
}

bool Cosine::inArray(string str, string* strArray, int strArraySize) {
    for (int i = 0; i < strArraySize; ++i) {
        if (str == strArray[i]) {
            return true;
        }
    }
    return false;
}
int Cosine::frequency(string token, string* tokens, int tokensSize) {
    int freq = 0;
    for (int i = 0; i < tokensSize; ++i) {
        if (token == tokens[i]) {
            ++freq;
        }
    }
    return freq;
}
int Cosine::dotProduct(int* v1, int* v2, int size) {
    int prod = 0;
    for (int i = 0; i < size; ++i) {
        prod += v1[i] * v2[i];
    }
    return prod;
}
double Cosine::sqrtt(int* t, int size) {
    return sqrt(dotProduct(t, t, size));
}
double Cosine::Similarity(string* t1, int t1Size,
    string* t2, int t2Size) {
    string* distinctTokens = new string[t1Size + t2Size];
    int distinctTokensSize = 0;
    for (int i = 0; i < t1Size; ++i) {
        if (!inArray(t1[i], distinctTokens, distinctTokensSize)) {
            distinctTokens[distinctTokensSize++] = t1[i];
        }
    }
    for (int i = 0; i < t2Size; ++i) {
        if (!inArray(t2[i], distinctTokens, distinctTokensSize)) {
            distinctTokens[distinctTokensSize++] = t2[i];
        }
    }
    int* frequencies1 = new int[distinctTokensSize];
    int* frequencies2 = new int[distinctTokensSize];
    for (int i = 0; i < distinctTokensSize; ++i) {
        frequencies1[i] = frequency(distinctTokens[i], t1, t1Size);
        frequencies2[i] = frequency(distinctTokens[i], t2, t2Size);
    }
    delete[] distinctTokens;
    double sim = dotProduct(
        frequencies1, frequencies2, distinctTokensSize) /
        (sqrtt(frequencies1, distinctTokensSize) *
            sqrtt(frequencies2, distinctTokensSize));
    delete[] frequencies1;
    delete[] frequencies2;
    return sim;
}

void Cosine::run(string alphabetString)
{
    string stringsentence1 = alphabetString;

    int t1Size;
    string* t1 = tokenize(stringsentence1, t1Size);
    
    int i = 0;

    while (i < stringsentence.size()) {
        string stringsentence2 = stringsentence[i].second;
        int t2Size;
        string* t2 = tokenize(stringsentence2, t2Size);
        stringsentence[i].first = Similarity(t1, t1Size, t2, t2Size);
        i++;
    }
    sort(stringsentence.begin(), stringsentence.end());
}

void Cosine::getVector()
{
    int countC =0;
    
    cout << "    < K-means Cosine similarity >" << endl << endl;
    for (int i = (int)stringsentence.size()-1; i >=5; i--)
    {
        cout << setw(10) << left << stringsentence[i].first;
        cout << stringsentence[i].second << endl;
        stringCosine[countC] = stringsentence[i].second;
        countC++;
    }
    cout << endl << endl;
}

