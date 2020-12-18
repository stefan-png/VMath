//
//  Matrix.hpp
//  VulkanBP
//
//  Created by Stefan Antoszko on 2020-04-17.
//  Copyright © 2020 Stefan Antoszko. All rights reserved.
//

#pragma once
#include "Vector.hpp"
#include <cmath>

namespace vmath {
		//column major:		0, 4, 8, 12
		//					1, 5, 9, 13
		//					2, 6, 10,114
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
		_mat4(const _mat4<T>& other) {
			this->m[0] = other.m[0];
			this->m[1] = other.m[1];
			this->m[2] = other.m[2];
			this->m[3] = other.m[3];
			this->m[4] = other.m[4];
			this->m[5] = other.m[5];
			this->m[6] = other.m[6];
			this->m[7] = other.m[7];
			this->m[8] = other.m[8];
			this->m[9] = other.m[9];
			this->m[10] = other.m[10];
			this->m[11] = other.m[11];
			this->m[12] = other.m[12];
			this->m[13] = other.m[13];
			this->m[14] = other.m[14];
			this->m[15] = other.m[15];
		};
private:
		_mat4(T* m) {
			this->m[0] = m[0];
			this->m[1] = m[1];
			this->m[2] = m[2];
			this->m[3] = m[3];
			this->m[4] = m[4];
			this->m[5] = m[5];
			this->m[6] = m[6];
			this->m[7] = m[7];
			this->m[8] = m[8];
			this->m[9] = m[9];
			this->m[10] = m[10];
			this->m[11] = m[11];
			this->m[12] = m[12];
			this->m[13] = m[13];
			this->m[14] = m[14];
			this->m[15] = m[15];
		};
public:
		T operator[](uint32_t index) { 
			return m[index];
		}

		template<typename U>
		operator _mat4<U>()  {
			std::cout << "casted type!" << std::endl;
			return _mat4<U> (m);
		}
	}; //struct _mat4

	template<typename T>
	_mat4<T> makeIdentityMat4() { return _mat4<T> ({1, 0, 0, 0, 
													0, 1, 0, 0, 
													0, 0, 1, 0, 
													0, 0, 0, 1});}

	template<typename T>
	_mat4<T> modelToWorld(_vec3<T> trans) {
		_mat4<T> out = makeIdentityMat4();
		out.m[3] = trans.x; out.m[7] = trans.y; out.m[11] = trans.z;
		return out;
	}
	template<typename T>
	_mat4<T> worldFromModel(_vec3<T> trans) {
		_mat4<T> out = makeIdentityMat4();
		out.m[12] = trans.x; out.m[13] = trans.y; out.m[14] = trans.z;
		return out;
	}
	template<typename T>
	_mat4<T> worldToView(_vec3<T> eye, float pitch, float yaw ) {
		_mat4<T> out = makeIdentityMat4();
		float pitchRad = pitch * M_PI / 180;
		float yawRad = yaw * M_PI / 180;
		float cosPitch = cos(pitchRad);
		float sinPitch = sin(pitchRad);
		float cosYaw = cos(yawRad);
		float sinYaw = sin(yawRad);

		Vec3 xaxis = {cosYaw, 0, -sinYaw};
		Vec3 yaxis = {sinYaw * sinPitch, cosPitch, cosYaw * sinPitch};
		Vec3 zaxis = {sinYaw * cosPitch, -sinPitch, cosPitch * cosYaw};

		out[0] = xaxis.x; out[4] = yaxis.x; out[8] = zaxis.x;  out[12] = 0;
		out[1] = xaxis.y; out[5] = yaxis.y; out[9] = zaxis.y;  out[13] = 0;
		out[2] = xaxis.z; out[6] = yaxis.z; out[10] = zaxis.z; out[14] = 0;
		out[3] = -xaxis.dot(eye); out[7] = -yaxis.dot(eye); out[11] = -zaxis.dot(eye); out[15] = 1;

		return out;
	}
	template<typename T>
	_mat4<T> viewToProj(float fovDegrees, float aspectRatio, float near, float far) {
		_mat4<T> out = makeIdentityMat4();
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
		_mat4<T> out = makeIdentityMat4();
		float scale = 1 / tan(fovDegrees * 0.5 * M_PI / 180);
		out.m[0] = scale * aspectRatio;
		out.m[5] = scale;
		out.m[10] = -far / (far - near);
		out.m[14] = -far * near / (far - near);
		out.m[11] = -1;
		out.m[15] = 0;
		return out;
	}

//aliases
using bmat4 = _mat4<bool>;
using cmat4 = _mat4<uint8_t>;
using imat4 = _mat4<int32_t>;
using umat4 = _mat4<uint32_t>;
using mat4 = _mat4<float>;
using dmat4 = _mat4<double>;

}	//namespace vbp
