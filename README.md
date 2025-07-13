OpenGL 3D Graphics Project
A comprehensive OpenGL application built with FreeGLUT that renders both 2D and 3D geometric shapes with interactive controls, lighting, and transformations.
🎯 Features
Shape Rendering

2D Shapes: Rectangle, Hexagon, Circle
3D Shapes: Cube, Pyramid, Sphere
Real-time shape switching with function keys (F1-F6)
Proper depth perception for 3D objects with perspective projection

Interactive Controls

Color Selection: 5 different colors (Cyan, Red, Green, Orange, Blue)
Shape Rotation: Toggle rotation with spacebar
Scaling: Increase/decrease object size with +/- keys
Movement: Navigate objects with arrow keys
Right-click Menu: Context menu for shape and color selection

Visual Features

Lighting System: Ambient and diffuse lighting for 3D objects
Wireframe Outlines: Black edges for all shapes
Smooth Animations: Time-based rotation for consistent movement
Boundary Checking: Objects stay within window bounds
User Information: Name and student ID displayed on screen

🛠️ Requirements
Dependencies

OpenGL: Graphics rendering
FreeGLUT: Window management and utilities
C++ Compiler: C++11 or later

System Requirements

Operating System: Windows, Linux, or macOS
OpenGL 2.1 or higher
Minimum 800x800 screen resolution

🚀 Installation
Linux (Ubuntu/Debian)
bashsudo apt-get update
sudo apt-get install freeglut3-dev libglu1-mesa-dev
Windows

Download FreeGLUT from official website
Extract and configure with your IDE
Link against: opengl32.lib, glu32.lib, freeglut.lib

macOS
bashbrew install freeglut
🔧 Compilation
Linux/macOS
bashg++ -o OpenGL_Project OpenGL_Project.cpp -lGL -lGLU -lglut
Windows (Visual Studio)

Create new C++ project
Add FreeGLUT include and library paths
Link required libraries
Build and run

🎮 Controls
Shape Selection

F1: Rectangle (2D)
F2: Hexagon (2D)
F3: Circle (2D)
F4: Cube (3D) - Default
F5: Pyramid (3D)
F6: Sphere (3D)

Color Selection

1: Cyan (Default)
2: Red
3: Green
4: Orange
5: Blue

Object Manipulation

Spacebar: Toggle rotation on/off
Arrow Keys: Move object (↑↓←→)
+ / =: Scale up
-: Scale down
ESC: Exit application

Menu System

Right Click: Open context menu

Shape selection submenu
Color selection submenu
Toggle rotation
Exit application



🏗️ Technical Implementation
Architecture

Modular Design: Separate functions for rendering, input handling, and transformations
State Management: Global variables for current shape, color, and transformation states
Event-Driven: Callback-based input handling with GLUT

Rendering Pipeline

Projection Setup: Perspective projection for 3D depth
Lighting Configuration: Directional light with ambient and diffuse components
Shape Rendering: Conditional lighting based on 2D/3D shape type
Transformation Application: Translation, rotation, and scaling
Wireframe Overlay: Black outlines for shape definition

Key Algorithms

Smooth Rotation: Time-based animation using glutGet(GLUT_ELAPSED_TIME)
Boundary Checking: Constraint-based movement within window bounds
Material Properties: Dynamic material assignment based on selected color
Normal Calculation: Proper surface normals for lighting calculations

📁 Project Structure
OpenGL_Project/
├── OpenGL_Project.cpp    # Main source file
├── README.md            # This file
└── LICENSE             # License file
🎨 Default Settings

Window Size: 800x800 pixels
Background: Light gray (0.9, 0.9, 0.9)
Default Shape: Cube (3D)
Default Color: Cyan
Initial Position: Center of screen
Initial Scale: 1.0x
Rotation: Disabled

🔍 Code Highlights
Shape Rendering System
cppvoid drawShape() {
    bool is3D = currentShape > 2;
    
    if (is3D) {
        glEnable(GL_LIGHTING);
        applyMaterial();
    } else {
        glDisable(GL_LIGHTING);
        applyColor();
    }
    // Shape-specific rendering...
}
Smooth Animation
cppvoid idle() {
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
    int elapsedTime = currentTime - lastTime;
    
    if (isRotating) {
        rotationAngle += 0.05f * elapsedTime;
        glutPostRedisplay();
    }
    
    lastTime = currentTime;
}
🐛 Troubleshooting
Common Issues

Black Screen: Check if OpenGL drivers are installed
Compilation Errors: Verify FreeGLUT is properly linked
Performance Issues: Update graphics drivers
Menu Not Appearing: Ensure right-click functionality is enabled

Platform-Specific Notes

Linux: May require libxi-dev and libxmu-dev packages
Windows: Ensure proper DLL files are in the executable directory
macOS: Use #include <GLUT/glut.h> instead of #include <GL/glut.h>

📋 Assignment Requirements
This project fulfills all requirements for the OpenGL Graphics course assignment:

✅ 2D and 3D shape rendering (20 points)
✅ Color selection and default settings (20 points)
✅ Rotation control and exit functionality (20 points)
✅ Scaling functionality (5 points)
✅ Movement with boundary checking (10 points)
✅ User information display (5 points)
✅ Right-click menu system (10 points)
✅ 3D lighting implementation (10 points)

👨‍💻 Author
ERVIS TZITZA
Student ID: 2589
🤝 Contributing
This is an academic project. For educational purposes, feel free to:

Fork the repository
Study the implementation
Suggest improvements
Report issues

🔗 References

OpenGL Documentation
FreeGLUT Documentation
OpenGL Programming Guide


This project was developed as part of the Computer Graphics course assignment at the University.
