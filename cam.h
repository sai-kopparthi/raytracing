#ifndef CAM_H
#define CAM_H
#include "vec.h"
std::ostream& operator<<(std::ostream & o, const vec3f &v);
#include "eye.h"
#include <cmath>
class cam{
public:
cam(){}
cam(vec3f ps, vec3f puu, vec3f pfd, int xp, int yp, float pd) : distan(pd), ab(xp), ip(yp), aeye(ps, puu, pfd)
{
rplane();
}
~cam();
float getangle();
void geteye(eye &);
vec3f getpos(int x, int y);
float getph();
float getwd();
void setdis(float );
void seteye(eye );	
private:
float distan;
float fw;
float fh;
int ab;
int ip;
vec3f vbl;
vec3f vtl;
vec3f vbr;
vec3f vtr;
eye aeye;
void rplane();
};
#endif
