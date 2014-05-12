//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>

//#define GLX_GLXEXT_PROTOTYPES
////#define GLEW_STATIC
//#include <GL/glew.h>
//#include <GL/glx.h>

//#include <iostream>
//using namespace std;

//#include <GL/glut.h>

////#include <eigen3/Eigen/Dense>
////using namespace Eigen;

//float vertices[] = {
//     0.0f,  0.5f, // Vertex 1 (X, Y)
//     0.5f, -0.5f, // Vertex 2 (X, Y)
//    -0.5f, -0.5f  // Vertex 3 (X, Y)
//};

//int main(int argc, char* argv[])
//{
////    MatrixXd m(2, 2);
////    m(0, 0) = 3;
////    m(1, 0) = 2.5;
////    m(0, 1) = -1;
////    m(1, 1) = m(1, 0) + m(0, 1);

////    cout << m << endl;
////    cout << m * m << endl;

////    Matrix3f A;
////    Vector3f b;
////    A << 1,2,3,  4,5,6,  7,8,10;
////    b << 3, 3, 4;
////    cout << "Here is the matrix A:\n" << A << endl;
////    cout << "Here is the vector b:\n" << b << endl;
////    Vector3f x = A.colPivHouseholderQr().solve(b);
////    cout << "The solution is:\n" << x << endl;

////    // Specify prototype of function
////    typedef void (*GENBUFFERS) (GLsizei, GLuint*);

////    //// Load address of function and assign it to a function pointer
////    //GENBUFFERS glGenBuffers = (GENBUFFERS)wglGetProcAddress("glGenBuffers");
////    // or Linux:
////    GENBUFFERS glGenBuffers = (GENBUFFERS)glXGetProcAddress((const GLubyte *) "glGenBuffers");
////    //// or OSX:
////    //GENBUFFERS glGenBuffers = (GENBUFFERS)NSGLGetProcAddress("glGenBuffers");

////    // Call function as normal
////    GLuint buffer;
////    glGenBuffers(1, &buffer);

////    sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Close);

////    cout << "aaa" << endl;
////    sf::sleep(sf::seconds(1.f));
////    cout << "bbb" << endl;
//    // Specify prototype of function
//    typedef void (*GENBUFFERS) (GLsizei, GLuint*);

//    //// Load address of function and assign it to a function pointer
//    GENBUFFERS glGenBuffers = (GENBUFFERS)glXGetProcAddress((const GLubyte *) "glGenBuffers");

//    GLuint vbo;
//    glGenBuffers(1, &vbo);

//    glDrawArrays(GL_TRIANGLES, 0, 3);
//    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//    return 0;
//}


// Link statically with GLEW
#define GLEW_STATIC

// Headers
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <iostream>

// Shader sources
const GLchar* vertexSource =
    "#version 150 core\n"
    "in vec2 position;"
    "void main() {"
    "   gl_Position = vec4(position, 0.0, 1.0);"
    "}";
const GLchar* fragmentSource =
    "#version 150 core\n"
    "out vec4 outColor;"
    "void main() {"
    "   outColor = vec4(1.0, 1.0, 1.0, 1.0);"
    "}";

int main()
{
    sf::Window window(sf::VideoMode(800, 600, 32), "OpenGL", sf::Style::Titlebar | sf::Style::Close);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    glewInit();

    // Create Vertex Array Object
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create a Vertex Buffer Object and copy the vertex data to it
    GLuint vbo;
    glGenBuffers(1, &vbo);

    GLfloat vertices[] = {
        0.0f, 0.5f,
        0.5f, -0.5f,
        -0.5f, -0.5f
    };

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Create and compile the vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    // Create and compile the fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    // Link the vertex and fragment shader into a shader program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glBindFragDataLocation(shaderProgram, 0, "outColor");
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    // Specify the layout of the vertex data
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

    while (window.isOpen())
    {
        sf::Event windowEvent;
        while (window.pollEvent(windowEvent))
        {
            switch (windowEvent.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw a triangle from the 3 vertices
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap buffers
        window.display();
    }

    glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);

    glDeleteBuffers(1, &vbo);

    glDeleteVertexArrays(1, &vao);
}
