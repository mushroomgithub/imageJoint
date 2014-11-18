/*************************************************************************
	> File Name: Camera_to_Frame.cpp
	> Author: mogu
	> Mail: ms15941699808@163.com
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
        if(!capture1)  
	{  
		fprintf(stderr,"Could not initialize capturing1...\n");  
		return -1;  
	}
	
	if(!capture2)  
	{  
		fprintf(stderr,"Could not initialize capturing2...\n");  
		return -1;  
	}  
	
	const char* filename1="capture1.avi";
	const char* filename2="capture2.avi";
        double w = 500, h = 320;
        cvSetCaptureProperty ( capture1, CV_CAP_PROP_FRAME_WIDTH,  w  );  
        cvSetCaptureProperty ( capture1, CV_CAP_PROP_FRAME_HEIGHT, h  );
        cvSetCaptureProperty ( capture2, CV_CAP_PROP_FRAME_WIDTH,  w  );  
        cvSetCaptureProperty ( capture2, CV_CAP_PROP_FRAME_HEIGHT, h  );

        cvNamedWindow( "Camera_1", CV_WINDOW_AUTOSIZE  );
        cvNamedWindow( "Camera_2", CV_WINDOW_AUTOSIZE  );

        IplImage* frame1;
        IplImage* frame2;
        frame1 = cvQueryFrame( capture1  );
        frame2 = cvQueryFrame( capture2  );
        CvVideoWriter *writer1 =cvCreateVideoWriter(filename1, -1, 25, cvSize(frame1->width,frame1->height));//create writer 
        CvVideoWriter *writer2 =cvCreateVideoWriter(filename2, -1, 25, cvSize(frame2->width,frame2->height));//create writer 
        int n = 2;
        while(1)
    {
                frame1 = cvQueryFrame( capture1  );
                if( !frame1  ) break;
                cvSaveImage("./frame1/frame1.jpg",frame1);
                cvWriteFrame(writer1,frame1);
                cvShowImage( "Camera_1", frame1  );

                frame2 = cvQueryFrame( capture2  );
                if( !frame2  ) break;
                cvSaveImage("./frame2/frame2.jpg",frame2);
                cvWriteFrame(writer2,frame);
                cvShowImage( "Camera_2", frame2  );

                int key = cvWaitKey(30);
                if( key == 27  ) break;
            
    }
        cvReleaseCapture( &capture1  );
        cvReleaseCapture( &capture2  );
        cvReleaseVideoWriter(&writer1);
        cvReleaseVideoWriter(&writer2);
        cvDestroyWindow( "Camera_1"  );
        cvDestroyWindow( "Camera_2"  );

        return 0;

}

