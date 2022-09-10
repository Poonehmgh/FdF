# FdF
FdF Project for making isometric projection or Wireframe models\n

MiniLibX, the graphical tool:\n

I have used the school graphical library: the MiniLibX. This library was
developed internally and includes basic necessary tools to open a window, create images
and deal with keyboard and mouse events.

-------------------------------------------------------------------------------------------------------------------

Project description: 

This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges).
The project must comply with the following rule:\n
• To use the MiniLibX. Either the version available on the school machines,
or installing it using its sources.
The program has to represent the model in isometric projection.
The coordinates of the landscape are stored in a .fdf file passed as a parameter to program.
-------------------------------------------------------------------------------------------------------------------

Each number represents a point in space:
• The horizontal position corresponds to its axis.
• The vertical position corresponds to its ordinate.
• The value corresponds to its altitude.
-------------------------------------------------------------------------------------------------------------------

Graphic management
• The program has to display the image in a window.
• The management of window must remain smooth (changing to another window, minimizing, and so forth).
• Pressing ESC must close the window and quit the program in a clean way.
• Clicking on the cross on the window’s frame must close the window and quit the
program in a clean way.
• The use of the images of the MiniLibX is mandatory.

-------------------------------------------------------------------------------------------------------------------
My Approcach: 

Line with Bresenham, 
a good guide: 

https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/

-------------------------------------------------------------------------------------------------------------------

Isometric conversion:

x_iso = (x - y)cos(a)

y_iso = (x_iso + y)sin(a)-z

-------------------------------------------------------------------------------------------------------------------

A good guide: 

https://github.com/nikGrape/FDF/blob/master/README.md

-------------------------------------------------------------------------------------------------------------------

My challenges: 

I didnt know what to do with negative numbers. Because after converting the numbers to isometric coordinates the Xs and Ys became negative. The answer was easy: just make some offset to overcome the negative values :))

Every dot should only be connected to its right and down dot. That is enough. So for drawing I go from top left to bottom right of map. 


