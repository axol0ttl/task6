#include <iostream>
#include <thread>
#include <chrono>

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <GLFW/glfw3.h>

#include "graphlib.h"

#define PI       3.14159
#define VX(X)    (((X)*2-Width)/Width)
#define VY(Y)    (((Y)*2-Height)/Height)
#define SLEEP(X) {glfwPollEvents(); std::this_thread::sleep_for(std::chrono::milliseconds(X));}

GLFWwindow* window;
int Width, Height;

void drawLine(float x0, float y0,float x1, float y1) {
  glBegin(GL_LINES);
  glVertex2f(VX(x0),VY(y0)); 
  glVertex2f(VX(x1),VY(y1)); 
  glEnd();
}

#define G2P(X) (((X)*2*PI)/360)

void drawArc(float cx, float cy, float r, float start_angle, float end_angle, int num_segments) {
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= num_segments; i++) {
        float theta = G2P(start_angle) + (float(i) / num_segments) * G2P(end_angle - start_angle);
        glVertex2f(VX(cx + r * cosf(theta)), VY(cy + r * sinf(theta)));
    }
    glEnd();
}

#define NLINES 1000
struct ZLine{
  int   state; // 0 - no, 1 - pass, 2 - active
  float r,g,b;
  float x0,y0,x1,y1;
}; 
ZLine ALines[NLINES];

void draw_line(float _x0,float _y0,float _x1,float _y1,float _r,float _g,float _b){
  int i=0;
  ZLine *pl=&ALines[0];
  for(i=0;i<NLINES;i++){
    pl=&ALines[i];
    if(pl->state == 0) break;
    if(pl->state == 1) continue;
    if(pl->x0 != _x0) continue;
    if(pl->y0 != _y0) continue;
    if(pl->x1 != _x1) continue;
    if(pl->y1 != _y1) continue;
    if(_r == 0 && _g == 0 && _b == 0){ pl->state=1; return; }
    pl->r=_r; pl->g=_g; pl->b=_b;
    return;
  }
  pl->x0=_x0; pl->y0=_y0; pl->x1=_x1; pl->y1=_y1; pl->r=_r; pl->g=_g; pl->b=_b;
  pl->state=2;
}

#define NARCS 1000

struct ZArc{
  int   state; // 0 - no, 1 - pass, 2 - active
  float r,g,b;
  float x,y,rad,s,e;
}; 
ZArc AArcs[NARCS];

 void draw_arc(float _x, float _y, float _rad, float _start, float _end, float _r, float _g, float _b){
   int i=0;
   ZArc *pl=&AArcs[0];
   for(i=0;i<NARCS;i++){
     pl=&AArcs[i];
     if(pl->state == 0) break;
     if(pl->state == 1) continue;
     if(pl->x != _x) continue;
     if(pl->y != _y) continue;
     if(pl->rad != _rad) continue;
//     if(pl->s != _start) continue;
//     if(pl->e != _end) continue;
     if(_r == 0 && _g == 0 && _b == 0){ pl->state=1; return; }
     pl->r=_r; pl->g=_g; pl->b=_b;
     return;
   }
   pl->x=_x; pl->y=_y; pl->rad=_rad; pl->s=_start; pl->e=_end; pl->r=_r; pl->g=_g; pl->b=_b;
   pl->state=2;
 }

void render_all(void){
  glColor3f(0,0,0);
  glClear(GL_COLOR_BUFFER_BIT);
  
  for(int i=0;i<NLINES;i++){
    ZLine *pl=&ALines[i];
    if(pl->state == 0) break;
    if(pl->state == 1) continue;
    glColor3f(pl->r, pl->g, pl->b);
    drawLine(pl->x0, pl->y0, pl->x1, pl->y1);
  }
  for(int i=0;i<NARCS;i++){
    ZArc *pl=&AArcs[i];
    if(pl->state == 0) break;
    if(pl->state == 1) continue;
    glColor3f(pl->r, pl->g, pl->b);  
    drawArc(pl->x, pl->y, pl->rad, pl->s, pl->e,50);
  }
  glfwSwapBuffers(window);
  glfwPollEvents();
}



void error_callback(int error, const char* description)
{
  std::cout << "Error: %s\n" << description;
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void wait4keyORmouse(void){
  render_all();
  while(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) SLEEP(5)
  while(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) SLEEP(5)
  while (!glfwWindowShouldClose(window)) {
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) return;   
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) return;
    SLEEP(10)
  }
}

int main(void){
  glfwSetErrorCallback(error_callback);
  if(!glfwInit()){ return -__LINE__; }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  window = glfwCreateWindow(1500, 800, "My Title", NULL, NULL);
  if(!window){ return -__LINE__; }
  glfwSetKeyCallback(window, key_callback);
  glfwMakeContextCurrent(window);


  glfwGetFramebufferSize(window, &Width, &Height);
  glViewport(0, 0, Width, Height);
  glClear(GL_COLOR_BUFFER_BIT);

  Main();

  glfwTerminate();
  return 0;
}