#include <string>
#include <iostream>
#include <fstream>
#include "vec.h"
#include "scene.h"
#include "light.h"
#include "plight.h"
#include "dlight.h"
#include "sobj.h"
#include "sp.h"
#include "cam.h"
#include "eye.h"
#include "ray.h"
std::ofstream ppmfile;
void init_scene(scene *, int, int);
vec3f *tpixelstd(vec3f pos, cam *c, float phight, float pwidth, scene *am, int index);
void rtrace(int xp, int yp, scene *am, vec3f *(*tracep) (vec3f, cam *, float, float, scene *, int), int index);
void init_scene(scene *p, int xp, int yp)
{
cam *c = new cam(vec3f(0.0f, 0.0f, -40.0f), vec3f(0.0f, 1.0f, 0.0f), vec3f(0.0f, 0.0f, -1.0f), xp, yp , 3.0f); 
plight *l1 = new plight(vec3f(0.0f, 0.0f, -100.0f), vec3f(0.1f, 0.1f, 0.1f), vec3f(0.2f, 0.2f, 0.2f), vec3f(0.8f, 0.8f, 0.8f));
dlight *l2 = new dlight(vec3f(0.5f, 0.5f, 0.0f), vec3f(0.2f, 0.05f, 0.05f), vec3f(0.4f, 0.1f, 0.1f), vec3f(0.8f, 0.6f, 0.6f));
sp *s1 = new sp(vec3f(15.0f, 0.0f, 10.0f), 5.0f, color(vec3f(0.4f, 0.0f, 0.3f), vec3f(0.5f, 0.0f, 0.0f), vec3f(0.8f, 0.8f, 0.8f)), 500.0f);
sp *s2 = new sp(vec3f(-1.0f, 0.0f, 0.0f), 5.0f,	color(vec3f(0.0f, 0.0f, 0.4f), vec3f(0.0f, 0.0, 0.6f), vec3f(0.3f, 0.3f, 0.3f)), 500.0f);
sp *s3 = new sp(vec3f(0.0f, 12.0f, 2.0f), 5.0f,	color(vec3f(0.0f, 0.4f, 0.0f), vec3f(0.0f, 0.0, 0.6f), vec3f(0.3f, 0.3f, 0.3f)), 500.0f);
p->scamera(c);
p->addli(l1);
p->addli(l2);
p->addsobj(s1);
p->addsobj(s2);
p->addsobj(s3);
}
int main(int argc, char **argv)
{
scene *am = new scene();
int xp = 500, yp = 500;
init_scene(am, xp, yp);
ppmfile.open("raytracer.ppm");	
ppmfile<<"P3"<<std::endl<<xp<<" "<<yp<<std::endl<< 255<<std::endl;
int ac;
printf("enter the depth of recursion");
scanf("%d",&ac);
rtrace(xp,yp,am,tpixelstd,ac);
delete am;
return 0;
}
void rtrace(int xp, int yp, scene *am, vec3f *(*tracep) (vec3f, cam *, float, float, scene *, int), int index)
{
cam *c;
c = am->gcam();
vec3f ***pixels = new vec3f **[yp];
for(int i = 0; i < yp; i++)
pixels[i] = new vec3f *[xp];
float pixelHeight = c->getph();
float pixelWidth = c->getwd();
for(int i = 0; i < yp; i++)
	{
		for(int j = 0; j < xp; j++)
		{
				pixels[i][j] = tracep(c->getpos(j, i), c, pixelHeight, pixelWidth, am, index);
				ppmfile << pixels[i][j]->colorPrint() << " ";
				delete pixels[i][j];
		}
		delete [] pixels[i];
		ppmfile << std::endl;
	}
	delete [] pixels;
}
vec3f *tpixelstd(vec3f pos, cam *c, float phight, float pWidth, scene *am, int index)
{
eye e;
c->geteye(e);
ray *r = new ray(pos, e.gpos());
vec3f *v = r->tr(am,index);
delete r;
return v;
}
