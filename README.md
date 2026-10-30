# Description

**get_next_line** is a project from the 42 common core . The goal is to create a function that reads a file descriptor and returns one line at a time, allowing a program to process files without reading the entire content into memory at once.

The function prototype is:

```
char *get_next_line(int fd);
```

Each call returns the next line, including the newline character (`\n`) if one is present. When there are no more lines to read, or an error occurs, the function returns `NULL`. **The returned line must be freed by the caller**.

The project consists of the following files:

- `get_next_line.c` — contains the main function and manages reading and line extraction.
- `get_next_line_utils.c` — contains helper functions used to manipulate strings and manage the stash.
- `get_next_line.h` — contains function prototypes, required headers, and the default value of `BUFFER_SIZE`.

# Instructions

## Compilation

Compile the source files together with your own `main.c` test file:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o your_program
```

The `BUFFER_SIZE`  determines how many bytes are read in each call to `read()`. You can change its value during compilation to test different buffer sizes.

If `BUFFER_SIZE` is not defined during compilation, the project uses the default value specified in `get_next_line.h`.


**Remember to free each returned line to avoid memory leaks.**

# Algorithm


1. **Initialize the reading process.** The function uses a static pointer named `stash` to preserve unread data between calls to `get_next_line()`. Unlike an ordinary local variable, a static variable retains its value after the function returns.

2. **Read data in chunks.** The program allocates a temporary buffer of `BUFFER_SIZE + 1` bytes and uses `read()` to retrieve data from the file descriptor.

3. **Append the data to the stash.** Each chunk is appended to the existing stash using `ft_strjoin`. The combined string contains all data read so far that has not yet been returned as a line.

4. **Extract the next line.** Once a newline is found, the function allocates memory for a new string and copies the characters up to and including the newline. If the end of the file is reached without another newline, the remaining characters form the final line.

5. **Preserve the remaining data.** After extracting the line, the returned portion is removed from the stash. Any characters following the newline remain stored for the next call, avoiding unnecessary rereading.

6. **Return the line.** The function returns the allocated line to the caller. The caller is responsible for freeing it after use.

7. **Handle the end of the file and errors.** When no data remains, the function returns `NULL`.

# Resources

- **42 get_next_line subject:** The project specification provided by the 42 curriculum.
- **GeeksforGeeks** — Static Variables in C
- **Youtube - Oceano** — get_next_line explained : develop a function that reads a file line by line
- **42 peers**

## Use of AI

AI assistance was used for visualizing the steps in the algorithm, and memory management understanding .

**All code was thought and written by kpagkalo**
