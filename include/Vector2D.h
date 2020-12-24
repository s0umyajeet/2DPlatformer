#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <math>

class Vector2D {
    public:
        //constructor
        Vector2D(float X = 0, float Y = 0) : m_x(X), m_y(Y) {}

        //getters and setters
        float getX() { return m_x; }
        float getY() { return m_y; }
        void setX(float x) { m_x = x; }
        void setY(float y) { m_y = y; }

        //operator + overload
        inline Vector2D operator+(const Vector2D& v) {
            return Vector2D(v.m_x + this->m_x, v.m_y + this->m_y);
        }

        //operator += overload
        Vector2D& operator+=(Vector2D& v1, const Vector2D& v2) {
            v1.m_x += v2.m_x;
            v1.m_y += v2.m_y;
            return v1;
        }

        //operator - overload
        inline Vector2D operator-(const Vector2D& v) {
            return Vector2D(v.m_x - this->m_x, v.m_y - this->m_y);
        }

        //operator -= overload
        Vector2D& operator-=(Vector2D& v1, const Vector2D& v2) {
            v1.m_x -= v2.m_x;
            v1.m_y -= v2.m_y;
            return v1;
        }

        //operator * overload
        inline Vector2D operator*(const float scalar) {
            return Vector2D(this->m_x * scalar, this->m_y * scalar);
        }

        //operator *= overload
        inline Vector2D operator*=(const float scalar) {
            m_x *= scalar;
            m_y *= scalar;
            return *this;
        }

        //operator / overload
        Vector2D operator/(float scalar) {
            return Vector2D(m_x / scalar, m_y / scalar);
        }

        //operator /= overload
        Vector2D& operator/=(float scalar) {
            m_x /= scalar;
            m_y /= scalar;
            return *this;
        }

        //get magnitude of a vector
        float magnitude() { return sqrt(m_x * m_x + m_y * m_y); }

        //normalize
        void normalize() {
            float m = magnitude();
            if (m > 0) {
                *this /= m;
            }
        }

        //for debug
        void printVector() {
            std::cout << "(" << x << "i + " << y << "j)" << std::endl;
        }

    private:
        //x and y coordinates
        float m_x;
        float m_y;
};
#endif // VECTOR2D_H
