#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include "cam.h"
#include "sobj.h"
#include "light.h"
class scene_object;
class light;
class scene{
private:
cam *dcam;
std::vector<light *> dlight;
std::vector<scene_object *> dsceneobj;
public:
scene();
~scene();
void addsobj(scene_object *);
void scamera(cam *);
void addli(light *);
std::vector<scene_object *> *gsobj();
void gcam(cam &);
cam *gcam();
std::vector<light *> *gli();
};
#endif 
