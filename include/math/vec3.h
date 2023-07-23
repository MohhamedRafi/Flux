class vec3 {
public:
	vec3(); 
	vec3(float x, float y, float z); 
	vec3(const vec3& v);


public:
	/**
	* Math operations for vec3
	*/
	vec3 add(const vec3& a, const vec3& b);
	vec3 subtract(const vec3& a, const vec3& b);
	vec3 scale(const vec3& a, float b);

	float dot(const vec3& a, const vec3& b);

public:
	/**
	* operator definitions
	*/
	vec3 operator+(const vec3& b);
	vec3 operator-(const vec3& b); 
	vec3 operator*(float b);
	float operator*(const vec3& b);

private:
	float m_vec[3]; 
};