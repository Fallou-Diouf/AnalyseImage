#include <opencv2/opencv.hpp>
#include "tpHistogram.h"
#include "tpGeometry.h"
#include "tpConvolution.h"
#include <cmath>
#include <algorithm>
#include <tuple>
#include <iomanip>
using namespace cv;
using namespace std;


Mat createMat(int height, int width)
{
    Mat img = Mat(height,width, CV_32FC1);
    for(int y=0; y<height; y++)
    {
        for(int x=0; x<width; x++)
        {
            img.at<float>(y,x) = (y*0.1) + (x*0.2);
        }
    }
    return img;
}

void affiche(Mat image)
{
    for(int y = 0; y < image.rows; y++)
    {
        for(int x = 0; x < image.cols; x++)
        {
            cout << fixed << setprecision(1) << image.at<float>(y, x) << " ";
        }
        cout << endl;
    }
}




int main()
{
    int height = 5;
    int width = 5;
    int choix;

    cout << "Donner votre choix: 1: tpHistogramme, 2: tpConvolution, 3: tpGeometrie" << endl;
    cin >> choix;

    Mat image = createMat(height, width);

    switch(choix)
    {
        case 1:
        {
            cout << "==================TP histogramme===============" << endl;
            affiche(image);

            Mat res = inverse(image);
            cout << "==================Inversion=================" << endl;
            affiche(res);

            cout << "==================Seuillage bas=================" << endl;
            Mat res2 = threshold(image, 50, 200);
            affiche(res2);

            cout << "==================Seuillage combiné=================" << endl;
            Mat res3 = quantize(image, 4);
            affiche(res3);
            break;
        }

        case 2:
        {
            cout << "==================TP convolution===============" << endl;
            cout << "==========Image initiale=======" << endl;
            affiche(image);
            cout << endl;

            cout << "==========Mean Filter=======" << endl;
            Mat mean = meanFilter(image, 1);
            affiche(mean);
            cout << endl;

            cout << "==========Convolution=======" << endl;
            cout << "Kernel" << endl;
            Mat k = createMat(3, 3);
            affiche(k);
            cout << endl;

            Mat conv = convolution(image, k);
            affiche(conv);
            cout << endl;

            cout << "==========Edge Sobel=======" << endl;
            Mat sobel = edgeSobel(image);
            affiche(sobel);
            cout << endl;
            break;
        }

        case 3:
        {
            cout << "==================TP transformation geometrique===============" << endl;
            cout << "==========Image Initiale=======" << endl;
            affiche(image);
            cout << endl;

            cout << "==========Transposee=======" << endl;
            Mat res = transpose(image);
            affiche(res);
            cout << endl;

            cout << "=====Interpolate nearest====" << endl;
            float y = 0.4f;
            float x = 0.6f;
            float pixel = interpolate_nearest(image, y, x);
            cout<<"v = " << fixed << setprecision(1) << pixel << " ";
            cout << endl;
            break;
        }

        default:
            cout << "Choix invalide" << endl;
            break;
    }

    return 0;
}
