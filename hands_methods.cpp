//
// Created by Dan Orel on 2019-09-17.
//
#include <cmath>
#include "hands_methods.h"

Mat MakeNegative(std::string filename){
    Mat GrayscaledImage = imread(filename, IMREAD_GRAYSCALE);
    if (!GrayscaledImage.data){
        std::cerr << "Error! No such image exists by the path " << filename << std::endl;
        exit(-1);
    }
    Mat NegativeImage = Mat(GrayscaledImage.size(), CV_8UC1);
    int width  = NegativeImage.cols;
    int height = NegativeImage.rows;
    for(int row = 0; row < height; row++){
        for(int column = 0; column < width; column++){
            NegativeImage.at<uchar>(row, column) = 255 - GrayscaledImage.at<uchar>(row, column);
        }
    }
    return NegativeImage;
}

Mat MakeLog(std::string filename){
    Mat GrayscaledImage = imread(filename, IMREAD_GRAYSCALE);
    if (!GrayscaledImage.data){
        std::cerr << "Error! No such image exists by the path " << filename << std::endl;
        exit(-1);
    }
    Mat LogImage = Mat(GrayscaledImage.size(), CV_8UC1);
    double j = 0.4;
    int width  = LogImage.cols;
    int height = LogImage.rows;
    for(int row = 0; row < height; row++){
        for(int column = 0; column < width; column++){
            LogImage.at<uchar>(row, column) = log2(pow(j, GrayscaledImage.at<uchar>(row, column) + 1));
        }
    }
    return LogImage;
}
