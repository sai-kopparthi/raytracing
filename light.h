#ifndef LIGHT_H
#define LIGHT_H
#include "rtracer.h"
#include "ray.h"
class ray;
class light{
private:
protected:
vec3f xspec;
vec3f xamb;
vec3f xdif;	
public:
light(vec3f, vec3f, vec3f);
~light();
vec3f gspecu();
vec3f gdiffu();
vec3f gambi();
virtual ray grtolight(pm *p)=0;
virtual float gdtolight(pm *p)=0;
virtual vec3f gtolight(pm *p)=0;
};
#endif 
