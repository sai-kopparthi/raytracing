#ifndef SP_H
#define SP_H

#include "rtracer.h"
#include "sobj.h"
#include "ray.h"

class sp : public scene_object{
private:
	vec3f cent;
	float rad;

public:
	sp(vec3f mc, float mrad, color mcol, float sh);
	~sp();
	pm inter(ray *, scene *);


};

#endif // SPHERE_H
