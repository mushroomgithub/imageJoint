#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
//#pragma comment(lib,"opencv_core245.lib")
//#pragma comment(lib,"opencv_highgui245.lib")
int main(){    
    const  char* file[2]={"./frame1/frame1.jpg","./frame2/frame2.jpg"};//2张原始图片    
    IplImage* pImg[2];      
    int i;    
     
    for(i=0;i<2;++i)        
        pImg[i]=cvLoadImage(file[i]);
         
    int sw=pImg[0]->width;    
    int sh=pImg[0]->height;
    IplImage* dstImg = cvCreateImage(cvSize(sw*2,sh),pImg[0]->depth,pImg[0]->nChannels);  
       
    cvZero(dstImg);
    printf("Please wait...\n");
     
    for(i=0;i<2;++i) {          
            cvSetImageROI(dstImg, cvRect(i*sw,0,sw,sh));         
            cvCopy(pImg[i], dstImg);          
            cvResetImageROI(dstImg);    
        }
     
    cvNamedWindow("dstImg");    
    cvShowImage("dstImg", dstImg);   
    cvSaveImage("result1.jpg",dstImg);//拼接图片之一    
     
    cvWaitKey(0);    
     
    for(i=0;i<2;++i)   
        cvReleaseImage(&pImg[i]);    
         
     cvReleaseImage(&dstImg);    
     cvDestroyWindow("dstImg");      
     system("pause");    
     return 0;
}
