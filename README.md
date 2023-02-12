# VisFractal

## Description
Tool for visualizing fractals.
At the moment only **The Mandelbrot Set** available.

## Prerequisites
You need SFML library installed on your system in order to build VisFractal.

## Building and running
Clone repo, then navigate to root dir.
```bash
mkdir build
cd build
cmake ..
make
./visfractal
```

## Playing around
At the moment, there's no much you can experiment with.
There's no configuration files or command line args to change something yet. You can edit code itself.
Most of things you can play with are set up in `main.cc` file.
You can change:
- screen and picture resolution;
- name of picture file that is stored on disk.
- Coplex plane area that set is calculated at.
