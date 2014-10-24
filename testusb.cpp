/*************************************************************************
	> File Name: testusb.cpp
	> Author: 
	> Mail: 
	> Created Time: 2014年10月22日 星期三 08时38分12秒
 ************************************************************************/

#include<iostream>
using namespace std;
//#include "stdafx.h"

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

int main(int argc,char* argv[])
{
        CvCapture* capture1 = cvCreateCameraCapture( 0  );
        CvCapture* capture2 = cvCreateCameraCapture( 1  );

        double w = 320, h = 240;
        cvSetCaptureProperty ( capture1, CV_CAP_PROP_FRAME_WIDTH,  w  );  
        cvSetCaptureProperty ( capture1, CV_CAP_PROP_FRAME_HEIGHT, h  );
        cvSetCaptureProperty ( capture2, CV_CAP_PROP_FRAME_WIDTH,  w  );  
        cvSetCaptureProperty ( capture2, CV_CAP_PROP_FRAME_HEIGHT, h  );

        cvNamedWindow( "Camera_1", CV_WINDOW_AUTOSIZE  );
        cvNamedWindow( "Camera_2", CV_WINDOW_AUTOSIZE  );

        IplImage* frame1;
        IplImage* frame2;

        int n = 2;
        while(1)
    {
                frame1 = cvQueryFrame( capture1  );
                if( !frame1  ) break;
                cvSaveImage("/home/mogu/kinect/frame1/frame1.jpg",frame1);
                cvShowImage( "Camera_1", frame1  );

                frame2 = cvQueryFrame( capture2  );
                if( !frame2  ) break;
                 cvSaveImage("/home/mogu/kinect/frame2/frame2.jpg",frame2);
                cvShowImage( "Camera_2", frame2  );

                int key = cvWaitKey(30);
                if( key == 27  ) break;
            
    }
        cvReleaseCapture( &capture1  );
        cvReleaseCapture( &capture2  );
        cvDestroyWindow( "Camera_1"  );
        cvDestroyWindow( "Camera_2"  );

        return 0;

}

