# OpenGL 3D Graphics Project
A comprehensive OpenGL application built with FreeGLUT that renders both 2D and 3D geometric shapes with interactive controls, lighting, and transformations.

## Features
- **Shape Rendering**: Display 2D shapes (Rectangle, Hexagon, Circle) and 3D shapes (Cube, Pyramid, Sphere)
- **Interactive Controls**: Real-time shape switching with function keys (F1-F6)
- **Color Selection**: 5 different colors (Cyan, Red, Green, Orange, Blue) with number keys
- **Shape Rotation**: Toggle smooth rotation with spacebar for enhanced visualization
- **Scaling**: Increase/decrease object size with +/- keys
- **Movement**: Navigate objects with arrow keys within window bounds
- **Right-click Menu**: Context menu for shape and color selection
- **Lighting System**: Ambient and diffuse lighting for 3D objects with proper depth perception
- **Wireframe Outlines**: Black edges for all shapes for better definition

## Requirements
- **OpenGL**: Graphics rendering library
- **FreeGLUT**: Window management and utilities
- **C++ Compiler**: C++11 or later
- **Operating System**: Windows, Linux, or macOS
- **OpenGL Version**: 2.1 or higher
- **Screen Resolution**: Minimum 800x800 pixels

## Installation
### Linux (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install freeglut3-dev libglu1-mesa-dev
```

### Windows
1. Download FreeGLUT from official website
2. Extract and configure with your IDE
3. Link against: `opengl32.lib`, `glu32.lib`, `freeglut.lib`

### macOS
```bash
brew install freeglut
```

## Compilation
### Linux/macOS
```bash
g++ -o OpenGL_Project OpenGL_Project.cpp -lGL -lGLU -lglut
```

### Windows (Visual Studio)
1. Create new C++ project
2. Add FreeGLUT include and library paths
3. Link required libraries
4. Build and run

## Controls
### Shape Selection
- **F1**: Rectangle (2D)
- **F2**: Hexagon (2D)
- **F3**: Circle (2D)
- **F4**: Cube (3D) - Default
- **F5**: Pyramid (3D)
- **F6**: Sphere (3D)

### Color Selection
- **1**: Cyan (Default)
- **2**: Red
- **3**: Green
- **4**: Orange
- **5**: Blue

### Object Manipulation
- **Spacebar**: Toggle rotation on/off
- **Arrow Keys**: Move object (↑↓←→)
- **+ / =**: Scale up
- **-**: Scale down
- **ESC**: Exit application
- **Right Click**: Open context menu

## Default Settings
- **Window Size**: 800x800 pixels
- **Background**: Light gray (0.9, 0.9, 0.9)
- **Default Shape**: Cube (3D)
- **Default Color**: Cyan
- **Initial Position**: Center of screen
- **Initial Scale**: 1.0x
- **Rotation**: Disabled

## Technical Implementation
### Architecture
- **Modular Design**: Separate functions for rendering, input handling, and transformations
- **State Management**: Global variables for current shape, color, and transformation states
- **Event-Driven**: Callback-based input handling with GLUT

### Key Features
- **Smooth Animation**: Time-based rotation using `glutGet(GLUT_ELAPSED_TIME)`
- **Boundary Checking**: Constraint-based movement within window bounds
- **Material Properties**: Dynamic material assignment based on selected color
- **Normal Calculation**: Proper surface normals for lighting calculations

## Assignment Requirements
This project fulfills all requirements for the OpenGL Graphics course assignment:
- 2D and 3D shape rendering (20 points)
- Color selection and default settings (20 points)
- Rotation control and exit functionality (20 points)
- Scaling functionality (5 points)
- Movement with boundary checking (10 points)
- User information display (5 points)
- Right-click menu system (10 points)
- 3D lighting implementation (10 points)

## Troubleshooting
### Common Issues
- **Black Screen**: Check if OpenGL drivers are installed
- **Compilation Errors**: Verify FreeGLUT is properly linked
- **Performance Issues**: Update graphics drivers
- **Menu Not Appearing**: Ensure right-click functionality is enabled

### Platform-Specific Notes
- **Linux**: May require `libxi-dev` and `libxmu-dev` packages
- **Windows**: Ensure proper DLL files are in the executable directory
- **macOS**: Use `#include <GLUT/glut.h>` instead of `#include <GL/glut.h>`

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
