#include "math/vec3.h"
#include <algorithm>
#include <exception>

namespace flux {
	/** Default Constructor **/
	vec3::vec3() : m_arr{ 0,0,0 } {}
	vec3::vec3(float x, float y, float z) : m_arr{ x,y,z } {}

	vec3::vec3(const std::initializer_list<float>& list) {
		if (list.size() != 3) {
			throw std::exception(); 
		}

		std::copy(list.begin(), list.end(), m_arr);
	}

	/** Copy Constructor **/
	vec3::vec3(const vec3& v) : m_arr{ v.m_arr[0],v.m_arr[1],v.m_arr[2] } {}

	/**
	* Math operations (explict functions)
	*/
	vec3 vec3::scale(const vec3& a, float b) {
		return vec3(a.m_arr[0] * b,
			a.m_arr[1] * b,
			a.m_arr[2] * b);
	}

	vec3 vec3::add(const vec3& a, const vec3& b) {
		return vec3(a.m_arr[0] + b.m_arr[0],
			a.m_arr[1] + b.m_arr[1],
			a.m_arr[2] + b.m_arr[2]);
	}

	vec3 vec3::subtract(const vec3& a, const vec3& b) {
		return add(a, scale(b, -1));
	}

	float vec3::dot(const vec3& a, const vec3& b) {
		return a.m_arr[0] * b.m_arr[0] +
			a.m_arr[1] * b.m_arr[1] +
			a.m_arr[2] * b.m_arr[2];
	}

	float vec3::norm() {
		return  std::sqrt(m_arr[0]*m_arr[0] +
			m_arr[1]*m_arr[1] +
			m_arr[2]*m_arr[2]);
	}

	float vec3::x() const {
		return m_arr[0];
	}

	float vec3::y() const {
		return m_arr[1];
	}

	float vec3::z() const {
		return m_arr[2];
	}

	vec3 vec3::operator+(const vec3& b) {
		return add(*this, b);
	}

	vec3 vec3::operator-(const vec3& b) {
		return subtract(*this, b);
	}

	vec3 vec3::operator*(float b) {
		return scale(*this, b);
	}

	float vec3::operator*(const vec3& b) {
		return dot(*this, b);
	}

	bool vec3::operator==(const vec3& b) const {
		return (this->x() == b.x()) && (this->y() == b.y()) && (this->z() == b.z());
	}

	std::ostream& operator<<(std::ostream& os, const vec3& b) {
		os << "(" << b.x() << "," << b.y() << "," << b.z() << ")";
		return os;
	}

	vec3 flux::operator*(float b, const vec3& a) {
		return vec3::scale(a, b);
	}
}