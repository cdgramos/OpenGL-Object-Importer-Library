# OpenGL Object Importer Library

This library is designed to import .obj files into OpenGL scenes.


## Features
* Support the drawing of the .obj vertices
* Support the drawing of the .obj simple faces



## Usage

To use this library, it is only needed to import the `objImporter.h` header file. 
The functions are explained below, and there is also a sample program in `example.c`.


### Object declaration

```c
// This will load the supported data from the obj file.
Model humanModel;
```


### Object loading

```c
// This will load the supported data from the obj file.
humanModel = loadModel("human.obj");
```



### Drawing functions
```c
// This function will draw the vertices of a loaded object. The first parameter is the vertice point size and the second is the object.
drawModelVertex(int , Model);
```

```c
// This function only supports simple faces. It accepts as the parameter an object and draws its faces.
drawModelFaces(humanModel);
```


## Sample picture of an imported object
![Sample model](Misc/human.jpg)

## Change Log
* 08-12-2015 - First version



## Acknowledgments
* `human.obj` model from opengameart.com
