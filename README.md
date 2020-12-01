# XO game with pure C

## Table of contents

- [General info](#general-info)
- [Technologies](#technologies)
- [Setup](#setup)

## General info

This project is simple XO game made by pure C .
i used makefile to make life easier

## Technologies

Project is created with:

- SDL2
- SDL2_image
- SDL2_gfx

## Setup

To run this project , u have to install SDL2, SDL2_image, SDL2_gfx

    they are the same to install :
    * dowload -> extact -> cd to folder
    * ./configure
    * make all
    * sudo make install
    * then in the make file add this to the flags u are compiling with :
    	-L/usr/local/lib -lSDL2 -lm -lSDL2_image  -lSDL2_gfx

## to clone repo

    git clone https://github.com/salahbesbes/XO_game_with_c

## How to use it

    * compile it with :
    make
    * execute:
    ./a.out
    * enjoy :)
