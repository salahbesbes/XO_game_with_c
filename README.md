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

- ## Linux

  Make sure you have some thing to unzip files and GCC:

        sudo apt-get update -y
        sudo apt install unzip -y
        sudo apt-get install -y libghc-sdl-gfx-dev
        sudo apt install build-essential
        sudo apt-get install xorg-dev
        sudo apt-get install lib32z1

  Install [SDL2](https://www.libsdl.org/release/SDL2-2.0.20.zip) & [SDL2_image](https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.5.zip) & [SDL_gfx](https://sourceforge.net/projects/sdl2gfx/)

        unzip filename.zip -d ~
        cd ~/SDL-folder
        ./configure
        make all
        sudo make install

- ## Windows

## to clone repo

    git clone https://github.com/salahbesbes/XO_game_with_c

## How to use it

    * compile it with :
    make
    * execute:
    ./a.out
    * enjoy :)

- then in the make file add this to the flags u are compiling with :
  -L/usr/local/lib -lSDL2 -lm -lSDL2_image -lSDL2_gfx
