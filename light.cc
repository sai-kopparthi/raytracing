#include "light.h"
light::light(vec3f amb, vec3f dif, vec3f spec): xamb(amb), xdif(dif), xspec(spec)
{
}
light::~light(){
}
vec3f light::gambi()
{
return xamb;
}
vec3f light::gdiffu()
{
return xdif;
}
vec3f light::gspecu()
{
return xspec;
}

