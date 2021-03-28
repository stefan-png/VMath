// Matrix.hpp

#pragma once
#include "Vector.hpp"
#include <cmath>

namespace vmath {
		//column major:		0, 4, 8, 12
		//					1, 5, 9, 13
		//					2, 6, 10,14
		//					3, 7, 11,15

	template<typename T>
	struct _mat4 {
		T m[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		_mat4() {}
		_mat4(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p) {
			this->m[0] = a;
			this->m[1] = b;
			this->m[2] = c;
			this->m[3] = d;
			this->m[4] = e;
			this->m[5] = f;
			this->m[6] = g;
			this->m[7] = h;
			this->m[8] = i;
			this->m[9] = j;
			this->m[10] = k;
			this->m[11] = l;
			this->m[12] = m;
			this->m[13] = n;
			this->m[14] = o;
			this->m[15] = p;
		} 
		_mat4(const _mat4<T>& m) {
			for(int i = 0; i < 16; i++) {
				this->m[i] = m[i];
			} 
		};
		_mat4(T* arr) {
			for(int i = 0; i < 16; i++) {
				this->m[i] = arr[i];
			} 
		};
		T& operator[](uint32_t index) { 
			return m[index];
		}
		const T& operator[](uint32_t index) const { 
			return m[index];
		}

		template<typename U>
		operator _mat4<U>()  {
			return _mat4<U> (m);
		}

		//multiplication
		_mat4<T> operator*=(const _mat4<T>& other) {
			this->m[0] = this->m[0]*other[0] + this->m[4]*other[1] + this->m[8]*other[2] + this->m[12]*other[3];
			this->m[1] = this->m[1]*other[0] + this->m[5]*other[1] + this->m[9]*other[2] + this->m[13]*other[3];
			this->m[2] = this->m[2]*other[0] + this->m[6]*other[1] + this->m[10]*other[2] + this->m[14]*other[3];
			this->m[3] = this->m[3]*other[0] + this->m[7]*other[1] + this->m[11]*other[2] + this->m[15]*other[3];

			this->m[4] = this->m[0]*other[4] + this->m[4]*other[5] + this->m[8]*other[6] + this->m[12]*other[7];
			this->m[5] = this->m[1]*other[4] + this->m[5]*other[5] + this->m[9]*other[6] + this->m[13]*other[7];
			this->m[6] = this->m[2]*other[4] + this->m[6]*other[5] + this->m[10]*other[6] + this->m[14]*other[7];
			this->m[7] = this->m[3]*other[4] + this->m[7]*other[5] + this->m[11]*other[6] + this->m[15]*other[7];

			this->m[8] = this->m[0]*other[8] + this->m[4]*other[9] + this->m[8]*other[0] + this->m[12]*other[11];
			this->m[9] = this->m[1]*other[8] + this->m[5]*other[9] + this->m[9]*other[0] + this->m[13]*other[11];
			this->m[10] = this->m[2]*other[8] + this->m[6]*other[9] + this->m[10]*other[0] + this->m[14]*other[11];
			this->m[11] = this->m[3]*other[8] + this->m[7]*other[9] + this->m[11]*other[0] + this->m[15]*other[11];

			this->m[12] = this->m[0]*other[12] + this->m[4]*other[13] + this->m[8]*other[14] + this->m[12]*other[15];
			this->m[13] = this->m[1]*other[12] + this->m[5]*other[13] + this->m[9]*other[14] + this->m[13]*other[15];
			this->m[14] = this->m[2]*other[12] + this->m[6]*other[13] + this->m[10]*other[14] + this->m[14]*other[15];
			this->m[15] = this->m[3]*other[12] + this->m[7]*other[13] + this->m[11]*other[14] + this->m[15]*other[15];
			return *this;
		}

		_mat4<T> operator*(const _mat4<T>& m) {
			return _mat4<T> (*this) *= m;
		}
		_mat4<T> operator*(const _mat4<T>& m) const{
			_mat4<T> out (*this);
			return out *= m;
		}

	}; //struct _mat4

	template<typename T>
	_mat4<T> makeIdentityMat4() { return _mat4<T> (1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);}

	template<typename T>
	_mat4<T> modelToWorld(_vec3<T> trans) {
		_mat4<T> out = makeIdentityMat4<T>();
		out.m[3] = trans.x; out.m[7] = trans.y; out.m[11] = trans.z;
		return out;
	}
	template<typename T>
	_mat4<T> worldFromModel(_vec3<T> trans) {
		_mat4<T> out = makeIdentityMat4<T>();
		out.m[12] = trans.x; out.m[13] = trans.y; out.m[14] = trans.z;
		return out;
	}
	template<typename T>
	_mat4<T> worldToView(_vec3<T> eye, float pitch, float yaw ) {
		_mat4<T> out = makeIdentityMat4<T>();
		float pitchRad = pitch * M_PI / 180;
		float yawRad = yaw * M_PI / 180;
		float cosPitch = cos(pitchRad);
		float sinPitch = sin(pitchRad);
		float cosYaw = cos(yawRad);
		float sinYaw = sin(yawRad);

		_vec3<T> xaxis = {cosYaw, 0, -sinYaw};
		_vec3<T> yaxis = {sinYaw * sinPitch, cosPitch, cosYaw * sinPitch};
		_vec3<T> zaxis = {sinYaw * cosPitch, -sinPitch, cosPitch * cosYaw};

		out[0] = xaxis.x; out[4] = yaxis.x; out[8] = zaxis.x;  out[12] = 0;
		out[1] = xaxis.y; out[5] = yaxis.y; out[9] = zaxis.y;  out[13] = 0;
		out[2] = xaxis.z; out[6] = yaxis.z; out[10] = zaxis.z; out[14] = 0;
		out[3] = -xaxis.dot(eye); out[7] = -yaxis.dot(eye); out[11] = -zaxis.dot(eye); out[15] = 1;

		return out;
	}
	template<typename T>
	_mat4<T> viewToProj(float fovDegrees, float aspectRatio, float near, float far) {
		_mat4<T> out = makeIdentityMat4<T>();
		float scale = 1 / tan(fovDegrees * 0.5 * M_PI / 180);
		out.m[0] = scale * aspectRatio;
		out.m[5] = scale;
		out.m[10] = -far / (far - near);
		out.m[11] = -far * near / (far - near);
		out.m[14] = -1;
		out.m[15] = 0;
		return out;
	}
	template<typename T>
	_mat4<T> projFromView(float fovDegrees, float aspectRatio, float near, float far) {
		_mat4<T> out = makeIdentityMat4<T>();
		float scale = 1 / tan(fovDegrees * 0.5 * M_PI / 180);
		out.m[0] = scale * aspectRatio;
		out.m[5] = scale;
		out.m[10] = -far / (far - near);
		out.m[14] = -far * near / (far - near);
		out.m[11] = -1;
		out.m[15] = 0;
		return out;
	}

	template<typename T>
	_vec4<T> operator*(const _vec4<T>& v, const _mat4<T>& m) {
		return _vec4<T>(v.x * m[0] + v.y * m[4] + v.z * m[8] + v.w * m[12],
						v.x * m[1] + v.y * m[5] + v.z * m[9] + v.w * m[13],
						v.x * m[2] + v.y * m[6] + v.z * m[10] + v.w * m[14],
						v.x * m[3] + v.y * m[7] + v.z * m[11] + v.w * m[15]);
	}

template<typename T>
std::ostream& operator<<(std::ostream& os, const _mat4<T>& m)  {
	for(int i = 0; i < 15; i++) {
		os << m[i] << ", ";
	}
	os << m[15];
    return os;
}

//aliases
using bmat4 = _mat4<bool>;
using cmat4 = _mat4<uint8_t>;
using imat4 = _mat4<int32_t>;
using umat4 = _mat4<uint32_t>;
using mat4 = _mat4<float>;
using dmat4 = _mat4<double>;

}	//namespace vmath
