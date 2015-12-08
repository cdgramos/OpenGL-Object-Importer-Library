VERSION 1.0

1) Object declaration:

	Model humanModel;
	
2) Loading Functions:
	
	humanModel = loadModel("human.obj");
	>this will load all the data supported at this moment.
	
3) Drawing Functions:

	drawModelVertex(int , Model);
	>this function will draw the vertices of a loaded object. the first parmeter is the vertice point size and the second is the object.
	
	
	drawModelFaces(humanModel);
	>this function only support simple faces yet. it takes as parameter object and draw it's faces.