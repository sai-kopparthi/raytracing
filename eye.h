#ifndef EYE_H
#define EYE_H
#include "vec.h"
class eye{
private:
vec3f qpos;
vec3f qup;
vec3f qforw;
public:
eye(vec3f pos, vec3f up, vec3f forw):
qpos(pos), qup(up), qforw(forw)
{
}
eye(){}
~eye(){
}
vec3f gpos();
vec3f gup();
vec3f gfor();
void spos(vec3f );
void sup(vec3f );
void sfor(vec3f );
void sangle(float );
};
#endif 
