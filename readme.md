

# Steps to Use

### 1: Create a Binary Pixel Art Image  

You can create binary pixel art using any text editor.

- **Recommended:** Use an image or create a pixel art design. Use a converter such as [dCode Binary Image Converter](https://www.dcode.fr/binary-image) to transform it into a bitmap.  
- **Adjustments:** You might want to edit some of the pixels from the result.
- **Size:**  
  - **Width:** The image should be 128 pixels wide or less to fit in the GLCD.
  - **Height:** The height **must** be a multiple of 8 and should be 64 pixels high or less to fit in the GLCD.

---

### 2: Edit the Makefile with Your Input File Name  

Modify the `Makefile` to specify the name of your input/output file:

```makefile
FILE_NAME = doner
INPUT_FILE = $(FILE_NAME).inp
OUTPUT_FILE = $(FILE_NAME).h
```

You can also test with the included inputs in the `inputs` folder.

---

### 3: Create the Input File  

**It should follow the following structure:**

```
name
N (rows)
M (columns)
[bitmap]
```

1. **Write the name for your resulting array**   

2. **Write the Number of rows (N) and columns (M):**  
   - `N` is the number of rows in your bit art.  
   - `N` must be a multiple of 8.
   - `M` is the number of columns in your bit art.
   - Be sure to add separation after each number with a space or newline

3. **Paste Your Bit Art:**  
   - Paste the binary pixel art below.

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

You can also execute both steps with make:  
```bash
make 
```

---

### 5: Move the needed file to Proteus  

Copy the resulting header file to your Proteus project:  

- `drawing.h`  

