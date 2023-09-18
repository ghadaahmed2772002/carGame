///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include <cmath>
#include <Windows.h>
#include<GL/glut.h>
#include <Gl/stb_image.h>


///global variables
/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int texture;
int width, height, nrChannels;
unsigned char* data = NULL;
bool fullScreen;
float ratio, angle1 = 0, angle, eyey = .3 * abs(cos(angle)),
eyez = -5, eyex, upx, upy, upz = -40, theta;
float lz = 0, tz = 0, cz = 0, cz1 = 0, zangle = 0, yangle = 0, xangle = 0;
float t = 0, y = 1, f = 0, play = 0, game_over = 1, score = 0;
bool paused = false;
bool flag = true;
/*......................*/
//for display text
const int font1 = (int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2 = (int)GLUT_BITMAP_HELVETICA_18;
char s[50];

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Functions

void renderBitmapString(float x, float y, void* font, const char* string)
{
    const char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void check(unsigned char* data) {
    if (data)
    {
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

}

void load(int imgnum) {
    if (imgnum == 1) {

        data = stbi_load("cube.png", &width, &height, &nrChannels, 0);
        check(data);
    }
    if (imgnum == 2) {

        data = stbi_load("cloud.png", &width, &height, &nrChannels, 0);
        check(data);
    }
}

void background() {
    //glClearColor(0, 0.7, 0, 0);
    glClearColor(0.2274509803921569, 0.2196078431372549, 0.2705882352941176, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
}

void first_page() {
    //this page when play =0  when  start the game
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -150.0f);
    background();

    glColor3f(0.67, 0.4, 0.8);
    glColor3f(0.7764705882352941, 0.607843137254902, 0.4823529411764706);
    renderBitmapString(2, 50, (void*)font2, "Car Game");

    glColor3f(0.7764705882352941, 0.607843137254902, 0.4823529411764706);
    renderBitmapString(2, 40, (void*)font2, "DO You Want to start the game if yes  Press >> 1");
    renderBitmapString(2, 30, (void*)font2, "DO You Want to Close the game if yes  Press >> 9");
    renderBitmapString(2, 20, (void*)font2, "turn car right  Press >> RIGHT KEY IN Keyboard");
    renderBitmapString(2, 10, (void*)font2, "turn car left   Press  << LEFTT KEY IN Keyboard");
    renderBitmapString(2, 0, (void*)font2, "move camera left Press >> 4 ");
    renderBitmapString(2, -10, (void*)font2, "move camera right Press >> 6");
    renderBitmapString(2, -20, (void*)font2, "move camera up Press >> 8 ");
    renderBitmapString(2, -30, (void*)font2, "move camera down Press >> 2");
    renderBitmapString(2, -40, (void*)font2, "pause car click  right or left of mouse");
    glutSwapBuffers();
}

void Game_Over()
{
    //this func when collesion happen >>  when game end
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -150.0f);
    background();

    glColor3f(0.67, 0.4, 0.8);
    glColor3f(0.7764705882352941, 0.607843137254902, 0.4823529411764706);
    renderBitmapString(10, 10, (void*)font1, "Game   Over");
    glColor3f(0.7764705882352941, 0.607843137254902, 0.4823529411764706);
    renderBitmapString(10, -10, (void*)font1, "DO You Want to start  again >> Press 1");
    renderBitmapString(10, -20, (void*)font1, "DO You Want to Close the game >> Press 9");

    glutSwapBuffers();
}

void timer(int v);

void draw_road()
{
    glTranslatef(0, 0, -7);
    //----------------gray road------------------//
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(3, -2, 200);
    glVertex3f(-3, -2, 200);
    glVertex3f(-3, -2, -10000);
    glVertex3f(3, -2, -10000);
    glEnd();

    //------------------green road----------------//
    glBegin(GL_QUADS);
    glColor3f(0, .7, 0);
    glVertex3f(50, -2, 300);
    glVertex3f(3, -2, 300);
    glVertex3f(3, -2, -10000);
    glVertex3f(50, -2, -10000);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, .7, 0);
    glVertex3f(-3, -2, 300);
    glVertex3f(-50, -2, 300);
    glVertex3f(-50, -2, -10000);
    glVertex3f(-3, -2, -10000);
    glEnd();
    glColor3f(1, 1, 1);

    load(2);
    glBegin(GL_QUADS);
    glTexCoord2d(1.0f, 1.0f);
    glVertex3f(-100, 0, -100);
    glTexCoord2d(0.0f, 1.0f);
    glVertex3f(100, 0, -100);
    glTexCoord2d(0.0f, 0.0f);
    glVertex3f(100, 70, -100);
    glTexCoord2d(1.0f, 0.0f);
    glVertex3f(-100, 70, -100);
    glEnd();

}

void draw_lines()
{
    for (float i = 1000; i >= -100000; i -= 1)
    {
        glPushMatrix();
        glScalef(.08, .08, 1);
        glBegin(GL_QUADS);
        glColor3f(1, 1, 1);
        glVertex3f(.25, -2, i + lz);
        glVertex3f(0, -2, i + lz);
        glVertex3f(0, -2, i - .5 + lz);
        glVertex3f(.25, -2, i - .5 + lz);
        glEnd();
        glPopMatrix();
    }
}

void draw_cube1()
{
    load(1);
    for (float i = -225; i >= -100000; i -= 250)
    {
        glPushMatrix();
        glScalef(.3, .3, .3);
        glTranslatef(-3.1, -4, cz1 + i);
        glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
        glColor3f(1.0f, 1.0f, 1.0f);
        glTexCoord2d(0.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glTexCoord2d(1.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glTexCoord2d(1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glTexCoord2d(0.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);

        // Bottom face (y = -1.0f)
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

        // Front face  (z = 1.0f)
        glColor3f(1.0f, 1.0f, 1.0f);
        glTexCoord2d(0.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glTexCoord2d(1.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glTexCoord2d(1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glTexCoord2d(0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);

        // Back face (z = -1.0f)
        glColor3f(1.0f, 1.0f, 1.0f);
        glTexCoord2d(0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glTexCoord2d(1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2d(1.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glTexCoord2d(0.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        // Left face (x = -1.0f)
        glColor3f(1.0f, 1.0f, 1.0f);
        glTexCoord2d(1.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glTexCoord2d(0.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glTexCoord2d(0.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2d(1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);

        // Right face (x = 1.0f)
        glColor3f(1.0f, 1.0f, 1.0f);
        glTexCoord2d(1.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glTexCoord2d(0.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glTexCoord2d(0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glTexCoord2d(1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glEnd();  // End of drawing color-cube
        glPopMatrix();
        /*if (cz + i >= -10)
            exit(0);*/
    }

}

void draw_cube2()
{
    load(1);
    for (float i = -100; i >= -100000; i -= 250)
    {
        glPushMatrix();
        glScalef(.3, .3, .3);
        glTranslatef(3.1, -4, cz + i);
        glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
        glColor3f(1.0f, 1.0f, 1.0f);
        glTexCoord2d(0.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glTexCoord2d(1.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glTexCoord2d(1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glTexCoord2d(0.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);

        // Bottom face (y = -1.0f)
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

        // Front face  (z = 1.0f)
        glColor3f(1.0f, 1.0f, 1.0f);
        glTexCoord2d(0.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glTexCoord2d(1.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glTexCoord2d(1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glTexCoord2d(0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);

        // Back face (z = -1.0f)
        glColor3f(1.0f, 1.0f, 1.0f);
        glTexCoord2d(0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glTexCoord2d(1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2d(1.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glTexCoord2d(0.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);

        // Left face (x = -1.0f)
        glColor3f(1.0f, 1.0f, 1.0f);
        glTexCoord2d(1.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glTexCoord2d(0.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glTexCoord2d(0.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2d(1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);

        // Right face (x = 1.0f)
        glColor3f(1.0f, 1.0f, 1.0f);
        glTexCoord2d(1.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glTexCoord2d(0.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glTexCoord2d(0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glTexCoord2d(1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glEnd();  // End of drawing color-cube
        glPopMatrix();
    }
}

void draw_tree(int x)
{
    for (float i = 50; i >= -10000; i -= 150)
    {
        glPushMatrix();
        glScalef(.04, .035, .01);
        glTranslatef(x, -2, i);
        glBegin(GL_QUADS);
        glColor3f(0.30f, 0.15f, 0.0f);     // brown 
        glVertex3f(1.0f, 6.0f, tz + -1.0f);
        glVertex3f(-1.0f, 6.0f, tz + -1.0f);
        glVertex3f(-1.0f, 6.0f, tz + 1.0f);
        glVertex3f(1.0f, 6.0f, tz + 1.0f);

        glColor3f(0.30f, 0.15f, 0.0f);     // brown 
        glVertex3f(1.0f, -6.0f, tz + 1.0f);
        glVertex3f(-1.0f, -6.0f, tz + 1.0f);
        glVertex3f(-1.0f, -6.0f, tz + -1.0f);
        glVertex3f(1.0f, -6.0f, tz + -1.0f);

        glColor3f(0.30f, 0.15f, 0.0f);     // brown 
        glVertex3f(1.0f, 6.0f, tz + 1.0f);
        glVertex3f(-1.0f, 6.0f, tz + 1.0f);
        glVertex3f(-1.0f, -6.0f, tz + 1.0f);
        glVertex3f(1.0f, -6.0f, tz + 1.0f);

        glColor3f(0.30f, 0.15f, 0.0f);     // brown 
        glVertex3f(1.0f, -6.0f, tz + -1.0f);
        glVertex3f(-1.0f, -6.0f, tz + -1.0f);
        glVertex3f(-1.0f, 6.0f, tz + -1.0f);
        glVertex3f(1.0f, 6.0f, tz + -1.0f);

        glColor3f(0.30f, 0.15f, 0.0f);     // brown 
        glVertex3f(-1.0f, 6.0f, tz + 1.0f);
        glVertex3f(-1.0f, 6.0f, tz + -1.0f);
        glVertex3f(-1.0f, -6.0f, tz + -1.0f);
        glVertex3f(-1.0f, -6.0f, tz + 1.0f);

        glColor3f(0.30f, 0.15f, 0.0f);     // brown 
        glVertex3f(1.0f, 6.0f, tz + -1.0f);
        glVertex3f(1.0f, 6.0f, tz + 1.0f);
        glVertex3f(1.0f, -6.0f, tz + 1.0f);
        glVertex3f(1.0f, -6.0f, tz + -1.0f);
        glEnd();

        glTranslatef(0.0f, 6.0f, 0.0f);
        glBegin(GL_TRIANGLES);
        glColor3f(0.133, 0.545, 0.133);   // green
        glVertex3f(0.0f, 6.0f, tz + 0.0f);
        glVertex3f(-3.0f, -3.0f, tz + 3.0f);
        glVertex3f(3.0f, -3.0f, tz + 3.0f);

        glColor3f(0.0f, 0.5f, 0.0f);     // green
        glVertex3f(0.0f, 6.0f, tz + 0.0f);
        glVertex3f(3.0f, -3.0f, tz + 3.0f);
        glVertex3f(3.0f, -3.0f, tz + -3.0f);

        glColor3f(0.0f, 0.5f, 0.0f);      // green
        glVertex3f(0.0f, 6.0f, tz + 0.0f);
        glVertex3f(3.0f, -3.0f, tz + -3.0f);
        glVertex3f(-3.0f, -3.0f, tz + -3.0f);

        glColor3f(0.0f, 1.0f, 0.0f);       // green
        glVertex3f(0.0f, 6.0f, tz + 0.0f);
        glVertex3f(-3.0f, -3.0f, tz + -3.0f);
        glVertex3f(-3.0f, -3.0f, tz + 3.0f);
        glEnd();
        glPopMatrix();
    }
}

void collision()
{
    //in road 1
    if (t == 0)
    {
        for (int i = 76; i <= 100000; i += 248)
        {
            if (cz == i)
                play = 2;  //game over page
        }
    }
    else
    {
        //in road 2
        for (int i = 200; i <= 100000; i += 248)
        {
            if (cz1 == i)
                play = 2;   //game over page
        }
    }
}

void draw_car()
{
    glPushMatrix();
    glTranslatef(t + 1.1, -1.1, -4);
    glScalef(1.1, 1.1, 1);
    glRotatef(-90, 0, 1, 0);
    glBegin(GL_QUADS);
    /* top of cube*/
    //FRONT BODY**
    glColor3f(.7, 0, 0);
    glVertex3f(0.2, 0.4, 0.6);
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.2, 0.4, 0.2);

    /* bottom of cube*/
    glVertex3f(0.2, 0.2, 0.6);
    glVertex3f(0.6, 0.2, 0.6);
    glVertex3f(0.6, 0.2, 0.2);
    glVertex3f(0.2, 0.2, 0.2);

    /* front of cube*/
    glVertex3f(0.2, 0.2, 0.6);
    glVertex3f(0.2, 0.4, 0.6);
    glVertex3f(0.2, 0.4, 0.2);
    glVertex3f(0.2, 0.2, 0.2);

    /* back of cube.*/
    glVertex3f(0.6, 0.2, 0.6);
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.6, 0.2, 0.2);

    /* left of cube*/
    glVertex3f(0.2, 0.2, 0.6);
    glVertex3f(0.6, 0.2, 0.6);
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.2, 0.4, 0.6);

    /* Right of cube */
    glVertex3f(0.2, 0.2, 0.2);
    glVertex3f(0.6, 0.2, 0.2);
    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.2, 0.4, 0.2);
    //******
    glVertex3f(0.7, 0.65, 0.6);
    glVertex3f(0.7, 0.65, 0.2);
    glVertex3f(1.7, 0.65, 0.2);        //top cover
    glVertex3f(1.7, 0.65, 0.6);
    //back guard*
    glColor3f(.7, .0, 0);
    glVertex3f(1.8, 0.5, 0.6);
    glVertex3f(1.8, 0.5, 0.2);
    glVertex3f(2.1, 0.4, 0.2);
    glVertex3f(2.1, 0.4, 0.6);

    /* bottom of cube*/
    glVertex3f(2.1, 0.2, 0.6);
    glVertex3f(2.1, 0.2, 0.2);
    glVertex3f(1.8, 0.2, 0.6);
    glVertex3f(1.8, 0.2, 0.6);
    /* back of cube.*/
    glVertex3f(2.1, 0.4, 0.6);
    glVertex3f(2.1, 0.4, 0.2);
    glVertex3f(2.1, 0.2, 0.2);
    glVertex3f(2.1, 0.2, 0.6);

    /* left of cube*/
    glVertex3f(1.8, 0.2, 0.2);
    glVertex3f(1.8, 0.5, 0.2);
    glVertex3f(2.1, 0.4, 0.2);
    glVertex3f(2.1, 0.2, 0.2);

    /* Right of cube */
    glVertex3f(1.8, 0.2, 0.6);
    glVertex3f(1.8, 0.5, 0.6);
    glVertex3f(2.1, 0.4, 0.6);
    glVertex3f(2.1, 0.2, 0.6);
    //MIDDLE BODY**
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.6, 0.2, 0.6);
    glVertex3f(1.8, 0.2, 0.6);
    glVertex3f(1.8, 0.5, 0.6);

    /* bottom of cube*/
    glVertex3f(0.6, 0.2, 0.6);
    glVertex3f(0.6, 0.2, 0.2);
    glVertex3f(1.8, 0.2, 0.2);
    glVertex3f(1.8, 0.2, 0.6);

    /* back of cube.*/
    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.6, 0.2, 0.2);
    glVertex3f(1.8, 0.2, 0.2);
    glVertex3f(1.8, 0.5, 0.2);
    //enter window*
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(0.77, 0.63, 0.2);
    glVertex3f(0.75, 0.5, 0.2);        //quad front window
    glVertex3f(1.2, 0.5, 0.2);
    glVertex3f(1.22, 0.63, 0.2);

    glVertex3f(1.27, 0.63, 0.2);
    glVertex3f(1.25, 0.5, 0.2);        //quad back window
    glVertex3f(1.65, 0.5, 0.2);
    glVertex3f(1.67, 0.63, 0.2);

    glColor3f(1, 1, 1);
    glVertex3f(0.7, 0.65, 0.2);
    glVertex3f(0.7, 0.5, 0.2);       //first separation
    glVertex3f(0.75, 0.5, 0.2);
    glVertex3f(0.77, 0.65, 0.2);

    glVertex3f(1.2, 0.65, 0.2);
    glVertex3f(1.2, 0.5, .2);       //second separation
    glVertex3f(1.25, 0.5, 0.2);
    glVertex3f(1.27, 0.65, 0.2);

    glVertex3f(1.65, 0.65, 0.2);
    glVertex3f(1.65, 0.5, .2);     //3d separation
    glVertex3f(1.7, 0.5, 0.2);
    glVertex3f(1.7, 0.65, 0.2);

    glVertex3f(0.75, 0.65, 0.2);
    glVertex3f(0.75, 0.63, 0.2);        //line strip
    glVertex3f(1.7, 0.63, 0.2);
    glVertex3f(1.7, 0.65, 0.2);

    glVertex3f(0.75, 0.65, 0.6);
    glVertex3f(0.75, 0.63, 0.6);        //line strip
    glVertex3f(1.7, 0.63, 0.6);
    glVertex3f(1.7, 0.65, 0.6);

    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(0.77, 0.63, 0.6);
    glVertex3f(0.75, 0.5, 0.6);        //quad front window
    glVertex3f(1.2, 0.5, 0.6);
    glVertex3f(1.22, 0.63, 0.6);

    glVertex3f(1.27, 0.63, .6);
    glVertex3f(1.25, 0.5, 0.6);        //quad back window
    glVertex3f(1.65, 0.5, 0.6);
    glVertex3f(1.67, 0.63, 0.6);

    glColor3f(1, 1, 1);
    glVertex3f(0.7, 0.65, 0.6);
    glVertex3f(0.7, 0.5, 0.6);       //first separation
    glVertex3f(0.75, 0.5, 0.6);
    glVertex3f(0.77, 0.65, 0.6);

    glVertex3f(1.2, 0.65, 0.6);
    glVertex3f(1.2, 0.5, 0.6);       //second separation
    glVertex3f(1.25, 0.5, 0.6);
    glVertex3f(1.27, 0.65, 0.6);

    glVertex3f(1.65, 0.65, 0.6);
    glVertex3f(1.65, 0.5, 0.6);
    glVertex3f(1.7, 0.5, 0.6);
    glVertex3f(1.7, 0.65, 0.6);
    glEnd();

    //******
    glBegin(GL_QUADS);
    /* top of cube*/
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.6, 0.5, 0.2);        //quad front window
    glVertex3f(0.7, 0.65, 0.2);
    glVertex3f(0.7, 0.65, 0.6);

    glVertex3f(1.7, 0.65, .6);
    glVertex3f(1.7, 0.65, 0.2);        //quad back window
    glVertex3f(1.8, 0.5, 0.2);
    glVertex3f(1.8, 0.5, 0.6);
    glEnd();

    glBegin(GL_TRIANGLES);                /* start drawing the cube.*/
    /* top of cube*/
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.7, 0.65, 0.6);       //tri front window
    glVertex3f(0.7, 0.5, 0.6);

    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.7, 0.65, 0.2);       //tri front window
    glVertex3f(0.7, 0.5, 0.2);

    glVertex3f(1.7, 0.65, 0.2);
    glVertex3f(1.8, 0.5, 0.2);       //tri back window
    glVertex3f(1.7, 0.5, 0.2);

    glVertex3f(1.7, 0.65, 0.6);
    glVertex3f(1.8, 0.5, 0.6);       //tri back window
    glVertex3f(1.7, 0.5, 0.6);

    glEnd();
    //WHEEL*
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    for (theta = 0; theta < 360; theta = theta + 20)
    {
        glVertex3f(0.6, 0.2, 0.62);
        glVertex3f(0.6 + (0.08 * (cos(((theta + angle1) * 3.14) / 180))), 0.2 + (0.08 * (sin(((theta + angle) * 3.14) / 180))), 0.62);
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (theta = 0; theta < 360; theta = theta + 20)
    {
        glVertex3f(0.6, 0.2, 0.18);
        glVertex3f(0.6 + (0.08 * (cos(((theta + angle1) * 3.14) / 180))), 0.2 + (0.08 * (sin(((theta + angle) * 3.14) / 180))), 0.18);
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (theta = 0; theta < 360; theta = theta + 20)
    {
        glVertex3f(1.7, 0.2, 0.18);
        glVertex3f(1.7 + (0.08 * (cos(((theta + angle1) * 3.14) / 180))), 0.2 + (0.08 * (sin(((theta + angle) * 3.14) / 180))), 0.18);
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (theta = 0; theta < 360; theta = theta + 20)
    {
        glVertex3f(1.7, 0.2, 0.62);
        glVertex3f(1.7 + (0.08 * (cos(((theta + angle1) * 3.14) / 180))), 0.2 + (0.08 * (sin(((theta + angle) * 3.14) / 180))), 0.62);
    }
    glEnd();
    glTranslatef(0.6, 0.2, 0.6);
    glColor3f(0, 0, 0);
    glutSolidTorus(0.025, 0.07, 10, 25);

    glTranslatef(0, 0, -0.4);
    glutSolidTorus(0.025, 0.07, 10, 25);

    glTranslatef(1.1, 0, 0);
    glutSolidTorus(0.025, 0.07, 10, 25);

    glTranslatef(0, 0, 0.4);
    glutSolidTorus(0.025, 0.07, 10, 25);
    glPopMatrix();
}

void playing() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(
        eyex, eyey, eyez,
        upx, upy, upz,
        0, y, 0);
    //----------------lines------------------//
    draw_lines();

    //----------------road-------------------//
    draw_road();

    //---------------tree------------------//
    draw_tree(21);
    draw_tree(-21);

    //----------------cube------------------//
    draw_cube1();
    draw_cube2();

    //----------------car------------------//
    draw_car();

    //--------------collision---------------//
    collision();
    glutSwapBuffers();
}

void mydraw() {

    if (play == 1)
    {
        playing();
    }
    else if (play == 0) {
        first_page();
    }
    else if (play == 2) {
        Game_Over();
    }
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    ratio = w / (float)h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, ratio, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        paused = !paused;
        if (paused) {
            flag = false;
        }
        else {
            flag = true;
            glutTimerFunc(0, timer, 0);
        }
    }
}

void timer(int v) {
    glutPostRedisplay();
    if (flag) {
        glutTimerFunc(30, timer, 0);
        //lines_move
        lz += .15;
        //tree_move
        tz += 9;
        //cube_move
        cz += 4;
        cz1 += 4;
    }
    else {
        exit;
        glutMouseFunc(mouse);
    }
}

void keyboard(unsigned char key, int x, int y) {
    angle += 0.5;
    if (key == 27)        //esc (exit)
        exit(0);
    if (key == '6')                   //move camera right
    {
        upx -= .9 * cos(.1);
    }
    if (key == '4')                   //move camera left
    {
        upx += .9 * cos(.1);
    }
    if (key == '8' && upy >= (.9 * cos(.1)))                   //move up
    {
        upy -= .9 * cos(.1);
    }
    if (key == '2' && upy <= 7 * (.9 * cos(.1)))                   //move down
    {
        upy += .9 * cos(.1);
    }
    if (key == '1')
    {
        play = 1;
    }
    else if (key == '9')
    {
        exit(0);
    }

}

void specialkeys(int key, int x, int y) {
    switch (key)
    {
    case GLUT_KEY_LEFT:    //car move left
        t = -1.3;
        break;
    case GLUT_KEY_RIGHT:   //car move right
        t = 0;
        break;
    }
}

int  main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(GetSystemMetrics(SM_CXSCREEN),
        GetSystemMetrics(SM_CYSCREEN));
    glutCreateWindow(" 3D Car");
    //glutFullScreen();
    background();
    glutDisplayFunc(mydraw);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutSpecialFunc(specialkeys);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}