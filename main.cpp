#define GLX_GLXEXT_PROTOTYPES
//#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glx.h>

//#ifdef LINUX
//#define GLX_GLXEXT_PROTOTYPES
//#include <GL/glx.h>
//#define wglxGetProcAddress(a) glXGetProcAddressARB((const GLubyte *) (a))
//#endif

#include <iostream>
using namespace std;

#include <GL/glut.h>
#include <SFML/System.hpp>

//extern void (*glXGetProcAddressARB(const GLubyte *))();

int main(int argc, char* argv[])
{
    // Specify prototype of function
    typedef void (*GENBUFFERS) (GLsizei, GLuint*);

    //// Load address of function and assign it to a function pointer
    //GENBUFFERS glGenBuffers = (GENBUFFERS)wglGetProcAddress("glGenBuffers");
    // or Linux:
    GENBUFFERS glGenBuffers = (GENBUFFERS)glXGetProcAddress((const GLubyte *) "glGenBuffers");
    //// or OSX:
    //GENBUFFERS glGenBuffers = (GENBUFFERS)NSGLGetProcAddress("glGenBuffers");

    // Call function as normal
    GLuint buffer;
    glGenBuffers(1, &buffer);


    cout << "aaa" << endl;
    sf::sleep(sf::seconds(1.f));
    cout << "bbb" << endl;
    return 0;
}
