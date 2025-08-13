./*This program is a simple OpenGL application that allows the user to draw and manipulate 2D and 3D shapes with various colors and transformations.
 * It uses the FreeGLUT library for window management and input handling.
 * The program supports basic shapes like rectangles, hexagons, circles, cubes, pyramids, and spheres.
 * Users can change the shape, color, and apply transformations like rotation and scaling.
 * The code is written in C++ using the C++17 standard.
*/

#include <GL/freeglut.h>
#include <cmath>
#include <string>

// Καθολικές μεταβλητές
int currentShape = 3;            // Προεπιλεγμένο σχήμα: κύβος (F4)
int currentColor = 0;            // Προεπιλεγμένο χρώμα: κυανό (1)
bool isRotating = false;         // Κατάσταση περιστροφής
float rotationAngle = 0.0f;      // Γωνία περιστροφής
float scaleValue = 1.0f;         // Συντελεστής κλίμακας
float posX = 0.0f, posY = 0.0f;  // Θέση αντικειμένου
int lastTime = 0;                // Για ομαλή κίνηση

// Εφαρμογή του τρέχοντος χρώματος για 2D αντικείμενα
void applyColor() {
    // Πίνακας με τα βασικά χρώματα
    static const float colors[][3] = {
        {0.0f, 1.0f, 1.0f},    // Κυανό (1)
        {1.0f, 0.0f, 0.0f},    // Κόκκινο (2)
        {0.0f, 1.0f, 0.0f},    // Πράσινο (3)
        {1.0f, 0.5f, 0.0f},    // Πορτοκαλί (4)
        {0.0f, 0.0f, 1.0f}     // Μπλε (5)
    };
    
    glColor3fv(colors[currentColor]);
}

// Εφαρμογή υλικού για 3D αντικείμενα
void applyMaterial() {
    GLfloat ambient[4], diffuse[4];
    
    // Βασικά χρώματα - απλοποιημένος φωτισμός
    static const float colors[][3] = {
        {0.0f, 1.0f, 1.0f},    // Κυανό (1)
        {1.0f, 0.0f, 0.0f},    // Κόκκινο (2)
        {0.0f, 1.0f, 0.0f},    // Πράσινο (3)
        {1.0f, 0.5f, 0.0f},    // Πορτοκαλί (4)
        {0.0f, 0.0f, 1.0f}     // Μπλε (5)
    };
    
    for (int i = 0; i < 3; i++) {
        ambient[i] = colors[currentColor][i] * 0.3f;
        diffuse[i] = colors[currentColor][i];
    }
    ambient[3] = diffuse[3] = 1.0f;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
}

// Σχεδίαση του τρέχοντος σχήματος
void drawShape() {
    bool is3D = currentShape > 2;  // Σχήματα 0-2 είναι 2D, 3-5 είναι 3D
    
    if (is3D) {
        glEnable(GL_LIGHTING);
        applyMaterial();
    } else {
        glDisable(GL_LIGHTING);
        applyColor();
    }
    
    // Επιλογή και σχεδίαση σχήματος
    switch (currentShape) {
        case 0: {  // Ορθογώνιο (F1)
            glBegin(GL_QUADS);
                glVertex2f(-2.0f, -1.0f);
                glVertex2f(2.0f, -1.0f);
                glVertex2f(2.0f, 1.0f);
                glVertex2f(-2.0f, 1.0f);
            glEnd();
            
            // Περίγραμμα
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
                glVertex2f(-2.0f, -1.0f);
                glVertex2f(2.0f, -1.0f);
                glVertex2f(2.0f, 1.0f);
                glVertex2f(-2.0f, 1.0f);
            glEnd();
            break;
        }
        case 1: {  // Εξάγωνο (F2)
            glBegin(GL_POLYGON);
                for (int i = 0; i < 6; i++) {
                    float angle = 2.0f * M_PI * i / 6.0f;
                    glVertex2f(1.5f * cos(angle), 1.5f * sin(angle));
                }
            glEnd();
            
            // Περίγραμμα
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
                for (int i = 0; i < 6; i++) {
                    float angle = 2.0f * M_PI * i / 6.0f;
                    glVertex2f(1.5f * cos(angle), 1.5f * sin(angle));
                }
            glEnd();
            break;
        }
        case 2: {  // Κύκλος (F3)
            const int segments = 36;
            glBegin(GL_POLYGON);
                for (int i = 0; i < segments; i++) {
                    float angle = 2.0f * M_PI * i / segments;
                    glVertex2f(1.5f * cos(angle), 1.5f * sin(angle));
                }
            glEnd();
            
            // Περίγραμμα
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
                for (int i = 0; i < segments; i++) {
                    float angle = 2.0f * M_PI * i / segments;
                    glVertex2f(1.5f * cos(angle), 1.5f * sin(angle));
                }
            glEnd();
            break;
        }
        case 3: {  // Κύβος (F4)
            glutSolidCube(2.0f);
            
            // Περίγραμμα
            glDisable(GL_LIGHTING);
            glColor3f(0.0f, 0.0f, 0.0f);
            glutWireCube(2.0f);
            break;
        }
        case 4: {  // Πυραμίδα (F5)
            glBegin(GL_TRIANGLES);
                // Μπροστινή έδρα
                glNormal3f(0.0f, 0.4472f, 0.8944f);
                glVertex3f(0.0f, 1.0f, 0.0f);    // Κορυφή
                glVertex3f(-1.0f, -1.0f, 1.0f);  // Μπροστά-αριστερά
                glVertex3f(1.0f, -1.0f, 1.0f);   // Μπροστά-δεξιά
            
                // Δεξιά έδρα
                glNormal3f(0.8944f, 0.4472f, 0.0f);
                glVertex3f(0.0f, 1.0f, 0.0f);    // Κορυφή
                glVertex3f(1.0f, -1.0f, 1.0f);   // Μπροστά-δεξιά
                glVertex3f(1.0f, -1.0f, -1.0f);  // Πίσω-δεξιά
            
                // Πίσω έδρα
                glNormal3f(0.0f, 0.4472f, -0.8944f);
                glVertex3f(0.0f, 1.0f, 0.0f);    // Κορυφή
                glVertex3f(1.0f, -1.0f, -1.0f);  // Πίσω-δεξιά
                glVertex3f(-1.0f, -1.0f, -1.0f); // Πίσω-αριστερά
            
                // Αριστερή έδρα
                glNormal3f(-0.8944f, 0.4472f, 0.0f);
                glVertex3f(0.0f, 1.0f, 0.0f);    // Κορυφή
                glVertex3f(-1.0f, -1.0f, -1.0f); // Πίσω-αριστερά
                glVertex3f(-1.0f, -1.0f, 1.0f);  // Μπροστά-αριστερά
            glEnd();
            
            // Βάση
            glBegin(GL_QUADS);
                glNormal3f(0.0f, -1.0f, 0.0f);
                glVertex3f(-1.0f, -1.0f, -1.0f);
                glVertex3f(1.0f, -1.0f, -1.0f);
                glVertex3f(1.0f, -1.0f, 1.0f);
                glVertex3f(-1.0f, -1.0f, 1.0f);
            glEnd();
            
            // Περίγραμμα
            glDisable(GL_LIGHTING);
            glColor3f(0.0f, 0.0f, 0.0f);
            
            // Βάση (τετράγωνο) και ακμές προς την κορυφή
            glBegin(GL_LINE_LOOP);
                glVertex3f(-1.0f, -1.0f, -1.0f);
                glVertex3f(1.0f, -1.0f, -1.0f);
                glVertex3f(1.0f, -1.0f, 1.0f);
                glVertex3f(-1.0f, -1.0f, 1.0f);
            glEnd();
            
            glBegin(GL_LINES);
                glVertex3f(-1.0f, -1.0f, -1.0f); glVertex3f(0.0f, 1.0f, 0.0f);
                glVertex3f(1.0f, -1.0f, -1.0f); glVertex3f(0.0f, 1.0f, 0.0f);
                glVertex3f(1.0f, -1.0f, 1.0f); glVertex3f(0.0f, 1.0f, 0.0f);
                glVertex3f(-1.0f, -1.0f, 1.0f); glVertex3f(0.0f, 1.0f, 0.0f);
            glEnd();
            break;
        }
        case 5: {  // Σφαίρα (F6)
            glutSolidSphere(1.5f, 32, 32);
            
            // Περίγραμμα
            glDisable(GL_LIGHTING);
            glColor3f(0.0f, 0.0f, 0.0f);
            glutWireSphere(1.5f, 16, 16);
            break;
        }
    }
}

// Συνάρτηση εμφάνισης
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Σχεδίαση αντικειμένου
    glPushMatrix();
    glTranslatef(posX, posY, 0.0f);
    glScalef(scaleValue, scaleValue, scaleValue);
    
    // Περιστροφή ανάλογα με το αν είναι 2D ή 3D
    if (currentShape <= 2) {
        glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);  // 2D: περιστροφή γύρω από Z
    } else {
        glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);  // 3D: περιστροφή γύρω από Y
    }
    
    drawShape();
    glPopMatrix();
    
    // Σχεδίαση στοιχείων
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800);
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    glDisable(GL_LIGHTING);
    glColor3f(0.0f, 0.0f, 0.0f);  // Μαύρο κείμενο
    std::string text = "Authored by: Your Name";
    glRasterPos2i(10, 780);
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
    
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    
    glutSwapBuffers();
}

// Συνάρτηση χειρισμού πληκτρολογίου
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Επιλογή χρώματος με πλήκτρα 1-5
        case '1': case '2': case '3': case '4': case '5':
            currentColor = key - '1';
            break;
        
        // Εναλλαγή περιστροφής με Space
        case ' ':
            isRotating = !isRotating;
            break;
        
        // Μεγέθυνση/Σμίκρυνση
        case '+': case '=':
            scaleValue = std::min(scaleValue + 0.1f, 3.0f);
            break;
        
        case '-':
            scaleValue = std::max(scaleValue - 0.1f, 0.2f);
            break;
        
        // Έξοδος με Escape
        case 27:
            exit(0);
            break;
    }
    
    glutPostRedisplay();
}

// Συνάρτηση χειρισμού ειδικών πλήκτρων
void specialKeys(int key, int x, int y) {
    float maxPos = 2.0f;
    float moveStep = 0.2f;
    
    switch (key) {
        // Επιλογή σχήματος με F1-F6
        case GLUT_KEY_F1: case GLUT_KEY_F2: case GLUT_KEY_F3:
        case GLUT_KEY_F4: case GLUT_KEY_F5: case GLUT_KEY_F6:
            currentShape = key - GLUT_KEY_F1;
            break;
        
        // Κίνηση με τα βέλη
        case GLUT_KEY_LEFT:
            posX = std::max(posX - moveStep, -maxPos);
            break;
        case GLUT_KEY_RIGHT:
            posX = std::min(posX + moveStep, maxPos);
            break;
        case GLUT_KEY_UP:
            posY = std::min(posY + moveStep, maxPos);
            break;
        case GLUT_KEY_DOWN:
            posY = std::max(posY - moveStep, -maxPos);
            break;
    }
    
    glutPostRedisplay();
}

// Συνάρτηση idle για ομαλή κίνηση
void idle() {
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
    int elapsedTime = currentTime - lastTime;
    
    if (isRotating) {
        rotationAngle += 0.05f * elapsedTime;
        if (rotationAngle > 360.0f) {
            rotationAngle -= 360.0f;
        }
        glutPostRedisplay();
    }
    
    lastTime = currentTime;
}

// Δημιουργία μενού
void createMenu() {
    int shapeMenu = glutCreateMenu([](int id) {
        currentShape = id;
        glutPostRedisplay();
    });
    glutAddMenuEntry("Rectangle", 0);
    glutAddMenuEntry("Hexagon", 1);
    glutAddMenuEntry("Circle", 2);
    glutAddMenuEntry("Cube", 3);
    glutAddMenuEntry("Pyramid", 4);
    glutAddMenuEntry("Sphere", 5);
    
    int colorMenu = glutCreateMenu([](int id) {
        currentColor = id;
        glutPostRedisplay();
    });
    glutAddMenuEntry("Cyan", 0);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Orange", 3);
    glutAddMenuEntry("Blue", 4);
    
    glutCreateMenu([](int id) {
        switch (id) {
            case 1: isRotating = !isRotating; break;
            case 2: exit(0); break;
        }
        glutPostRedisplay();
    });
    glutAddSubMenu("Shape", shapeMenu);
    glutAddSubMenu("Color", colorMenu);
    glutAddMenuEntry("Toggle Rotation", 1);
    glutAddMenuEntry("Exit", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Η κύρια συνάρτηση του προγράμματος
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("ERGASIA");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutIdleFunc(idle);
    createMenu();
    glClearColor(0.9f, 0.9f, 0.9f, 1.0f);  // Ανοιχτό γκρι φόντο
    glEnable(GL_DEPTH_TEST);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -8.0f);
    
    // Απλοποιημένη ρύθμιση φωτισμού
    GLfloat lightPos[] = { 5.0f, 5.0f, 5.0f, 1.0f };
    GLfloat ambLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat diffLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffLight);
    
    glEnable(GL_LIGHT0);
    
    glutMainLoop();
    return 0;
}



