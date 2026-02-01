#include "tpHistogram.h"
#include <cmath>
#include <algorithm>
#include <tuple>
using namespace cv;
using namespace std;

/**
    Inverse a grayscale image with float values.
    for all pixel p: res(p) = 1.0 - image(p)
*/
Mat inverse(Mat image)
{
    // clone original image
    Mat res = image.clone();
      /********************************************
                YOUR CODE HERE
    *********************************************/
    res = 1.0 - res;
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}

/**
    Thresholds a grayscale image with float values.
    for all pixel p: res(p) =
        | 0 if image(p) <= lowT
        | image(p) if lowT < image(p) <= hightT
        | 1 otherwise
*/
Mat threshold(Mat image, float lowT, float highT)
{
    Mat res = image.clone();
    assert(lowT <= highT);
    /********************************************
                YOUR CODE HERE
    *********************************************/
    for(int i = 0; i < res.rows; i++)
    {
        for(int j = 0; j < res.cols; j++)
        {
            if(res.at<float>(i, j) <= lowT)
            {
                res.at<float>(i, j) = 0;
            }
            else if(res.at<float>(i, j) > highT)
            {
                res.at<float>(i, j) = 1;
            }
        }
    }
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}

/**
    Quantize the input float image in [0,1] in numberOfLevels different gray levels.
    
    eg. for numberOfLevels = 3 the result should be for all pixel p: res(p) =
        | 0 if image(p) < 1/3
        | 1/2 if 1/3 <= image(p) < 2/3
        | 1 otherwise

        for numberOfLevels = 4 the result should be for all pixel p: res(p) =
        | 0 if image(p) < 1/4
        | 1/3 if 1/4 <= image(p) < 1/2
        | 2/3 if 1/2 <= image(p) < 3/4
        | 1 otherwise

        and so on for other values of numberOfLevels.

*/
Mat quantize(Mat image, int numberOfLevels)
{
    Mat res = image.clone();
    assert(numberOfLevels>0);
    /********************************************
                YOUR CODE HERE
    *********************************************/
    if(numberOfLevels == 3)
    {
        for(int i = 0; i < res.rows; i++)
        {
            for(int j = 0; j < res.cols; j++)
            {
                if(res.at<float>(i, j) < 1/3)
                {
                    res.at<float>(i, j) = 0;
                }
                else if(res.at<float>(i, j) >= 1/3 && res.at<float>(i, j) < 2/3)
                {
                    res.at<float>(i, j) = 1/2;
                }
                else
                {
                    res.at<float>(i, j) = 1;
                }
            }
        }
    }

    if(numberOfLevels == 4)
    {
        for(int i = 0; i < res.rows; i++)
        {
            for(int j = 0; j < res.cols; j++)
            {
                if(res.at<float>(i, j) < 1/4)
                {
                    res.at<float>(i, j) = 0;
                }
                else if(res.at<float>(i, j) >= 1/4 && res.at<float>(i, j) < 1/2)
                {
                    res.at<float>(i, j) = 1/3;
                }
                else if(res.at<float>(i, j) >= 1/2 && res.at<float>(i, j) < 3/4)
                {
                    res.at<float>(i, j) = 2/3;
                }
                else
                {
                    res.at<float>(i, j) = 1;
                }
            }
        }
    }
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}

/**
    Normalize a grayscale image with float values
    Target range is [minValue, maxValue].
*/
float min(Mat image)
{
    float minValue = image.at<float>(0, 0);
    for(int i = 0; i < image.rows; i++)
    {
        for(int j = 0; j < image.cols; j++)
        {
            if(image.at<float>(i, j) < minValue)
            {
                minValue = image.at<float>(i, j);
            }
        }
    }
    return minValue;
}
float max(Mat image)
{
    float maxValue = image.at<float>(0, 0);
    for(int i = 0; i < image.rows; i++)
    {
        for(int j = 0; j < image.cols; j++)
        {
            if(image.at<float>(i, j) > maxValue)
            {
                maxValue = image.at<float>(i, j);
            }
        }
    }
    return maxValue;
}

Mat normalize(Mat image, float minValue, float maxValue)
{
    Mat res = image.clone();
    assert(minValue <= maxValue);
    /********************************************
                YOUR CODE HERE
    *********************************************/
    float fmin = min(res);
    float fmax = max(res);
    for(int i = 0; i < res.rows; i++)
    {
        for(int j = 0; j < res.cols; j++)
        {
            res.at<float>(i, j) = ((res.at<float>(i, j) - fmin) * (maxValue - minValue) / (fmax - fmin)) + minValue;
        }
    }
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}



/**
    Equalize image histogram with unsigned char values ([0;255])

    Warning: this time, image values are unsigned chars but calculation will be done in float or double format.
    The final result must be rounded toward the nearest integer 
*/
Mat equalize(Mat image)
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

/**
    Compute a binarization of the input float image using an automatic Otsu threshold.
    Input image is of type unsigned char ([0;255])
*/
Mat thresholdOtsu(Mat image)
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