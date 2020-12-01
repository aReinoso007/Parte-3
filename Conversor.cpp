#include "Conversor.hpp"

Conversor::Conversor(){

}

void Conversor::hsv(cv::Mat src, cv::Mat dest){
    cvtColor(src, dest, COLOR_BGR2HSV);
    
}

void Conversor::toGray(Mat src, Mat dest){

}

void Conversor::toLAb(){

}

void Conversor::toYcrCb(){
    
}