#ifndef _SCENE_H_
#define _SCENE_H_

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "Camera.h"
#include "Color.h"
#include "Model.h"
#include "Rotation.h"
#include "Scaling.h"
#include "Translation.h"
#include "Triangle.h"
#include "Vec3.h"
#include "Vec4.h"

using namespace std;

class Scene
{
public:
	Color backgroundColor;
	bool cullingEnabled;
	int projectionType;

	vector< vector<Color> > image;
	vector< Camera* > cameras;
	vector< Vec3* > vertices;
	vector< Color* > colorsOfVertices;
	vector< Scaling* > scalings;
	vector< Rotation* > rotations;
	vector< Translation* > translations;
	vector< Model* > models;

	Scene(const char *xmlPath);

	void initializeImage(Camera* camera);
	void forwardRenderingPipeline(Camera* camera);
	int makeBetweenZeroAnd255(double value);
	void writeImageToPPMFile(Camera* camera);
	void convertPPMToPNG(string ppmFileName, int osType);
	Color subtractColor(Color c1, Color c2);
	Color sumColor(Color c1, Color c2);
	Color divideColor(Color c1, double divider);
	Color roundColor(Color c);
	Color alphaColor(Vec4 startVertex, Vec4 endVertex, Color startColor, Color endColor, int x);
	void midpoint(int x0,int y0, int x1,int y1, int incrementVal, Color startColor, Color endColor, Camera* cam);
	double fxx(int x,int y ,Vec4 point0, Vec4 point1);
	Color multiplyColor(Color c1, double divider);
};

#endif
