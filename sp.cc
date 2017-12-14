#include "sp.h"
#include <cmath>
#include <limits>
sp::sp(vec3f mc, float mrad, color mcol, float malp) :
scene_object(mcol, malp), cent(mc), rad(mrad)
{
}
sp::~sp()
{
}
pm sp::inter(ray *r, scene *s){
vec3f dst = r->gta() - cent;
pm p;
float bisc=dst.dot(r->gdi());
float cop= dst.dot(dst)-pow(rad, 2);
float dam= bisc*bisc-cop;
if(dam > 0){
p.h = true;
p.di = (-bisc - sqrt(dam));
p.point = r->gta() + r->gdi()*p.di;
p.nor = p.point - cent;
}
else
{
p.h = false;
p.di = std::numeric_limits<float>::infinity();
}
return p;
}
