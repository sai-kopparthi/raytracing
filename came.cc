#include "cam.h"
#include <iostream>
cam::~cam(){	
}
void cam::geteye(eye &e){
e = aeye;
}
vec3f cam::getpos(int a, int v){
float xr = static_cast<float>(a) / static_cast<float>(ab);
float yr = static_cast<float>(v) / static_cast<float>(ip);
vec3f xdif = vtr - vtl;
vec3f ydif = vtl - vbl;
return vbl + (xdif * xr) + (ydif * yr);
}
float cam::getph(){
return fh / ip;	
}
float cam::getwd(){
return fw / ab;
}
void cam::setdis(float pd){
distan = pd;
rplane();
}
void cam::seteye(eye peye){
aeye= peye;
rplane();
}
void cam::rplane(){
float sc = 1.0f;
aeye.gup().norma();
aeye.gfor().norma();
fw = static_cast<float>(ab);
fh = static_cast<float>(ip);
float tmp = std::min(fw,fh);
while(tmp > 10.0f){
sc *= 10.0f;
tmp /= 10.0f;
}
fw /= sc;
fh /= sc;
float wt = fw / 2.0f;
float ht = fh / 2.0f;
vec3f np = aeye.gpos() + aeye.gfor()*distan;
vbl =np - aeye.gup()*ht - aeye.gup().cross(aeye.gfor())*wt;
vtl = np + aeye.gup()*ht - aeye.gup().cross(aeye.gfor())*wt;
vbr =np - aeye.gup()*ht + aeye.gup().cross(aeye.gfor())*wt;
vtr =np + aeye.gup()*ht + aeye.gup().cross(aeye.gfor())*wt;
std::cout << vbl << " " << vtl << vbr << " " << vtr << std::endl;
}

