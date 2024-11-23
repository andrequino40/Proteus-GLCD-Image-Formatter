# STEPS TO USE #

### 1: Create binary pixelart image  

    Possible with any text editor.

    I recommend finding a suitable image or creating a pixelart and then using a converter such as https://www.dcode.fr/binary-image 
    Then most likely you'll need to manually change the result

    Recommended result: 64 * 64
    The result **has to be 64 bits wide**

### 2: Edit the Makefile with your input file name 
    INPUT_FOLDER = ./inputs
    INPUT_FILE = \[input_file_name\]

    You can also test the included inputs

### 3: Create the file 

    Write a number *N* at the start of your file
    - N is the number of columns of your bitart
    - **N has to be a multiple of 8**

    Paste the bitart afterwards

### 4: Transform to an array  
    Use the Makefile

    Compile the included program: 
    - make converter 

    Convert your input file 
    - make drawing

    (you can also use make all)
    

### 5: Move the needed files to Proteus
    animation.h 
    drawing.h
    (also the files in "dependencies")

### 6: In your code 
   
   You **have** to include:

   #include "ascii.h"
   #include "GLCD.h"
   
   and **after** that:

   #include "animation.h"

### 7: use the functions 

    writeDrawing()
    - Writes your drawing on the screen

    animateDrawing()
    - Animated scrolling loop after you have written on the screen


