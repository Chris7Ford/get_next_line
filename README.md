# Get Next Line

### Purpose
The point of this project is to make a function that fills a pointer to character variable with a line of a given file, regardless of its length, so the caller can use it however it likes.  I was allowed to use only system calls:

*read*,
*malloc*
and *free*

To use it, just compile with the *get_next_line.c* file.  The function is prototyped like this:

`int     get_next_line(const int fd, char **line)`

Yes, there are much better ways to use this in C, but the point of the project is to manage the data coming in from the file, manage the memory appropriately and learn about static variables and their usefulness.

Want to know more about this project?

Feel free to read the included PDF instructions, or you can check out the article I wrote about it [here](https://medium.com/@fordchristoph3r/re-creating-the-line-getter-from-scratch-ecae32252d88).


![Grade](https://user-images.githubusercontent.com/29003743/62430780-d9361400-b6d5-11e9-8d3d-9a6f4422619f.png)

![Progress](https://user-images.githubusercontent.com/29003743/62430707-e1da1a80-b6d4-11e9-901f-1415f15520ea.png)
