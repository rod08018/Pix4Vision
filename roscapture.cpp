#include <opencv2/opencv.hpp>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/videoio/videoio.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <ctype.h>
#include <unistd.h>
#include <vector>
using namespace std;
using namespace cv;

  void guardar(Mat a, string name);
  void fix();
  int num=0;
  string IntToStr(int n) 
  {
      stringstream result;
      result << n;
      return result.str();
  }
      VideoCapture capture;
      
      Mat RGB;
   int main()
   {
      capture.set(3, 1280);
      capture.set(4, 720);
      

      if(!capture.open(1))
      {
        cout<<"Video Not Found"<<endl;
        return -1;
      }

       while(true)
       {

          capture>>RGB;  

          if(RGB.empty()) 
          {
             cout<<"Capture Finished"<<endl;
             break;
          }
          
          sleep(0.5);
          num=num+1;
          guardar(RGB,"ndvi");
          double dWidth = capture.get(CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
         double dHeight = capture.get(CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video
         cout << "Frame size : " << dWidth << " x " << dHeight << endl;
          
       }

       capture.release();
       waitKey(0);
      return 0;
   }
   void fix(){
      //system("cp YUV.jpg YUV_`date +%S%H%M`.jpg");
      system("cp gray.jpg gray_`*`.jpg");
      system("cp HSV.jpg HSV_`date +%S%H%M`.jpg");
      //system("cp RBG.jpg RBG_`date +%S%H%M`.jpg");
   }
   void guardar(Mat a, string name){
      vector<int> compression_params; //vector that stores the compression parameters of the image

     compression_params.push_back(IMWRITE_JPEG_QUALITY); //specify the compression technique

     compression_params.push_back(0 ); //specify the compression quality
     string path="ndvi/";


     bool bSuccess = imwrite(path+name+IntToStr(num)+ ".jpg", a, compression_params); //write the image to file



     if ( !bSuccess )

    {

         cout << "ERROR : Failed to save the image" << endl;

         //system("pause"); //wait for a key press

    }
   }