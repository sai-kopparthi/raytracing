#include "eye.h"
vec3f eye::gfor()
{
return qforw;
}
vec3f eye::gpos()
{
return qpos;
}
void eye::sfor(vec3f forw)
{
qforw=forw;
}
vec3f eye::gup()
{
return qup;
}
void eye::spos(vec3f pos)
{
qpos =pos;
}
void eye::sup(vec3f up)
{
qup=up;
}

