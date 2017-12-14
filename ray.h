#ifndef RAY_H
#define RAY_H
#include "rtracer.h"
#include "vec.h"
#include "scene.h"
class scene;
class ray{
public:
ray(vec3f mti, vec3f mta) : vti(mti), vta(mta)
{
}
~ray()
{
}
vec3f *tr(scene *s, int r);
vec3f gti();
vec3f gta();
vec3f gdi();
pm trp(scene *s);
private:
vec3f vti;
vec3f vta;
};
#endif 
