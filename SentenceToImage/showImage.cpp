#include "showImage.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>
#include "englishWord.hpp"
#include <map>
#include <set>
using namespace std;
using namespace cv;

ShowImage::ShowImage(string image[5]) {
    for(int i=0;i<5;i++) {
        this->image[i] = image[i];
    }
}
void ShowImage::ShowRecommendedImage() {

    for(int i=0;i<5;i++) {
        if(image[i].size()>2) {
            image[i].erase(image[i].size()-3,2);
        }
    }
    string location = "/Users/eunyoung/Desktop/realimage/";
//    string imageLocation[5];
//    for(int i=0;i<5;i++) {
//        imageLocation[i] = location + image[i] + ".png";
//    }
    string image111 = image[0];
    string image222 = image[1];
    string image333 = image[2];
    string image444 = image[3];
    string image555 = image[4];

    string image11 = location + image111;
    string image22 = location + image222;
    string image33 = location + image333;
    string image44 = location + image444;
    string image55 = location + image555;
//    for(int i=0;i<5;i++) {
//        imageLocation[i] = image[i].append(".png");
//    }
    string imageLocation1 = image11;
    string imageLocation2 = image22;
    string imageLocation3 = image33;
    string imageLocation4 = image44;
    string imageLocation5 = image55;
    
//    for(int i=0;i<5;i++) {
//        cout<<"위치 확인용"<<endl;
//        cout<<imageLocation[i]<<endl;
//    }
    cout<<imageLocation1<<endl;
    
    if(image11.empty() || image22.empty() || image33.empty() || image44.empty() || image55.empty()) {
        cout<<"image load failed"<<endl;
    }
    else {
        Mat reJimage1;
        Mat reJimage2;
        Mat reJimage3;
        Mat reJimage4;
        Mat reJimage5;

        Mat reCimage1;
        Mat reCimage2;
        Mat reCimage3;
        Mat reCimage4;
        Mat reCimage5;
        
//        resize(Jimage1, reJimage1, Size(100,100));
//        resize(Jimage2, reJimage2, Size(100,100));
//        resize(Jimage3, reJimage3, Size(100,100));
//        resize(Jimage4, reJimage4, Size(100,100));
//        resize(Jimage5, reJimage5, Size(100,100));
//
//        resize(Cimage1, reCimage1, Size(100,100));
//        resize(Cimage2, reCimage2, Size(100,100));
//        resize(Cimage3, reCimage3, Size(100,100));
//        resize(Cimage4, reCimage4, Size(100,100));
//        resize(Cimage5, reCimage5, Size(100,100));
        
        Mat result1;
        Mat result2;
        Mat result3;
        Mat result4;
        Mat result5;
        hconcat(reJimage1, reCimage1, result1);
        hconcat(reJimage2, reCimage2, result2);
        hconcat(reJimage3, reCimage3, result3);
        hconcat(reJimage4, reCimage4, result4);
        hconcat(reJimage5, reCimage5, result5);
    
//        hconcat(Jimage1, Cimage1, result1);
//        hconcat(Jimage2, Cimage2, result2);
//        hconcat(Jimage3, Cimage3, result3);
//        hconcat(Jimage4, Cimage4, result4);
//        hconcat(Jimage5, Cimage5, result5);
        
        

        imshow("no.1_JACCARD && CONSINE", result1);
        imshow("no.2_JACCARD && CONSINE", result2);
        imshow("no.3_JACCARD && CONSINE", result3);
        imshow("no.4_JACCARD && CONSINE", result4);
        imshow("no.5_JACCARD && CONSINE", result5);
//
//        imshow("no.1_COSINE", Cimage1);
//        imshow("no.2_COSINE", Cimage2);
//        imshow("no.3_COSINE", Cimage3);
//        imshow("no.4_COSINE", Cimage4);
//        imshow("no.5_COSINE", Cimage5);
        
        waitKey(0);
   }
}
