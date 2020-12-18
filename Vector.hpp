//
//  vmath.h
//  VulkanBP
//
//  Created by Stefan Antoszko on 2020-04-05.
//  Copyright © 2020 Stefan Antoszko. All rights reserved.
//
#pragma once
#include <iostream>
#include <cmath>

namespace vmath {

//declarations
template<typename T>
struct _vec2;
template<typename T>
struct _vec3;
template<typename T>
struct _vec4;

//aliases
using bvec2 = _vec2<bool>;
using cvec2 = _vec2<uint8_t>;
using ivec2 = _vec2<int32_t>;
using uvec2 = _vec2<uint32_t>;
using vec2 = _vec2<float>;
using dvec2 = _vec2<double>;

using bvec3 = _vec3<bool>;
using cvec3 = _vec3<uint8_t>;
using ivec3 = _vec3<int32_t>;
using uvec3 = _vec3<uint32_t>;
using vec3 = _vec3<float>;
using dvec3 = _vec3<double>;

using bvec4 = _vec4<bool>;
using cvec4 = _vec4<uint8_t>;
using ivec4 = _vec4<int32_t>;
using uvec4 = _vec4<uint32_t>;
using vec4 = _vec4<float>;
using dvec4 = _vec4<double>;

//function declarations
template<typename U>
float dot(const _vec2<U>& a, const _vec2<U>& b);
template<typename U>
float dot(const _vec3<U>& a, const _vec3<U>& b);
template<typename U>
float dot(const _vec4<U>& a, const _vec4<U>& b);
template<typename U>
_vec3<U> cross(const _vec3<U>& a, const _vec3<U>& b);
template<typename U>
_vec3<U> rotate(const _vec3<U> vector, const _vec3<U>& axis, float angle);
template<typename U>
_vec3<U> rotate(const _vec3<U> vector, const _vec4<U>& axisAngle);

//definitions
template<typename T>
struct _vec2 {
    _vec2() : x(0), y(0) {}
    _vec2(T x, T y) : x(x), y(y) {}
    _vec2(T scalar) : x(scalar), y(scalar) {}
    _vec2(const _vec2<T>& other) = default;


    //type-cast overload
    template<typename U>
    operator _vec2<U>()  {
        std::cout << "casted type!" << std::endl;
        return _vec2<U> (x, y);
    }

    //component access
    T operator[](uint32_t i) {
        switch(i) {
            default:
                return x;
            case 1:
                return y;
        }
    }

    //arithmetic
    template<typename U>
    _vec2<T> operator+=(const _vec2<U>& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    template<typename U>
    _vec2<T> operator+=(U scalar) {
        this->x += scalar;
        this->y += scalar;
        return *this;
    }

    template<typename U>
    _vec2<T> operator-=(const _vec2<U>& other) {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }
    template<typename U>
    _vec2<T> operator-=(U scalar) {
        this->x -= scalar;
        this->y -= scalar;
        return *this;
    }

    template<typename U>
    _vec2<T> operator*=(const _vec2<U>& other) {
        this->x *= other.x;
        this->y *= other.y;
        return *this;
    }
    template<typename U>
    _vec2<T> operator*=(U scalar) {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    template<typename U>
    _vec2<T> operator/=(const _vec2<U>& other) {
        this->x /= other.x;
        this->y /= other.y;
        return *this;
    }
    template<typename U>
    _vec2<T> operator/=(U scalar) {
        this->x /= scalar;
        this->y /= scalar;
        return *this;
    }

    template<typename U>
    _vec2<T> operator++() {
        ++this->x;  //return value after it is incremented
        ++this->y;
        return *this;
    }
    template<typename U>
    _vec2<T> operator++(int i) {
        _vec2<T> temp = *this;  //save this as a return value
        ++*this;                //increment this
        return *this;           //return saved value (old)
    }

    template<typename U>
    _vec2<T> operator--() {
        --this->x;  //return value after it is decremented
        --this->y;
        return *this;
    }
    template<typename U>
    _vec2<T> operator--(int i) {
        _vec2<T> temp = *this;  //save this as a return value
        --*this;                //decremented this
        return *this;           //return saved value (old)
    }

   template<typename U>
    _vec3<T> operator+(const _vec3<U>& other) {
        return _vec3<T> (*this) += other;
    }
    template<typename U>
    _vec3<T> operator+(U scalar) {
        return _vec3<T> (*this) += scalar;
    }
    template<typename U>
    _vec3<T> operator+(const _vec3<U>& other) const{
        _vec3<T> out = _vec3<T> (*this);
        return out += other;
    }
    template<typename U>
    _vec3<T> operator+(U scalar) const{
        _vec3<T> out = _vec3<T> (*this);
        return out += scalar;
    }

    template<typename U>
    _vec3<T> operator-(const _vec3<U>& other) {
        return _vec3<T> (*this) -= other;
    }
    template<typename U>
    _vec3<T> operator-(U scalar) {
        return _vec3<T> (*this) -= scalar;
    }
    template<typename U>
    _vec3<T> operator-(const _vec3<U>& other) const{
        _vec3<T> out = _vec3<T> (*this);
        return out -= other;
    }
    template<typename U>
    _vec3<T> operator-(U scalar) const{
        _vec3<T> out = _vec3<T> (*this);
        return out -= scalar;
    }
    
    template<typename U>
    _vec3<T> operator*(const _vec3<U>& other) {
        return _vec3<T> (*this) *= other;
    }
    template<typename U>
    _vec3<T> operator*(U scalar) {
        return _vec3<T> (*this) *= scalar;
    }
    template<typename U>
    _vec3<T> operator*(const _vec3<U>& other) const{
        _vec3<T> out = _vec3<T> (*this);
        return out *= other;
    }
    template<typename U>
    _vec3<T> operator*(U scalar) const{
        _vec3<T> out = _vec3<T> (*this);
        return out *= scalar;
    }

    template<typename U>
    _vec3<T> operator/(const _vec3<U>& other) {
        return _vec3<T> (*this) /= other;
    }
    template<typename U>
    _vec3<T> operator/(U scalar) {
        return _vec3<T> (*this) /= scalar;
    }
    template<typename U>
    _vec3<T> operator/(const _vec3<U>& other) const{
        _vec3<T> out = _vec3<T> (*this);
        return out /= other;
    }
    template<typename U>
    _vec3<T> operator/(U scalar) const{
        _vec3<T> out = _vec3<T> (*this);
        return out /= scalar;
    }

    //      _vec2 defines
    template<typename U>
    float length() const{ 
        return sqrt(x*x + y*y); 
    }
    template<typename U>
    _vec2<U> normalize() const{ 
        return *this / length(); 
    }

    template<typename U>
    float distance(const _vec2<U>& other) const{
        return length(*this - other);
    }

    template<typename U>
    float dot(const _vec2<U>& other) const{ 
        return (x * other.x) + (y * other.y);
}
    //members
    T x, y;
};  //_vec2

template<typename T>
struct _vec3 {
    _vec3() : x(0), y(0), z(0) {}
    _vec3(T x, T y, T z) : x(x), y(y), z(z) {}
    _vec3(T scalar) : x(scalar), y(scalar), z(scalar) {}
    _vec3(const _vec3<T>& other) = default;


    //type-cast overload
    template<typename U>
    operator _vec3<U>()  {
        std::cout << "casted type!" << std::endl;
        return _vec3<U> (x, y, z);
    }

    //component access
    T operator[](uint32_t i) {
        switch(i) {
            default:
                return x;
            case 1:
                return y;
			case 2:
                return z;
        }
    }
	
    //arithmetic
    template<typename U>
    _vec3<T> operator+=(const _vec3<U>& other) {
        this->x += other.x;
        this->y += other.y;
		this->z += other.z;
        return *this;
    }
    template<typename U>
    _vec3<T> operator+=(U scalar) {
        this->x += scalar;
        this->y += scalar;
		this->z += scalar;
        return *this;
    }

    template<typename U>
    _vec3<T> operator-=(const _vec3<U>& other) {
        this->x -= other.x;
        this->y -= other.y;
		this->z -= other.z;
        return *this;
    }
    template<typename U>
    _vec3<T> operator-=(U scalar) {
        this->x -= scalar;
        this->y -= scalar;
		this->z -= scalar;
        return *this;
    }

    template<typename U>
    _vec3<T> operator*=(const _vec3<U>& other) {
        this->x *= other.x;
        this->y *= other.y;
		this->z *= other.z;
        return *this;
    }
    template<typename U>
    _vec3<T> operator*=(U scalar) {
        this->x *= scalar;
        this->y *= scalar;
		this->z *= scalar;
        return *this;
    }

    template<typename U>
    _vec3<T> operator/=(const _vec3<U>& other) {
        this->x /= other.x;
        this->y /= other.y;
		this->z /= other.z;
        return *this;
    }
    template<typename U>
    _vec3<T> operator/=(U scalar) {
        this->x /= scalar;
        this->y /= scalar;
		this->z /= scalar;
        return *this;
    }

    template<typename U>
    _vec3<T> operator++() {
        ++this->x;  //return value after it is incremented
        ++this->y;
		++this->z;
        return *this;
    }
    template<typename U>
    _vec3<T> operator++(int i) {
        _vec3<T> temp = *this;  //save this as a return value
        ++*this;                //increment this
        return *this;           //return saved value (old)
    }

    template<typename U>
    _vec3<T> operator--() {
        --this->x;  //return value after it is decremented
        --this->y;
		--this->z;
        return *this;
    }
    template<typename U>
    _vec3<T> operator--(int i) {
        _vec3<T> temp = *this;  //save this as a return value
        --*this;                //decremented this
        return *this;           //return saved value (old)
    }

    template<typename U>
    _vec3<T> operator+(const _vec3<U>& other) {
        return _vec3<T> (*this) += other;
    }
    template<typename U>
    _vec3<T> operator+(U scalar) {
        return _vec3<T> (*this) += scalar;
    }
    template<typename U>
    _vec3<T> operator+(const _vec3<U>& other) const{
        _vec3<T> out = _vec3<T> (*this);
        return out += other;
    }
    template<typename U>
    _vec3<T> operator+(U scalar) const{
        _vec3<T> out = _vec3<T> (*this);
        return out += scalar;
    }

    template<typename U>
    _vec3<T> operator-(const _vec3<U>& other) {
        return _vec3<T> (*this) -= other;
    }
    template<typename U>
    _vec3<T> operator-(U scalar) {
        return _vec3<T> (*this) -= scalar;
    }
    template<typename U>
    _vec3<T> operator-(const _vec3<U>& other) const{
        _vec3<T> out = _vec3<T> (*this);
        return out -= other;
    }
    template<typename U>
    _vec3<T> operator-(U scalar) const{
        _vec3<T> out = _vec3<T> (*this);
        return out -= scalar;
    }
    
    template<typename U>
    _vec3<T> operator*(const _vec3<U>& other) {
        return _vec3<T> (*this) *= other;
    }
    template<typename U>
    _vec3<T> operator*(U scalar) {
        return _vec3<T> (*this) *= scalar;
    }
    template<typename U>
    _vec3<T> operator*(const _vec3<U>& other) const{
        _vec3<T> out = _vec3<T> (*this);
        return out *= other;
    }
    template<typename U>
    _vec3<T> operator*(U scalar) const{
        _vec3<T> out = _vec3<T> (*this);
        return out *= scalar;
    }

    template<typename U>
    _vec3<T> operator/(const _vec3<U>& other) {
        return _vec3<T> (*this) /= other;
    }
    template<typename U>
    _vec3<T> operator/(U scalar) {
        return _vec3<T> (*this) /= scalar;
    }
    template<typename U>
    _vec3<T> operator/(const _vec3<U>& other) const{
        _vec3<T> out = _vec3<T> (*this);
        return out /= other;
    }
    template<typename U>
    _vec3<T> operator/(U scalar) const{
        _vec3<T> out = _vec3<T> (*this);
        return out /= scalar;
    }

    //      _vec3 defines
    float length() const{ 
        return sqrt(x*x + y*y + z*z); 
    }
	_vec3<T> normalize() const{ 
        return *this / length(); 
    }
    template<typename U>
    float distance(const _vec3<U>& other) const{
        return length(*this - other);
    }
    template<typename U>
	float dot(const _vec3<U>& other) const{ 
        return (x * other.x) + (y * other.y)+ (z * other.z);
    }
	template<typename U>
	_vec3<T> cross(const _vec3<U>& other) const{ 
        return _vec3<T>(this->y*other.z - this->z*other.y,
						this->z*other.x - this->x*other.z,
						this->x*other.y - this->y*other.x);
    }
	template<typename U>
	void rotate(const _vec3<U>& axis, float angle) {
		*this = *this * cos(angle) + axis.cross(*this) * sin(angle) + axis * axis.dot(*this) * (1 - cos(angle));
	}

	template<typename U>
	void rotate(const _vec4<U>& axisAngle)  {
	    _vec3<T> axis(axisAngle.x, axisAngle.y, axisAngle.z);
	    *this = *this * cos(axisAngle.w) + axis.dot(*this) * sin(axisAngle.w) + axis * axis.dot(*this) * (1 - cos(axisAngle.w));
    }

    //members
    T x, y, z;
};  //_vec3

template<typename T>
struct _vec4 {
    _vec4() : x(0), y(0), z(0), w(0) {}
    _vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
    _vec4(T scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}
    _vec4(const _vec4<T>& other) = default;


    //type-cast overload
    template<typename U>
    operator _vec4<U>()  {
        std::cout << "casted type!" << std::endl;
        return _vec4<U> (x, y, z, w);
    }

    //component access
    T operator[](uint32_t i) {
        switch(i) {
            default:
                return x;
            case 1:
                return y;
			case 2:
                return z;
			case 3:
                return w;
        }
    }
	
    //arithmetic
    template<typename U>
    _vec4<T> operator+=(const _vec4<U>& other) {
        this->x += other.x;
        this->y += other.y;
		this->z += other.z;
		this->w += other.w;
        return *this;
    }
    template<typename U>
    _vec4<T> operator+=(U scalar) {
        this->x += scalar;
        this->y += scalar;
		this->z += scalar;
		this->w += scalar;
        return *this;
    }

    template<typename U>
    _vec4<T> operator-=(const _vec4<U>& other) {
        this->x -= other.x;
        this->y -= other.y;
		this->z -= other.z;
		this->w -= other.w;
        return *this;
    }
    template<typename U>
    _vec4<T> operator-=(U scalar) {
        this->x -= scalar;
        this->y -= scalar;
		this->z -= scalar;
		this->w -= scalar;
        return *this;
    }

    template<typename U>
    _vec4<T> operator*=(const _vec4<U>& other) {
        this->x *= other.x;
        this->y *= other.y;
		this->z *= other.z;
		this->w *= other.w;
        return *this;
    }
    template<typename U>
    _vec4<T> operator*=(U scalar) {
        this->x *= scalar;
        this->y *= scalar;
		this->z *= scalar;
		this->w *= scalar;
        return *this;
    }

    template<typename U>
    _vec4<T> operator/=(const _vec4<U>& other) {
        this->x /= other.x;
        this->y /= other.y;
		this->z /= other.z;
		this->w /= other.w;
        return *this;
    }
    template<typename U>
    _vec4<T> operator/=(U scalar) {
        this->x /= scalar;
        this->y /= scalar;
		this->z /= scalar;
		this->w /= scalar;
        return *this;
    }

    template<typename U>
    _vec4<T> operator++() {
        ++this->x;  //return value after it is incremented
        ++this->y;
		++this->z;
		++this->w;
        return *this;
    }
    template<typename U>
    _vec4<T> operator++(int i) {
        _vec4<T> temp = *this;  //save this as a return value
        ++*this;                //increment this
        return *this;           //return saved value (old)
    }

    template<typename U>
    _vec4<T> operator--() {
        --this->x;  //return value after it is decremented
        --this->y;
		--this->z;
		--this->w;
        return *this;
    }
    template<typename U>
    _vec4<T> operator--(int i) {
        _vec4<T> temp = *this;  //save this as a return value
        --*this;                //decremented this
        return *this;           //return saved value (old)
    }

    template<typename U>
    _vec3<T> operator+(const _vec3<U>& other) {
        return _vec3<T> (*this) += other;
    }
    template<typename U>
    _vec3<T> operator+(U scalar) {
        return _vec3<T> (*this) += scalar;
    }
    template<typename U>
    _vec3<T> operator+(const _vec3<U>& other) const{
        _vec3<T> out = _vec3<T> (*this);
        return out += other;
    }
    template<typename U>
    _vec3<T> operator+(U scalar) const {
        _vec3<T> out = _vec3<T> (*this);
        return out += scalar;
    }

    template<typename U>
    _vec3<T> operator-(const _vec3<U>& other) {
        return _vec3<T> (*this) -= other;
    }
    template<typename U>
    _vec3<T> operator-(U scalar) {
        return _vec3<T> (*this) -= scalar;
    }
    template<typename U>
    _vec3<T> operator-(const _vec3<U>& other) const{
        _vec3<T> out = _vec3<T> (*this);
        return out -= other;
    }
    template<typename U>
    _vec3<T> operator-(U scalar) const{
        _vec3<T> out = _vec3<T> (*this);
        return out -= scalar;
    }
    
    template<typename U>
    _vec3<T> operator*(const _vec3<U>& other) {
        return _vec3<T> (*this) *= other;
    }
    template<typename U>
    _vec3<T> operator*(U scalar) {
        return _vec3<T> (*this) *= scalar;
    }
    template<typename U>
    _vec3<T> operator*(const _vec3<U>& other) const{
        _vec3<T> out = _vec3<T> (*this);
        return out *= other;
    }
    template<typename U>
    _vec3<T> operator*(U scalar) const{
        _vec3<T> out = _vec3<T> (*this);
        return out *= scalar;
    }

    template<typename U>
    _vec3<T> operator/(const _vec3<U>& other) {
        return _vec3<T> (*this) /= other;
    }
    template<typename U>
    _vec3<T> operator/(U scalar) {
        return _vec3<T> (*this) /= scalar;
    }
    template<typename U>
    _vec3<T> operator/(const _vec3<U>& other) const{
        _vec3<T> out = _vec3<T> (*this);
        return out /= other;
    }
    template<typename U>
    _vec3<T> operator/(U scalar) const{
        _vec3<T> out = _vec3<T> (*this);
        return out /= scalar;
    }

    //geometry things
    float length() { 
        return sqrt(x*x + y*y + z*z + w*w); 
    }

	_vec4 normalize() { 
        return *this / length(); 
    }

    template<typename U>
    float distance(const _vec4<U>& other) {
        return length(*this - other);
    }

    template<typename U>
	float dot(const _vec4<U>& other) { 
        return (x * other.x) + (y * other.y) + (z * other.z) + (w * other.w);
    }
    //members
    T x, y, z, w;
};  //_vec4

//debug
template<typename U>
std::ostream& operator<<(std::ostream& os, const _vec2<U>& vec)  {
    os << vec.x << ", " << vec.y;
    return os;
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const _vec3<U>& vec)  {
    os << vec.x << ", " << vec.y << ", " << vec.z;
    return os;
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const _vec4<U>& vec)  {
    os << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
    return os;
}

//      global defines
template<typename U>
float dot(const _vec2<U>& a, const _vec2<U>& b) { 
	return (a.x * b.x) + (a.y * b.y);
}
template<typename U>
float dot(const _vec3<U>& a, const _vec3<U>& b) { 
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
template<typename U>
float dot(const _vec4<U>& a, const _vec4<U>& b) { 
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

template<typename U>
_vec3<U> cross(const _vec3<U>& a, const _vec3<U>& b) { 
	return _vec3<U>(a.y*b.z - a.z*b.y,
					a.z*b.x - a.x*b.z,
					a.x*b.y - a.y*b.x);
}

template<typename U>
_vec3<U> rotate(const _vec3<U> vector, const _vec3<U>& axis, float angle) {
	return _vec3<U> (vector * cos(angle) + (axis.cross(vector)) * sin(angle) + axis * (axis.dot(vector)) * (1 - cos(angle)));
}
template<typename U>
_vec3<U> rotate(const _vec3<U> vector, const _vec4<U>& axisAngle) {
	_vec3<U> axis(axisAngle.x, axisAngle.y, axisAngle.z);
	return _vec3<U> (vector * cos(axisAngle.x) + cross(axis, vector) * sin(axisAngle.w) + axis * dot(axis, vector) * (1 - cos(axisAngle.w)));
}

}	//namespace vbp
