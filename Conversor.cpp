#include "Conversor.hpp"

Conversor::Conversor(){

}

cv::Mat Conversor::hsv(cv::Mat src, cv::Mat dest){
    cvtColor(src, dest, COLOR_BGR2HSV);
    return dest;
}

cv::Mat Conversor::toGray(cv::Mat src, cv::Mat dest){
    cvtColor(src, dest, COLOR_BGR2GRAY);
    return dest;
}

cv::Mat Conversor::toLAb(cv::Mat src, cv::Mat dest){
    cvtColor(src, dest, COLOR_BGR2Lab);
    return dest;
}

cv::Mat Conversor::toYcrCb(cv::Mat src, cv::Mat dest){
    cvtColor(src, dest, COLOR_BGR2YCrCb);
    return dest;
}