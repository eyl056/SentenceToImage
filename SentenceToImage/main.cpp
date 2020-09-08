#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>
#include "englishWord.hpp"
#include "senToWord.hpp"
#include "showImage.hpp"
#include "stringAlgorithm.hpp"
#include "KmeansJaccard.hpp"
#include "Similarity.hpp"
#include "KmeansCosine.hpp"
#include <map>
#include <set>
using namespace std;
using namespace cv;
#define EAGAIN 35

int main() {

    string alphabetString;
    
    cout << "원하는 문장을 입력하세요 >> ";
    getline(cin, alphabetString);
    
    SenToWor program(alphabetString);
    string lastword[10];
    program.run(lastword);
    
//    char pattern[MAX];
//    cout << endl << "단어를 입력하세요 >> ";
//    cin.getline(pattern, MAX);
    

    cout <<endl<<"---------------------------------------KMP-----------------------------------------" << endl << endl;

    rabinKarp kmp;
    kmp.run(lastword);

    cout << "-----------------------------------------RABIN_KARP--------------------------------------" << endl << endl;

    rabinKarp rk;
    rk.run(lastword);


    cout << "-----------------------------------------BOYERMOORE-------------------------------------" << endl << endl;

    rabinKarp bm;
    bm.run(lastword);
    cout<<endl<<endl;

    Similarity similarity1(kmp.strAlgol); // kmp 문자열 비교 알고리즘
    Similarity similarity2(rk.strAlgol); // rabin-karp 문자열 비교 알고리즘
    Similarity similarity3(bm.strAlgol); // boyer-mooyer 문자열 비교 알고리즘
    
    cout<<"---------KMP---------K-MEANS JACCARD---------"<<endl;
    // kmp 알고리즘 -> K-means Jaccard 알고리즘
    Jaccard jaccardAlgoRK1(similarity1.similarString);
    jaccardAlgoRK1.run(alphabetString);
    jaccardAlgoRK1.getVector();
    cout<<endl;
    
    cout<<"---------KMP---------K-MEANS COSINE---------"<<endl;
    // kmp 알고리즘 -> K-means Cosine 알고리즘
    Cosine CosineAlgoRK1(similarity1.similarString);
    CosineAlgoRK1.run(alphabetString);
    CosineAlgoRK1.getVector();
    
    
    cout<<endl<<endl;
    cout<<"---------RABIN_KARP---------K-MEANS JACCARD---------"<<endl;
    // rabin-karp 알고리즘 -> K-means Jaccard 알고리즘
    Jaccard jaccardAlgoRK2(similarity2.similarString);
    jaccardAlgoRK2.run(alphabetString);
    jaccardAlgoRK2.getVector();
    cout<<endl;
    
    cout<<"---------RABIN_KARP---------K-MEANS COSINE---------"<<endl;
    // rabin-karp 알고리즘 -> K-means Cosine 알고리즘
    Cosine CosineAlgoRK2(similarity2.similarString);
    CosineAlgoRK2.run(alphabetString);
    CosineAlgoRK2.getVector();
    
    
    cout<<endl<<endl;
    cout<<"---------BOYERMOORE---------K-MEANS JACCARD---------"<<endl;
    // boyer-mooyer 알고리즘 -> K-means Jaccard 알고리즘
    Jaccard jaccardAlgoRK3(similarity3.similarString);
    jaccardAlgoRK3.run(alphabetString);
    jaccardAlgoRK3.getVector();
    ShowImage ImageJaccard(jaccardAlgoRK3.stringJaccard);
    ImageJaccard.ShowRecommendedImage();
    cout<<endl;
    
    cout<<"---------BOYERMOORE---------K-MEANS COSINE---------"<<endl;
    // boyer-mooyer 알고리즘 -> K-means Cosine 알고리즘
    Cosine CosineAlgoRK3(similarity3.similarString);
    CosineAlgoRK3.run(alphabetString);
    CosineAlgoRK3.getVector();
    ShowImage ImageCosine(CosineAlgoRK3.stringCosine);
    ImageCosine.ShowRecommendedImage();
    
            
    
    return 0;
}
