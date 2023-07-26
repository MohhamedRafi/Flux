#include "math/vec3.h"

namespace flux {
	/** Default Constructor **/
	vec3::vec3() : m_vec{ 0,0,0 } {}
	vec3::vec3(float x, float y, float z) : m_vec{ x,y,z } {}

	/** Copy Constructor **/
	vec3::vec3(const vec3& v) : m_vec{ v.m_vec[0],v.m_vec[1],v.m_vec[2] } {}

	/**
	* Math operations (explict functions)
	*/
	vec3 vec3::scale(const vec3& a, float b) {
		return vec3(a.m_vec[0] * b,
			a.m_vec[1] * b,
			a.m_vec[2] * b);
	}

	vec3 vec3::add(const vec3& a, const vec3& b) {
		return vec3(a.m_vec[0] + b.m_vec[0],
			a.m_vec[1] + b.m_vec[1],
			a.m_vec[2] + b.m_vec[2]);
	}

	vec3 vec3::subtract(const vec3& a, const vec3& b) {
		return add(a, scale(b, -1));
	}

	float vec3::dot(const vec3& a, const vec3& b) {
		return a.m_vec[0] * b.m_vec[0] +
			a.m_vec[1] * b.m_vec[1] +
			a.m_vec[2] * b.m_vec[2];
	}

	float vec3::norm() {
		return  std::sqrt(m_vec[0]*m_vec[0] +
			m_vec[1]*m_vec[1] +
			m_vec[2]*m_vec[2]);
	}

	float vec3::x() const {
		return m_vec[0];
	}

	float vec3::y() const {
		return m_vec[1];
	}

	float vec3::z() const {
		return m_vec[2];
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