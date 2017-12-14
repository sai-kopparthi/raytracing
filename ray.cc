#include "ray.h"
#include <iostream>
#include <vector>
#include "sobj.h"
vec3f ray::gta(){
return vta;
}
vec3f ray::gti(){
return vti;
}
pm ray::trp(scene *s){
pm lo, p;
lo.h = false;
std::vector<scene_object *>::iterator a = s->gsobj()->begin();
while( a != s->gsobj()->end()){
        p = (*a)->inter(this, s);
	p.obj= (*a);
	if(p.h && (p.di < lo.di || !lo.h))
	 {
	  lo = p;
	 }
	  ++a;	
	}
 return lo;
}
vec3f *ray::tr(scene *s, int r){
pm close;
close = trp(s);
vec3f q;
if(close.h){
close.col = static_cast<scene_object *>(close.obj)->pho(&close, s, r);
q = vec3f(close.col.amb + close.col.dif + close.col.spec);
}	
return new vec3f(q);
}
vec3f ray::gdi(){
vec3f w = vti-vta;
w.norma();
return w;
}
