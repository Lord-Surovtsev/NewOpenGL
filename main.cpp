#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#define GLX_GLXEXT_PROTOTYPES
#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glx.h>

#include <iostream>
using namespace std;

#include <GL/glut.h>

//#include <eigen3/Eigen/Dense>
//using namespace Eigen;

float vertices[] = {
     0.0f,  0.5f, // Vertex 1 (X, Y)
     0.5f, -0.5f, // Vertex 2 (X, Y)
    -0.5f, -0.5f  // Vertex 3 (X, Y)
};

int main(int argc, char* argv[])
{
//    MatrixXd m(2, 2);
//    m(0, 0) = 3;
//    m(1, 0) = 2.5;
//    m(0, 1) = -1;
//    m(1, 1) = m(1, 0) + m(0, 1);

//    cout << m << endl;
//    cout << m * m << endl;

//    Matrix3f A;
//    Vector3f b;
//    A << 1,2,3,  4,5,6,  7,8,10;
//    b << 3, 3, 4;
//    cout << "Here is the matrix A:\n" << A << endl;
//    cout << "Here is the vector b:\n" << b << endl;
//    Vector3f x = A.colPivHouseholderQr().solve(b);
//    cout << "The solution is:\n" << x << endl;

//    // Specify prototype of function
//    typedef void (*GENBUFFERS) (GLsizei, GLuint*);

//    //// Load address of function and assign it to a function pointer
//    //GENBUFFERS glGenBuffers = (GENBUFFERS)wglGetProcAddress("glGenBuffers");
//    // or Linux:
//    GENBUFFERS glGenBuffers = (GENBUFFERS)glXGetProcAddress((const GLubyte *) "glGenBuffers");
//    //// or OSX:
//    //GENBUFFERS glGenBuffers = (GENBUFFERS)NSGLGetProcAddress("glGenBuffers");

//    // Call function as normal
//    GLuint buffer;
//    glGenBuffers(1, &buffer);

//    sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Close);

    cout << "aaa" << endl;
    sf::sleep(sf::seconds(1.f));
    cout << "bbb" << endl;

    return 0;
}
