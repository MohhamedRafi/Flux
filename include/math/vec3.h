#pragma once
#include <cmath>
#include <ostream>
#include <initializer_list>

namespace flux {
	class vec3 {
	public:
		vec3();
		vec3(const std::initializer_list<float>& list);
		vec3(float x, float y, float z);
		vec3(const vec3& v);


	public:
		/**
		* Math operations for vec3, explict functions are static as we don't need to refer to the 
		* instance variables
		*/
		static vec3 add(const vec3& a, const vec3& b);
		static vec3 subtract(const vec3& a, const vec3& b);
		static vec3 scale(const vec3& a, float b);

		static float dot(const vec3& a, const vec3& b);
		float norm();

	public:
		/**
		* Note the const after the function header, which states that any member variables won't changed during function
		* call. This is required for some operator overloads since we are passing a const vec3&. It's strange to me that
		* we have to specify this for a const ref. but it's safer regardless.
		*/
		float x() const;
		float y() const;
		float z() const;

	public:
		/**
		* operator definitions
		*/
		vec3 operator+(const vec3& b);
		vec3 operator-(const vec3& b);
		vec3 operator*(float b);
		float operator*(const vec3& b);
		bool operator==(const vec3& b) const;


		friend std::ostream& operator<<(std::ostream& os, const vec3& b);

	private:
		float m_arr[3];
	};

	vec3 operator*(float b, const vec3& a);
}