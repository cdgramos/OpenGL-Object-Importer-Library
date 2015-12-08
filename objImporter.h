/***************************************
Developed by: Cristiano Ramos
E-mail: cdgramos@live.com.pt
Web site: www.cdgramos.com
This library is licensed by: CC BY-SA 
**************************************/

/***************************************
This library allows you to import OBJ 
models to your OpenGL project in C.
**************************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct{
	float X;
	float Y;
	float Z;
} vertex;

typedef struct{
	int vNumber;
	float *Faces;
} faces;


typedef struct{
	int totV;
	int totF;
	vertex *v;
	faces *f;
}Model;



Model loadModel(char *fileName){
	FILE *pFile;
 	char mystring [100];
 	char myAuxstring [100];
  char *pch;
  int i=0;
  int j=0;
  int space=0;

  Model objModel;

  pFile = fopen (fileName, "r");
    if (pFile == NULL) perror ("Error opening file");
 
  //count the vertex number
  while(fgets (mystring , 100 , pFile) != NULL ){
    if(strcmp(strtok (mystring," "),"v")==0)
      i++;
	}

	//total of vertex
	objModel.totV=i;
	objModel.v = malloc(i * sizeof(vertex));
	rewind(pFile);
  i=0;

  //count the faces number
  	while(fgets (mystring , 100 , pFile) != NULL ){
    if(strcmp(strtok (mystring," "),"v")==0)
    i++;
	}

	//total of faces
	objModel.totF=i;
	objModel.f = malloc(i * sizeof(vertex));
	rewind(pFile);
	i=0;


  //count how many vertex a face have
  while(fgets (mystring , 100 , pFile) != NULL ){
  	for (i=0;i<strlen(mystring);i++) if(mystring[i]==' ') space++;
    	if(strcmp(strtok (mystring," "),"f")==0){   	
        if(space==3){
        	objModel.f[j].Faces = malloc (3 * sizeof(float));
				  objModel.f[j].vNumber=3;
        }
        if(space==4){
        	objModel.f[j].Faces = malloc (4 * sizeof(float));
				  objModel.f[j].vNumber=4;
        }
        j++;
    	}
    	space=0;
	}

  rewind(pFile);
  i=0;j=0;


  //parsing vertex
  while(fgets (mystring , 100 , pFile) != NULL ){
    if(strcmp(strtok (mystring," "),"v")==0){
      pch = strtok (NULL, " ");
    	if(pch!=NULL) objModel.v[i].X=atof(pch);
        pch = strtok (NULL, " ");
      if(pch!=NULL) objModel.v[i].Y=atof(pch);
        pch = strtok (NULL, " ");
      if(pch!=NULL) objModel.v[i].Z=atof(pch);
        i++;
    }	
	}

	rewind(pFile);
  i=0;
 

 	//parsing faces
  while(fgets (mystring , 100 , pFile) != NULL ){
    if(strcmp(strtok (mystring," "),"f")==0){
    	if(objModel.f[j].vNumber==3){
        pch = strtok (NULL, " ");
        if(pch!=NULL) objModel.f[j].Faces[0]=atoi(pch);
          pch = strtok (NULL, " ");
        if(pch!=NULL) objModel.f[j].Faces[1]=atoi(pch);
          pch = strtok (NULL, " ");
        if(pch!=NULL) objModel.f[j].Faces[2]=atoi(pch);
    	}

    	if(objModel.f[j].vNumber==4){
      	pch = strtok (NULL, " ");
      	if(pch!=NULL) objModel.f[j].Faces[0]=atoi(pch);
        	pch = strtok (NULL, " ");
      	if(pch!=NULL) objModel.f[j].Faces[1]=atoi(pch);
         	pch = strtok (NULL, " ");
      	if(pch!=NULL) objModel.f[j].Faces[2]=atoi(pch);
        	pch = strtok (NULL, " ");
      	if(pch!=NULL) objModel.f[j].Faces[3]=atoi(pch);    	    			
    	}
      i=0;
      j++;
    }	
	}

  fclose (pFile);
	return objModel;
}





void drawModelVertex(float pointSize, Model objModel){
    int i;
    for(i=0;i<objModel.totV;i++){
        glPointSize(pointSize);
        glBegin(GL_POINTS);
        glVertex3f(objModel.v[i].X,objModel.v[i].Y,objModel.v[i].Z);
    glEnd();
    }
}




void drawModelFaces(Model objModel){
    int i;
    int j;
    int v1,v2,v3,v4;
    for(i=0;i<objModel.totF;i++){
    	if(objModel.f[i].vNumber==3){
    		glBegin(GL_TRIANGLE_FAN);
    			v1=objModel.f[i].Faces[0];
    			v2=objModel.f[i].Faces[1];
    			v3=objModel.f[i].Faces[2];
    			v1--;v2--;v3--;
    		    glVertex3f(objModel.v[v1].X,objModel.v[v1].Y,objModel.v[v1].Z);
    		    glVertex3f(objModel.v[v2].X,objModel.v[v2].Y,objModel.v[v2].Z);
    		    glVertex3f(objModel.v[v3].X,objModel.v[v3].Y,objModel.v[v3].Z);
    		glEnd();
    	}
    	if(objModel.f[i].vNumber==4){
    		glBegin(GL_TRIANGLE_FAN);
    			v1=objModel.f[i].Faces[0];
    			v2=objModel.f[i].Faces[1];
    			v3=objModel.f[i].Faces[2];
    			v4=objModel.f[i].Faces[3];
    			v1--;v2--;v3--;v4--;
    		    glVertex3f(objModel.v[v1].X,objModel.v[v1].Y,objModel.v[v1].Z);
    		    glVertex3f(objModel.v[v2].X,objModel.v[v2].Y,objModel.v[v2].Z);
    		    glVertex3f(objModel.v[v3].X,objModel.v[v3].Y,objModel.v[v3].Z);
    		    glVertex3f(objModel.v[v4].X,objModel.v[v4].Y,objModel.v[v4].Z);
    		glEnd();
    	}
    }	
}


