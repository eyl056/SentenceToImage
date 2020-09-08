#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>
#include "englishWord.hpp"
#include <map>
#include <set>
using namespace std;
//using namespace cv;
#ifndef senToWord_hpp
#define senToWord_hpp

class SenToWor {
    string alphabetString;
    string wordAssembled = "";
    string wordAssembledCount[100];
    int count = 0;
    map <string, string> dicV;
    set <string> dicVorigin;
public:
    SenToWor(string alphabetString);
    void run(string* str);
};

#endif /* senToWord_hpp */
