//
// Created by Theo Bessel on 2019-07-24.
//

#pragma once

#ifndef SMARTRECO_IMAGE_HPP
#define SMARTRECO_IMAGE_HPP

#define SR_OPENCV_INTEGRATION

#ifdef SR_OPENCV_INTEGRATION
#include <opencv2/opencv.hpp>
#endif

#include <vector>

namespace SR {
    namespace Graphics {
        template < typename T = uint8_t >
        class Image {
        public:
            Image(std::initializer_list< std::initializer_list< T > >);
            Image(std::size_t, std::size_t, uint8_t);
            Image() = default;
            T const& operator()(std::size_t, std::size_t) const;
            T const& operator()(std::size_t) const;
            T& operator()(std::size_t, std::size_t);
            Image& operator+=(const Image& mat);
            Image& operator-=(const Image& mat);
            Image& operator*=(const Image& mat);
            Image& operator/=(const Image& mat);
            Image& operator+=(float scalar);
            Image& operator-=(float scalar);
            Image& operator*=(float scalar);
            Image& operator/=(float scalar);

            Image& operator*(const Image& mat);

            void readPng(std::string filename);

            #ifdef SR_OPENCV_INTEGRATION
            void readOpenCVMat(const cv::Mat& mat);
            void readOpenCVMatB(const cv::Mat& mat);
            void readOpenCVMatG(const cv::Mat& mat);
            void readOpenCVMatR(const cv::Mat& mat);
            cv::Mat_<cv::Vec3b> toOpenCVMat();
            #endif

            void printImage();

            std::size_t size() const;
            std::size_t width() const;
            std::size_t height() const;
        private:
            std::size_t m_row;
            std::size_t m_column;
            std::vector< T > m_mat;
            uint8_t m_channelCount {};
            uint8_t m_bitDepth {};
        };
    }
}

#ifdef SR_OPENCV_INTEGRATION
template < typename T >
cv::Mat_<cv::Vec3b> bgrCvMatFrom3Images(SR::Graphics::Image< T > b, SR::Graphics::Image< T > g, SR::Graphics::Image< T > r) {
    assert(("Images must have the same size", b.size() == g.size() == r.size()));
    cv::Mat_<cv::Vec3b> mat(cv::Size2d(b.width(), b.height()), {255, 255, 255});
    for (int i,o = 0; i < b.width(); ++i) {
        for (int j = 0; j < b.height(); ++j,++o) {
            mat.at<cv::Vec3b>(j, i) = cv::Vec3b(b(o), g(o), r(o));
        }
    }
    return mat;
}
#endif


#include "Image.inl"

#endif //SMARTRECO_IMAGE_HPP