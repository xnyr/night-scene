#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include "camera.h"
#include "cube.h"

#ifndef _WIN32
#define __stdcall
#endif

#ifndef CALLBACK
#define CALLBACK
#endif

int drawMode = 0;
float pitch, yaw = 0.0;
float sensitivity = 0.05;
int tick = 0;
bool lights_on = true;
bool noclip = false;




//TESTING THINGS HERE--------------------------
float no_mat[] = {0.0f, 0.0f, 0.0f, 1.0f};
float mat_ambient[] = {0.4f, 0.4f, 0.4f, 1.0f};
float mat_ambient_color[] = {0.1f, 0.1f, 0.025f, 1.0f};
float mat_diffuse[] = {0.1f, 0.5f, 0.8f, 1.0f};
float mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
float no_shininess = 0.0f;
float low_shininess = 5.0f;
float high_shininess = 100.0f;
float mat_emission[] = {1.0f, 0.2f, 0.0f, 0.0f};
GLUquadric* quadric = gluNewQuadric();
//----------------------------------------------



GLfloat no_val[] = {0,0,0,0};
GLfloat ambient_val[] = {0,0,0,1};
GLfloat diffuse_val[] = {1,1,1,1};
GLfloat specular_val[] = {1,1,1,1};
GLfloat position_val[] = {0,0,0,0};
GLfloat static_pos[] = {1,1,1,0};
GLfloat light_mat[] = {0.95,0.4,0,1};
//GLfloat low_shininess = 5.0f;
GLfloat light_dir[] = {0,0,-1,0};
GLfloat light_pos[] = {1,1,0,0};
GLfloat model_val[] = {0.2,0.2,0.2,1};

GLfloat blue_val[] = {0,0,1,1};
//GLfloat no_shininess = 0.0f;

Camera camera;
float position[] = {-25.0f, -35.0f, 20.0f, 1.0f};


Cube shape2(100,50,-100,50);
Cube house1(30,-15,0,-15);
Cube house2(30,45,0,-15);
Cube house3(30,-15,0,45);
Cube house4(30,45,0,45);

Cube h1window1(8,-14.7,5,-19);
Cube h1window2(8,-14.7,5,-33);
Cube h1window3(8,-14.7,17,-19);
Cube h1window4(8,-14.7,17,-33);

Cube h2window1(8,-14.7,5,41);
Cube h2window2(8,-14.7,5,27);
Cube h2window3(8,-14.7,17,41);
Cube h2window4(8,-14.7,17,27);

Cube h3window1(8,22.7,5,-19);
Cube h3window2(8,22.7,5,-33);
Cube h3window3(8,22.7,17,-19);
Cube h3window4(8,22.7,17,-33);

Cube h4window1(8,22.7,5,41);
Cube h4window2(8,22.7,5,27);
Cube h4window3(8,22.7,17,41);
Cube h4window4(8,22.7,17,27);


Cube collision_shapes[] = {shape2, house1, house2, house3, house4};
Cube windows[] = 
{h1window1, h1window2, h1window3, h1window4,
h2window1, h2window2, h2window3, h2window4,
h3window1, h3window2, h3window3, h3window4,
h4window1, h4window2, h4window3, h4window4};


double oldx = camera.eyex;
double oldy = camera.eyey;
double oldz = camera.eyez;


void drawLight(Cube cube){
	glTranslatef(cube.transX, cube.transY, cube.transZ);
	
	
	/*
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	*/
	
	//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	
	
	
	
	
	/*
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    */
    
    
    
    
    
    
    
	//gluSphere(quadric, 6.0f, 128, 128);
	//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	//glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	
	//glMaterialfv(GL_FRONT, GL_AMBIENT, blue_val);
	//glMaterialfv(GL_FRONT, GL_EMISSION, diffuse_val);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, blue_val);
	//glMaterialf(GL_FRONT, GL_SHININESS, low_shininess);
	//glMaterialfv(GL_FRONT, GL_EMISSION, blue_val);
	
	//glColor3f(0,0,1);
	
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, light_mat);
	//glMaterialfv(GL_FRONT, GL_POSITION, light_dir);
	//glMaterialfv(GL_FRONT, GL_EMISSION, light_mat);
	
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, light_mat);
	//glLightfv(GL_LIGHT0, GL_POSITION, light_dir);
	
	//Draw the cube here
	//Begins at forward upper right corner
	
	
	
	glBegin(GL_TRIANGLES); //setting all color values to white for now
		glColor3f(1,0.5,0); //red, top
			glVertex3f(cube.points[7][0], cube.points[7][1], cube.points[7][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
			glVertex3f(cube.points[5][0], cube.points[5][1], cube.points[5][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
		glColor3f(1,0.5,0); //green, right
			glVertex3f(cube.points[7][0], cube.points[7][1], cube.points[7][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
			glVertex3f(cube.points[0][0], cube.points[0][1], cube.points[0][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
		glColor3f(1,0.5,0); //blue, front
			glVertex3f(cube.points[7][0], cube.points[7][1], cube.points[7][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
		glColor3f(1,0.5,0); //orange, bottom
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[0][0], cube.points[0][1], cube.points[0][2]);
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
			glVertex3f(cube.points[1][0], cube.points[1][1], cube.points[1][2]);
			glVertex3f(cube.points[0][0], cube.points[0][1], cube.points[0][2]);
		glColor3f(1,0.5,0); //cyan, left
			glVertex3f(cube.points[5][0], cube.points[5][1], cube.points[5][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
			glVertex3f(cube.points[5][0], cube.points[5][1], cube.points[5][2]);
			glVertex3f(cube.points[1][0], cube.points[1][1], cube.points[1][2]);
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
		glColor3f(1,0.5,0); //purple, back
			glVertex3f(cube.points[5][0], cube.points[5][1], cube.points[5][2]);
			glVertex3f(cube.points[1][0], cube.points[1][1], cube.points[1][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
			glVertex3f(cube.points[0][0], cube.points[0][1], cube.points[0][2]);
			glVertex3f(cube.points[1][0], cube.points[1][1], cube.points[1][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
	glEnd();
	
}

void drawCube(Cube cube){
	
	glTranslatef(cube.transX, cube.transY, cube.transZ);
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialf(GL_FRONT, GL_SHININESS, low_shininess);
	
	//Draw the cube here
	//Begins at forward upper right corner
	glBegin(GL_TRIANGLES); //setting all color values to white for now
		glColor3f(0,0,0); //red, top
			glVertex3f(cube.points[7][0], cube.points[7][1], cube.points[7][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
			glVertex3f(cube.points[5][0], cube.points[5][1], cube.points[5][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
		glColor3f(0,0,0); //green, right
			glVertex3f(cube.points[7][0], cube.points[7][1], cube.points[7][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
			glVertex3f(cube.points[0][0], cube.points[0][1], cube.points[0][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
		glColor3f(0,0,0); //blue, front
			glVertex3f(cube.points[7][0], cube.points[7][1], cube.points[7][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
		glColor3f(0,0,0); //orange, bottom
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[0][0], cube.points[0][1], cube.points[0][2]);
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
			glVertex3f(cube.points[1][0], cube.points[1][1], cube.points[1][2]);
			glVertex3f(cube.points[0][0], cube.points[0][1], cube.points[0][2]);
		glColor3f(0,0,0); //cyan, left
			glVertex3f(cube.points[5][0], cube.points[5][1], cube.points[5][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
			glVertex3f(cube.points[5][0], cube.points[5][1], cube.points[5][2]);
			glVertex3f(cube.points[1][0], cube.points[1][1], cube.points[1][2]);
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
		glColor3f(0,0,0); //purple, back
			glVertex3f(cube.points[5][0], cube.points[5][1], cube.points[5][2]);
			glVertex3f(cube.points[1][0], cube.points[1][1], cube.points[1][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
			glVertex3f(cube.points[0][0], cube.points[0][1], cube.points[0][2]);
			glVertex3f(cube.points[1][0], cube.points[1][1], cube.points[1][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
	glEnd();
}

void drawCube2(Cube cube){
	
	glTranslatef(cube.transX, cube.transY, cube.transZ);
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialf(GL_FRONT, GL_SHININESS, low_shininess);
	
	//Draw the cube here
	//Begins at forward upper right corner
	glBegin(GL_TRIANGLES); //setting all color values to white for now
		glColor3f(1,1,1); //red, top
			glVertex3f(cube.points[7][0], cube.points[7][1], cube.points[7][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
			glVertex3f(cube.points[5][0], cube.points[5][1], cube.points[5][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
		glColor3f(1,1,1); //green, right
			glVertex3f(cube.points[7][0], cube.points[7][1], cube.points[7][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
			glVertex3f(cube.points[0][0], cube.points[0][1], cube.points[0][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
		glColor3f(1,1,1); //blue, front
			glVertex3f(cube.points[7][0], cube.points[7][1], cube.points[7][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
		glColor3f(1,1,1); //orange, bottom
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
			glVertex3f(cube.points[3][0], cube.points[3][1], cube.points[3][2]);
			glVertex3f(cube.points[0][0], cube.points[0][1], cube.points[0][2]);
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
			glVertex3f(cube.points[1][0], cube.points[1][1], cube.points[1][2]);
			glVertex3f(cube.points[0][0], cube.points[0][1], cube.points[0][2]);
		glColor3f(1,1,1); //cyan, left
			glVertex3f(cube.points[5][0], cube.points[5][1], cube.points[5][2]);
			glVertex3f(cube.points[6][0], cube.points[6][1], cube.points[6][2]);
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
			glVertex3f(cube.points[5][0], cube.points[5][1], cube.points[5][2]);
			glVertex3f(cube.points[1][0], cube.points[1][1], cube.points[1][2]);
			glVertex3f(cube.points[2][0], cube.points[2][1], cube.points[2][2]);
		glColor3f(1,1,1); //purple, back
			glVertex3f(cube.points[5][0], cube.points[5][1], cube.points[5][2]);
			glVertex3f(cube.points[1][0], cube.points[1][1], cube.points[1][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
			glVertex3f(cube.points[0][0], cube.points[0][1], cube.points[0][2]);
			glVertex3f(cube.points[1][0], cube.points[1][1], cube.points[1][2]);
			glVertex3f(cube.points[4][0], cube.points[4][1], cube.points[4][2]);
	glEnd();
}

void generateView(){
	glMatrixMode(GL_MODELVIEW);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	//Don't forget gluLookAt ...
	gluLookAt(camera.eyex, camera.eyey, camera.eyez,
	camera.centerx, camera.centery, camera.centerz,
	camera.upx, camera.upy, camera.upz);
	//gluPerspective( 90.0, 1.0, 1.0, 200.0 );
	
	/*
	glPushMatrix();
        glTranslatef(0.0f, 0.0f, 20.0f);
        glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialf(GL_FRONT, GL_SHININESS, low_shininess);
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
        gluSphere(quadric, 10.0f, 16, 16);
    glPopMatrix();
	
	// Sphere - 
	
	
	*/
	/*
	glPushMatrix();
        glTranslatef(-15.0f, 0.0f, -35.0f);
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialf(GL_FRONT, GL_SHININESS, low_shininess);
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
        gluSphere(quadric, 12.0f, 128, 128);
    glPopMatrix();
	*/
	
	
	
	//glPushMatrix();
	
	/*
	glPushMatrix();
	drawLight(shape1);
	glPopMatrix();
	
	
	
	glPushMatrix();
	drawCube2(shape3);
	glPopMatrix();
	
	glPushMatrix();
	drawCube2(shape4);
	glPopMatrix();
	*/
	
	/*
	glPushMatrix();
	drawCube(shape2);
	glPopMatrix();
	
	glPushMatrix();
	drawCube(house1);
	glPopMatrix();
	*/
	
	for(int i = 0; i < (sizeof(collision_shapes) / sizeof(collision_shapes[0])); i++){
		glPushMatrix();
		drawCube(collision_shapes[i]);
		glPopMatrix();
	}
	for(int i = 0; i < (sizeof(windows) / sizeof(windows[0])); i++){
		glPushMatrix();
		drawLight(windows[i]);
		glPopMatrix();
	}
	
	glEnd();
	
	
	//glPopMatrix();
	
	
	glutSwapBuffers();
}

bool checkCenterCollision(Cube cube){
	bool colliding = false;
	for(int i = 0; i < (sizeof(collision_shapes) / sizeof(collision_shapes[0])); i++){
		if((camera.centerx > cube.xmin && camera.centerx < cube.xmax &&
			camera.centery > cube.ymin && camera.centery < cube.ymax &&
			camera.centerz > cube.zmin && camera.centerz < cube.zmax)){
			colliding = true;
		}
	}
	return colliding;
}

bool checkEyeCollision(Cube cube){
	bool colliding = false;
	for(int i = 0; i < (sizeof(collision_shapes) / sizeof(collision_shapes[0])); i++){
		if((camera.eyex > cube.xmin && camera.eyex < cube.xmax &&
			camera.eyey > cube.ymin && camera.eyey < cube.ymax &&
			camera.eyez > cube.zmin && camera.eyez < cube.zmax)){
			colliding = true;
		}
	}
	return colliding;
}

bool checkForwardCollision(Cube cube[]){
	bool colliding = false;
	for(int i = 0; i < (sizeof(collision_shapes) / sizeof(collision_shapes[0])); i++){
		if((checkCenterCollision(cube[i])) && (checkEyeCollision(cube[i]))){
			colliding = true;
		}
	}
	//std::cout<<"Collision: "<<colliding<<" yaw: "<<yaw<<std::endl;
	return colliding;
}

bool checkBackwardCollision(Cube cube[]){
	bool colliding = false;
	for(int i = 0; i < (sizeof(collision_shapes) / sizeof(collision_shapes[0])); i++){
		if(
		((2 * camera.eyex - camera.centerx) > (cube[i].xmin)) &&
		((2 * camera.eyex - camera.centerx) < (cube[i].xmax)) &&
		((2 * camera.eyey - camera.centery) > (cube[i].ymin)) &&
		((2 * camera.eyey - camera.centery) < (cube[i].ymax)) &&
		((2 * camera.eyez - camera.centerz) > (cube[i].zmin)) &&
		((2 * camera.eyez - camera.centerz) < (cube[i].zmax))
		){
			colliding = true;
		}
	}
	//std::cout<<"Collision: "<<colliding<<" yaw: "<<yaw<<std::endl;
	return colliding;
}

bool checkLeftCollision(Cube cube[]){
	bool colliding = false;
	//std::cout<<"New eyex val: "<<camera.eyex + (-1 * camera.deltax * camera.speed)<<std::endl;
	//std::cout<<"New eyez val: "<<camera.eyez + (-1 * camera.deltaz * camera.speed)<<std::endl;
	//std::cout<<"New eyey val: "<<camera.eyey<<std::endl;
	camera.updateDeltas(camera.deltax, camera.deltaz);
	for(int i = 0; i < (sizeof(collision_shapes) / sizeof(collision_shapes[0])); i++){
		if((fmod(abs(yaw), 360)) >= 0 && (fmod(abs(yaw), 360) <= 180) && yaw >= 0){
			if( //check y values here too
			(camera.eyex + (-1 * camera.deltax * camera.speed) > (cube[i].xmin)) &&
			(camera.eyex + (-1 * camera.deltax * camera.speed) < (cube[i].xmax)) &&
			(camera.eyez + (-1 * camera.deltaz * camera.speed) > (cube[i].zmin)) &&
			(camera.eyez + (-1 * camera.deltaz * camera.speed) < (cube[i].zmax)) &&
			(camera.eyey > cube[i].ymin && camera.eyey < cube[i].ymax)
			){
				colliding = true;
			}
		} else {
			if(
			(camera.eyex - (-1 * camera.deltax * camera.speed) > (cube[i].xmin)) &&
			(camera.eyex - (-1 * camera.deltax * camera.speed) < (cube[i].xmax)) &&
			(camera.eyez - (-1 * camera.deltaz * camera.speed) > (cube[i].zmin)) &&
			(camera.eyez - (-1 * camera.deltaz * camera.speed) < (cube[i].zmax)) &&
			(camera.eyey > cube[i].ymin && camera.eyey < cube[i].ymax)
			){
				colliding = true;
			}
		}
	}
	//std::cout<<"Collision: "<<colliding<<" yaw: "<<yaw<<std::endl;
	return colliding;
}

bool checkRightCollision(Cube cube[]){
	bool colliding = false;
	//std::cout<<"New eyex val: "<<camera.eyex + (camera.deltax * camera.speed)<<std::endl;
	//std::cout<<"New eyez val: "<<camera.eyez + (camera.deltaz * camera.speed)<<std::endl;
	//std::cout<<"New eyey val: "<<camera.eyey<<std::endl;
	camera.updateDeltas(camera.deltax, camera.deltaz);
	for(int i = 0; i < (sizeof(collision_shapes) / sizeof(collision_shapes[0])); i++){
		if((fmod(abs(yaw), 360)) >= 0 && (fmod(abs(yaw), 360) <= 180) && yaw >= 0){
			if(
			(camera.eyex + (camera.deltax * camera.speed) > (cube[i].xmin)) &&
			(camera.eyex + (camera.deltax * camera.speed) < (cube[i].xmax)) &&
			(camera.eyez + (camera.deltaz * camera.speed) > (cube[i].zmin)) &&
			(camera.eyez + (camera.deltaz * camera.speed) < (cube[i].zmax)) &&
			(camera.eyey > cube[i].ymin && camera.eyey < cube[i].ymax)
			){
				colliding = true;
			}
		} else {
			if(
			(camera.eyex - (camera.deltax * camera.speed) > (cube[i].xmin)) &&
			(camera.eyex - (camera.deltax * camera.speed) < (cube[i].xmax)) &&
			(camera.eyez - (camera.deltaz * camera.speed) > (cube[i].zmin)) &&
			(camera.eyez - (camera.deltaz * camera.speed) < (cube[i].zmax)) &&
			(camera.eyey > cube[i].ymin && camera.eyey < cube[i].ymax)
			){
				colliding = true;
			}
		}
	}
	//std::cout<<"Collision: "<<colliding<<" yaw: "<<yaw<<std::endl;
	return colliding;
}

void mouseMove(int x, int y){
	//moving left/right - adjust centerx and centery
	//moving up/down - adjust centerz
	

	double mousex = x - 360;
	double mousey = 360 - y;

	yaw += mousex * sensitivity;
	pitch += mousey * sensitivity;
	
	//make sure yaw is between 0 and 360 at all times
	if(yaw >= 360){
		yaw -= 360;
	}
	if(yaw <= 0){
		yaw += 360;
	}
	
	//Clamp to looking straight up or straight down at most
	if(pitch > 89.0f){
		pitch = 89.0f;
	}
	if(pitch < -89.0f){
		pitch = -89.0f;
	}
	
	//keeps pointer at the center of the screen, as a game would
	//works well with hiding the cursor, also as a game would (usually)
	if(tick % 10 == 0){
		glutWarpPointer(360, 360);
	}
	if(tick % 120 == 0){ 
		tick = 0; 
	}
	tick++; 
}

void keyPressed(unsigned char key, int x, int y){
	switch(key){
		case 27:
			glutDestroyWindow(glutGetWindow());
			break;
		case 'w':
			oldx = camera.eyex;
			oldy = camera.eyey;
			oldz = camera.eyez;
			if(not checkForwardCollision(collision_shapes) && not noclip){
				camera.moveForward();
			}
			break;
		case 's':
			if(not checkBackwardCollision(collision_shapes) && not noclip){
				camera.moveBackward();
			}
			break;
		case 'd':
			if
			(not checkRightCollision(collision_shapes) && not noclip){
				camera.updateDeltas(camera.deltax, camera.deltaz);
				camera.strafeRight(pitch, yaw);
			}
			break;
		case 'a':
			if
			(not checkLeftCollision(collision_shapes) && not noclip){
				camera.updateDeltas(camera.deltax, camera.deltaz);
				camera.strafeLeft(pitch, yaw);
			}
			break;
		case ' ':
			//Defaults to a normal view. 
			//Pressing space switches to wireframe mode.
			//Pressing space again breaks everything for some reason.
			drawMode = ++drawMode % 3;
			if(drawMode == 0) { // fill mode
			
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				glEnable(GL_DEPTH_TEST);
				glEnable(GL_CULL_FACE);
			}
			else if(drawMode == 1) { // wireframe mode
			
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				glDisable(GL_DEPTH_TEST);
				glDisable(GL_CULL_FACE);
			}
			else if(drawMode == 2) { // point mode
				glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
				glDisable(GL_DEPTH_TEST);
				glDisable(GL_CULL_FACE);
			}
			//std::cout<<drawMode<<std::endl;
			break;
		case 't':
			std::cout<<"centerx: "<<camera.centerx<<" centery: "<<camera.centery<<" centerz: "<<camera.centerz<<std::endl;
			std::cout<<"eyex: "<<camera.eyex<<" eyey: "<<camera.eyey<<" eyez: "<<camera.eyez<<std::endl;
			std::cout<<"yaw: "<<yaw<<std::endl;
			break;
		case '+':
			if(camera.speed < 2){
				camera.speed += 0.05;
			}
			break;
		case '-':
			if(camera.speed > 0.5){
				camera.speed -= 0.05;
			}
			break;
		case 'l':
			if(lights_on){
				lights_on = false;
				glDisable(GL_LIGHTING);
			}
			else{
				lights_on = true;
				glEnable(GL_LIGHTING);
			}
			std::cout<<lights_on<<std::endl;
			break;
		case 'c':
			if(noclip){
				noclip = false;
			} else {
				noclip = true;
			}
			std::cout<<"Clipping: "<<std::endl;
			break;
	}
	
	
}

void reshape(GLsizei width, GLsizei height){
	if (height == 0)
		height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	
	glViewport(0, 0, width, height);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(45.0f, aspect, 0.1f, 500.0f);
}

void idleFunction(){
	
	//std::cout<<"Yaw: "<<yaw<<std::endl;
	
	//dir variables say whether left is positive or negative
	if(camera.centerx - camera.eyex <= 0){
		camera.zdir = 1;
	} else {
		camera.zdir = -1;
	}
	if(camera.centerz - camera.eyez <= 0){
		camera.xdir = 1;
	} else {
		camera.xdir = -1;
	}
	
	//2I - P = B
	//I = initial point, P = looking at, B = backwards
	
	camera.centerx = cos(yaw * M_PI / 180) * cos(pitch * M_PI / 180) + camera.eyex;
	camera.centery = sin(pitch * M_PI / 180) + camera.eyey;
	camera.centerz = sin(yaw * M_PI / 180) * cos(pitch * M_PI / 180) + camera.eyez;
	
	position_val[0] = camera.eyex;
	position_val[1] = camera.eyey;
	position_val[2] = camera.eyez;
	
	
	
	generateView();
}

void initLighting(){
	float ambient[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    
   
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
	
	float model_ambient[] = {0.4f, 0.4f, 0.4f, 1.0f};
    int model_two_side = 1;                                
    int viewpoint = 0;
	
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
	//glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, viewpoint);
	//glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, model_two_side); //this breaks things up into triangles for some reason
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_RESCALE_NORMAL);
	/*
	glShadeModel(GL_SMOOTH);
	glClearDepth(1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_mat);
	
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, no_val);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_val);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular_val);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_val);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 0);
	
	*/
	
	
	//glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_val);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_val);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, specular_val);
	//glLightfv(GL_LIGHT0, GL_POSITION, position_val);
}

int main(int argc, char** argv) {
	//std::cout<<shape1.xmin<<" "<<shape1.xmax<<" "<<shape1.ymin<<" "<<shape1.ymax<<" "<<shape1.zmin<<" "<<shape1.zmax<<std::endl;
	std::cout<<shape2.xmin<<" "<<shape2.xmax<<" "<<shape2.ymin<<" "<<shape2.ymax<<" "<<shape2.zmin<<" "<<shape2.zmax<<std::endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(720, 720);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Collision and Lighting");
	//initializeClasses();
	glutSetCursor(GLUT_CURSOR_NONE);
	glutKeyboardFunc(keyPressed);
	glutPassiveMotionFunc(mouseMove);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(generateView);
	glClearColor(0,0,0.15,1);
	initLighting();
	glutReshapeFunc(reshape);
	glutIdleFunc(idleFunction);
	glutMainLoop();
	return 0;
}
