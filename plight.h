#ifndef PLIGHT_H
#define PLIGHT_H
#include "light.h"
class plight : public light{
private:
protected:
vec3f mp;
public:
vec3f gtolight(pm *p);
ray grtolight(pm *p);
plight(vec3f apoin, vec3f aamb, vec3f adif, vec3f aspec);	
float gdtolight(pm *p);	
};
#endif 
