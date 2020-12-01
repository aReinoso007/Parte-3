#include "Conversor.hpp"




/*Para determinar a que espacio de color se va a cambiar al mover un trackbar*/
void eventoTrackEspacios(int v, void *pP){
    cout <<"Valor trackbar: " << v << endl;
}

int main(int argc, char *argv[]){
    
    VideoCapture video(0);
    Mat resultado;
    

    namedWindow("video", WINDOW_AUTOSIZE);
    namedWindow("Efecto", WINDOW_AUTOSIZE);
    int iSliderValue1=0;
    createTrackbar("Efecto", "video", &iSliderValue1, 4, eventoTrackEspacios, NULL);

    if(video.isOpened()){
        Mat frame;
        namedWindow("Video",WINDOW_AUTOSIZE);
        while(3==3){
            video >> frame;
            
            if(frame.rows<=0 || frame.cols<=0)
                break;
            /*cvtColor(frame, resultado, COLOR_BGR2HSV);*/
            //1 para HSV

            if(iSliderValue1 == 1){
                cout <<"HSV" << endl;
                cvtColor(frame, resultado, COLOR_BGR2HSV);
            }
                //2 para gray
            else if(iSliderValue1 == 2) {
                cout <<"Gray" << endl; 
                cvtColor(frame, resultado, COLOR_BGR2GRAY);
            //3 para LAb
            }
            else if(iSliderValue1 == 3) {
                cout <<"LAB" << endl; 
                cvtColor(frame, resultado, COLOR_BGR2Lab);
            }
            //4 para yCrCb
            else if(iSliderValue1 == 4){ 
                cout <<"toYcrCb" << endl; 
                cvtColor(frame, resultado, COLOR_BGR2YCrCb);
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