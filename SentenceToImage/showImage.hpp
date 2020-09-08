#ifndef showImage_hpp
#define showImage_hpp

#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>
#include "englishWord.hpp"
#include <map>
#include <set>
using namespace std;
using namespace cv;

class ShowImage {
    string location = "/Users/eunyoung/Desktop/realimage/";
    string image[5];
public:
    ShowImage(string image[5]);
    void ShowRecommendedImage();
};

#endif /* showImage_hpp */
