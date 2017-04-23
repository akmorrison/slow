#ifndef ARGS_H_
#define ARGS_H_
#include <string>

using namespace std;

struct Args{
        Args(int argc, char* argv[]);
        int speed; //the amount of microseconds between each redraw of the screen
        string (*get_string_func)(string, int, int, int, int);
        bool print_help;
};

#endif
