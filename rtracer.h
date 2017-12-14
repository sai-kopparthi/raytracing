#ifndef rtracer_H
#define rtracer_H
#include "vec.h"
struct ctp{
vec3f amb;
vec3f dif;
vec3f spec;
ctp(vec3f pamb, vec3f pdif, vec3f pspec) : amb(pamb), dif(pdif), spec(pspec)   {}
ctp() : amb(vec3f(0.0f,0.0f,0.0f)), dif(vec3f(0.0f,0.0f,0.0f)), spec(vec3f(0.0f,0.0f,0.0f)){}
};
struct pof{
ctp col;	
float di;
vec3f nor;
void *obj;
bool h;
vec3f point;	
};
typedef pof pm;
typedef ctp color;
#endif  
