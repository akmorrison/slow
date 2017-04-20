#include"args.h"
#include"animations.h"
#include<iostream>
#include<string>
#include<stdlib.h>

void setOption(int& field, char* value){
        field = atoi(value);
        if(field <= 0)
                throw "Invalid speed parameter";
}

Args::Args(int argc, char* argv[]){
        //default values
        speed = 100 * 1000;
        get_string_func = string_to_print_tl;

        bool skip_flag = false;
        for(int i = 1; i < argc; i++){
                if(skip_flag){
                        skip_flag = false;
                        goto endfor;
                }
                //if the argument starts with a -
                if(*argv[i] == '-'){
                        while(*(++argv[i])){
                                if(*argv[i] == 'u'){
                                        if(i == argc -1)
                                                throw "Missing parameter";
                                        setOption(speed, argv[i+1]);
                                        skip_flag = true;
                                        goto endfor;
                                }
                                else{
                                        throw "Unrecognized Option!";
                                }
                        }
                }
                endfor:
                continue;
        }
}
