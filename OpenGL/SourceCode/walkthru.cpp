#include <GL/glew.h>
#include "math_3d.h"
using namespace std;

GLenum res=glewInit();
if(res!=GLEW_OK)
{
  fprintf(stderr, "Error:'%s\n'", glewGetErrorString(res));
  return 1;
}

Vector3f Vertices[1];
//We create an array of one Vector3f structures (this type is defined in math_3d.h) and initialize XYZ to be zero. This will make the dot appear at the middle of the screen.
Vertices[0]=Vector3f(0.0f,0.0f,0.0f);

GLuint VBO;
glGenBuffers(1,&VBO);
glBindBuffer(GL_ARRAY_BUFFER,VBO);
glBufferData(GL_ARRAY_BUFFER,sizeof(Vertices),Vertices,GL_STATIC_DRAW);
glEnableVertexAttribArray(0);
glBindBuffer(GL_ARRAY_BUFFER,VBO);

glVertexAtttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
glDrawArrays(GL_POINTS,0,1);
glDisableVertexAttribArray(0);
