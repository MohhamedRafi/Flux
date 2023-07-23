#include "math/vec3.h"

/** Default Constructor **/
vec3::vec3() : m_vec{ 0,0,0 }  { }
vec3::vec3(float x, float y, float z) : m_vec{x,y,z} { }

/** Copy Constructor **/
vec3::vec3(vec3& v) : m_vec{ v.m_vec[0],v.m_vec[1],v.m_vec[2] } { }

/**
* Math operations (explict functions) 
*/

