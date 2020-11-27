#include "Conversor.hpp"




/*Para determinar a que espacio de color se va a cambiar al mover un trackbar*/
void eventoTrackEspacios(int v, void *pP){
    cout <<"Valor trackbar: " << v << endl;
}

int main(int argc, char *argv[]){
    
    VideoCapture video(0);
    

    namedWindow("video", WINDOW_AUTOSIZE);

    if(video.isOpened()){
        Mat frame;
        namedWindow("Video",WINDOW_AUTOSIZE);
        while(3==3){
            video >> frame;
            
            if(frame.rows<=0 || frame.cols<=0)
                break;

            imshow("Video", frame);

            
            if(waitKey(23)==27) //Pedimos que espere 23 milisegundos a que el usario presione la tecla escape
                break;
        }
        destroyAllWindows();
    }
    return 0;
}