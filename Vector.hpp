//  Vector.hpp

#pragma once
#include <iostream>
#include <cmath>
#include <type_traits>  //for std::is_fundamental

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
template<typename U>
_vec2<U> normalize(const _vec2<U>& vec);
template<typename U>
_vec3<U> normalize(const _vec3<U>& vec);
template<typename U>
_vec4<U> normalize(const _vec4<U>& vec);

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
    T& operator[](uint32_t i) {
        switch(i) {
            default:
                return x;
            case 1:
                return y;
        }
    }

    //arithmetic
    _vec2<T> operator+=(const _vec2<T>& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    _vec2<T> operator+=(T scalar) {
        this->x += scalar;
        this->y += scalar;
        return *this;
    }


    _vec2<T> operator-=(const _vec2<T>& other) {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    _vec2<T> operator-=(T scalar) {
        this->x -= scalar;
        this->y -= scalar;
        return *this;
    }


    _vec2<T> operator*=(const _vec2<T>& other) {
        this->x *= other.x;
        this->y *= other.y;
        return *this;
    }

    _vec2<T> operator*=(T scalar) {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }


    _vec2<T> operator/=(const _vec2<T>& other) {
        this->x /= other.x;
        this->y /= other.y;
        return *this;
    }

    _vec2<T> operator/=(T scalar) {
        this->x /= scalar;
        this->y /= scalar;
        return *this;
    }


    _vec2<T> operator++() {
        ++this->x;  //return value after it is incremented
        ++this->y;
        return *this;
    }

    _vec2<T> operator++(int i) {
        _vec2<T> temp = *this;  //save this as a return value
        ++*this;                //increment this
        return *this;           //return saved value (old)
    }


    _vec2<T> operator--() {
        --this->x;  //return value after it is decremented
        --this->y;
        return *this;
    }

    _vec2<T> operator--(int i) {
        _vec2<T> temp = *this;  //save this as a return value
        --*this;                //decremented this
        return *this;           //return saved value (old)
    }


    _vec2<T> operator+(const _vec2<T>& other) {
        return _vec2<T> (*this) += other;
    }

    _vec2<T> operator+(T scalar) {
        return _vec2<T> (*this) += scalar;
    }

    _vec2<T> operator+(const _vec2<T>& other) const{
        _vec2<T> out (*this);
        return out += other;
    }

    _vec2<T> operator+(T scalar) const{
        _vec2<T> out (*this);
        return out += scalar;
    }


    _vec2<T> operator-(const _vec2<T>& other) {
        return _vec2<T> (*this) -= other;
    }

    _vec2<T> operator-(T scalar) {
        return _vec2<T> (*this) -= scalar;
    }

    _vec2<T> operator-(const _vec2<T>& other) const{
        _vec2<T> out (*this);
        return out -= other;
    }

    _vec2<T> operator-(T scalar) const{
        _vec2<T> out (*this);
        return out -= scalar;
    }
    

    _vec2<T> operator*(const _vec2<T>& other) {
        return _vec2<T> (*this) *= other;
    }

    _vec2<T> operator*(T scalar) {
        return _vec2<T> (*this) *= scalar;
    }

    _vec2<T> operator*(const _vec2<T>& other) const{
        _vec2<T> out (*this);
        return out *= other;
    }

    _vec2<T> operator*(T scalar) const{
        _vec2<T> out (*this);
        return out *= scalar;
    }


    _vec2<T> operator/(const _vec2<T>& other) {
        return _vec2<T> (*this) /= other;
    }

    _vec2<T> operator/(T scalar) {
        return _vec2<T> (*this) /= scalar;
    }

    _vec2<T> operator/(const _vec2<T>& other) const{
        _vec2<T> out (*this);
        return out /= other;
    }

    _vec2<T> operator/(T scalar) const{
        _vec2<T> out (*this);
        return out /= scalar;
    }

    //      _vec2 defines
    float length() const{ 
        return sqrt(x*x + y*y); 
    }

    float distance(const _vec2<T>& other) const{
        return length(*this - other);
    }

    float dot(const _vec2<T>& other) const{ 
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
    T& operator[](uint32_t i) {
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
    _vec3<T> operator+=(const _vec3<T>& other) {
        this->x += other.x;
        this->y += other.y;
		this->z += other.z;
        return *this;
    }
    _vec3<T> operator+=(T scalar) {
        this->x += scalar;
        this->y += scalar;
		this->z += scalar;
        return *this;
    }

    _vec3<T> operator-=(const _vec3<T>& other) {
        this->x -= other.x;
        this->y -= other.y;
		this->z -= other.z;
        return *this;
    }
    _vec3<T> operator-=(T scalar) {
        this->x -= scalar;
        this->y -= scalar;
		this->z -= scalar;
        return *this;
    }

    _vec3<T> operator*=(const _vec3<T>& other) {
        this->x *= other.x;
        this->y *= other.y;
		this->z *= other.z;
        return *this;
    }
    
    _vec3<T> operator*=(T scalar) {
        std::cout << "is fundamental: "<<std::is_fundamental<T>::value << std::endl;
        this->x *= scalar;
        this->y *= scalar;
		this->z *= scalar;
        return *this;
    }

    _vec3<T> operator/=(const _vec3<T>& other) {
        this->x /= other.x;
        this->y /= other.y;
		this->z /= other.z;
        return *this;
    }
    _vec3<T> operator/=(T scalar) {
        this->x /= scalar;
        this->y /= scalar;
		this->z /= scalar;
        return *this;
    }

    _vec3<T> operator++() {
        ++this->x;  //return value after it is incremented
        ++this->y;
		++this->z;
        return *this;
    }
    _vec3<T> operator++(int i) {
        _vec3<T> temp = *this;  //save this as a return value
        ++*this;                //increment this
        return *this;           //return saved value (old)
    }

    _vec3<T> operator--() {
        --this->x;  //return value after it is decremented
        --this->y;
		--this->z;
        return *this;
    }
    _vec3<T> operator--(int i) {
        _vec3<T> temp = *this;  //save this as a return value
        --*this;                //decremented this
        return *this;           //return saved value (old)
    }

    _vec3<T> operator+(const _vec3<T>& other) {
        return _vec3<T> (*this) += other;
    }
    _vec3<T> operator+(T scalar) {
        return _vec3<T> (*this) += scalar;
    }
    _vec3<T> operator+(const _vec3<T>& other) const{
        _vec3<T> out (*this);
        return out += other;
    }
    _vec3<T> operator+(T scalar) const{
        _vec3<T> out (*this);
        return out += scalar;
    }

    _vec3<T> operator-(const _vec3<T>& other) {
        return _vec3<T> (*this) -= other;
    }
    _vec3<T> operator-(T scalar) {
        return _vec3<T> (*this) -= scalar;
    }
    _vec3<T> operator-(const _vec3<T>& other) const{
        _vec3<T> out (*this);
        return out -= other;
    }
    _vec3<T> operator-(T scalar) const{
        _vec3<T> out (*this);
        return out -= scalar;
    }
    
    _vec3<T> operator*(const _vec3<T>& other) {
        return _vec3<T> (*this) *= other;
    }
    _vec3<T> operator*(T scalar) {
        return _vec3<T> (*this) *= scalar;
    }
    _vec3<T> operator*(const _vec3<T>& other) const{
        _vec3<T> out (*this);
        return out *= other;
    }
    _vec3<T> operator*(T scalar) const{
        _vec3<T> out (*this);
        return out *= scalar;
    }

    _vec3<T> operator/(const _vec3<T>& other) {
        return _vec3<T> (*this) /= other;
    }
    _vec3<T> operator/(T scalar) {
        return _vec3<T> (*this) /= scalar;
    }
    _vec3<T> operator/(const _vec3<T>& other) const{
        _vec3<T> out (*this);
        return out /= other;
    }
    _vec3<T> operator/(T scalar) const{
        _vec3<T> out (*this);
        return out /= scalar;
    }

    //      _vec3 defines
    float length() const{ 
        return sqrt(x*x + y*y + z*z); 
    }

    float distance(const _vec3<T>& other) const{
        return length(*this - other);
    }
	float dot(const _vec3<T>& other) const{ 
        return (x * other.x) + (y * other.y)+ (z * other.z);
    }
	_vec3<T> cross(const _vec3<T>& other) const{ 
        return _vec3<T>(this->y*other.z - this->z*other.y,
						this->z*other.x - this->x*other.z,
						this->x*other.y - this->y*other.x);
    }
	void rotate(const _vec3<T>& axis, float angle) {
		*this = *this * cos(angle) + axis.cross(*this) * sin(angle) + axis * axis.dot(*this) * (1 - cos(angle));
	}

	void rotate(const _vec4<T>& axisAngle)  {
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
    T& operator[](uint32_t i) {
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
    _vec4<T> operator+=(const _vec4<T>& other) {
        this->x += other.x;
        this->y += other.y;
		this->z += other.z;
		this->w += other.w;
        return *this;
    }
    _vec4<T> operator+=(T scalar) {
        this->x += scalar;
        this->y += scalar;
		this->z += scalar;
		this->w += scalar;
        return *this;
    }

    _vec4<T> operator-=(const _vec4<T>& other) {
        this->x -= other.x;
        this->y -= other.y;
		this->z -= other.z;
		this->w -= other.w;
        return *this;
    }
    _vec4<T> operator-=(T scalar) {
        this->x -= scalar;
        this->y -= scalar;
		this->z -= scalar;
		this->w -= scalar;
        return *this;
    }

    _vec4<T> operator*=(const _vec4<T>& other) {
        this->x *= other.x;
        this->y *= other.y;
		this->z *= other.z;
		this->w *= other.w;
        return *this;
    }
    _vec4<T> operator*=(T scalar) {
        this->x *= scalar;
        this->y *= scalar;
		this->z *= scalar;
		this->w *= scalar;
        return *this;
    }

    _vec4<T> operator/=(const _vec4<T>& other) {
        this->x /= other.x;
        this->y /= other.y;
		this->z /= other.z;
		this->w /= other.w;
        return *this;
    }
    _vec4<T> operator/=(T scalar) {
        this->x /= scalar;
        this->y /= scalar;
		this->z /= scalar;
		this->w /= scalar;
        return *this;
    }

    _vec4<T> operator++() {
        ++this->x;  //return value after it is incremented
        ++this->y;
		++this->z;
		++this->w;
        return *this;
    }
    _vec4<T> operator++(int i) {
        _vec4<T> temp = *this;  //save this as a return value
        ++*this;                //increment this
        return *this;           //return saved value (old)
    }

    _vec4<T> operator--() {
        --this->x;  //return value after it is decremented
        --this->y;
		--this->z;
		--this->w;
        return *this;
    }
    _vec4<T> operator--(int i) {
        _vec4<T> temp = *this;  //save this as a return value
        --*this;                //decremented this
        return *this;           //return saved value (old)
    }

    _vec4<T> operator+(const _vec4<T>& other) {
        return _vec4<T> (*this) += other;
    }
    _vec4<T> operator+(T scalar) {
        return _vec4<T> (*this) += scalar;
    }
    _vec4<T> operator+(const _vec4<T>& other) const{
        _vec4<T> out (*this);
        return out += other;
    }
    _vec4<T> operator+(T scalar) const {
        _vec4<T> out (*this);
        return out += scalar;
    }

    _vec4<T> operator-(const _vec4<T>& other) {
        return _vec4<T> (*this) -= other;
    }
    _vec4<T> operator-(T scalar) {
        return _vec4<T> (*this) -= scalar;
    }
    _vec4<T> operator-(const _vec4<T>& other) const{
        _vec4<T> out (*this);
        return out -= other;
    }
    _vec4<T> operator-(T scalar) const{
        _vec4<T> out (*this);
        return out -= scalar;
    }
    
    _vec4<T> operator*(const _vec4<T>& other) {
        return _vec4<T> (*this) *= other;
    }
    _vec4<T> operator*(T scalar) {
        return _vec4<T> (*this) *= scalar;
    }
    _vec4<T> operator*(const _vec4<T>& other) const{
        _vec4<T> out (*this);
        return out *= other;
    }
    _vec4<T> operator*(T scalar) const{
        _vec4<T> out (*this);
        return out *= scalar;
    }

    _vec4<T> operator/(const _vec4<T>& other) {
        return _vec4<T> (*this) /= other;
    }
    _vec4<T> operator/(T scalar) {
        return _vec4<T> (*this) /= scalar;
    }
    _vec4<T> operator/(const _vec4<T>& other) const{
        _vec4<T> out (*this);
        return out /= other;
    }
    _vec4<T> operator/(T scalar) const{
        _vec4<T> out (*this);
        return out /= scalar;
    }

    //geometry things
    float length() { 
        return sqrt(x*x + y*y + z*z + w*w); 
    }

    float distance(const _vec4<T>& other) {
        return length(*this - other);
    }

	float dot(const _vec4<T>& other) { 
        return (x * other.x) + (y * other.y) + (z * other.z) + (w * other.w);
    }
    //members
    T x, y, z, w;
};  //_vec4

//templated primitive arithmetic
template<typename T>
_vec2<T> operator+(T scalar, const _vec2<T>& vec) {
    return _vec2<T>(scalar + vec.x,
                    scalar + vec.y );
}
template<typename T>
_vec2<T> operator-(T scalar, const _vec2<T>& vec) {
    return _vec2<T>(scalar - vec.x,
                    scalar - vec.y );
}
template<typename T>
_vec2<T> operator*(T scalar, const _vec2<T>& vec) {
    return _vec2<T>(scalar * vec.x,
                    scalar * vec.y );
}
template<typename T>
_vec2<T> operator/(T scalar, const _vec2<T>& vec) {
    return _vec2<T>(scalar / vec.x,
                    scalar / vec.y );
}

template<typename T>
_vec3<T> operator+(T scalar, const _vec3<T>& vec) {
    return _vec3<T>(scalar + vec.x,
                    scalar + vec.y,
                    scalar + vec.z );
}
template<typename T>
_vec3<T> operator-(T scalar, const _vec3<T>& vec) {
    return _vec3<T>(scalar - vec.x,
                    scalar - vec.y,
                    scalar - vec.z );
}
template<typename T>
_vec3<T> operator*(T scalar, const _vec3<T>& vec) {
    return _vec3<T>(scalar * vec.x,
                    scalar * vec.y,
                    scalar * vec.z );
}
template<typename T>
_vec3<T> operator/(T scalar, const _vec3<T>& vec) {
    return _vec3<T>(scalar / vec.x,
                    scalar / vec.y,
                    scalar / vec.z );
}

template<typename T>
_vec4<T> operator+(T scalar, const _vec4<T>& vec) {
    return _vec4<T>(scalar + vec.x,
                    scalar + vec.y,
                    scalar + vec.z,
                    scalar + vec.w );
}
template<typename T>
_vec4<T> operator-(T scalar, const _vec4<T>& vec) {
    return _vec4<T>(scalar - vec.x,
                    scalar - vec.y,
                    scalar - vec.z,
                    scalar - vec.w );
}
template<typename T>
_vec4<T> operator*(T scalar, const _vec4<T>& vec) {
    return _vec4<T>(scalar * vec.x,
                    scalar * vec.y,
                    scalar * vec.z,
                    scalar * vec.w );
}
template<typename T>
_vec4<T> operator/(T scalar, const _vec4<T>& vec) {
    return _vec4<T>(scalar / vec.x,
                    scalar / vec.y,
                    scalar / vec.z,
                    scalar / vec.w );
}

//debug
template<typename T>
std::ostream& operator<<(std::ostream& os, const _vec2<T>& vec)  {
    os << vec.x << ", " << vec.y;
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const _vec3<T>& vec)  {
    os << vec.x << ", " << vec.y << ", " << vec.z;
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const _vec4<T>& vec)  {
    os << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
    return os;
}

//      global defines
template<typename T>
float dot(const _vec2<T>& a, const _vec2<T>& b) { 
	return (a.x * b.x) + (a.y * b.y);
}
template<typename T>
float dot(const _vec3<T>& a, const _vec3<T>& b) { 
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
template<typename T>
float dot(const _vec4<T>& a, const _vec4<T>& b) { 
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

template<typename T>
_vec3<T> cross(const _vec3<T>& a, const _vec3<T>& b) { 
	return _vec3<T>(a.y*b.z - a.z*b.y,
					a.z*b.x - a.x*b.z,
					a.x*b.y - a.y*b.x);
}

template<typename T>
_vec2<T> normalize(const _vec2<T>& vec) { 
    return vec / vec.length(); 
}

template<typename T>
_vec3<T> normalize(const _vec3<T>& vec) { 
    return vec / vec.length(); 
}

template<typename T>
_vec4<T> normalize(const _vec4<T>& vec) { 
    return vec / vec.length(); 
}

template<typename T>
_vec3<T> rotate(const _vec3<T> vector, const _vec3<T>& axis, float angle) {
	return _vec3<T> (vector * cos(angle) + (axis.cross(vector)) * sin(angle) + axis * (axis.dot(vector)) * (1 - cos(angle)));
}
template<typename T>
_vec3<T> rotate(const _vec3<T> vector, const _vec4<T>& axisAngle) {
	_vec3<T> axis(axisAngle.x, axisAngle.y, axisAngle.z);
	return _vec3<T> (vector * cos(axisAngle.x) + cross(axis, vector) * sin(axisAngle.w) + axis * dot(axis, vector) * (1 - cos(axisAngle.w)));
}

}	//namespace vbp
