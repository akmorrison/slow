#ifndef ARGS_H_
#define ARGS_H_

struct Args{
        Args(int argc, char* argv[]);
        int speed; //the amount of microseconds between each redraw of the screen
};

#endif
