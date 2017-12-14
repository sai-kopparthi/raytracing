#include "vec.h"
#include <ostream>
#include <cmath>
#include <sstream>
#include <string>
vec3f vec3f::operator+ (const vec3f& ha) const{
	vec3f temper;
	temper[0] = ha[0]+veca[0];
	temper[1] = ha[1]+veca[1];
	temper[2] = ha[2]+veca[2];
	return temper;
}

vec3f vec3f::operator- (const vec3f& s) const{
	vec3f temper;
	temper[0] = veca[0]-s[0];
	temper[1] = veca[1]-s[1];
	temper[2] = veca[2]-s[2];
	return temper;
}
vec3f vec3f::operator* (float b) const{
	vec3f a;
	a[0] = veca[0]*b;
	a[1] = veca[1]*b;
	a[2] = veca[2]*b;
	return a;
}
vec3f vec3f::operator* (vec3f ac) const{
	vec3f tempor;
	tempor[0] = veca[0]*ac[0];
	tempor[1] = veca[1]*ac[1];
	tempor[2] = veca[2]*ac[2];
	return tempor;
}
vec3f& vec3f::operator=(const vec3f& vece){
	veca[0] = vece[0];
	veca[1] = vece[1];
	veca[2] = vece[2];
	return *this;
}
vec3f vec3f::operator/(float ma) const{
	vec3f temper;
	temper[0] = veca[0]/ma;
	temper[1] = veca[1]/ma;
	temper[2] = veca[2]/ma;
	return temper;
}
float vec3f::operator[](const int i) const{
	return veca[i];
}
float& vec3f::operator[](const int i){
	return veca[i];
}
vec3f vec3f::cross(const vec3f& v) const{
	vec3f temp;
	temp[0] = veca[1]*v[2]-veca[2]*v[1];
	temp[1] = veca[2]*v[0]-veca[0]*v[2];
	temp[2] = veca[0]*v[1]-veca[1]*v[0];
	return temp;
}

float vec3f::dot(const vec3f& va) const{
	return veca[0]*va[0] + veca[1]*va[1] + veca[2]*va[2];
}

float vec3f::distance(const vec3f& va) const{
	return sqrt(pow(veca[0]-va[0], 2)+pow(veca[1]-va[1], 2)+pow(veca[2]-va[2], 2));
}
void vec3f::norma(){
	float mo = this->distance(vec3f());
	(*this) = (*this)*(1/mo);
}
vec3f vec3f::ref(const vec3f& v) const{
	vec3f tempor;
	float tmp = 2.0 * (v.dot((*this)));
	tempor = (*this)*tmp - v;
	return tempor;
}
std::string vec3f::colorPrint(){
	std::ostringstream o;
	o << std::max(std::min(static_cast<int>(veca[0]*255), 255), 0) << " " << std::max(std::min(static_cast<int>(veca[1]*255), 255), 0) << " " << std::max(std::min(static_cast<int>(veca[2]*255), 255), 0);
	return o.str();
}
std::ostream& operator<<(std::ostream& t, const vec3f &vam){ 
	t << "[ " << vam[0] << ", " << vam[1] << ", " << vam[2] << "]"; 
	return t;
}
