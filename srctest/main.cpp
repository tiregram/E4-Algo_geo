
#include <GL/freeglut.h>
#include <GL/glew.h>
#include <iostream>

int main(int argc, char *argv[]) {

  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);

  glutCreateWindow("OPENGL LINUX");

  GLint erro = glewInit();

  if (erro != GLEW_OK) {
    std::cerr << "NO GLEW INITIALSED" << std::endl;
    exit(1);
  }
  if (!GLEW_VERSION_2_1) {
    std::cerr << "NO OPENGL 2.1 please UPDATE or by a new computer"
              << "\n"
              << "You version is " << glewGetString(GLEW_VERSION) << std::endl;
    exit(1);
  }

  // glutReshapeWindow(Glut_w, Glut_h);

  // glutReshapeFunc(reshape);
  // glutDisplayFunc(display);
  // glutKeyboardFunc(keyboard);
  // glutSpecialFunc(keyboard2);
  // glutMotionFunc(mousedrag);
  // glutMouseFunc(mouse);
  // glutMouseWheelFunc(mouseWheel);
  // glutIdleFunc(idle);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  glClearColor(1, 1, 1, 0);

  glEnable(GL_MULTISAMPLE);

  GLuint vertexshader =
      initshaders(GL_VERTEX_SHADER, "shaders/light.vert.glsl");
  GLuint fragmentshader =
      initshaders(GL_FRAGMENT_SHADER, "shaders/light.frag.glsl");
  shaderprogram = initprogram(vertexshader, fragmentshader);

  glutMainLoop();
  return 0;
}
