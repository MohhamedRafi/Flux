class vec3 {
public:
	vec3(); 
	vec3(float x, float y, float z); 
	vec3(vec3& v);


public:
	/**
	* Math operations for vec3
	*/
	vec3 add(vec3 a, vec3 b);
	vec3 subtract(vec3 a, vec3 b);
	vec3 dot(vec3 a, vec3 b);
	vec3 scale(vec3 a, float b);



private:
	float m_vec[3]; 
};