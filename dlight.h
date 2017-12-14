#ifndef DLIGHT_H
#define DLIGHT_H
#include "light.h"
class dlight : public light{
protected:
vec3f dir;
public:
dlight(vec3f mdir, vec3f mambi, vec3f mdif, vec3f mspec);
vec3f gtolight(pm *p);
float gdtolight(pm *p);
ray grtolight(pm *p);
};
#endif
