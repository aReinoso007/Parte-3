#include "Conversor.hpp"




/*Para determinar a que espacio de color se va a cambiar al mover un trackbar*/
void eventoTrackEspacios(int v, void *pP){
    cout <<"Valor trackbar: " << v << endl;
}

int main(int argc, char *argv[]){
    
    VideoCapture video(0);
    Mat resultado;
    Conversor conversor;

    namedWindow("video", WINDOW_AUTOSIZE);
    namedWindow("Efecto", WINDOW_AUTOSIZE);
    int iSliderValue1=0;
    createTrackbar("Efecto", "video", &iSliderValue1, 4, eventoTrackEspacios, NULL);

    if(video.isOpened()){
        Mat frame;
        namedWindow("Video",WINDOW_AUTOSIZE);
        while(3==3){
            video >> frame;
            resultado = Mat(Size(frame.cols, frame.rows), CV_8UC3, Scalar(255, 255, 255));
            if(frame.rows<=0 || frame.cols<=0)
                break;
            if(iSliderValue1==1){
                conversor.hsv(frame, resultado);
                imwrite("imagenes/hsv.png", resultado);
            }
            else if(iSliderValue1==2) {
                cvtColor(frame, resultado, COLOR_BGR2GRAY);
                imwrite("imagenes/gray.png", resultado);
            }
            else if(iSliderValue1==3) {
                conversor.toLAb(frame, resultado);
                imwrite("imagenes/lab.png", resultado);
            }
            else if(iSliderValue1==4){ 
                conversor.toYcrCb(frame, resultado);
                imwrite("imagenes/ycrcb.png", resultado);
            }
            else if(iSliderValue1==0){
                resultado = frame;
            }
            
            imshow("Video", frame);
            imshow("Efecto", resultado);


            if(waitKey(23)==27) //Pedimos que espere 23 milisegundos a que el usario presione la tecla escape
                break;
        }
        destroyAllWindows();
    }
    return 0;
}