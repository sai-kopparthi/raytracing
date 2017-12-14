#include "dlight.h"
#include <limits>
dlight::dlight(vec3f mdir, vec3f mambi, vec3f mdif, vec3f mspec)
: light( mambi,mdif, mspec ), dir(mdir)
{
}
vec3f dlight::gtolight(pm *p)
{
return dir;
}
ray dlight::grtolight(pm *p)
{
return ray(dir, vec3f(0.0f, 0.0f, 0.0f));
}
float dlight::gdtolight(pm *p)
{
return std::numeric_limits<float>::infinity();
}
