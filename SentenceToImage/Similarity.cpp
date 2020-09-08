#include "stringAlgorithm.hpp"
#include "Similarity.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

Similarity::Similarity(string *str) {
    similarString.push_back(make_pair(-1, str[0]));
    similarString.push_back(make_pair(-1, str[1]));
    similarString.push_back(make_pair(-1, str[2]));
    similarString.push_back(make_pair(-1, str[3]));
    similarString.push_back(make_pair(-1, str[4]));
    similarString.push_back(make_pair(-1, str[5]));
    similarString.push_back(make_pair(-1, str[6]));
    similarString.push_back(make_pair(-1, str[7]));
    similarString.push_back(make_pair(-1, str[8]));
    similarString.push_back(make_pair(-1, str[9]));
//    for(iter = similarRK.begin(); iter!=similarRK.end();iter++) {
//        cout<<"유사도 처음 초기화 출력 확인"<<endl;
//        cout<<(*iter).second<<endl;
//    }
}
