#include "sobj.h"
#include <vector>
#include <cmath>
#include <iostream>
color scene_object::pho(pm *pom, scene *sm, int rec){
color ca;
std::vector<light *>::iterator mas = sm->gli()->begin();
while(mas != sm->gli()->end()){
vec3f a, na, hit , v, rf;
a = (*mas)->gtolight(pom);
na = pom->nor;
a.norma();
na.norma();
hit = a + v;
hit = hit / hit.distance(vec3f());
rf = v.ref(na);
rf.norma();
eye e;
sm->gcam()->geteye(e);
v = e.gpos() - pom->point;
v.norma();
float alpha = aalp;
vec3f *refCol = NULL;
if(rec > 0){
ray r = ray(pom->point + rf*2.0f, pom->point + rf);
refCol = r.tr(sm, rec - 1);
(*refCol) = (*refCol)*0.8f;
}
vec3f tmpamb = (*mas)->gambi();
ca.amb = ca.amb + tmpamb*acolo.amb;
vec3f tmpdif = (*mas)->gdiffu();
ca.dif = ca.dif + tmpdif*acolo.dif*std::max(0.0f, a.dot(na));
vec3f tmpspec = (*mas)->gspecu();
ca.spec = ca.spec + tmpspec*acolo.spec*pow(std::max(0.0f, na.dot(hit)), alpha); 
if(refCol){
ca.amb = ca.amb + (*refCol);
delete refCol;
}
++mas;
}
return ca;
}
