#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <sstream>
#include <nfd/nfd.h>

#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp> 

using namespace std;

#include "myPoint3D.h"
#include "myVector3D.h"
#include "myFace.h"
#include "myMesh.h"


enum MENU { MENU_CATMULLCLARK, MENU_DRAWWIREFRAME, MENU_EXIT, MENU_DRAWMESH, MENU_LOOP, MENU_DRAWMESHVERTICES,
            MENU_CONTRACTEDGE, MENU_CONTRACTFACE, MENU_DRAWCREASE, MENU_DRAWSILHOUETTE,
            MENU_GENERATE, MENU_CUT, MENU_INFLATE, MENU_SELECTEDGE, MENU_SELECTFACE, MENU_SELECTVERTEX,
            MENU_SHADINGTYPE, MENU_SMOOTHEN, MENU_SPLITEDGE, MENU_SPLITFACE, MENU_SELECTCLEAR,
            MENU_TRIANGULATE, MENU_UNDO, MENU_WRITE, MENU_SIMPLIFY, MENU_DRAWNORMALS, MENU_OPENFILE,MENU_CHECK
};

myMesh *m;
myPoint3D *pickedpoint;
myHalfedge *closest_edge;
myVertex *closest_vertex;
myFace *closest_face;

#include "helperFunctions.h"


void clear()
{
	closest_edge = NULL;
	closest_vertex = NULL;
	closest_face = NULL;
	pickedpoint = NULL;
}

void menu(int item)
{
	switch(item)
	{
	case MENU_TRIANGULATE:
		{
			m->triangulate();
			m->computeNormals();
			makeBuffers(m);
			break;
		}
	case MENU_SHADINGTYPE:
		{
			smooth = !smooth;
			break;
		}
	case MENU_DRAWMESH:
		{
			drawmesh = !drawmesh;
			break;
		}
  case MENU_SMOOTHEN:
		{
      m->smoothenMesh(0.05);
			m->computeNormals();
      makeBuffers(m);
			break;
		}

	case MENU_DRAWMESHVERTICES:
		{
			drawmeshvertices = !drawmeshvertices;
			break;
		}
	case MENU_DRAWWIREFRAME:
		{
			drawwireframe = !drawwireframe;
			break;
		}
	case MENU_DRAWNORMALS:
		{
			drawnormals = !drawnormals;
			break;
		}
	case MENU_DRAWSILHOUETTE:
		{
			drawsilhouette = !drawsilhouette;
			break;
		}
	case MENU_SELECTCLEAR:
		{
			clear();
			break;
		}
	case MENU_SELECTEDGE:
		{
			if (pickedpoint == NULL) break;
			closest_edge = (*m->halfedges.begin());
			double min = std::numeric_limits<double>::max();
			for (vector<myHalfedge *>::iterator it = m->halfedges.begin(); it != m->halfedges.end(); it++)
			{
				myHalfedge *e = (*it);
				myVertex *v1 = (*it)->source;
				if ((*it)->twin == NULL) continue;
				myVertex *v2 = (*it)->twin->source;

				double d = pickedpoint->dist(v1->point, v2->point);
				if (d < min) { min = d; closest_edge = e; } 
			}
			break;
		}
	case MENU_SELECTVERTEX:
		{
			if (pickedpoint == NULL) break;
			closest_vertex = (*m->vertices.begin());
			double min = std::numeric_limits<double>::max();
			for (vector<myVertex *>::iterator it = m->vertices.begin(); it != m->vertices.end(); it++)
			{
				double d = pickedpoint->dist(*( (*it)->point ));
				if (d<min) { min = d; closest_vertex = *it; }
			}
			break;
		}
	case MENU_INFLATE:
		{
      m->inflateMesh(0.01);
      m->computeNormals();
      makeBuffers(m);

      //      for (vector<myVertex *>::iterator it = m->vertices.begin(); it != m->vertices.end(); it++)
			//	*((*it)->point) = *((*it)->point) + *((*it)->normal)*0.01;
			break;

	}
	case MENU_CATMULLCLARK:
		{
			m->subdivisionCatmullClark();
			clear();
			m->computeNormals();
			makeBuffers(m);
			break;
		}
	case MENU_SPLITEDGE:
		{


      m->splitEdge(m->halfedges[0], new myPoint3D(0,0,0));

      m->checkMesh();
      //clear();
      m->computeNormals();
      makeBuffers(m);

			// if (pickedpoint != NULL && closest_edge != NULL)
			// 	m->splitEdge(closest_edge, pickedpoint);
			// clear();
			// m->computeNormals();
			// makeBuffers(m);
			break;
		}

	case MENU_SPLITFACE:
		{

      if (closest_vertex != NULL){

        m->splitFace(m->faces[0], new myPoint3D(0,0,0) );
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
	case MENU_OPENFILE:
	    {
			nfdchar_t *outPath = NULL;
			nfdresult_t result = NFD_OpenDialog("obj", NULL, &outPath);
			m->clear();
			m->readFile(outPath);
			m->computeNormals();
			makeBuffers(m);
			break;
	    }
	case MENU_EXIT:
		{
			m->clear();
			glDeleteBuffers(10, &buffers[0]);
			glDeleteVertexArrays(10, &vaos[0]);
			exit(0);
			break;
		}
    
  case MENU_CHECK:
		{
      m->checkMesh();
			break;
		}

	}

	glutPostRedisplay();
}



//This function is called to display objects on screen.
void display() 
{
  vector<GLfloat> color;
  color.resize(4);

	//Clearing the color on the screen.
  //	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Setting up the projection matrix.
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, Glut_w/(float)Glut_h, zNear, zFar);
	glViewport(0, 0, Glut_w, Glut_h);

	//Setting up the modelview matrix.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera_eye.X, camera_eye.Y, camera_eye.Z, camera_eye.X + camera_forward.dX, camera_eye.Y + camera_forward.dY, camera_eye.Z + camera_forward.dZ, camera_up.dX, camera_up.dY, camera_up.dZ);

	if (drawmesh || drawsilhouette){
		glLineWidth(1.0);
		glEnable(GL_POLYGON_OFFSET_FILL); glPolygonOffset(2.0f, 2.0f); //for z-bleeding, z-fighting.
		if (drawsilhouette && !drawmesh) glUseProgram(0);
		glBegin(GL_TRIANGLES);
		if (drawmesh) glColor3f(0.4f,0.8f,0.4f);
		else glColor3f(1.0,1.0,1.0);
		for (vector<myFace *>::iterator it = m->faces.begin(); it != m->faces.end(); it++)
		{
			myHalfedge *estart = (*it)->adjacent_halfedge;
			myHalfedge *e = estart->next;
			myVertex *vstart = estart->source;
			while (e->next != estart)
			{
				myVertex *v;
				myVector3D r;
				v = vstart;
				if (smooth) r = *(v->normal);
				else r = *(*it)->normal;
				glNormal3f(r.dX, r.dY, r.dZ);
				glVertex3f( v->point->X, v->point->Y, v->point->Z);

				v = e->source;
				if (smooth) r = *(v->normal);
				else r = *(*it)->normal;
				glNormal3f(r.dX, r.dY, r.dZ);
				glVertex3f( v->point->X, v->point->Y, v->point->Z);

				v = e->next->source;
				if (smooth) r = *(v->normal);
				else r = *(*it)->normal;
				glNormal3f(r.dX, r.dY, r.dZ);
				glVertex3f( v->point->X, v->point->Y, v->point->Z);

				e = e->next;
			}
		}
		glEnd();
		if (drawsilhouette) glUseProgram(shaderprogram);
		glDisable(GL_POLYGON_OFFSET_FILL);
	}

	if (drawmeshvertices)
	{
		glUseProgram(0);
		glPointSize(2.0);
		glBegin(GL_POINTS);
		glColor3f(0,0,0);
		for (unsigned int i=0;i<m->vertices.size();i++)
			glVertex3f(m->vertices[i]->point->X, m->vertices[i]->point->Y, m->vertices[i]->point->Z);
		glEnd();
		glUseProgram(shaderprogram);
	}

	if (drawwireframe)
	{
		glLineWidth(2.0);
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		for (vector<myHalfedge *>::iterator it = m->halfedges.begin(); it != m->halfedges.end(); it++)
		{
			myHalfedge *e = (*it);
			myVertex *v1 = (*it)->source;
			myVertex *v2 = (*it)->next->source;

			glNormal3f(v1->normal->dX, v1->normal->dY, v1->normal->dZ);
			glVertex3f( v1->point->X , v1->point->Y, v1->point->Z);
			glNormal3f(v2->normal->dX, v2->normal->dY, v2->normal->dZ);
			glVertex3f( v2->point->X, v2->point->Y, v2->point->Z );
		}
		glEnd();
	}


	if (drawsilhouette)
	{
		glLineWidth(4.0);


		color[0] = 1.0f, color[1] = 0.0f, color[2] = 0.0f, color[3] = 1.0f;
		glUniform4fv(glGetUniformLocation(shaderprogram, "kd"), 1, &color[0]);

		vector <GLuint> silhouette_edges;
		for (vector<myHalfedge *>::iterator it = m->halfedges.begin(); it != m->halfedges.end(); it++)
		{

			myHalfedge* e = (*it);

        myVertex *v1 = (*it)->source;
			if ((*it)->twin == NULL) continue;
			myVertex *v2 = (*it)->twin->source;


      myVector3D ey_ray(v1->point->X - camera_eye.X, v1->point->Y - camera_eye.Y, v1->point->Z - camera_eye.Z);
      
      myFace* f1 = e->adjacent_face;
      myFace* f2 = e->twin->adjacent_face;


			//if ( *v1->normal * ey_ray1   < 0.2  and *v1->normal * ey_ray1   > - 0.2 and  *v2->normal * ey_ray2   < 0.2  and *v2->normal * ey_ray2   > - 0.2 )
      if((*(f1->normal) * ey_ray < 0 and  *(f2->normal) * ey_ray > 0) or
          (*(f1->normal) * ey_ray > 0 and  *(f2->normal) * ey_ray < 0) )
			{
				silhouette_edges.push_back(v1->index);
				silhouette_edges.push_back(v2->index);
			}
		}

		GLuint silhouette_edges_buffer;
		glGenBuffers(1, &silhouette_edges_buffer);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, silhouette_edges_buffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, silhouette_edges.size() * sizeof(GLuint),
			&silhouette_edges[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTICES]);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_NORMALS_PERVERTEX]);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(1);

		glDrawElements(GL_LINES, silhouette_edges.size(), GL_UNSIGNED_INT, 0);

		glDeleteBuffers(1, &silhouette_edges_buffer);
 	}


	if (drawnormals)
	{
		glUseProgram(0);
		glLineWidth(1.0);
		glBegin(GL_LINES);
		glColor3f(0.2f,0.2f,0.2f);
		for (vector<myVertex *>::iterator it = m->vertices.begin(); it != m->vertices.end(); it++)
		{
			myVertex *v = *it;
			myVector3D *normal = v->normal;

			glVertex3f( v->point->X, v->point->Y, v->point->Z);
			glVertex3f( v->point->X + 0.02*normal->dX, v->point->Y + 0.02*normal->dY, v->point->Z+ 0.02*normal->dZ);
		}
		glEnd();
		glUseProgram(shaderprogram);
	}


	if (pickedpoint != NULL)
	{
		glUseProgram(0);
		glPointSize(8.0);
		glBegin(GL_POINTS);
		glColor3f(1,0,1);
		glVertex3f(pickedpoint->X, pickedpoint->Y, pickedpoint->Z);
		glEnd();
		glUseProgram(shaderprogram);
	}

	if (closest_edge != NULL)
	{
		glUseProgram(0);
		glLineWidth(4.0);
		glBegin(GL_LINES);
		glColor3f(1,0,1);
		glVertex3f(closest_edge->source->point->X, closest_edge->source->point->Y, closest_edge->source->point->Z);
		glVertex3f(closest_edge->twin->source->point->X, closest_edge->twin->source->point->Y, closest_edge->twin->source->point->Z);
		glEnd();
		glUseProgram(shaderprogram);
	}
	
	if (closest_vertex != NULL)
	{
		glUseProgram(0);
		glPointSize(8.0);
		glBegin(GL_POINTS);
		glColor3f(0,0,0);
		glVertex3f(closest_vertex->point->X, closest_vertex->point->Y, closest_vertex->point->Z);
		glEnd();
		glUseProgram(shaderprogram);
	}
	
	if (closest_face != NULL)
	{
		glUseProgram(0);
		glBegin(GL_TRIANGLES);
		glColor3f(0.1,0.1,0.9);
		myHalfedge *e = closest_face->adjacent_halfedge;
		myVertex *v;
		myVector3D r;

		v = e->source;
		glVertex3f( v->point->X, v->point->Y, v->point->Z);
		e = e->next; v = e->source;
		glVertex3f( v->point->X, v->point->Y, v->point->Z);
		e = e->next; v = e->source;
		glVertex3f( v->point->X, v->point->Y, v->point->Z);

		glEnd();
		glUseProgram(shaderprogram);
	}

	draw_text(0.0f,1.0f, 0, "Vertices:    " + to_string(static_cast<long long>(m->vertices.size())),color );
	draw_text(0.0f,22.0f, 0,"Halfedges: " + to_string(static_cast<long long>(m->halfedges.size())),color );
	draw_text(0.0f,41.0f, 0,"Faces:       " + to_string(static_cast<long long>(m->faces.size())),color );

	glFlush();
}



// //This function is called to display objects on screen.
// void display() 
// {
// 	//Clearing the color on the screen.
// 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

// 	glViewport(0, 0, Glut_w, Glut_h);

// 	glm::mat4 projection_matrix = glm::perspective(glm::radians(fovy), (float)Glut_w / (float)Glut_h, zNear, zFar);
// 	glUniformMatrix4fv(glGetUniformLocation(shaderprogram, "myprojection_matrix"),
// 		1, GL_FALSE, &projection_matrix[0][0]);

// 	glm::mat4 view_matrix = glm::lookAt(glm::vec3(camera_eye.X, camera_eye.Y, camera_eye.Z),
// 										glm::vec3(camera_eye.X + camera_forward.dX, camera_eye.Y + camera_forward.dY, camera_eye.Z + camera_forward.dZ),
// 										glm::vec3(camera_up.dX, camera_up.dY, camera_up.dZ));
// 	glUniformMatrix4fv(glGetUniformLocation(shaderprogram, "myview_matrix"),
// 		1, GL_FALSE, &view_matrix[0][0]);

// 	glm::mat3 normal_matrix = glm::transpose(glm::inverse(glm::mat3(view_matrix)));
// 	glUniformMatrix3fv(glGetUniformLocation(shaderprogram, "mynormal_matrix"),
// 		1, GL_FALSE, &normal_matrix[0][0]);
 
// 	vector<GLfloat> color; 
// 	color.resize(4);

// 	if ( (drawmesh && vaos[VAO_TRIANGLES_NORMSPERVERTEX]) || drawsilhouette)
// 	{
// 		glLineWidth(1.0);
// 		glEnable(GL_POLYGON_OFFSET_FILL); glPolygonOffset(2.0f, 2.0f); //for z-bleeding, z-fighting.
// 		if (drawsilhouette && !drawmesh)  glUniform1i(glGetUniformLocation(shaderprogram, "type"), 1);
// 		if (drawmesh) { color[0] = 0.4f, color[1] = 0.8f, color[2] = 0.4f, color[3] = 1.0f; }
// 		else { color[0] = 1.0f, color[1] = 1.0f, color[2] = 1.0f, color[3] = 1.0f; }
// 		glUniform4fv(glGetUniformLocation(shaderprogram, "kd"), 1, &color[0]);

// 		if (smooth)
// 		{
// 			glBindVertexArray(vaos[VAO_TRIANGLES_NORMSPERVERTEX]);
// 			glDrawArrays(GL_TRIANGLES, 0, num_triangles * 3);
// 			glBindVertexArray(0);
// 		}
// 		else 
// 		{
// 			glBindVertexArray(vaos[VAO_TRIANGLES_NORMSPERFACE]);
// 			glDrawArrays(GL_TRIANGLES, 0, num_triangles * 3);
// 			glBindVertexArray(0);
// 		}

// 		glUniform1i(glGetUniformLocation(shaderprogram, "type"), 0);
// 		glDisable(GL_POLYGON_OFFSET_FILL);
// 	}

// 	if (drawmeshvertices && vaos[VAO_VERTICES])
// 	{
// 		glPointSize(4.0);
// 		color[0] = 0.0f, color[1] = 0.0f, color[2] = 0.0f, color[3] = 1.0f;		
// 		glUniform4fv(glGetUniformLocation(shaderprogram, "kd"), 1, &color[0]);

// 		glBindVertexArray(vaos[VAO_VERTICES]);
// 		glDrawElements(GL_POINTS, m->vertices.size(), GL_UNSIGNED_INT, 0);
// 		glBindVertexArray(0);
// 	}

// 	if (drawwireframe && vaos[VAO_EDGES])
// 	{
// 		glLineWidth(2.0);
// 		color[0] = 0.0f, color[1] = 0.0f, color[2] = 0.0f, color[3] = 1.0f;
//         glUniform4fv(glGetUniformLocation(shaderprogram, "kd"), 1, &color[0]);
// 		glBindVertexArray(vaos[VAO_EDGES]);
// 		glDrawElements(GL_LINES, m->halfedges.size()*2, GL_UNSIGNED_INT, 0);
// 		glBindVertexArray(0);
// 	}

// 	if (drawsilhouette)
// 	{
// 		glLineWidth(4.0);
// 		color[0] = 1.0f, color[1] = 0.0f, color[2] = 0.0f, color[3] = 1.0f;
// 		glUniform4fv(glGetUniformLocation(shaderprogram, "kd"), 1, &color[0]);

// 		vector <GLuint> silhouette_edges;
// 		for (vector<myHalfedge *>::iterator it = m->halfedges.begin(); it != m->halfedges.end(); it++)
// 		{
// 			/**** TODO: WRITE CODE TO COMPUTE SILHOUETTE ****/
// 			myHalfedge *e = (*it);
// 			myVertex *v1 = (*it)->source;
// 			if ((*it)->twin == NULL) continue;
// 			myVertex *v2 = (*it)->twin->source;

// 			if ( 0 /*ADD THE CONDITION TO CHECK IF THE HALFEDGE DEFINED BY (V1, V2) IS A SILHOUETTE EDGE*/ )
// 			{
// 				silhouette_edges.push_back(v1->index);
// 				silhouette_edges.push_back(v2->index);
// 			}
// 		}

// 		GLuint silhouette_edges_buffer;
// 		glGenBuffers(1, &silhouette_edges_buffer);

// 		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, silhouette_edges_buffer);
// 		glBufferData(GL_ELEMENT_ARRAY_BUFFER, silhouette_edges.size() * sizeof(GLuint),
// 			&silhouette_edges[0], GL_STATIC_DRAW);

// 		glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTICES]);
// 		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
// 		glEnableVertexAttribArray(0);

// 		glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_NORMALS_PERVERTEX]);
// 		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
// 		glEnableVertexAttribArray(1);

// 		glDrawElements(GL_LINES, silhouette_edges.size(), GL_UNSIGNED_INT, 0);

// 		glDeleteBuffers(1, &silhouette_edges_buffer);
//  	}

// 	if (drawnormals && vaos[VAO_NORMALS])
// 	{
// 		glLineWidth(1.0);
// 		color[0] = 0.2f, color[1] = 0.2f, color[2] = 0.2f, color[3] = 1.0f;		
// 		glUniform4fv(glGetUniformLocation(shaderprogram, "kd"), 1, &color[0]);

// 		glBindVertexArray(vaos[VAO_NORMALS]);
// 		glDrawArrays(GL_LINES, 0, m->vertices.size()*2 );
// 		glBindVertexArray(0);
// 	}

// 	if (pickedpoint != NULL)
// 	{
// 		glUseProgram(0);
// 		glPointSize(8.0);
// 		glBegin(GL_POINTS);
// 		glColor3f(1,0,1);
// 		glVertex3f((float)pickedpoint->X, (float)pickedpoint->Y, (float)pickedpoint->Z);
// 		glEnd();
// 		glUseProgram(shaderprogram);
// 	}

// 	if (closest_edge != NULL)
// 	{
// 		glUseProgram(0);
// 		glLineWidth(4.0);
// 		glBegin(GL_LINES);
// 		glColor3f(1,0,1);
// 		glVertex3f((float)closest_edge->source->point->X, (float)closest_edge->source->point->Y, (float)closest_edge->source->point->Z);
// 		glVertex3f((float)closest_edge->twin->source->point->X, (float)closest_edge->twin->source->point->Y, (float)closest_edge->twin->source->point->Z);
// 		glEnd();
// 		glUseProgram(shaderprogram);
// 	}

// 	if (closest_vertex != NULL)
// 	{
// 		glUseProgram(0);
// 		glPointSize(8.0);
// 		glBegin(GL_POINTS);
// 		glColor3f(0,0,0);
// 		glVertex3f((float)closest_vertex->point->X, (float)closest_vertex->point->Y, (float)closest_vertex->point->Z);
// 		glEnd();
// 		glUseProgram(shaderprogram);
// 	}

// 	if (closest_face != NULL)
// 	{
// 		glUseProgram(0);
// 		glBegin(GL_TRIANGLES);
// 		glColor3f(0.1f,0.1f,0.9f);
// 		myHalfedge *e = closest_face->adjacent_halfedge;
// 		myVertex *v;
// 		myVector3D r;

// 		v = e->source;
// 		glVertex3f((float)v->point->X, (float)v->point->Y, (float)v->point->Z);
// 		e = e->next; v = e->source;
// 		glVertex3f((float)v->point->X, (float)v->point->Y, (float)v->point->Z);
// 		e = e->next; v = e->source;
// 		glVertex3f((float)v->point->X, (float)v->point->Y, (float)v->point->Z);

// 		glEnd();
// 		glUseProgram(shaderprogram);
// 	}


// 	color[0] = 0.0f, color[1] = 0.0f, color[2] = 0.0f;
// 	draw_text(0.0f, 1.0f, 0, "Vertices:    " + to_string(static_cast<long long>(m->vertices.size())), color );
// 	draw_text(0.0f,22.0f, 0,"Halfedges: " + to_string(static_cast<long long>(m->halfedges.size())), color );
// 	draw_text(0.0f,41.0f, 0,"Faces:       " + to_string(static_cast<long long>(m->faces.size())), color );
// 	color[0] = 0.9f;
// 	draw_text(Glut_w - 150.0f, Glut_h - 20.0f, 0, "FPS:       " + to_string(static_cast<long long>( fps)), color );

// 	glFlush();
// }


void initMesh()
{
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


int main(int argc, char* argv[])
{
  auto a = myPoint3D(0,0,0);
  auto b = myPoint3D(0,1,1);
  auto u = myVector3D(1,0,0);
  u.normalize();
  auto v = myVector3D(0,1,0);
  v.normalize();

  

try {
  ligneClosest(a,u,b,v);
 } catch (char const * err  ) {
  cout << err  << "\n";
 }


	initInterface(argc, argv);

	initMesh();

	glutMainLoop();

	return 0;
}
