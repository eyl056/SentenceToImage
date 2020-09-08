#include "KmeansJaccard.hpp"
#include "Similarity.hpp"
#ifndef PROJECT_KMEANSJACCARD_H
#define PROJECT_KMEANSJACCARD_H
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
Jaccard::Jaccard(vector <pair<double, string>> text)
{
    this->text = text;
}

void Jaccard::preprocess(string & text)
{
    for (int i = 0; NONCHAR[i]; ++i) {
        text.erase(remove(text.begin(), text.end(), NONCHAR[i]), text.end());
    }
}

void Jaccard::erasee(string& str) {
    string newString = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            str.erase(i, 1);
        }
    }
}

string Jaccard::STR(string str, int maxLength) {
    auto itr = str.begin();
    if (str.length() > (maxLength * 3))
    {
        int len = 0;
        while (itr != str.end())
        {
            if (len > (maxLength * 2) - 1)
            {
                return str.substr(0, std::distance(str.begin(), itr));
            }

            unsigned char c = *itr;

            if (c > 128)
            {
                itr += 2;
                ++len;
            }

            ++itr;
            ++len;
        }

    }

    return str;
}

double Jaccard::jaccard(string str1, string str2) {
    erasee(str1);
    erasee(str2);
    vector<string> strSet1;
    vector<string> strSet2;
    vector<string> unionSet;
    vector<string> interSet;

    int count = 0;
    int flag = 0;
    string temp = "";

    for (int i = 0; i < str1.length(); ) {
        if (str1[i] >> 7) {
            temp += str1.substr(i, 3);
            i += 3;
            count++;
            flag = 3;
        }
        else {
            temp += str1.substr(i, 1);
            i++;
            count++;
            flag = 1;
        }
        if (count == 2) {
            strSet1.push_back(temp);
            temp = "";
            count = 0;
            i -= flag;
        }
    }
    count = 0;
    flag = 0;
    temp = "";
    for (int i = 0; i < str2.length(); ) {
        if (str2[i] >> 7) {
            temp += str2.substr(i, 3);
            i += 3;
            count++;
            flag = 3;
        }
        else {
            temp += str2.substr(i, 1);
            i++;
            count++;
            flag = 1;
        }
        if (count == 2) {
            strSet2.push_back(temp);
            temp = "";
            count = 0;
            i -= flag;
        }
    }


    for (int i = 0; i < strSet1.size(); i++) {
        for (int j = 0; j < strSet2.size(); j++) {
            if (strSet1[i] == strSet2[j]) interSet.push_back(strSet2[j]);
        }
    }
    unionSet.insert(unionSet.end(), strSet1.begin(), strSet1.end());
    unionSet.insert(unionSet.end(), strSet2.begin(), strSet2.end());

    sort(unionSet.begin(), unionSet.end());
    unionSet.erase(unique(unionSet.begin(), unionSet.end()), unionSet.end());
    sort(interSet.begin(), interSet.end());
    interSet.erase(unique(interSet.begin(), interSet.end()), interSet.end());

    return (double)interSet.size() / (double)unionSet.size();

}

void Jaccard::run(string alphabetString)
{
    string text1 = alphabetString;

    int i = 0;

    while (i < text.size()) {
        string text2 = text[i].second;
        //preprocess(text2);
        text[i].first = jaccard(text1, text2);
        i++;
    }
    sort(text.begin(), text.end());
}

void Jaccard::getVector()
{
    int countJ=0;
    
    cout << "    < K-means Jaccard similarity >" << endl << endl;
    for (int i = (int)text.size()-1; i >=5; i--)
    {
        cout << setw(10) << left << text[i].first;
        cout << text[i].second << endl;
        //cout << "    " << text[i].second << endl << text[i].first << endl;
        
//        for(int j=0;j<text[i].second.size();j++) {
//            if(text[i].second[j]=='\n') {text[i].second[j-1]='p';}
//        }
        
        text[i].second.append("png");
        
        //string temppp= stringJaccard[countJ];
    
        stringJaccard[countJ] = text[i].second;
        countJ++;
    }
    
    cout << endl << endl;
}


#endif //PROJECT_KMEANSJACCARD_H

