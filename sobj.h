#ifndef Scene_object_H
#define Scene_object_H
#include "rtracer.h"
#include "vec.h"
#include "ray.h"
#include "scene.h"
class ray;
class scene;
class  scene_object{
protected:
color acolo;
float aalp;	
public:
scene_object(color mcolo, float malp): acolo(mcolo), aalp(malp){
}
virtual color pho(pm *i, scene *, int );
virtual pm inter(ray *, scene *) = 0;	
};
#endif 
