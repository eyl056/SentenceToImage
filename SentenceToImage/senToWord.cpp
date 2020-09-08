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
#include "senToWord.hpp"

SenToWor::SenToWor(string alphabetString) {
    this->alphabetString = alphabetString;
}
void SenToWor::run(string* str) {
    for(int i=0;i<alphabetString.size();i++) {
         alphabetString[i] = tolower(alphabetString[i]);
     }
     
    VtoV(dicV, dicVorigin);

    for (int i = 0; i < alphabetString.size(); i++) {

       bool isWord = true;
       if (alphabetString[i] == ' ' || alphabetString[i] == '\n' || alphabetString[i] == '.' || alphabetString[i] == ',' ) {
          isWord = false;
          //cout<<endl;
          //cout<<wordAssembled<<endl;
          wordAssembledCount[count] = wordAssembled;
          count++;
          wordAssembled = "";
       }
       if (isWord) {
          wordAssembled += alphabetString[i];
       }
    }
    //cout<< wordAssembled<<"안녕"<<endl;
    wordAssembledCount[count] = wordAssembled;
    count++;

    for (int i = 0; i < 10; i++) {
       int wordSize = (int)wordAssembledCount[i].size();

       if (wordSize >= 1) {
          cout << "단어 " << i + 1 << ": " << wordAssembledCount[i] << endl;
       }
    }
    cout << endl << endl;

    string wordAssembledCountCopy[100];
     string checke[100];
    string readWordAssembled[100];
    set<string>::iterator iter;
    for (int i = 0; i < 10; i++) {
       int wordSize = (int)wordAssembledCount[i].size();


       wordAssembledCountCopy[i] = wordAssembledCount[i];
       if (wordSize >= 1) {
           // he's 처럼 조사 이어진 경우
           if (wordSize>=2 && wordAssembledCountCopy[i].at(wordSize - 1) == 's' && wordAssembledCountCopy[i].at(wordSize - 2) == '\'') {
              wordAssembledCountCopy[i].erase(wordSize - 2, 2);
              //wordSize = (int)wordAssembledCountCopy[i].size();
           }
           // you're 처럼 조사 이어진 경우
           else if (wordSize>=3 && wordAssembledCountCopy[i].at(wordSize - 1) == 'e' && wordAssembledCountCopy[i].at(wordSize - 2) == 'r' && wordAssembledCountCopy[i].at(wordSize - 3) == '\'') {
              wordAssembledCountCopy[i].erase(wordSize - 3, 3);
              //wordSize = (int)wordAssembledCount[i].size();
           }
          // ing(진행형) 제거
          else if (wordSize >=3 && wordAssembledCountCopy[i].at(wordSize - 1) == 'g' && wordAssembledCountCopy[i].at(wordSize - 2) == 'n' && wordAssembledCountCopy[i].at(wordSize - 3) == 'i') {
              
             wordAssembledCountCopy[i].erase(wordSize - 3, 3);
              
              // sitting 처럼 하나 더 나오는 경우
              int newWordSize = (int)wordAssembledCountCopy[i].size();
              if(wordAssembledCountCopy[i].at(newWordSize-1)==wordAssembledCountCopy[i].at(newWordSize-2)) {
                  wordAssembledCountCopy[i].erase(newWordSize-1,1);
              }
              
              
              checke[i] = wordAssembledCountCopy[i];
              checke[i].append("e");
              for (iter = dicVorigin.begin(); iter != dicVorigin.end(); iter++) {
                 if (checke[i] == *iter) {
                    wordAssembledCountCopy[i] = checke[i];
                 }
              }
             //wordSize = (int)wordAssembledCount[i].size();
          }
           // d(과거형 제거)
          else if (wordSize>=1 && wordAssembledCountCopy[i].at(wordSize - 1) == 'd') {
              wordAssembledCountCopy[i].erase(wordSize - 1, 1);
              //wordSize = (int)wordAssembledCount[i].size();
           }
          // ed(과거형) 제거
          else if (wordSize>=2 && wordAssembledCountCopy[i].at(wordSize - 1) == 'd' && wordAssembledCountCopy[i].at(wordSize - 2) == 'e') {
             wordAssembledCountCopy[i].erase(wordSize - 2, 2);
             //wordSize = (int)wordAssembledCount[i].size();
          }
           // ies(복수형) 제거 ( 명사 )
           else if (wordSize>=3 && wordAssembledCountCopy[i].at(wordSize - 1) == 's' && wordAssembledCountCopy[i].at(wordSize - 2) == 'e' &&
               wordAssembledCountCopy[i].at(wordSize - 3) == 'i') {
              wordAssembledCountCopy[i].erase(wordSize - 3, 3);
               wordAssembledCountCopy[i].append("y");
              //wordSize = (int)wordAssembledCountCopy[i].size();
           }
           // es(복수형) 제거(명사)
           else if (wordSize>=2 && wordAssembledCountCopy[i].at(wordSize - 1) == 's' && wordAssembledCountCopy[i].at(wordSize - 2) == 'e') {
              wordAssembledCountCopy[i].erase(wordSize - 2, 2);
              //wordSize = (int)wordAssembledCountCopy[i].size();
           }
          // s(복수형) 제거 (명사, 동사)
          else if (wordAssembledCountCopy[i].at(wordSize - 1) == 's') {
             wordAssembledCountCopy[i].erase(wordSize - 1, 1);
             //wordSize = (int)wordAssembledCount[i].size();
          }
           
           

           int flag1 = 0;
          for (iter = dicVorigin.begin(); iter != dicVorigin.end(); iter++) {
             if (wordAssembledCountCopy[i] == *iter) { // 바꾼 동사가 있다면 출력
                cout << "변형 단어 " << i + 1 << " : " << *iter << endl;
                readWordAssembled[i] = wordAssembledCountCopy[i];
                //i++;
                 flag1 = 1;
             }
          }
           if(flag1 != 1) {
               cout << "변형 단어 " << i + 1 << " : " << wordAssembledCount[i] << endl; // 바꾸기 전 단어 출력
               readWordAssembled[i] = wordAssembledCount[i];
           }
       }
    }
    cout << endl << endl;

    //    for(int i=0;i<10;i++) {
    //        cout<<readWordAssembled[i]<<endl;
    //    }

    string lastWordAssembled[100];
    // 원형 단어로 최종 출력

    map<string, string>::iterator iter2;
    for (int i = 0; i < 10; i++) {
       int flag2 = 0;
       int wordSize = (int)readWordAssembled[i].size();
       if (wordSize >= 1) {
             
          for (iter2 = dicV.begin(); iter2 != dicV.end(); iter2++) {
             
             if (readWordAssembled[i] == (*iter2).first) {
                cout << "원형 단어 " << i + 1 << " : " << (*iter2).second << endl;
                
                lastWordAssembled[i] = (*iter2).second;
                flag2 = 1;
                break;
                
             }
          }

          if (flag2 != 1) {
             cout << "원형 단어 " << i + 1 << " : " << readWordAssembled[i] << endl;
             lastWordAssembled[i] = readWordAssembled[i];
          }
          }
          

    }
     
     // 의미 없는 단어 제거하기
     string nonMeaningful[27] = {"a", "the", "because", "and", "of", "with", "in", "its", "be",
         "on", "by", "also", "that", "type", "do", "when", "it", "there", "to", "at", "for", "from",
         "while", "during", "about", "so" , "it"
     };

     for(int i=0;i<10;i++) {
         for(int j=0;j<27;j++) {
             if(lastWordAssembled[i]==nonMeaningful[j])
                 lastWordAssembled[i]="";
         }
     }
     
     
    cout << endl << endl;
    for (int i = 0; i < 10; i++) {
       int fSize = (int)lastWordAssembled[i].size();
       if (fSize >= 1) {
          cout << "최종 단어 " << i + 1 << " : " << lastWordAssembled[i] << endl;
       }
    }
    
    
    
    string lastreal[10];
    int count = 0;
    for(int i=0;i<10;i++) {
        if(lastWordAssembled[i]!="") {
            lastreal[count] = lastWordAssembled[i];
            count++;
        }
    }
    
    cout<<endl<<endl<<"구별된 최종 단어"<<endl;
    for(int i=0;i<10;i++) {
        if(lastreal[i]!="") {
            cout<<i+1<<"번째 : "<<lastreal[i]<<' ';
        }
    }
    cout<<endl;
    
    for (int i=0; i<10; i++) {
        str[i] = lastreal[i];
    }
}





 
