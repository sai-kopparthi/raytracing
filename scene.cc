#include "scene.h"
scene::scene()
{
}
scene::~scene(){
if(dcam)
delete dcam;
std::vector<light *>::iterator lita = dlight.begin();
while(lita != dlight.end()){
if((*lita))
delete (*lita);
++lita;
}
std::vector<scene_object *>::iterator sita = dsceneobj.begin();
while(sita != dsceneobj.end()){
if((*sita))
delete (*sita);
++sita;
}
}
void scene::addli(light *am)
{
dlight.push_back(am);
}
void scene::scamera(cam *pcam)
{
dcam = pcam;
}
void scene::addsobj(scene_object *a)
{
dsceneobj.push_back(a);
}
std::vector<scene_object *> *scene::gsobj(){
return &dsceneobj;
}
std::vector<light *> *scene::gli(){
return &dlight;
}
void scene::gcam(cam &fcam){
fcam = (*dcam);
}
cam * scene::gcam(){
return dcam;
}
