# Fractol
Create beautiful fractales. 

## Description
This program written in C allows the user to create and manipulate repetitive geometrical figures called fractales. 
<img src="https://donsefactory.files.wordpress.com/2020/02/fractale_03.gif" width=500 height=500/>

Features:
* Infinite zooming(up to computer capabilities) 
* 3 different types of fractals: Mandelbrot, Julia, burning_ship
* 9 colors sets + 1 randomize color set
* Redefine julia fractals through mouse cursor ('L' key to activate)
* Increase/decrease iterations
* Multithreaded

<img src="https://donsefactory.files.wordpress.com/2020/02/fractale_04.gif" width=500 height=500/>
<img src="https://donsefactory.files.wordpress.com/2020/02/fractale_02.gif" width=500 height=500/>

## Installation
***Only works on MacOS with provided library***<br/>
Install the library and program by typing: <br/>
`make`

OpenGL has to be installed as it is required by the MLX library.

## Usage
`./fractol [mandelbrot/julia//burning_ship/]`
