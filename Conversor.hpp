#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <sstream>
#include <fstream>

#include <dirent.h>

#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <opencv4/opencv2/video/video.hpp>
#include <opencv4/opencv2/videoio/videoio.hpp>
#include <opencv4/opencv2/imgcodecs/imgcodecs.hpp>

#include <math.h>

using namespace std;
using namespace cv;


class Conversor{

    public:
        Conversor();
        /*
            H - Hue
            S - Saturacion (pureza / sombras de color)
            V - Valor (intensidad)
         */
        cv::Mat hsv(Mat, Mat);

        cv::Mat toGray(Mat, Mat);
        /*
            L - lightness (intensity)
            a - color component ranging from Green to magenta
            b - color component ranging from Blue to Yellow

            L -> es independiente de informacion de color y solo guarda la intensidad o brillo
            cvtColor(Mat input, Mat output, COLOR_BGR2LAB)
         */
        cv::Mat toLAb(Mat, Mat);

        /* 
            Y - Luminesencia o Luma, componente obtenido de RGB despues de hacer una correccion gamma
            Cr : R - Y (distancia componente rojo de Luma)
            Cb - B - Y ( distancia componente azul de Luma)

            cv::cvtColor(bright, brightYCB, cv::COLOR_BGR2YCrCb);
	        cv::cvtColor(dark, darkYCB, cv::COLOR_BGR2YCrCb);
        */
        cv::Mat toYcrCb(Mat, Mat);


};