//
//  OPENGL_mod.cpp
//  Nibbler
//
//  Created by quentin PIDOUX on 06/03/12.
//  Copyright (c) 2012 EPITECH. All rights reserved.
//

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>
#include <string>
#include "OPENGL_mod.hh"

void print_map(int limit_x, int limit_y)
{
    glBegin(GL_QUADS);
    glColor3ub(205,112,84);
    glVertex2d(0, 0);
    glVertex2d(0, limit_y);
    glVertex2d(1, limit_y);
    glVertex2d(1, 0);

    glVertex2d(0, limit_y - 1.5);
    glVertex2d(0, limit_y);
    glVertex2d(limit_x, limit_y);
    glVertex2d(limit_x, limit_y - 1.5);

    glVertex2d(limit_x - 15, 0);
    glVertex2d(limit_x - 15, limit_y);
    glVertex2d(limit_x, limit_y);
    glVertex2d(limit_x, 0);

    glVertex2d(0, 0);
    glVertex2d(0, 1.5);
    glVertex2d(limit_x, 1.5);
    glVertex2d(limit_x, 0);
    glEnd(); 

    glFlush();
}

void print_snack(int x, int y)
{
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
    glVertex2d(x, y);
    glVertex2d(x, y + 1.5);
    glVertex2d(x + 1, y + 1.5);
    glVertex2d(x + 1, y);
    glEnd(); 
    glFlush();
}

void print_apple(int x, int y)
{
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2d(x, y);
    glVertex2d(x, y + 1.5);
    glVertex2d(x + 1, y + 1.5);
    glVertex2d(x + 1, y);
    glEnd(); 
    glFlush();
}

int OPENGL_mod::get_key()
{
    SDL_Event event;
    SDL_EnableKeyRepeat(10,10);

    while (SDL_WaitEvent(&event))
    {
        if(event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
                return 27;
            else if (event.key.keysym.sym == SDLK_UP)
                return 260;
            else if (event.key.keysym.sym == SDLK_DOWN)
                return 261;
            else if (event.key.keysym.sym == SDLK_LEFT)
                return 259;
            else if (event.key.keysym.sym == SDLK_RIGHT)
                return 258;
            else    
                return -1;
        }
    }
}

void print_score(int highscore, int score, int apple_eat, int x)
{
    highscore = 0;
    score = 0;
    apple_eat = 0;
    x = 0;
}

int main(int argc, char *argv[])
{
    int x = 0;
    int y = 0;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Nibbler OpenGL",NULL);
    SDL_SetVideoMode(800, 480, 32, SDL_OPENGL);
    
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, 51, 0, 51, 0, 51);

    SDL_Event event;

    SDL_EnableKeyRepeat(10,10);

    while (SDL_WaitEvent(&event))
    {
        if(event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    exit (0);
                break;
                case SDLK_UP:
                if (y < 48)
                    y++;
                break;
                case SDLK_DOWN:
                if (y > 2)
                    y--;
                break;
                case SDLK_LEFT:
                if (x > 1)
                    x--;
                break;
                case SDLK_RIGHT:
                if (x < 35)
                    x++;
                break;
            }
            glClear(GL_COLOR_BUFFER_BIT+GL_DEPTH_BUFFER_BIT);
        }
        print_map(51, 51);
        print_snack(x, y);
        print_apple(15, 21);
        print_score(1252, 15, 5, 0);
        SDL_GL_SwapBuffers();
    }
    return 0;
}