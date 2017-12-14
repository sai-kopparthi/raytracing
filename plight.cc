#include "plight.h"
#include <iostream>
plight::plight(vec3f apoin, vec3f aamb, vec3f adif, vec3f aspec)
: light( aamb, adif , aspec ), mp(apoin)
{
}
vec3f plight::gtolight(pm *pa){
return mp - pa->point;
}
ray plight::grtolight(pm *pa){
return ray(mp, pa->point);
}
float plight::gdtolight(pm *pa){
return mp.distance(pa->point);
}
