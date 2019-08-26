#include <iostream>
#include <maths/Matrix.hpp>
#include <maths/Vec3.hpp>
#include <graphics/Image.hpp>

#include <opencv2/opencv.hpp>

int main() {
    float time;
    clock_t t1, t2;

    SR::Graphics::Image<float> img({
            {1.2, 2.4, 3.5, 4.1},
            {5.1, 6.5, 7.8, 4.8},
            {3.9, 2.1, 4.9, 5.2},
            {3.1, 2.7, 1.1, 4.1}
        }
    );

    SR::Graphics::Image<float> img2({
            {3.4, 3.4, 3.5, 3.1},
            {3.1, 3.5, 3.8, 3.8},
            {3.9, 3.1, 3.9, 3.2},
            {3.1, 3.7, 3.1, 3.1},
        }
    );

    SR::Graphics::Image<int> testingimageB({
        {245,003,000,034},
        {023,189,100,230},
        {020,180,023,030},
        {245,003,000,0034}
    });

    SR::Graphics::Image<int> testingimageG({
        {023,189,100,230},
        {030,180,033,200},
        {245,003,000,034},
        {245,003,000,034}
    });

    SR::Graphics::Image<int> testingimageR({
        {030,180,033,030},
        {245,003,000,034},
        {245,003,000,034},
        {23,189,100,203}
    });
    
    SR::Maths::Matrix<int, 3, 3> mat( {
        {1,2,5},
        {4,5,8},
        {0,7,9}
    });

    img.printImage();
    img2.printImage();
    img *= img2;
    img.printImage();

    cv::Mat image = cv::imread("/Users/theobessel/Desktop/image.jpg", cv::IMREAD_COLOR);
    if(!image.data) {
        std::cerr <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    imshow("Display window", image);

    t1 = clock();
    t2 = clock();

    time = (float)(t2-t1)/CLOCKS_PER_SEC;

    std::cout << "Time : " << time << std::endl;

    SR::Maths::Vec3<int> color({255, 0, 14});
    std::cout << " R: " << color[0] << ", G: " << color[1] << ", B: " << color[2] << std::endl;

    SR::Graphics::Image<int> testimage;
    testimage.readOpenCVMat(image);

    SR::Graphics::Image<int> B,G,R;
    B.readOpenCVMatB(image);
    G.readOpenCVMatG(image);
    R.readOpenCVMatR(image);

    namedWindow("Display window6", cv::WINDOW_AUTOSIZE);
    imshow("Display window6", bgrCvMatFrom3Images(B, G, G));

    namedWindow("R", cv::WINDOW_AUTOSIZE);
    imshow("R", testingimageR.toOpenCVMat());

    namedWindow("G", cv::WINDOW_AUTOSIZE);
    imshow("G", testingimageG.toOpenCVMat());

    namedWindow("B", cv::WINDOW_AUTOSIZE);
    imshow("B", testingimageB.toOpenCVMat());

    namedWindow("RGB", cv::WINDOW_AUTOSIZE);
    imshow("RGB", bgrCvMatFrom3Images(testingimageB, testingimageG, testingimageR ));

    cv::waitKey(0);
    return 0;
}