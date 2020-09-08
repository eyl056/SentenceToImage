#include "stringAlgorithm.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 10000

void kmp::initSP(char *p) {// 최대 접두부 테이블 설계

   int i, j, m = (int)strlen(p);

   SP = new int[m];
   SP[0] = -1; // 최대 접두부의 끝 위치 초기화

   for (i = 1, j = -1; i <= m - 1; i++) {

      // 일치되던 중 불일치가 발생하면 j값 수정
      while ((j >= 0) && (p[j + 1] != p[i]))
         j = SP[j];
      if (p[j + 1] == p[i])
         j++;



      SP[i] = j;
   }
}

int kmp::kmpsearch(char *p, char *a) {
   int num = 0;
   int i, j, m = (int)strlen(p), n = (int)strlen(a);

   initSP(p); //최대 접두부 테이블

   for (i = 0, j = -1; i <= n - 1; i++) {

      // 불일치 발생 시 주어진 정보로 최대한 중간단계  생략
      while ((j >= 0) && (p[j + 1] != a[i]))
         j = SP[j];

      // 일치하면
      if (p[j + 1] == a[i])
         j++;

      // 완전히 일치할 경우
      if (j == m - 1) {

         j = SP[j];
         num++;
      }
   }

   return num;
}

    
void kmp::run(string p[10]) {
    
    for (int i = 0; i < 10; i++) {
     char pattern[MAX] = {};
     line_count = 0;
     for (int j = 0; j < p[i].size(); j++) {

        pattern[j] = p[i][j];

     }cout<<pattern<<endl;
        FILE * p_file = NULL;

    p_file = fopen("data.txt","rt");
    
    if(p_file==NULL) {
        cout<<"ERROR"<<endl;
    }
    else {

       while (fgets(text, MAX, p_file) != NULL) {
          
          word_num[line_count] = kmpsearch(pattern, text);// 검색한 단어가 문장에서 일치하는 횟수를 buffer에 저장
          str[line_count] = text;//line_count번째 문장을 string 배열 str[]에 저장

          //if (word_num[line_count] != 0) {//여기는 출력 제대로 되는지
          //   cout << buffer << word_num[line_count] << endl;//확인용
          //}//코드입니다
           final_num[line_count] += word_num[line_count];
           line_count++;

       }

    }fclose(p_file);
     }
       int max;
    
    int temp[10];
    for (int i = 0; i < 10; i++) {
       max = 0;
       for (int j = 0; j < 135; j++) {
          if (max < final_num[j]) {
             max = final_num[j];
             temp[i] = j;
             
          }

       }
       
       final_num[temp[i]] =  0 ;
    }

    if (temp[0] == 0) {// 만약 겹치는 단어가 하나도 없을 경우
       cout << "일치하지 않아 출력할 이모티콘이 없습니다." << endl;
    }
    else {//겹치는 게 있으면
       for (int i = 0; i < 10; i++) {// 문장을 5개까지 출력
          cout << str[temp[i]] << endl;
           strKMP[i] = str[temp[i]];
       }
    }
    
   delete[] SP;
}



int rabinKarp::rksearch(char *p, char *a) {

   int i, j, dM = 1, h1 = 0, h2 = 0, flag;
   int m = (int)strlen(p), n = (int)strlen(a);
   int num = 0; //일치 개수

   for (i = 1; i < m; i++) {
      dM = (d*dM) % q;
   }

   for (i = 0; i < m; i++) {
      h1 = (h1*d + p[i]) % q; // 패턴 해시 값
      h2 = (h2*d + a[i]) % q; // 텍스트 해시 값
   }
   for (i = 0; i < n - m + 1; i++) {


      // 해시값이 동일한 경우
      if (h1 == h2) {

         flag = 1;

         for (j = i; j < m + i; j++) {


            if (a[j] != p[j - i]) { // 세부패턴 일치하지 않으면
               flag = 0;
               break;
            }
         }

         if (flag) { //일치하면
            num++;
         }
      }

      // 해시값이 일치하지 않는 경우 해시값을 재설정
      if (i < n - m) {
         h2 = (h2 - a[i] * dM) % q;

         //h2값이 음수일 경우
         if (h2 < 0)
            h2 = h2 % q + q;

         h2 = (h2*d + a[i + m]) % q;

      }
   }

   return num;
}

void rabinKarp::run(string p[10]) {
    for (int i = 0; i < 10; i++) {
    char pattern[MAX] = {};
    line_count = 0;
    for (int j = 0; j < p[i].size(); j++) {

       pattern[j] = p[i][j];

    }   FILE * p_file = NULL;

   p_file = fopen("data.txt","rt");
   
   if(p_file==NULL) {
       cout<<"ERROR"<<endl;
   }
   else {

      while (fgets(text, MAX, p_file) != NULL) {
         
         word_num[line_count] = rksearch(pattern, text);// 검색한 단어가 문장에서 일치하는 횟수를 buffer에 저장
         str[line_count] = text;//line_count번째 문장을 string 배열 str[]에 저장

         //if (word_num[line_count] != 0) {//여기는 출력 제대로 되는지
         //   cout << buffer << word_num[line_count] << endl;//확인용
         //}//코드입니다
          final_num[line_count] += word_num[line_count];
          line_count++;

      }

   }fclose(p_file);
    }
      int max;
   
   int temp[10];
   for (int i = 0; i < 10; i++) {
      max = 0;
      for (int j = 0; j < 135; j++) {
         if (max < final_num[j]) {
            max = final_num[j];
            temp[i] = j;
            
         }

      }
      
      final_num[temp[i]] =  0 ;
   }

   if (temp[0] == 0) {// 만약 겹치는 단어가 하나도 없을 경우
      cout << "일치하지 않아 출력할 이모티콘이 없습니다." << endl;
   }
   else {//겹치는 게 있으면
      for (int i = 0; i < 10; i++) {// 문장을 5개까지 출력
         cout << str[temp[i]] << endl;
          strAlgol[i] = str[temp[i]];
      }
   }



}


void boyerMoore::initSP(char *p, int m) {
   int i, j;
   SP[0] = -1;// 최대 접두부의 끝 위치 초기화

   for (i = 1, j = -1; i <= m - 1; i++) {

      // 일치되던 중 불일치가 발생하면 j값 수정
      while ((j >= 0) && (p[j + 1] != p[i])) {
         j = SP[j];

      }
      if (p[j + 1] == p[i])
         j++;

      SP[i] = j;
   }
}
int boyerMoore::index(char c) {
   if (c == ' ')
      return 0;
   else
      return toupper(c) - 'A';
}
int boyerMoore::max(int a, int b) {
   return a >= b ? a : b;
}
void boyerMoore::LastPos(char *p, int m) {
   for (int i = 0; i <= alphabet_count; i++)
      lp[i] = -1;

   for (int i = 0; i < m; i++)
      lp[index(p[i])] = i; // 알파벳이 마지막으로 출현한 위치
}
void boyerMoore::GoodSuffix(char *p, int m) {
   int i, k;

   char *r_p = new char[m];

   for (i = 0; i < m; i++) // 역순 패턴 생성
      r_p[m - i - 1] = p[i];

   initSP(r_p, m); // 역순 패턴에 대한 SP 테이블 생성

   for (i = -1; i <= m - 1; i++) // 이동량 초기화
      skip[i] = m - 1 - SP[m - 1];

   for (k = 0; k <= m - 1; k++) { // 패턴 중간에 일치접미부가 존재하는 경우

      i = m - 1 - SP[k] - 1;
      if (skip[i] > k - SP[k]) // 이동량 선택
         skip[i] = k - SP[k];
   }
}
int boyerMoore::BoyerMoore(char *p, char *a) {
   int num = 0;
   int i, j, m = (int)strlen(p), n = (int)strlen(a);
   int comp = 0;

   skip = new int[m];
   SP = new int[m];
   lp = new int[27];

   LastPos(p, m);           // 불일치 문자 방책에서 알파벳 크기의 마지막 위치
   GoodSuffix(p, m); //일치 접미부 방책의 이동 거리 계산 알고리즘

   j = 0;

   while (j <= n - m) {
      for (i = m - 1; i >= 0 && p[i] == a[j + i]; i--) // 패턴을 하나씩 비교해서 다른 패턴이 나올때까지 반복
         comp++;

      if (i == -1) {
         num++;

         j = j + skip[-1]; // 다음 탐색을 위한 문자열 포인터의 위치 복원

      }
      else  // 불일치문자방책에 의한 이동량과 비교하여 효율성을 위해 보다 큰 이동량 선택해 활용
         j = j + max(skip[i], i - lp[index(a[j + i])]);

   }

   return num;
}
void boyerMoore::run(string p[10]) {
    for (int i = 0; i < 10; i++) {
    char pattern[MAX] = {};
    line_count = 0;
    for (int j = 0; j < p[i].size(); j++) {

       pattern[j] = p[i][j];

    }
   FILE * p_file = NULL;



   cout << endl;

    p_file = fopen("data.txt","rt");
    
    if(p_file==NULL) {
        cout<<"ERROR"<<endl;
    }
    else {

       while (fgets(text, MAX, p_file) != NULL) {
         
         word_num[line_count] = BoyerMoore(pattern, text);// 검색한 단어가 문장에서 일치하는 횟수를 buffer에 저장
         str[line_count] = text;//line_count번째 문장을 string 배열 str[]에 저장

         //if (word_num[line_count] != 0) {//여기는 출력 제대로 되는지
         //   cout << buffer << word_num[line_count] << endl;//확인용
         //}//코드입니다
           final_num[line_count] += word_num[line_count];
        line_count++;
      }

   }fclose(p_file);
    }
   int max;
   int temp[10];
   for (int i = 0; i < 10; i++) {
      max = 0;
      for (int j = 0; j < 135; j++) {
         if (max < final_num[j]) {
            max = final_num[j];
            temp[i] = j;

         }

      }
      final_num[temp[i]] = 0;
   }

   if (temp[0] == 0) {// 만약 겹치는 단어가 하나도 없을 경우
      cout << "일치하지 않아 출력할 이모티콘이 없습니다." << endl;
   }
   else {//겹치는 게 있으면
      for (int i = 0; i < 10; i++) {// 문장을 5개까지 출력
         cout << str[temp[i]] << endl;
          strBM[i] = str[temp[i]];
      }
   }

   delete[] SP;
}
