#ifndef VEC_H
#define VEC_H
#include <iostream>
class vec3f{
private:
float veca[3];
public:
vec3f(){
veca[0] = 0.0f;
veca[1] = 0.0f;
veca[2] = 0.0f;
}
vec3f(float x, float y, float z){
veca[0] = x;
veca[1] = y;
veca[2] = z;
}
vec3f(const vec3f &l){
veca[0] = l.veca[0];
veca[1] = l.veca[1];
veca[2] = l.veca[2];
}~vec3f(){}
vec3f operator-(const vec3f&) const;
vec3f operator/(float ) const;
float operator[](const int ) const;
float distance(const vec3f&) const;
vec3f ref(const vec3f&) const;
vec3f operator*(float ) const;
vec3f cross(const vec3f&) const;
float dot(const vec3f&) const;
vec3f operator*(vec3f ) const;
float& operator[](const int );
vec3f& operator=(const vec3f&);		
vec3f operator+(const vec3f&) const;
std::string colorPrint();		
void norma();
};
std::ostream& operator<<(std::ostream & o, const vec3f &v);
#endif 
