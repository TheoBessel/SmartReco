//
// Created by Theo Bessel on 2019-07-24.
//


#ifdef SR_OPENCV_INTEGRATION
#include <opencv2/opencv.hpp>
#endif

#define NDEBUG
#include <cassert>
#include <fstream>
#include <libpng16/png.h>
#include <zlib.h>
#include "../maths/Vec3.hpp"


namespace SR {
    namespace Graphics {
        template < typename T >
        Image< T >::Image(std::initializer_list< std::initializer_list< T > > mat)
                : m_row{mat.begin()->size()}, m_column{mat.size()}, m_mat(m_row * m_column) {
            std::size_t i = 0;
            for (auto&& elements : mat) {
                for (auto&& element : elements) {
                    m_mat[i] = element;
                    ++i;
                }
            }
        }

        template < typename T >
        Image< T >::Image(std::size_t width, std::size_t height, uint8_t initvalue)
                : m_row{width}, m_column{height}, m_mat(m_row * m_column) {
            for (int i = 0; i < width*height; ++i) {
                m_mat[i] = initvalue;
            }
        }

        template < typename T >
        T const& Image< T >::operator()(std::size_t x, std::size_t y) const {
            assert(("Index out of range!", x < m_row));
            assert(("Index out of range!",y < m_column));
            return m_mat[x + y * m_row];
        }

        template < typename T >
        T& Image< T >::operator()(std::size_t x, std::size_t y) {
            assert(("Index out of range!", x < m_row));
            assert(("Index out of range!",y < m_column));
            return m_mat[x + y * m_row];
        }

        template < typename T >
        T const& Image< T >::operator()(std::size_t x) const {
            return m_mat[x];
        }

        template < typename T >
        Image< T >& Image< T >::operator+=(const Image& mat) {
            assert(("Matrix size error!", m_mat.size() == mat.size()));
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] += mat.m_mat[i];
            return *this;
        }

        template < typename T >
        Image< T >& Image< T >::operator-=(const Image& mat) {
            assert(("Matrix size error!", m_mat.size() == mat.size()));
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] -= mat.m_mat[i];
            return *this;
        }

        template <typename T>
        Image< T >& Image< T >::operator*=(const Image& mat) {
            assert(("Matrix size error!", m_mat.size() == mat.size()));
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] *= mat.m_mat[i];
            return *this;
        }

        template <typename T>
        Image< T >& Image< T >::operator/=(const Image& mat) {
            assert(("Matrix size error!", m_mat.size() == mat.size()));
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] /= mat.m_mat[i];
            return *this;
        }

        template < typename T >
        Image< T >& Image< T >::operator+=(float scalar) {
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] += scalar;
            return *this;
        }

        template < typename T >
        Image< T >& Image< T >::operator-=(float scalar) {
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] -= scalar;
            return *this;
        }

        template <typename T>
        Image< T >& Image< T >::operator*=(float scalar) {
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] *= scalar;
            return *this;
        }

        template <typename T>
        Image< T >& Image< T >::operator/=(float scalar) {
            for (std::size_t i = 0; i < m_mat.size(); ++i)
                m_mat[i] /= scalar;
            return *this;
        }

        template <typename T>
        Image< T >& Image< T >::operator*(const Image& mat) {
            assert(("Matrix size error!", width() == mat.height() | height() == mat.width()));
            for (std::size_t i = 0; i < width(); ++i)
                for (std::size_t j = 0; j < height(); ++j)
                    operator()(i, j) = mat.operator()(i, j );
            return *this;
        }

        template < typename T >
        void Image< T >::readPng(std::string filename) {

        }

        #ifdef SR_OPENCV_INTEGRATION
        template < typename T >
        void Image< T >::readOpenCVMat(const cv::Mat& mat) {
            m_row = mat.size().width;
            m_column = mat.size().height;
            m_mat.resize(size());
            cv::Vec3b poolVeccolor;
            for (int i,o = 0; i < m_row; ++i) {
                for (int j = 0; j < m_column; ++j, ++o) {
                    poolVeccolor = mat.at<cv::Vec3b>(j, i);
                    m_mat[o] = (poolVeccolor[0] + poolVeccolor[1] + poolVeccolor[2])/3;
                }
            }
        }

        template < typename T >
        void Image< T >::readOpenCVMatB(const cv::Mat& mat) {
            m_row = mat.size().width;
            m_column = mat.size().height;
            m_mat.resize(size());
            cv::Vec3b poolVeccolor;
            for (int i,o = 0; i < m_row; ++i) {
                for (int j = 0; j < m_column; ++j, ++o) {
                    poolVeccolor = mat.at<cv::Vec3b>(j, i);
                    m_mat[o] = (poolVeccolor[0]);
                }
            }
        }

        template < typename T >
        void Image< T >::readOpenCVMatG(const cv::Mat& mat) {
            m_row = mat.size().width;
            m_column = mat.size().height;
            m_mat.resize(size());
            cv::Vec3b poolVeccolor;
            for (int i,o = 0; i < m_row; ++i) {
                for (int j = 0; j < m_column; ++j, ++o) {
                    poolVeccolor = mat.at<cv::Vec3b>(j, i);
                    m_mat[o] = (poolVeccolor[1]);
                }
            }
        }

        template < typename T >
        void Image< T >::readOpenCVMatR(const cv::Mat& mat) {
            m_row = mat.size().width;
            m_column = mat.size().height;
            m_mat.resize(size());
            cv::Vec3b poolVeccolor;
            for (int i,o = 0; i < m_row; ++i) {
                for (int j = 0; j < m_column; ++j, ++o) {
                    poolVeccolor = mat.at<cv::Vec3b>(j, i);
                    m_mat[o] = (poolVeccolor[2]);
                }
            }
        }

        template < typename T >
        cv::Mat_<cv::Vec3b> Image< T >::toOpenCVMat() {
            cv::Mat_<cv::Vec3b> mat(cv::Size2d(width(), height()), {255, 255, 255});
            for (int i,o = 0; i < width(); ++i) {
                for (int j = 0; j < height(); ++j,++o) {
                    mat.at<cv::Vec3b>(j, i) = cv::Vec3b(m_mat[o], m_mat[o], m_mat[o]);
                }
            }
            return mat;
        };
        #endif

        template < typename T >
        void Image< T >::printImage() {
            std::cerr << size() << std::endl;
            for (std::size_t j = 0; j < height(); ++j) {
                for (std::size_t i = 0; i < width(); ++i) {
                    std::cout << static_cast<float>(operator()(i, j)) << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            std::cout << "end" << std::endl;
        }

        template < typename T >
        std::size_t Image< T >::size() const {
            return m_row * m_column;
        }

        template < typename T >
        std::size_t Image< T >::width() const {
            return m_row;
        }

        template < typename T >
        std::size_t Image< T >::height() const {
            return m_column;
        }
    }
}