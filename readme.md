

# Steps to Use

### 1: Create a Binary Pixel Art Image  

You can create binary pixel art using any text editor.

- **Recommended:** Use an image or create a pixel art design. Use a converter such as [dCode Binary Image Converter](https://www.dcode.fr/binary-image).  
- **Adjustments:** The output from the website might neet to be edited.
- **Specifications:**  
  - **Size:** 64 × 64 pixels recommended.  
  - **Width:** The image **must** be 64 bits wide.
  - **Height:** The height **must** be a multiple of 8- 

---

### 2: Edit the Makefile with Your Input File Name  

Modify the `Makefile` to specify your input file:

```makefile
INPUT_FOLDER = ./inputs
INPUT_FILE = [input_file_name]
```

You can also test with the included inputs.

---

### 3: Create the Input File  

1. **Write the Number of Columns (N):**  
   - `N` is the number of columns in your bit art.  
   - `N` must be a multiple of 8.

2. **Paste Your Bit Art:**  
   - Place the binary pixel art below.

---

### 4: Transform to an Array  

Use the `Makefile` to process your input file:  

1. **Compile the Converter Program:**  
   ```bash
   make converter
   ```

2. **Convert the Input File:**  
   ```bash
   make drawing
   ```

You can also execute both steps with:  
```bash
make all
```

---

### 5: Move the needed files to Proteus  

Copy the following files to your Proteus project:  

- `animation.h`  
- `drawing.h`  
- All files in the `dependencies` folder.  

---

### 6: Include necessary Headers  

In your code, include the following headers **in order**:  

```c
#include "GLCD.h"
// afterwards
#include "animation.h"
```

---

### 7: Use the Functions  

1. **Write the Drawing:**  
   ```c
   writeDrawing();
   ```
   - Displays your drawing on the screen.  

2. **Animate the Drawing:**  
   ```c
   animateDrawing();
   ```
   - Executes an animated scrolling loop after displaying the drawing.  

---
