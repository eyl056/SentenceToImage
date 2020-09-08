#ifndef stringAlgorithm_hpp
#define stringAlgorithm_hpp

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define MAX 10000

class kmp {
   int *SP;     // SP에 대한 메모리는 p의 크기만큼 동적 할당 해야한다.

   
   char text[MAX];
    int final_num[135] = { 0, };
    int line_count;
   int word_num[135];
   
public:
    string strKMP[10];
    string str[MAX];
   int kmpsearch(char *p, char *a);
   void initSP(char *p);
   void run(string p[10]);
};

class rabinKarp {
   
   const int q = 33554393; // 최대 소수
   const int d = 26;
   int final_num[135] = { 0, };
   char text[MAX];
   

   int line_count;
   int word_num[135];
   
public:
    // 원래 : string strRK[5];
    string strAlgol[10];
    string str[MAX];
   int rksearch(char *p, char *a);
   void run(string p[10]);
};

class boyerMoore {
   int *SP;     // SP에 대한 메모리는 p의 크기만큼 동적 할당 해야한다.
   int *skip;   // SP와 같은 크기로 동적 할당해 주어야함
   int *lp;
   const int alphabet_count = 26;
    int final_num[135] = { 0, };
   
   char text[MAX];
   
   
   int line_count;
   int word_num[135];
   
public:
    string strBM[10];
    string str[MAX];
   void initSP(char *p, int m);
   int index(char c);
   int max(int a, int b);
   void LastPos(char *p, int m);
   void GoodSuffix(char *p, int m);
   int BoyerMoore(char *p, char *a);
   void run(string p[10]);
};

#endif /* stringAlgorithm_hpp */
