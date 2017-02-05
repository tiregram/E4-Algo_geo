#define GLM_FORCE_RADIANS

#include "helperFunctions.hpp"

#include "matrix.hpp"

#include <fstream>
#include <nfd/nfd.h>
#include <sstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/freeglut.h>
#include <GL/glew.h>

bool smooth = false;
bool drawmesh = true;
bool drawwireframe = false;
bool drawmeshvetrices = false;
bool drawsilhouette = false;
bool drawnormals = false;
bool drawmeshvertices = false;

GLuint shaderprogram;
// width and height of the window.
int Glut_w = 600, Glut_h = 400;

// Variables and their values for the camera setup.
myPoint3D camera_eye(0, 0, 2);
myVector3D camera_up(0, 1, 0);
myVector3D camera_forward(0, 0, -1);

float fovy = 45.0f;
float zNear = 1;
float zFar = 6000;

int frame = 0, timebase = 0;
float fps = 0;

int button_pressed = 0; // 1 if a button is currently being pressed.
int GLUTmouse[2] = {0, 0};

#define NUM_BUFFERS 10
std::vector<GLuint> buffers(NUM_BUFFERS, 0);
std::vector<GLuint> vaos(NUM_BUFFERS, 0);
unsigned int num_triangles;

void makeBuffers(myMesh *input_mesh) {
  std::vector<GLfloat> verts;
  verts.clear();
  std::vector<GLfloat> norms_per_face;
  norms_per_face.clear();
  std::vector<GLfloat> norms;
  norms.clear();
  std::vector<GLfloat> verts_and_normals;
  verts_and_normals.clear();

  num_triangles = 0;
  unsigned int index = 0;
  for (unsigned int i = 0; i < input_mesh->faces.size(); i++) {
    myHalfedge *e = input_mesh->faces[i]->adjacent_halfedge->next;
    do {
      verts.push_back(
          (GLfloat)input_mesh->faces[i]->adjacent_halfedge->source->point->X);
      verts.push_back(
          (GLfloat)input_mesh->faces[i]->adjacent_halfedge->source->point->Y);
      verts.push_back(
          (GLfloat)input_mesh->faces[i]->adjacent_halfedge->source->point->Z);
      input_mesh->faces[i]->adjacent_halfedge->source->index = index;
      index++;

      verts.push_back((GLfloat)e->source->point->X);
      verts.push_back((GLfloat)e->source->point->Y);
      verts.push_back((GLfloat)e->source->point->Z);
      e->source->index = index;
      index++;

      verts.push_back((GLfloat)e->next->source->point->X);
      verts.push_back((GLfloat)e->next->source->point->Y);
      verts.push_back((GLfloat)e->next->source->point->Z);
      e->next->source->index = index;
      index++;

      norms_per_face.push_back((GLfloat)input_mesh->faces[i]->normal->dX);
      norms_per_face.push_back((GLfloat)input_mesh->faces[i]->normal->dY);
      norms_per_face.push_back((GLfloat)input_mesh->faces[i]->normal->dZ);

      norms_per_face.push_back((GLfloat)input_mesh->faces[i]->normal->dX);
      norms_per_face.push_back((GLfloat)input_mesh->faces[i]->normal->dY);
      norms_per_face.push_back((GLfloat)input_mesh->faces[i]->normal->dZ);

      norms_per_face.push_back((GLfloat)input_mesh->faces[i]->normal->dX);
      norms_per_face.push_back((GLfloat)input_mesh->faces[i]->normal->dY);
      norms_per_face.push_back((GLfloat)input_mesh->faces[i]->normal->dZ);

      norms.push_back(
          (GLfloat)input_mesh->faces[i]->adjacent_halfedge->source->normal->dX);
      norms.push_back(
          (GLfloat)input_mesh->faces[i]->adjacent_halfedge->source->normal->dY);
      norms.push_back(
          (GLfloat)input_mesh->faces[i]->adjacent_halfedge->source->normal->dZ);

      norms.push_back((GLfloat)e->source->normal->dX);
      norms.push_back((GLfloat)e->source->normal->dY);
      norms.push_back((GLfloat)e->source->normal->dZ);

      norms.push_back((GLfloat)e->next->source->normal->dX);
      norms.push_back((GLfloat)e->next->source->normal->dY);
      norms.push_back((GLfloat)e->next->source->normal->dZ);

      num_triangles++;
      e = e->next;
    } while (e->next != input_mesh->faces[i]->adjacent_halfedge);
  }

  for (unsigned int i = 0; i < input_mesh->vertices.size(); i++) {
    verts_and_normals.push_back((GLfloat)input_mesh->vertices[i]->point->X);
    verts_and_normals.push_back((GLfloat)input_mesh->vertices[i]->point->Y);
    verts_and_normals.push_back((GLfloat)input_mesh->vertices[i]->point->Z);

    verts_and_normals.push_back(
        (GLfloat)(input_mesh->vertices[i]->point->X +
                  input_mesh->vertices[i]->normal->dX / 20.0f));
    verts_and_normals.push_back(
        (GLfloat)(input_mesh->vertices[i]->point->Y +
                  input_mesh->vertices[i]->normal->dY / 20.0f));
    verts_and_normals.push_back(
        (GLfloat)(input_mesh->vertices[i]->point->Z +
                  input_mesh->vertices[i]->normal->dZ / 20.0f));
  }

  std::vector<GLuint> indices_edges;
  for (unsigned int i = 0; i < input_mesh->halfedges.size(); i++) {
    if (input_mesh->halfedges[i] == NULL ||
        input_mesh->halfedges[i]->next->next == NULL)
      continue;
    indices_edges.push_back(input_mesh->halfedges[i]->source->index);
    indices_edges.push_back(input_mesh->halfedges[i]->next->source->index);
  }

  std::vector<GLuint> indices_vertices;
  for (unsigned int i = 0; i < input_mesh->vertices.size(); i++)
    indices_vertices.push_back(input_mesh->vertices[i]->index);

  glDeleteBuffers(NUM_BUFFERS, &buffers[0]);
  glDeleteVertexArrays(NUM_BUFFERS, &vaos[0]);

  buffers.assign(buffers.size(), 0);
  vaos.assign(vaos.size(), 0);

  glGenBuffers(NUM_BUFFERS, &buffers[0]);

  glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTICES]);
  glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(GLfloat), &verts[0],
               GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_NORMALS_PERVERTEX]);
  glBufferData(GL_ARRAY_BUFFER, norms.size() * sizeof(GLfloat), &norms[0],
               GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_NORMALS_PERFACE]);
  glBufferData(GL_ARRAY_BUFFER, norms_per_face.size() * sizeof(GLfloat),
               &norms_per_face[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTICESFORNORMALDRAWING]);
  glBufferData(GL_ARRAY_BUFFER, verts_and_normals.size() * sizeof(GLfloat),
               &verts_and_normals[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[BUFFER_INDICES_EDGES]);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_edges.size() * sizeof(GLuint),
               &indices_edges[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[BUFFER_INDICES_VERTICES]);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               indices_vertices.size() * sizeof(GLuint), &indices_vertices[0],
               GL_STATIC_DRAW);

  glGenVertexArrays(NUM_BUFFERS, &vaos[0]);

  glBindVertexArray(vaos[VAO_TRIANGLES_NORMSPERVERTEX]);
  glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTICES]);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_NORMALS_PERVERTEX]);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(1);
  glBindVertexArray(0);

  glBindVertexArray(vaos[VAO_TRIANGLES_NORMSPERFACE]);
  glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTICES]);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_NORMALS_PERFACE]);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(1);
  glBindVertexArray(0);

  glBindVertexArray(vaos[VAO_EDGES]);
  glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTICES]);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_NORMALS_PERVERTEX]);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[BUFFER_INDICES_EDGES]);
  glBindVertexArray(0);

  glBindVertexArray(vaos[VAO_VERTICES]);
  glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTICES]);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_NORMALS_PERVERTEX]);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[BUFFER_INDICES_VERTICES]);
  glBindVertexArray(0);

  glBindVertexArray(vaos[VAO_NORMALS]);
  glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTICESFORNORMALDRAWING]);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);
  glBindVertexArray(0);
}

myVector3D *constructRay(int x, int y) {
  glm::mat4 projection_matrix = glm::perspective(
      glm::radians(fovy), (float)Glut_w / (float)Glut_h, zNear, zFar);
  glm::mat4 view_matrix =
      glm::lookAt(glm::vec3(camera_eye.X, camera_eye.Y, camera_eye.Z),
                  glm::vec3(camera_eye.X + camera_forward.dX,
                            camera_eye.Y + camera_forward.dY,
                            camera_eye.Z + camera_forward.dZ),
                  glm::vec3(camera_up.dX, camera_up.dY, camera_up.dZ));

  float x_c = (2.0 * x) / (float)Glut_w - 1.0;
  float y_c = (2.0 * y) / (float)Glut_h - 1.0;

  glm::vec4 tmp = glm::vec4(x_c, y_c, -1.0f, 1.0f);
  tmp = glm::inverse(projection_matrix) * tmp;
  tmp.z = -1.0f;
  tmp.w = 0.0f;

  tmp = glm::inverse(view_matrix) * tmp;

  myVector3D *r = new myVector3D(tmp.x, tmp.y, tmp.z);
  r->normalize();
  return r;
}

void draw_text(GLfloat x, GLfloat y, GLfloat z, std::string text,
               std::vector<GLfloat> color) {
  glUseProgram(0);

  GLfloat w = 1;
  GLfloat fx, fy;
  glColor3f(color[0], color[1], color[2]);

  glPushAttrib(GL_TRANSFORM_BIT | GL_VIEWPORT_BIT);

  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  glDepthRange(z, z);
  glViewport((int)x - 1, (int)y - 1, 2, 2);

  fx = x - (int)x;
  fy = y - (int)y;
  glRasterPos4f(fx, fy, 0.0, w);

  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();

  glPopAttrib();

  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
                   (const unsigned char *)text.c_str());
  glUseProgram(shaderprogram);
}

bool PickedPoint(int x, int y) {
  // Check position
  if ((x < 0) || (Glut_w <= x) || (y < 0) || (Glut_h <= y)) {
    printf("Pick (%d,%d) outside viewport: (0,%d) (0,%d)\n", x, y, Glut_w,
           Glut_h);
    return false;
  }

  // Allocate select buffer
  const int SELECT_BUFFER_SIZE = 1024;
  GLuint select_buffer[SELECT_BUFFER_SIZE];
  GLint select_buffer_hits;

  // Initialize select buffer
  glSelectBuffer(SELECT_BUFFER_SIZE, select_buffer);
  glRenderMode(GL_SELECT);
  glInitNames();
  glPushName(0);

  // Initialize view transformation
  GLint viewport[4];
  glViewport(0, 0, Glut_w, Glut_h);
  glGetIntegerv(GL_VIEWPORT, viewport);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPickMatrix((GLdouble)x, (GLdouble)y, 1, 1, viewport);
  // Set projection transformation
  // NOTE: THIS MUST MATCH CODE IN GLUTRedraw
  gluPerspective(fovy, Glut_w / (float)Glut_h, zNear, zFar);

  // Set camera transformation
  // NOTE: THIS MUST MATCH CODE IN GLUTRedraw
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(camera_eye.X, camera_eye.Y, camera_eye.Z,
            camera_eye.X + camera_forward.dX, camera_eye.Y + camera_forward.dY,
            camera_eye.Z + camera_forward.dZ, camera_up.dX, camera_up.dY,
            camera_up.dZ);

  // Draw mesh with pick names into selection buffer
  glLoadName(0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  int i = 0;
  for (std::vector<myFace *>::iterator it = m->faces.begin();
       it != m->faces.end(); it++) {
    glLoadName(++i);
    glBegin(GL_POLYGON);
    myHalfedge *e = (*it)->adjacent_halfedge;
    myVertex *v;

    v = e->source;
    glVertex3f((float)v->point->X, (float)v->point->Y, (float)v->point->Z);

    e = e->next;
    v = e->source;
    glVertex3f((float)v->point->X, (float)v->point->Y, (float)v->point->Z);

    e = e->next;
    v = e->source;
    glVertex3f((float)v->point->X, (float)v->point->Y, (float)v->point->Z);
    glEnd();
  }

  glFlush();
  select_buffer_hits = glRenderMode(GL_RENDER);

  // Process select buffer to find front-most hit
  int hit = 0;
  GLuint hit_z = 0xFFFFFFFF;
  GLuint *bufp = select_buffer;
  GLuint numnames, z1, z2;
  for (int i = 0; i < select_buffer_hits; i++) {
    numnames = *bufp++;
    z1 = *bufp++;
    z2 = *bufp++;
    while (numnames--) {
      if (z1 < hit_z) {
        hit = (int)*bufp;
        hit_z = z1 / 2 + z2 / 2;
      }
      bufp++;
    }
  }

  // Return closest face
  if ((hit > 0)) {
    // Find face
    // if (pick_face) {
    // Subtract one because added one in glLoadName
    closest_face = m->faces[hit - 1];

    // }

    // Find hit position
    if (pickedpoint) {
      GLdouble p[3];
      GLdouble modelview_matrix[16];
      GLdouble projection_matrix[16];
      GLint viewport[16];
      glGetDoublev(GL_MODELVIEW_MATRIX, modelview_matrix);
      glGetDoublev(GL_PROJECTION_MATRIX, projection_matrix);
      glGetIntegerv(GL_VIEWPORT, viewport);
      GLdouble z = (GLdouble)hit_z / (GLdouble)0xFFFFFFFF;
      gluUnProject(x, y, z, modelview_matrix, projection_matrix, viewport,
                   &(p[0]), &(p[1]), &(p[2]));
      pickedpoint->X = p[0];
      pickedpoint->Y = p[1];
      pickedpoint->Z = p[2];
    }

    // Return hit
    // std::cout << "true\n";
    return true;
  } else {
    // Return no hit
    // std::cout << "false\n";
    return false;
  }
}

void mouse(int button, int state, int x, int y) {
  // Remember button state
  button_pressed = (state == GLUT_DOWN) ? 1 : 0;

  // Remember mouse position
  GLUTmouse[0] = x;
  GLUTmouse[1] = Glut_h - y;

  int mode = glutGetModifiers();
  // Process mouse button event
  if (state == GLUT_DOWN) {
    if (button == GLUT_LEFT_BUTTON) {
      if (mode == GLUT_ACTIVE_CTRL) {
        std::cout << "Picking a point.\n";
        myVector3D *picking_ray = constructRay(x, Glut_h - y);
        /////////////// VERTEX
        double bestDist = DBL_MAX;
        closest_vertex = NULL;
        std::cout << picking_ray->dX << "," << picking_ray->dY << ","
                  << picking_ray->dZ << "\n";

        for (auto p : m->vertices) {

          double curent_dist = abs(p->point->dist(&camera_eye, picking_ray));
          if (curent_dist < bestDist) {
            //                   std::cout<<"abs "<< curent_dist<<"\n";
            bestDist = curent_dist;
            closest_vertex = p;
          }
        }

        /* //////////// hedge */
        double bestDistedhe = DBL_MAX;

        for (auto p : m->halfedges) {

          auto a = camera_eye;
          auto b = *p->source->point;
          auto u = *picking_ray;
          auto nb = p->next->source->point;
          auto v = myVector3D(nb->X - b.X, nb->Y - b.Y, nb->Z - b.Z);

          myPoint3D p1;
          myPoint3D p2;

          auto solu = ligneClosest(a, u, b, v);
          if (solu.first < 0) {
            p1 = a;
          } else {
            p1 = a + u * solu.first;
          }

          if (solu.second < 0) {
            p2 = b;
          } else if (solu.second > 1) {
            p2 = b + v * 1;
          } else {
            p2 = b + v * solu.second;
          }

          auto curent_dist = p2.dist(p1);
          if (curent_dist < bestDistedhe) {
            //                   std::cout<<"abs "<< curent_dist<<"\n";
            bestDistedhe = curent_dist;
            closest_edge = p;
          }
        }

        /*////////////////////// face*/

        // solving matrix is simple

        double best_dist = DBL_MAX; // if no colition
        double best_t = DBL_MAX;    // if colition because best_dist == 0

        auto matrice_to_solve = new double[3][3];
        double c0[3] = {picking_ray->dX, picking_ray->dY, picking_ray->dZ};

        set_c_of_matrix(matrice_to_solve, 0, c0);

        for (auto f : m->faces) {
          auto a = f->adjacent_halfedge->source->point;
          auto b = f->adjacent_halfedge->next->source->point;
          auto c = f->adjacent_halfedge->next->next->source->point;

          auto c1 = *a - *c;
          auto c2 = *b - *c;
          auto solu = camera_eye - *c;

          set_c_of_matrix(matrice_to_solve, 1, c1.components);
          set_c_of_matrix(matrice_to_solve, 2, c2.components);

          auto reverse = solve_matrix(matrice_to_solve);

          auto aplication = reverse * solu;

          auto t = -aplication[0];
          auto alpha = aplication[1];
          auto beta = aplication[2];
          auto gama = 1 - alpha - beta;

          if (alpha + beta + gama == 1) {

            auto d = myPoint3D(a->X * alpha + b->X * beta + c->X * gama,
                               a->Y * alpha + b->Y * beta + c->Y * gama,
                               a->Z * alpha + b->Z * beta + c->Z * gama);

            std::cout << "touch face: " << f->index << "in " << d.X << ","
                      << d.Y << "," << d.Z << " at " << t << ' ';

            auto dis = d.dist(camera_eye);
            std::cout << " dist:" << dis << " ";
            if (t > 0 and t < best_t) {
              best_t = t;
              closest_face = f;
              std::cout << aplication[0] << "," << aplication[1] << ","
                        << aplication[2] << "\n";
            } else {
              // std::cout<<"no"<<"\n";
            }
          } else {
            std::cout << "no on face \n";
          }
          std::cout << "\n";
        }
      }
      if (mode == GLUT_ACTIVE_SHIFT) {
      }
    } else if (button == GLUT_MIDDLE_BUTTON) {
    } else if (button == GLUT_RIGHT_BUTTON) {
    }
  }

  if (state == GLUT_UP) {
  }

  glutPostRedisplay();
}

// This function is called when the mouse is dragged.
void mousedrag(int x, int y) {
  // Invert y coordinate
  y = Glut_h - y;

  // change in the mouse position since last time
  int dx = x - GLUTmouse[0];
  int dy = y - GLUTmouse[1];

  GLUTmouse[0] = x;
  GLUTmouse[1] = y;

  if (glutGetModifiers() == GLUT_ACTIVE_SHIFT)
    return;
  if ((dx == 0 && dy == 0) || !button_pressed)
    return;

  double vx = (double)dx / (double)Glut_w;
  double vy = (double)dy / (double)Glut_h;
  double theta = 4.0 * (fabs(vx) + fabs(vy));

  myVector3D camera_right = camera_forward.crossproduct(camera_up);
  camera_right.normalize();

  myVector3D tomovein_direction = -camera_right * vx + -camera_up * vy;

  myVector3D rotation_axis = tomovein_direction.crossproduct(camera_forward);
  rotation_axis.normalize();

  camera_forward.rotate(rotation_axis, theta);
  camera_up.rotate(rotation_axis, theta);
  camera_eye.rotate(rotation_axis, theta);

  camera_up.normalize();
  camera_forward.normalize();

  glutPostRedisplay();
}

void mouseWheel(int button, int dir, int x, int y) {
  if (dir > 0)
    camera_eye += camera_forward * 0.02;
  else
    camera_eye += -camera_forward * 0.02;
  glutPostRedisplay();
}

// This function is called when an arrow key is pressed.
void keyboard2(int key, int x, int y) {
  switch (key) {
  case GLUT_KEY_UP:
    camera_eye += camera_forward * 0.01;
    break;
  case GLUT_KEY_DOWN:
    camera_eye += -camera_forward * 0.01;
    break;
  case GLUT_KEY_LEFT:
    camera_up.normalize();
    camera_forward.rotate(camera_up, 0.01);
    camera_forward.normalize();
    break;
  case GLUT_KEY_RIGHT:
    camera_up.normalize();
    camera_forward.rotate(camera_up, -0.01);
    camera_forward.normalize();
    break;
  }
  glutPostRedisplay();
}

void idle() {
  frame++;
  int time = glutGet(GLUT_ELAPSED_TIME);

  if (time - timebase > 1000) {
    fps = frame * 1000.0f / (time - timebase);
    timebase = time;
    frame = 0;
  }

  glutPostRedisplay();
}

void reshape(int width, int height) {
  Glut_w = width;
  Glut_h = height;

  glutPostRedisplay();
}

// This function is called when a key is pressed.
void keyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 27: // Escape to quit
    m->clear();
    glDeleteBuffers(10, &buffers[0]);
    glDeleteVertexArrays(10, &vaos[0]);
    exit(0);
    break;
  case 'h':
    std::cout << "The keys for various algorithms are:\n";
    break;

  case 'n':
    menu(MENU_DRAWNORMALS);
    break;

  case 'w':
  case 'v':
    menu(MENU_DRAWWIREFRAME);
    break;

  case 'c':
    menu(MENU_CHECK);
    break;

  case 'C':
    menu(MENU_CATMULLCLARK);
    break;

    break;
  case 't':
    menu(MENU_TRIANGULATE);
    break;

  case 's':
    menu(MENU_DRAWSILHOUETTE);
    break;

  case 'm':
    menu(MENU_DRAWMESH);
    break;

  case 'i':
    menu(MENU_INFLATE);
    break;

  case 'F':
    menu(MENU_SPLITFACE);
    break;

  case 'R':
    menu(MENU_SPLITFACE4);
    break;

  case 'E':
    menu(MENU_SPLITEDGE);
    break;

  case 'S':
    menu(MENU_SMOOTHEN);
    break;
  }
  glutPostRedisplay();
}

void initInterface(int argc, char *argv[]) {
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

  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(keyboard2);
  glutMotionFunc(mousedrag);
  glutMouseFunc(mouse);
  glutMouseWheelFunc(mouseWheel);
  glutIdleFunc(idle);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  glClearColor(1, 1, 1, 0);

  glEnable(GL_MULTISAMPLE);

  GLuint vertexshader =
      initshaders(GL_VERTEX_SHADER, "shaders/light.vert.glsl");
  GLuint fragmentshader =
      initshaders(GL_FRAGMENT_SHADER, "shaders/light.frag.glsl");
  shaderprogram = initprogram(vertexshader, fragmentshader);

  int sm1 = glutCreateMenu(menu);
  glutAddMenuEntry("Vertex-shading/face-shading", MENU_SHADINGTYPE);
  glutAddMenuEntry("Mesh", MENU_DRAWMESH);
  glutAddMenuEntry("Wireframe", MENU_DRAWWIREFRAME);
  glutAddMenuEntry("Vertices", MENU_DRAWMESHVERTICES);
  glutAddMenuEntry("Normals", MENU_DRAWNORMALS);
  glutAddMenuEntry("Silhouette", MENU_DRAWSILHOUETTE);
  glutAddMenuEntry("Crease", MENU_DRAWCREASE);

  int sm2 = glutCreateMenu(menu);
  glutAddMenuEntry("Catmull-Clark subdivision", MENU_CATMULLCLARK);
  glutAddMenuEntry("Loop subdivision", MENU_LOOP);
  glutAddMenuEntry("Inflate", MENU_INFLATE);
  glutAddMenuEntry("Smoothen", MENU_SMOOTHEN);
  glutAddMenuEntry("Simplification", MENU_SIMPLIFY);

  int sm3 = glutCreateMenu(menu);
  glutAddMenuEntry("Closest Edge", MENU_SELECTEDGE);
  glutAddMenuEntry("Closest Face", MENU_SELECTFACE);
  glutAddMenuEntry("Closest Vertex", MENU_SELECTVERTEX);
  glutAddMenuEntry("Clear", MENU_SELECTCLEAR);

  int sm4 = glutCreateMenu(menu);
  glutAddMenuEntry("Split edge", MENU_SPLITEDGE);
  glutAddMenuEntry("Split face", MENU_SPLITFACE);
  glutAddMenuEntry("Contract edge", MENU_CONTRACTEDGE);
  glutAddMenuEntry("Contract face", MENU_CONTRACTFACE);

  int m = glutCreateMenu(menu);
  glutAddSubMenu("Draw", sm1);
  glutAddSubMenu("Mesh Operations", sm2);
  glutAddSubMenu("Select", sm3);
  glutAddSubMenu("Face Operations", sm4);
  glutAddMenuEntry("Open File", MENU_OPENFILE);
  glutAddMenuEntry("Triangulate", MENU_TRIANGULATE);
  glutAddMenuEntry("Write to File", MENU_WRITE);
  glutAddMenuEntry("Undo", MENU_UNDO);
  glutAddMenuEntry("Generate Mesh", MENU_GENERATE);
  glutAddMenuEntry("Cut Mesh", MENU_CUT);
  glutAddMenuEntry("Exit", MENU_EXIT);

  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// This is a basic program to initiate a shader
// The textFileRead function reads in a filename into astd::string
// programerrors and shadererrors output compilation errors
// initshaders initiates a vertex or fragment shader
// initprogram initiates a program with vertex and fragment shaders

std::string textFileRead(const char *filename) {
  std::string str, ret = "";
  std::ifstream in;
  in.open(filename);
  if (in.is_open()) {
    getline(in, str);
    while (in) {
      ret += str + "\n";
      getline(in, str);
    }
    //   std::cout << "Shader below\n" << ret << "\n" ;
    return ret;
  } else {
    std::cerr << "Unable to Open File " << filename << "\n";
    throw 2;
  }
}

void programerrors(const GLint program) {
  GLint length;
  GLchar *log;
  glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
  log = new GLchar[length + 1];
  glGetProgramInfoLog(program, length, &length, log);
  std::cout << "Compile Error, Log Below\n" << log << "\n";
  delete[] log;
}
void shadererrors(const GLint shader) {
  GLint length;
  GLchar *log;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
  log = new GLchar[length + 1];
  glGetShaderInfoLog(shader, length, &length, log);
  std::cout << "Compile Error, Log Below\n" << log << "\n";
  delete[] log;
}

GLuint initshaders(GLenum type, const char *filename) {
  // Using GLSL shaders, OpenGL book, page 679

  GLuint shader = glCreateShader(type);
  GLint compiled;
  std::string str = textFileRead(filename);
  GLchar *cstr = new GLchar[str.size() + 1];
  const GLchar *cstr2 = cstr; // Weirdness to get a const char
                              // strcpy_s(cstr, str.size() + 1, str.c_str());
  strncpy(cstr, str.c_str(), str.size() + 1);
  glShaderSource(shader, 1, &cstr2, NULL);
  glCompileShader(shader);
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
  if (!compiled) {
    shadererrors(shader);
    throw 3;
  }
  return shader;
}

GLuint initprogram(GLuint vertexshader, GLuint fragmentshader) {
  GLuint program = glCreateProgram();
  GLint linked;
  glAttachShader(program, vertexshader);
  glAttachShader(program, fragmentshader);
  glLinkProgram(program);
  glGetProgramiv(program, GL_LINK_STATUS, &linked);
  if (linked)
    glUseProgram(program);
  else {
    programerrors(program);
    throw 4;
  }
  return program;
}

std::pair<double, double> ligneClosest(const myPoint3D &a, const myVector3D &u,
                                       const myPoint3D &b,
                                       const myVector3D &v) {
  auto val = u * v;
  if (val == 1 or val == -1) {
    // std::cout << "u*v:" << val << "\n";
    //  throw "TODO";
  }

  if (!(1 - 0.01 < v.length() and v.length() < 1 + 0.01) or
      !(1 - 0.01 < u.length() and u.length() < 1 + 0.01)) {
    std::cout << (v.length() != 1) << "," << (u.length() != 1) << " << "
              << v.length() << " , " << u.length() << "\n";
    // throw "TODO 3";
  }

  auto ab = myVector3D(b.X - a.X, b.Y - a.Y, b.Z - a.Z);
  // myVector3D tmp3 = u/(1+u*v) - (v-u) / ((1-v*u)*(1+v*u));

  auto tmp = 1 - ((v * u) * (u * v));
  auto tmp2 = ((-ab) * v) + ((ab * v) * (u * v));

  if (tmp == 0) {
    //      throw "TODO 2";
  }
  double tp = tmp2 / tmp;
  double t = (ab * u) + (tp * (v * u));

  return std::make_pair(t, tp);
}

void initMesh() {
  pickedpoint = NULL;
  closest_edge = NULL;
  closest_vertex = NULL;
  closest_face = NULL;

  m = new myMesh();
  if (m->readFile("obj/dolphin.obj")) {
    m->computeNormals();
    makeBuffers(m);
  }
}

// This function is called to display objects on screen.
void display() {
  std::vector<GLfloat> color;
  color.resize(4);

  // Clearing the color on the screen.
  //	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Setting up the projection matrix.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(fovy, Glut_w / (float)Glut_h, zNear, zFar);
  glViewport(0, 0, Glut_w, Glut_h);

  // Setting up the modelview matrix.
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(camera_eye.X, camera_eye.Y, camera_eye.Z,
            camera_eye.X + camera_forward.dX, camera_eye.Y + camera_forward.dY,
            camera_eye.Z + camera_forward.dZ, camera_up.dX, camera_up.dY,
            camera_up.dZ);

  if (drawmesh || drawsilhouette) {
    glLineWidth(1.0);
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(2.0f, 2.0f); // for z-bleeding, z-fighting.
    if (drawsilhouette && !drawmesh)
      glUseProgram(0);
    glBegin(GL_TRIANGLES);
    if (drawmesh)
      glColor3f(0.4f, 0.8f, 0.4f);
    else
      glColor3f(1.0, 1.0, 1.0);
    for (std::vector<myFace *>::iterator it = m->faces.begin();
         it != m->faces.end(); it++) {
      myHalfedge *estart = (*it)->adjacent_halfedge;
      myHalfedge *e = estart->next;
      myVertex *vstart = estart->source;
      while (e->next != estart) {
        myVertex *v;
        myVector3D r;
        v = vstart;
        if (smooth)
          r = *(v->normal);
        else
          r = *(*it)->normal;
        glNormal3f(r.dX, r.dY, r.dZ);
        glVertex3f(v->point->X, v->point->Y, v->point->Z);

        v = e->source;
        if (smooth)
          r = *(v->normal);
        else
          r = *(*it)->normal;
        glNormal3f(r.dX, r.dY, r.dZ);
        glVertex3f(v->point->X, v->point->Y, v->point->Z);

        v = e->next->source;
        if (smooth)
          r = *(v->normal);
        else
          r = *(*it)->normal;
        glNormal3f(r.dX, r.dY, r.dZ);
        glVertex3f(v->point->X, v->point->Y, v->point->Z);

        e = e->next;
      }
    }
    glEnd();
    if (drawsilhouette)
      glUseProgram(shaderprogram);
    glDisable(GL_POLYGON_OFFSET_FILL);
  }

  if (drawmeshvertices) {
    glUseProgram(0);
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glColor3f(0, 0, 0);
    for (unsigned int i = 0; i < m->vertices.size(); i++)
      glVertex3f(m->vertices[i]->point->X, m->vertices[i]->point->Y,
                 m->vertices[i]->point->Z);
    glEnd();
    glUseProgram(shaderprogram);
  }

  if (drawwireframe) {
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    for (std::vector<myHalfedge *>::iterator it = m->halfedges.begin();
         it != m->halfedges.end(); it++) {
      myHalfedge *e = (*it);
      myVertex *v1 = (*it)->source;
      myVertex *v2 = (*it)->next->source;

      glNormal3f(v1->normal->dX, v1->normal->dY, v1->normal->dZ);
      glVertex3f(v1->point->X, v1->point->Y, v1->point->Z);
      glNormal3f(v2->normal->dX, v2->normal->dY, v2->normal->dZ);
      glVertex3f(v2->point->X, v2->point->Y, v2->point->Z);
    }
    glEnd();
  }

  if (drawsilhouette) {
    glLineWidth(4.0);

    color[0] = 1.0f, color[1] = 0.0f, color[2] = 0.0f, color[3] = 1.0f;
    glUniform4fv(glGetUniformLocation(shaderprogram, "kd"), 1, &color[0]);

    std::vector<GLuint> silhouette_edges;
    for (std::vector<myHalfedge *>::iterator it = m->halfedges.begin();
         it != m->halfedges.end(); it++) {

      myHalfedge *e = (*it);

      myVertex *v1 = (*it)->source;
      if ((*it)->twin == NULL)
        continue;
      myVertex *v2 = (*it)->twin->source;

      myVector3D ey_ray(v1->point->X - camera_eye.X,
                        v1->point->Y - camera_eye.Y,
                        v1->point->Z - camera_eye.Z);

      myFace *f1 = e->adjacent_face;
      myFace *f2 = e->twin->adjacent_face;

      // if ( *v1->normal * ey_ray1   < 0.2  and *v1->normal * ey_ray1   > - 0.2
      // and  *v2->normal * ey_ray2   < 0.2  and *v2->normal * ey_ray2   > - 0.2
      // )
      if ((*(f1->normal) * ey_ray < 0 and *(f2->normal) * ey_ray > 0) or
          (*(f1->normal) * ey_ray > 0 and *(f2->normal) * ey_ray < 0)) {
        silhouette_edges.push_back(v1->index);
        silhouette_edges.push_back(v2->index);
      }
    }

    GLuint silhouette_edges_buffer;
    glGenBuffers(1, &silhouette_edges_buffer);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, silhouette_edges_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 silhouette_edges.size() * sizeof(GLuint), &silhouette_edges[0],
                 GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTICES]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_NORMALS_PERVERTEX]);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(1);

    glDrawElements(GL_LINES, silhouette_edges.size(), GL_UNSIGNED_INT, 0);

    glDeleteBuffers(1, &silhouette_edges_buffer);
  }

  if (drawnormals) {
    glUseProgram(0);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    for (std::vector<myVertex *>::iterator it = m->vertices.begin();
         it != m->vertices.end(); it++) {
      myVertex *v = *it;
      auto normal = v->normal;

      glVertex3f(v->point->X, v->point->Y, v->point->Z);
      glVertex3f(v->point->X + 0.02 * normal->dX,
                 v->point->Y + 0.02 * normal->dY,
                 v->point->Z + 0.02 * normal->dZ);
    }
    glEnd();
    glUseProgram(shaderprogram);
  }

  if (pickedpoint != NULL) {
    glUseProgram(0);
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glColor3f(1, 0, 1);
    glVertex3f(pickedpoint->X, pickedpoint->Y, pickedpoint->Z);
    glEnd();
    glUseProgram(shaderprogram);
  }

  if (closest_edge != NULL) {
    glUseProgram(0);
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 1);
    glVertex3f(closest_edge->source->point->X, closest_edge->source->point->Y,
               closest_edge->source->point->Z);
    glVertex3f(closest_edge->twin->source->point->X,
               closest_edge->twin->source->point->Y,
               closest_edge->twin->source->point->Z);
    glEnd();
    glUseProgram(shaderprogram);
  }

  if (closest_vertex != NULL) {
    glUseProgram(0);
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glColor3f(0, 0, 0);
    glVertex3f(closest_vertex->point->X, closest_vertex->point->Y,
               closest_vertex->point->Z);
    glEnd();
    glUseProgram(shaderprogram);
  }

  if (closest_face != NULL) {
    glUseProgram(0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.1, 0.1, 0.9);
    myHalfedge *e = closest_face->adjacent_halfedge;
    myVertex *v;
    myVector3D r;

    v = e->source;
    glVertex3f(v->point->X, v->point->Y, v->point->Z);
    e = e->next;
    v = e->source;
    glVertex3f(v->point->X, v->point->Y, v->point->Z);
    e = e->next;
    v = e->source;
    glVertex3f(v->point->X, v->point->Y, v->point->Z);

    glEnd();
    glUseProgram(shaderprogram);
  }

  draw_text(0.0f, 1.0f, 0,
            "Vertices:    " +
                std::to_string(static_cast<long long>(m->vertices.size())),
            color);
  draw_text(0.0f, 22.0f, 0,
            "Halfedges: " +
                std::to_string(static_cast<long long>(m->halfedges.size())),
            color);
  draw_text(0.0f, 41.0f, 0,
            "Faces:       " +
                std::to_string(static_cast<long long>(m->faces.size())),
            color);

  draw_text(Glut_w -150.0f, Glut_h -30.0f, 0,
            "fps:   " +
            std::to_string(static_cast<long long>(fps)),
            color);

  glFlush();
}

void clear() {
  closest_edge = NULL;
  closest_vertex = NULL;
  closest_face = NULL;
  pickedpoint = NULL;
}

void menu(int item) {
  switch (item) {
  case MENU_TRIANGULATE: {
    m->triangulate();
    m->computeNormals();
    makeBuffers(m);
    break;
  }
  case MENU_SHADINGTYPE: {
    smooth = !smooth;
    break;
  }
  case MENU_DRAWMESH: {
    drawmesh = !drawmesh;
    break;
  }
  case MENU_SMOOTHEN: {
    m->smoothenMesh(0.05);
    m->computeNormals();
    makeBuffers(m);
    break;
  }

  case MENU_DRAWMESHVERTICES: {
    drawmeshvertices = !drawmeshvertices;
    break;
  }
  case MENU_DRAWWIREFRAME: {
    drawwireframe = !drawwireframe;
    break;
  }
  case MENU_DRAWNORMALS: {
    drawnormals = !drawnormals;
    break;
  }
  case MENU_DRAWSILHOUETTE: {
    drawsilhouette = !drawsilhouette;
    break;
  }
  case MENU_SELECTCLEAR: {
    clear();
    break;
  }
  case MENU_SELECTEDGE: {
    if (pickedpoint == NULL)
      break;
    closest_edge = (*m->halfedges.begin());
    double min = std::numeric_limits<double>::max();
    for (std::vector<myHalfedge *>::iterator it = m->halfedges.begin();
         it != m->halfedges.end(); it++) {
      myHalfedge *e = (*it);
      myVertex *v1 = (*it)->source;
      if ((*it)->twin == NULL)
        continue;
      myVertex *v2 = (*it)->twin->source;

      double d = pickedpoint->dist(*v1->point, *v2->point);
      if (d < min) {
        min = d;
        closest_edge = e;
      }
    }
    break;
  }
  case MENU_SELECTVERTEX: {
    if (pickedpoint == NULL)
      break;
    closest_vertex = (*m->vertices.begin());
    double min = std::numeric_limits<double>::max();
    for (std::vector<myVertex *>::iterator it = m->vertices.begin();
         it != m->vertices.end(); it++) {
      double d = pickedpoint->dist(*((*it)->point));
      if (d < min) {
        min = d;
        closest_vertex = *it;
      }
    }
    break;
  }
  case MENU_INFLATE: {
    m->inflateMesh(0.01);
    m->computeNormals();
    makeBuffers(m);

    break;
  }
  case MENU_CATMULLCLARK: {
    m->subdivisionCatmullClark();
    m->checkMesh();
    clear();
    m->computeNormals();
    makeBuffers(m);
    break;
  }
  case MENU_SPLITEDGE: {

    m->splitEdge(m->halfedges[0], std::make_shared<myPoint3D>(0, 0, 0));

    m->checkMesh();
    // clear();
    m->computeNormals();
    makeBuffers(m);

    // if (pickedpoint != NULL && closest_edge != NULL)
    // 	m->splitEdge(closest_edge, pickedpoint);
    // clear();
    // m->computeNormals();
    // makeBuffers(m);
    break;
  }

  case MENU_SPLITFACE: {

    if (closest_vertex != NULL) {

      m->splitFace(m->faces[0], std::make_shared<myPoint3D>(0, 0, 0));
      m->checkMesh();
      m->computeNormals();
      makeBuffers(m);
    }

    // if (pickedpoint != NULL && closest_face != NULL)
    // 	m->splitFaceTRIS(closest_face, pickedpoint);
    // clear();
    // m->computeNormals();
    // makeBuffers(m);
    break;
  }

  case MENU_SPLITFACE4: {

    if (closest_vertex != NULL) {

      m->splitFaceQUADS(m->faces[0], std::make_shared<myPoint3D>(0, 0, 0));
      m->checkMesh();
      m->computeNormals();
      makeBuffers(m);
    }

    // if (pickedpoint != NULL && closest_face != NULL)
    // 	m->splitFaceTRIS(closest_face, pickedpoint);
    // clear();
    // m->computeNormals();
    // makeBuffers(m);
    break;
  }

  case MENU_OPENFILE: {
    nfdchar_t *outPath = NULL;
    nfdresult_t result = NFD_OpenDialog("obj", NULL, &outPath);
    m->clear();
    m->readFile(outPath);
    m->computeNormals();
    makeBuffers(m);
    closest_face = nullptr;
    closest_edge = nullptr;
    closest_vertex = nullptr;

    break;
  }
  case MENU_EXIT: {
    m->clear();
    glDeleteBuffers(10, &buffers[0]);
    glDeleteVertexArrays(10, &vaos[0]);
    exit(0);
    break;
  }

  case MENU_CHECK: {
    m->checkMesh();
    break;
  }
  }

  glutPostRedisplay();
}
