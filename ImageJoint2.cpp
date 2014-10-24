/*************************************************************************
	> File Name: ImageJoint2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2014年10月22日 星期三 10时59分34秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/stitching/stitcher.hpp"
using namespace std;
using namespace cv;
int main(void)
{
    string srcFile[3]={"./RawImage2/1.jpg","./RawImage2/2.jpg","./RawImage2/3.jpg"};     
        string dstFile="./RawImage2/result.jpg";     
        vector<Mat> imgs;
        for(int i=0;i<3;++i)     
        {          
             Mat img=imread(srcFile[i]);          
                 if (img.empty())          
                 {              
                              cout<<"Can't read image '"<<srcFile[i]<<"'\n";              
                                  system("pause");              
                                  return -1;           
                 }         
             imgs.push_back(img);     
         }
         cout<<"Please wait..."<<endl;     
        Mat pano;     
        Stitcher stitcher = Stitcher::createDefault(false);     
        Stitcher::Status status = stitcher.stitch(imgs, pano);
    if (status != Stitcher::OK)     
        {          
                cout<<"Can't stitch images, error code=" <<int(status)<<endl;          
                system("pause");         
                return -1;     
        }
        imwrite(dstFile, pano);    
        namedWindow("Result");     
        imshow("Result",pano);      
        waitKey(0);    
        destroyWindow("Result");
        system("pause");     
        return 0;
}
