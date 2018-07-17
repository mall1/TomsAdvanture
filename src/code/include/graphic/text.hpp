#ifndef TEXT_HPP
#define TEXT_HPP

#include <GL/glut.h>
#include <string>



void textdisplay(double x, double y, std::string text){
    glDisable(GL_DEPTH_TEST);
    glPushMatrix();
    glOrtho(-1,1,-1,1,-1,1);
    glRasterPos2f(x,y);
    for (unsigned int i=0; i<text.size(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
    glPopMatrix();

}


void getFPS()
{
    static int frame = 0, time, timebase = 0;
    std::string buffer;

    frame++;
    time=glutGet(GLUT_ELAPSED_TIME);
    if (time - timebase > 1000) {
        buffer="FPS:%4.2f"+std::to_string(frame*1000.0/(time-timebase));
        timebase = time;
        frame = 0;
    }
    glColor4b(1,0,0,1);
    textdisplay(0.1,0.1, buffer);
}




#endif // TEXT_HPP
