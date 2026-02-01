
#include "tpConvolution.h"
#include <cmath>
#include <algorithm>
#include <tuple>
using namespace cv;
using namespace std;
/**
    Compute a mean filter of size 2k+1.

    Pixel values outside of the image domain are supposed to have a zero value.
*/
cv::Mat meanFilter(cv::Mat image, int k)
{
    Mat res = image.clone();
    /********************************************
                YOUR CODE HERE
    *********************************************/
    int fen = 2*k + 1;
    int N = fen*fen;
    for(int y = k; y < image.rows - k; y++)
    {
        for(int x = k; x < image.cols - k; x++)
        {
            float sum = 0.0;
            for(int j = -k; j <= k; j++)
            {
                for(int i = -k; i <= k; i++)
                {
                    sum += image.at<float>(y + j, x + i);
                }
            }
            res.at<float>(y, x) = sum / N;
        }
    }
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}
/**
    Compute the convolution of a float image by kernel.
    Result has the same size as image.
    
    Pixel values outside of the image domain are supposed to have a zero value.
*/
Mat convolution(Mat image, cv::Mat kernel)
{
    Mat res = image.clone();
    /********************************************
                YOUR CODE HERE
    *********************************************/
    int k = kernel.rows / 2;  
    for (int y = k; y < image.rows - k; y++)
    {
        for (int x = k; x < image.cols - k; x++)
        {
            float sum = 0.0;

            for (int j = -k; j <= k; j++)
            {
                for (int i = -k; i <= k; i++)
                {
                    float pixel = image.at<float>(y + j, x + i);
                    float coeff = kernel.at<float>(k - j, k - i); // convolution
                    sum += pixel * coeff;
                }
            }

            res.at<float>(y, x) = sum;
        }
    }
    /********************************************
                END OF YOUR CODE
    *********************************************/

    return res;
}

/**
    Compute the sum of absolute partial derivative according to Sobel's method
*/
cv::Mat edgeSobel(cv::Mat image)
{
    Mat res = image.clone();
    /********************************************
                YOUR CODE HERE
    *********************************************/
     float sobel_x[3][3] = {{-1,0,1}, {-2,0,2}, {-1,0,1}};
     float sobel_y[3][3] = {{1,2,1}, {0,0,0}, {-1,-2,-1}};
     for(int y=1; y<image.rows-1; y++)
     {
        for(int x=1; x<image.cols-1; x++)
        {
            float fx =0.0;
            float fy = 0.0;
            for(int j=-1; j<=1; j++)
            {
                for(int i=-1; i<=1; i++)
                {
                    float pixel = image.at<float>(y+j,x+i);
                    fy += sobel_y[j+1][i+1]*pixel;
                    fx += sobel_x[j+1][i+1]*pixel;
                }
            }
            res.at<float>(y,x) = sqrt(fx*fx + fy*fy);
        }
     }
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}

/**
    Value of a centered gaussian of variance (scale) sigma at point x.
*/
float gaussian(float x, float sigma2)
{
    //return 1.0/(2*M_PI*sigma2)*exp(-x*x/(2*sigma2));
    return 0;
}

/**
    Performs a bilateral filter with the given spatial smoothing kernel 
    and a intensity smoothing of scale sigma_r.

*/
cv::Mat bilateralFilter(cv::Mat image, cv::Mat kernel, float sigma_r)
{
    Mat res = image.clone();
    /********************************************
                YOUR CODE HERE
    *********************************************/
   
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}