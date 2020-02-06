#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cmath>

#include "Scene.h"
#include "Camera.h"
#include "Color.h"
#include "Model.h"
#include "Rotation.h"
#include "Scaling.h"
#include "Translation.h"
#include "Triangle.h"
#include "Vec3.h"
#include "tinyxml2.h"
#include "Helpers.h"

using namespace tinyxml2;
using namespace std;
#define PI 3.14159265

/*
	Transformations, clipping, culling, rasterization are done here.
	You can define helper functions inside Scene class implementation.
*/
 Color Scene::subtractColor(Color c1, Color c2){
	Color result;
    result.r = c1.r - c2.r;
    result.g = c1.g - c2.g;
    result.b = c1.b - c2.b;

    return result;
 }

Color Scene::sumColor(Color c1, Color c2){
	Color result;
	result.r = c1.r - c2.r;
    result.g = c1.g - c2.g;
    result.b = c1.b - c2.b;
	return result;
}

Color Scene::divideColor(Color c1, double divider){
	Color result;
	result.r = (double) c1.r / divider;
	result.g = (double) c1.g / divider;
	result.b = (double) c1.b / divider;

	return result;
}
Color Scene::multiplyColor(Color c1, double multiplier){
	Color result;
	result.r = (double) c1.r * multiplier;
	result.g = (double) c1.g * multiplier;
	result.b = (double) c1.b * multiplier;

	return result;
}

Color Scene::roundColor(Color c){
	return {(int)c.r,(int)c.g,(int)c.b};
}

double Scene::fxx(int x,int y ,Vec4 point0, Vec4 point1){
	return x*(point0.y-point1.y) + y*(point1.x- point0.x) + point0.x * point1.y - point0.y*point1.x;
}



void Scene::midpoint(int x0,int y0, int x1,int y1, int incrementVal, Color startColor, Color endColor, Camera* cam){
	double m;
	if(x1-x0 == 0)m = 999;
	else m = double (y1 - y0)/ (x1 - x0);
	if(m >=0 && m <= 1 ){ // base case
		double y = y0;
		double d = 2*(y0 - y1) + (x1 - x0);
		//todo: burada vec4e colorId leri atmıyoruz. vec3ten vec4e cevirirken colorıdleri de at 
		Color c = startColor;
		Color dc;
		if(x1-x0 == 0) dc = subtractColor(startColor,endColor);
		else dc = divideColor(subtractColor(startColor,endColor),x1 - x0 );
		for(double x = x0; x <= x1; x++ ){
			if(x>=0 && y>=0 && cam->horRes > x && cam->verRes > y ){
				image[x][y] = roundColor(c) ;
			}
			if( d< 0 )// choose NE
			{
				y = y+1;
				d += 2*((y0 - y1) + (x1 - x0));
			}
			else{
				d += 2* (y0 - y1);
			}
			c = sumColor(c,dc);
		}
	}
	else
	 if(m >1 ){ // base case
		double x = x0;
		double d = 2*(x1 - x0) + (y0 - y1);
		//todo: burada vec4e colorId leri atmıyoruz. vec3ten vec4e cevirirken colorıdleri de at 
		Color c = startColor;
		Color dc;
		if(y1-y0 == 0) dc = subtractColor(startColor,endColor);
		else dc = divideColor(subtractColor(startColor,endColor),y1 - y0 );
		for(double y = y0; y <= y1; y++ ){
			if(x>0 && y>0 && cam->horRes > x && cam->verRes > y ){
				image[x][y] = roundColor(c) ;
			}
			if( d > 0 )// choose NE
			{
				x = x+1;
				d += 2*((x1 - x0) + (y0 - y1));
			}
			else{
				d += 2* (x1 - x0);
			}
			c = sumColor(c,dc);
		}
	}
	else
	 if(m >-1 && m<0 ){ // base case
		double y = y0;
		double d = 2*(y0 - y1) + (x1 - x0);
		//todo: burada vec4e colorId leri atmıyoruz. vec3ten vec4e cevirirken colorıdleri de at 
		Color c = startColor;
		Color dc;
		if(x1-x0 == 0) dc = subtractColor(startColor,endColor);
		else dc = divideColor(subtractColor(startColor,endColor),x1 - x0 );
		for(double x = x0; x <= x1; x++ ){
			if(x>=0 && y>=0 && cam->horRes > x && cam->verRes > y ){
				image[x][y] = roundColor(c) ;
			}
			if( d< 0 )// choose NE
			{
				y = y-1;
				d += 2*((y1 - y0) + (x1 - x0));
			}
			else{
				d += 2* (y1 - y0);
			}
			c = sumColor(c,dc);
		}
	}
	else
	 if(m <=-1 ){ // base case
		double x = x0;
		double d = 2*(x0 - x1) + (y1 - y0);
		//todo: burada vec4e colorId leri atmıyoruz. vec3ten vec4e cevirirken colorıdleri de at 
		Color c = startColor;
		Color dc;
		if(y1-y0 == 0) dc = subtractColor(startColor,endColor);
		else dc = divideColor(subtractColor(startColor,endColor),y1 - y0 );
		for(double y = y0; y >= y1; y-- ){
			if(x>0 && y>0 && cam->horRes > x && cam->verRes > y ){
				image[x][y] = roundColor(c) ;
			}
			if( d < 0 )// choose NE
			{
				x = x+1;
				d += 2*((x0 - x1) + (y0 - y1));
			}
			else{
				d += 2* (x0 - x1);
			}
			c = sumColor(c,dc);
		}
	}
	
	
}
/* 
Vec3 liangBarsky(Vec3 currentVertex, Camera *camera){
	Vec3 result;
	double te = 0, tl = 0;
	bool visible = false;
	if visible(,,&te,&tl){

	}
}


bool visible(double den, double num, double* te, double* tl){
	double t = num / den;; 
	if(den>0){
		if ( t > *tl){
			return false;
		}
		if ( t > *te ){
			*te = t;		// burada te degisecek mi? yukaridaki fonksiyonda yani
		}
	}
	else if(den<0){
		if ( t < *te){
			return false;
		}
		if ( t < *tl ){
			*tl = t;		// burada tl degisecek mi? yukaridaki fonksiyonda yani
		}
	}
	else if(num>0){
		return false;
	}
	return true;
} 
*/

void Scene::forwardRenderingPipeline(Camera *camera)
{


	// TODO: bool isTransformed[numberOfVertices+1]; gerekli mi kontrol et
	int verticeCount = vertices.size();
	int modelCount = models.size();
	bool repeatingTransform[verticeCount+1];
	Vec4 conVertices[verticeCount+1];
	double depthOfVertices[verticeCount];
	bool culling[verticeCount];
	for (int i = 0; i < verticeCount; i++){
		conVertices[i].x =(vertices[i])->x ;
		conVertices[i].y =(vertices[i])->y ;
		conVertices[i].z =(vertices[i])->z ;
		conVertices[i].t = 1.0 ;
		conVertices[i].colorId =(vertices[i])->colorId ;
		repeatingTransform[i] = false;
		culling[i] = true;
	}
	for(int j = 0; j < modelCount ; j ++ ){
		Model model = *(models[j]);
		for(int i = 0; i < model.numberOfTransformations; i++){
			for (int z = 0; z < verticeCount; z++){
				repeatingTransform[z] = false;
			}
			char transformationType = model.transformationTypes[i];
			int transformationId = model.transformationIds[i];
			Vec4 cacheTrans;
			Vec4 triangleFour;
			Vec3 newVertex;
			for(int k = 0; k < model.numberOfTriangles; k++){
				Triangle curTriangle = model.triangles[k];
				
				for(int l = 0; l < 3 ; l++ ){
					//cout << "transformationType: " << transformationType << endl;
					//cout << "ucgenin kosesi:" << l << endl;
					//cout << "kosenin idsi:" << curTriangle.vertexIds[l] << endl;
					//cout << "transformation tekrari:" << repeatingTransform[curTriangle.vertexIds[l]-1] << endl;
					if(!repeatingTransform[curTriangle.vertexIds[l]-1]){
						
						Vec4  curVertex = conVertices[curTriangle.vertexIds[l]-1];
						//cout << "kosenin 3lu hali: " << curVertex << endl;
						triangleFour.x = curVertex.x;
						triangleFour.y = curVertex.y;
						triangleFour.z = curVertex.z;
						triangleFour.t = 1;		
						//cout << "4lu hali: " <<triangleFour << endl;
						
						if(transformationType == 't'){

							Translation* curTranslation = translations[transformationId-1];
							double transformationArray[4][4] = {{1,0,0, curTranslation->tx},
																{0,1,0, curTranslation->ty},
																{0,0,1, curTranslation->tz},
																{0,0,0,1}};
							Matrix4 transformationMatrix(transformationArray);
							cacheTrans = multiplyMatrixWithVec4(transformationMatrix, triangleFour);
							//conVertices[curTriangle.vertexIds[l]]	= {cacheTrans.x,cacheTrans.y,cacheTrans.z, curTriangle.vertexIds[l]}; // bu gerekli mi kontrol et	
							//cout << "once conVertices: " << conVertices[curTriangle.vertexIds[l]-1] << endl;	
							conVertices[curTriangle.vertexIds[l]-1].x	= cacheTrans.x;
							conVertices[curTriangle.vertexIds[l]-1].y	= cacheTrans.y;
							conVertices[curTriangle.vertexIds[l]-1].z	= cacheTrans.z;
							conVertices[curTriangle.vertexIds[l]-1].t	= 1;
							// todo: renkleri burada atıyorum:
							conVertices[curTriangle.vertexIds[l]-1].colorId = curVertex.colorId; 
							//		check: curTriangle.vertexIds[l] neden cacheTrans.t degil. hata verir cunku Vec3 tanimlamisiz. 
							// check: yukaridaki transformationMatrix'i matrix haline getirebiliyorsun.
							//cout << "sonra conVertices: " << conVertices[curTriangle.vertexIds[l]-1] << endl;	
							repeatingTransform[curTriangle.vertexIds[l]-1] = true;
							//cout << "cacheTrans: " <<cacheTrans << endl;
						}
						else if( transformationType == 'r'){
							//cok cirkin burasi. slaytlara bak. alternative method var oraya bak bi de.	
							Rotation* curRotation = rotations[transformationId-1];
							//Assume we want to rotate around the unit vector u:
							
							Vec3 rotationVec3(curRotation->ux, curRotation->uy, curRotation->uz, -1);
							//turn rotation vector to unit vector.
							rotationVec3 = normalizeVec3(rotationVec3);
							// create orthonormal basis uvw. 
							// to find v:
							Vec3 v;
							if(abs(rotationVec3.x) <= abs(rotationVec3.y) && abs(rotationVec3.x) <= abs(rotationVec3.z)){
								v.x = 0;
								v.y = -rotationVec3.z;
								v.z = rotationVec3.y;
							}
							else if(abs(rotationVec3.y) <= abs(rotationVec3.x) && abs(rotationVec3.y) <= abs(rotationVec3.z)){
								v.x = -rotationVec3.z;
								v.y = 0;
								v.z = rotationVec3.x;
							}
							else if(abs(rotationVec3.z) <= abs(rotationVec3.x) && abs(rotationVec3.z) <= abs(rotationVec3.y)){
								v.x = -rotationVec3.y;
								v.y = rotationVec3.x;
								v.z = 0;
							}
							// find w:
							//cout << "v: " <<v << endl;
							Vec3 w;
							w = crossProductVec3(rotationVec3,v);
							w = normalizeVec3(w);
							v = normalizeVec3(v);
							//cout << "normalized v: " <<v << endl;
							//cout << "normalized v: " <<w << endl;

							double MInverse[4][4] = {{rotationVec3.x,v.x,w.x,0},
														{rotationVec3.y,v.y,w.y,0},
														{rotationVec3.z,v.z,w.z,0},
														{0,0,0,1}};
							Matrix4 inverseM(MInverse);

							double Mduz[4][4] = {{rotationVec3.x,rotationVec3.y,rotationVec3.z,0},
												{v.x,v.y,v.z,0},
												{w.x,w.y,w.z,0},
												{0,0,0,1}};
							Matrix4 M(Mduz);
							double angle = (curRotation->angle* PI) / 180.0;

							double rotationAround[4][4] = {{1,0,0,0},{0,cos(angle),-sin(angle),0},{0, sin(angle), cos(angle),0},{0,0,0,1}};
							Matrix4 rotationAroundX(rotationAround);
							//cout << "rotationAroundX : " << rotationAroundX << endl;
							//cout << "inverseM: " <<inverseM << endl;
							//cout << "M: " <<M << endl;
							Matrix4 mir = multiplyMatrixWithMatrix(inverseM, rotationAroundX);
							Matrix4 transformationMatrix = multiplyMatrixWithMatrix(mir, M);
							cacheTrans = multiplyMatrixWithVec4(transformationMatrix, triangleFour);
							//cout << "once conVertices: " << conVertices[curTriangle.vertexIds[l]-1] << endl;	
							conVertices[curTriangle.vertexIds[l]-1].x	= cacheTrans.x;
							conVertices[curTriangle.vertexIds[l]-1].y	= cacheTrans.y;
							conVertices[curTriangle.vertexIds[l]-1].z	= cacheTrans.z;
							conVertices[curTriangle.vertexIds[l]-1].t	= 1;
							// todo: renkleri burada atıyorum:
							conVertices[curTriangle.vertexIds[l]-1].colorId = curVertex.colorId; 
							//cout << "sonra conVertices: " <<conVertices[curTriangle.vertexIds[l]-1] << endl;	
							repeatingTransform[curTriangle.vertexIds[l]-1] = true;
							//cout << "cacheTrans: " <<cacheTrans << endl;
						}
						else{
							Scaling* curScaling = scalings[transformationId-1];
							double transformationArray[4][4] = {{curScaling->sx,0,0,0},
																{0,curScaling->sy,0, 0},
																{0,0,curScaling->sz, 0},
																{0,0,0,1}};
							Matrix4 transformationMatrix(transformationArray);
							cacheTrans = multiplyMatrixWithVec4(transformationMatrix, triangleFour);
							//cout << "once conVertices: " << conVertices[curTriangle.vertexIds[l]-1] << endl;	
							//check: bu gerekli mi kontrol et. vec4.
							conVertices[curTriangle.vertexIds[l]-1].x	= cacheTrans.x;
							conVertices[curTriangle.vertexIds[l]-1].y	= cacheTrans.y;
							conVertices[curTriangle.vertexIds[l]-1].z	= cacheTrans.z;
							conVertices[curTriangle.vertexIds[l]-1].t	= 1;
							// todo: renkleri burada atıyorum:
							conVertices[curTriangle.vertexIds[l]-1].colorId = curVertex.colorId; 
							//cout << "sonra conVertices: " <<conVertices[curTriangle.vertexIds[l]-1] << endl;	
							repeatingTransform[curTriangle.vertexIds[l]-1] = true;
							//cout << "cacheTrans: " <<cacheTrans << endl;
						}	
					}		
				}


			}
		}
	}
	//TODO: rotation yap


	/*
	cout << "transformationlar bitti" << endl;

	for (int i = 0; i < verticeCount; i++){
		cout << conVertices[i] << endl ;
		cout << repeatingTransform[i] << endl;
	}

	*/
	//yeni asama
	// new: camera transformation
	//
	Matrix4 cameraTransformation = Matrix4();
	double cameraRotation[4][4] = {		{camera->u.x,camera->u.y,camera->u.z, 0},
										{camera->v.x,camera->v.y,camera->v.z, 0},
										{camera->w.x,camera->w.y,camera->w.z, 0},
										{0,0,0,1}};	
	double cameraTranslation[4][4] = {		{1,0,0, -camera->pos.x},
											{0,1,0, -camera->pos.y},
											{0,0,1, -camera->pos.z},
											{0,0,0,1}};


	cameraTransformation = multiplyMatrixWithMatrix(cameraRotation, cameraTranslation);
	//bunu nasil kullanicaz
	// new: orthograhic projection
	//Matrix4 orthographicTransformation = Matrix4();
	double orthographicProj[4][4] = {	{2/(camera->right -camera->left ),		0,									0, 								-(camera->right + camera->left) / (camera->right - camera->left )},
										{0,										2/(camera->top -camera->bottom ),	0, 								-(camera->top +camera->bottom) / (camera->top -camera->bottom )},
										{0,										0,									-2/(camera->far -camera->near), -(camera->far + camera->near) / (camera->far -camera->near)},
										{0,0,0,1}};	
	Matrix4 orthographicTransformation = Matrix4(orthographicProj);	
	// perspective projection
	double perspectiveProj[4][4] = {	{2*camera->near/(camera->right -camera->left ),				0, (camera->right + camera->left) / (camera->right - camera->left ),0},
										{0,												2*camera->near/(camera->top -camera->bottom ), 			(camera->top +camera->bottom) / (camera->top -camera->bottom ),0},
										{0,												0,-(camera->far +camera->near)/(camera->far -camera->near), -2*(camera->far * camera->near) / (camera->far -camera->near)},
										{0,									0,			-1,0}};	
	Matrix4 perspectiveTransformation = Matrix4(perspectiveProj);
	// after/before? perspective transformation: perspective divide!!!!
	
	// burada clipping culling
	
	//viewport transformation
	double vpTransformation[4][4] = {{camera->horRes/2.0, 0, 0, (camera->horRes-1)/2},
									{0, camera->verRes/2.0, 0, (camera->verRes-1)/2},
									{0,0,0.5,0.5},
									{0,0,0,1}}; // check: slaytta burasi yok. matrix4e uydurmak icin boyle yaptim.
	Matrix4 viewportTransformation = Matrix4(vpTransformation);
	// mvp * (perspective divide?) mper * mcam * vertex
	cout << viewportTransformation << endl;
	for(int i = 0; i < verticeCount; i++)
	{
		Vec4 camTransformedVec = multiplyMatrixWithVec4(cameraTransformation ,conVertices[i]);
		Vec4 projectionTrans;
		if (this->projectionType == 1) // perspective protection
		{
			projectionTrans = multiplyMatrixWithVec4(perspectiveTransformation, camTransformedVec);

			// bu kisim clipping gelince sonrasina tasinacak
/* 			projectionTrans.x = projectionTrans.x / projectionTrans.t;
			projectionTrans.y = projectionTrans.y / projectionTrans.t;
			projectionTrans.z = projectionTrans.z / projectionTrans.t;
			projectionTrans.t = 1; */
		}
		else if (this->projectionType == 0) // ortographic protection
		{
			projectionTrans = multiplyMatrixWithVec4(orthographicTransformation, camTransformedVec);

		}
		cout << "projectionTrans: " << endl;
		cout << projectionTrans << endl;
		conVertices[i] = projectionTrans; //newly added
		//new: viewtrans is moved after culling
	}
	cout << "projection bitti" << endl;





	if(cullingEnabled){
		for(int i = 0; i < modelCount; i++){
			Model* currentModel = models[i];
			for(int k = 0; k < currentModel->numberOfTriangles; k++){
				Triangle currentTriangle = currentModel->triangles[k];
				
				Vec3 triangle1stVertex;
				Vec3 triangle2ndVertex;
				Vec3 triangle3rdVertex;
				triangle1stVertex.x = conVertices[currentTriangle.getFirstVertexId()-1].x; 
				triangle2ndVertex.x = conVertices[currentTriangle.getSecondVertexId()-1].x; 
				triangle3rdVertex.x = conVertices[currentTriangle.getThirdVertexId()-1].x; 
				triangle1stVertex.y = conVertices[currentTriangle.getFirstVertexId()-1].y; 
				triangle2ndVertex.y = conVertices[currentTriangle.getSecondVertexId()-1].y; 
				triangle3rdVertex.y = conVertices[currentTriangle.getThirdVertexId()-1].y; 
				triangle1stVertex.z = conVertices[currentTriangle.getFirstVertexId()-1].z; 
				triangle2ndVertex.z = conVertices[currentTriangle.getSecondVertexId()-1].z; 
				triangle3rdVertex.z = conVertices[currentTriangle.getThirdVertexId()-1].z; 


				Vec3 middleTriangle;
				//new
/* 				middleTriangle.x = (triangle1stVertex.x + triangle2ndVertex.x + triangle3rdVertex.x)/3.0;
				middleTriangle.y = (triangle1stVertex.y + triangle2ndVertex.y + triangle3rdVertex.y)/3.0;
				middleTriangle.z = (triangle1stVertex.z + triangle2ndVertex.z + triangle3rdVertex.z)/3.0; */
				Vec3 addedVertex = addVec3(triangle1stVertex, triangle2ndVertex);
				Vec3 lastAddedVertex = addVec3(addedVertex, triangle3rdVertex);
				middleTriangle = multiplyVec3WithScalar(lastAddedVertex, 1/3.0);
				Vec3 triangleNormal = crossProductVec3(subtractVec3(triangle2ndVertex, triangle1stVertex), subtractVec3(triangle3rdVertex, triangle1stVertex));
				Vec3 sifir(0,0,0,-1);
				Vec3 middletoEye = subtractVec3(sifir, middleTriangle); // check: camera->pos yanlis mi ? neden sifir :( cunku viewport olmadı cameraya
				// middletoEye ile triangleNormali dot product yap. sonra sıfırdan buyukse backface culling.
				if(dotProductVec3(middletoEye, triangleNormal)>0){
					// this triangle can be culled (i.e is not visible)
					// todo: what happen our triangles? 
					// maybe if they are not visible we dont add to our new model // we should create new model for our new triangles ? 
					culling[currentTriangle.getThirdVertexId()-1] = false;
				}
				else{
					culling[currentTriangle.getThirdVertexId()-1] = true;
					// todo:
					// this part is visible. maybe we can keep a boolean for triangle. visible[k] = true. when rasterazing we can check this condition.
				}

			}
		}
	}



	//newly added
	for (int i = 0; i < verticeCount; i++){
		//perspective divide
		conVertices[i].x = conVertices[i].x / conVertices[i].t;
		conVertices[i].y = conVertices[i].y / conVertices[i].t;
		conVertices[i].z = conVertices[i].z / conVertices[i].t;
		conVertices[i].t = 1;
		Vec4 viewTrans = multiplyMatrixWithVec4(viewportTransformation,conVertices[i]);
		cout << "viewTrans: " << endl;
		cout << viewTrans << endl;
		//convertices are changed.
		conVertices[i] = viewTrans;
	}

	// Color cc(255,255,255);
	// image[300][300] = cc;
	
	for(int i = 0; i < modelCount; i++){
		Model* currentModel = models[i];
		for(int j = 0; j < currentModel->numberOfTriangles; j++){
			Triangle currentTriangle = currentModel->triangles[j];
			Vec4 firstVertex = conVertices[currentTriangle.getFirstVertexId()-1]; 
			Vec4 secondVertex = conVertices[currentTriangle.getSecondVertexId()-1]; 
			Vec4 thirdVertex = conVertices[currentTriangle.getThirdVertexId()-1];

			Color firstColor = *(colorsOfVertices[firstVertex.colorId-1]);
			Color secondColor = *(colorsOfVertices[secondVertex.colorId-1]);
			Color thirdColor =*(colorsOfVertices[thirdVertex.colorId-1]); 
			if(culling[currentTriangle.getThirdVertexId()-1]){	//newly added culling
				if(currentModel->type == 0 ){ // woreframe only
					
					if(firstVertex.x > secondVertex.x){
					
						midpoint(secondVertex.x,secondVertex.y,firstVertex.x,firstVertex.y, 1, secondColor, firstColor, camera );
					}
					else{
						midpoint(firstVertex.x,firstVertex.y,secondVertex.x,secondVertex.y,1, firstColor, secondColor, camera );
					}

					if(secondVertex.x > thirdVertex.x){
						midpoint(thirdVertex.x,thirdVertex.y,secondVertex.x,secondVertex.y,1, thirdColor, secondColor, camera );
					}
					else{
						midpoint(secondVertex.x,secondVertex.y,thirdVertex.x,thirdVertex.y, 1, secondColor, thirdColor, camera );
					}

					if(thirdVertex.x > firstVertex.x){
						midpoint(firstVertex.x,firstVertex.y,thirdVertex.x,thirdVertex.y,1, firstColor, thirdColor, camera );
					}
					else{
						midpoint(thirdVertex.x,thirdVertex.y,firstVertex.x,firstVertex.y,1, thirdColor, firstColor, camera );
					}
				}
				else {
					int xmin = firstVertex.x;
					int ymin = firstVertex.y;
					int xmax = firstVertex.x;
					int ymax = firstVertex.y;

					if(secondVertex.x < xmin) xmin = secondVertex.x;
					if(thirdVertex.x < xmin) xmin = thirdVertex.x;

					if(secondVertex.y < ymin) ymin = secondVertex.y;
					if(thirdVertex.y < ymin) ymin = thirdVertex.y;


					if(secondVertex.x > xmax) xmax = secondVertex.x;
					if(thirdVertex.x > xmax) xmax = thirdVertex.x;

					if(secondVertex.y > ymax) ymax = secondVertex.y;
					if(thirdVertex.y > ymax) ymax = thirdVertex.y;

					for (int y = ymin; y <= ymax; y++)
					{
						for(int x = xmin; x <= xmax; x++){
							double alpha = fxx(x,y,secondVertex,thirdVertex)/fxx(firstVertex.x,firstVertex.y,secondVertex,thirdVertex);
							double beta = fxx(x,y,thirdVertex,firstVertex)/fxx(secondVertex.x,secondVertex.y,thirdVertex,firstVertex);
							double gama = fxx(x,y,firstVertex,secondVertex)/fxx(thirdVertex.x,thirdVertex.y, firstVertex,secondVertex);
							 cout << "calculating alpha"<< alpha << ' ' << fxx(x,y,secondVertex,thirdVertex) <<' ' << fxx(firstVertex.x,firstVertex.y,secondVertex,thirdVertex) << endl;
							 cout << "calculating beta"<< beta << ' ' << fxx(x,y,thirdVertex,firstVertex) <<' ' << fxx(secondVertex.x,secondVertex.y,thirdVertex,firstVertex) << endl;
							 cout << "calculating gama"<< gama << ' ' << fxx(x,y,firstVertex,secondVertex) <<' ' << fxx(thirdVertex.x,thirdVertex.y, firstVertex,secondVertex) << endl;
							if(alpha>=0 && beta >= 0 && gama >= 0 ){
								Color c = sumColor(sumColor(multiplyColor(firstColor,alpha),multiplyColor(secondColor,beta)),multiplyColor(thirdColor,gama));
								image[x][y] = roundColor(c);
							}
						}
					}
					
					

				}





				/*
				for(int x0= x1-5; x0<x1 +5;x0++){
					for(int y0= y1-5; y0<y1 +5;y0++)
					if(x0>0 && y0>0){
						image[x0][y0] = cc;
					}
						
				}
				for(int x0= x2-5; x0<x2 +5;x0++){
					for(int y0= y2-5; y0<y2 +5;y0++)
					if(x0>0 && y0>0){
						image[x0][y0] = cc;
					}	
				}
				for(int x0= x3-5; x0<x3 +5;x0++){
					for(int y0= y3-5; y0<y3 +5;y0++)
					image[x0][y0] = cc;	
				}
				if(x1>0 && y1>0 && x2>0 && y2>0 && x3>0 && y3>0){
					image[x1][y1] = cc;
					image[x2][y2] = cc;
					image[x2][y2] = cc;
				}
				*/
			
			
			
			
			}
		}
	}

	
	
	
	
	
	
	
	
	

	// TODO: Vec3 changedVertices2[numberOfVertices+1];
	
	// clipping falan viewporttan once olacak. vertexlerimizi camera transformation ile carpiyoruz. perspective ile carpiyoruz
	// sonra clipping yapıyoruz. culling yapıyoruz sanırım. sonra vertexlerimizi viewport ile carpiyoz.
	// new: clipping. liang - barsky sanki iyi olur. hazirda var zaten slaytta
/*
	for(int i = 0; i < modelCount; i++){
		Model* currentModel = models[i];
		for( int j = 0; j < currentModel->numberOfTriangles; j++){
			Triangle currentTriangle = currentModel->triangles[j];
			// triangles vertices will change with the algorithm?.
			for(int k = 0; k < 3; k++){
				//liang-barsky ile yeni noktalari al.
				// en ustte implement etmeye basladim.
			}
			
		}
	} 
	
	*/


	// new: culling


	//rasterization
	// rasterizationı halledelim gorelim
	// rasterization midpoint ve barycentric olarak ikiye ayrılacak. wireframed icin midpoint


}



/*
	Parses XML file
*/
Scene::Scene(const char *xmlPath)
{
	const char *str;
	XMLDocument xmlDoc;
	XMLElement *pElement;

	xmlDoc.LoadFile(xmlPath);

	XMLNode *pRoot = xmlDoc.FirstChild();

	// read background color
	pElement = pRoot->FirstChildElement("BackgroundColor");
	str = pElement->GetText();
	sscanf(str, "%lf %lf %lf", &backgroundColor.r, &backgroundColor.g, &backgroundColor.b);

	// read culling
	pElement = pRoot->FirstChildElement("Culling");
	if (pElement != NULL)
		pElement->QueryBoolText(&cullingEnabled);

	// read projection type
	pElement = pRoot->FirstChildElement("ProjectionType");
	if (pElement != NULL)
		pElement->QueryIntText(&projectionType);

	// read cameras
	pElement = pRoot->FirstChildElement("Cameras");
	XMLElement *pCamera = pElement->FirstChildElement("Camera");
	XMLElement *camElement;
	while (pCamera != NULL)
	{
		Camera *cam = new Camera();

		pCamera->QueryIntAttribute("id", &cam->cameraId);

		camElement = pCamera->FirstChildElement("Position");
		str = camElement->GetText();
		sscanf(str, "%lf %lf %lf", &cam->pos.x, &cam->pos.y, &cam->pos.z);

		camElement = pCamera->FirstChildElement("Gaze");
		str = camElement->GetText();
		sscanf(str, "%lf %lf %lf", &cam->gaze.x, &cam->gaze.y, &cam->gaze.z);

		camElement = pCamera->FirstChildElement("Up");
		str = camElement->GetText();
		sscanf(str, "%lf %lf %lf", &cam->v.x, &cam->v.y, &cam->v.z);

		cam->gaze = normalizeVec3(cam->gaze);
		cam->u = crossProductVec3(cam->gaze, cam->v);
		cam->u = normalizeVec3(cam->u);

		cam->w = inverseVec3(cam->gaze);
		cam->v = crossProductVec3(cam->u, cam->gaze);
		cam->v = normalizeVec3(cam->v);

		camElement = pCamera->FirstChildElement("ImagePlane");
		str = camElement->GetText();
		sscanf(str, "%lf %lf %lf %lf %lf %lf %d %d",
			   &cam->left, &cam->right, &cam->bottom, &cam->top,
			   &cam->near, &cam->far, &cam->horRes, &cam->verRes);

		camElement = pCamera->FirstChildElement("OutputName");
		str = camElement->GetText();
		cam->outputFileName = string(str);

		cameras.push_back(cam);

		pCamera = pCamera->NextSiblingElement("Camera");
	}

	// read vertices
	pElement = pRoot->FirstChildElement("Vertices");
	XMLElement *pVertex = pElement->FirstChildElement("Vertex");
	int vertexId = 1;

	while (pVertex != NULL)
	{
		Vec3 *vertex = new Vec3();
		Color *color = new Color();

		vertex->colorId = vertexId;

		str = pVertex->Attribute("position");
		sscanf(str, "%lf %lf %lf", &vertex->x, &vertex->y, &vertex->z);

		str = pVertex->Attribute("color");
		sscanf(str, "%lf %lf %lf", &color->r, &color->g, &color->b);

		vertices.push_back(vertex);
		colorsOfVertices.push_back(color);

		pVertex = pVertex->NextSiblingElement("Vertex");

		vertexId++;
	}

	// read translations
	pElement = pRoot->FirstChildElement("Translations");
	XMLElement *pTranslation = pElement->FirstChildElement("Translation");
	while (pTranslation != NULL)
	{
		Translation *translation = new Translation();

		pTranslation->QueryIntAttribute("id", &translation->translationId);

		str = pTranslation->Attribute("value");
		sscanf(str, "%lf %lf %lf", &translation->tx, &translation->ty, &translation->tz);

		translations.push_back(translation);

		pTranslation = pTranslation->NextSiblingElement("Translation");
	}

	// read scalings
	pElement = pRoot->FirstChildElement("Scalings");
	XMLElement *pScaling = pElement->FirstChildElement("Scaling");
	while (pScaling != NULL)
	{
		Scaling *scaling = new Scaling();

		pScaling->QueryIntAttribute("id", &scaling->scalingId);
		str = pScaling->Attribute("value");
		sscanf(str, "%lf %lf %lf", &scaling->sx, &scaling->sy, &scaling->sz);

		scalings.push_back(scaling);

		pScaling = pScaling->NextSiblingElement("Scaling");
	}

	// read rotations
	pElement = pRoot->FirstChildElement("Rotations");
	XMLElement *pRotation = pElement->FirstChildElement("Rotation");
	while (pRotation != NULL)
	{
		Rotation *rotation = new Rotation();

		pRotation->QueryIntAttribute("id", &rotation->rotationId);
		str = pRotation->Attribute("value");
		sscanf(str, "%lf %lf %lf %lf", &rotation->angle, &rotation->ux, &rotation->uy, &rotation->uz);

		rotations.push_back(rotation);

		pRotation = pRotation->NextSiblingElement("Rotation");
	}

	// read models
	pElement = pRoot->FirstChildElement("Models");

	XMLElement *pModel = pElement->FirstChildElement("Model");
	XMLElement *modelElement;
	while (pModel != NULL)
	{
		Model *model = new Model();

		pModel->QueryIntAttribute("id", &model->modelId);
		pModel->QueryIntAttribute("type", &model->type);

		// read model transformations
		XMLElement *pTransformations = pModel->FirstChildElement("Transformations");
		XMLElement *pTransformation = pTransformations->FirstChildElement("Transformation");

		pTransformations->QueryIntAttribute("count", &model->numberOfTransformations);

		while (pTransformation != NULL)
		{
			char transformationType;
			int transformationId;

			str = pTransformation->GetText();
			sscanf(str, "%c %d", &transformationType, &transformationId);

			model->transformationTypes.push_back(transformationType);
			model->transformationIds.push_back(transformationId);

			pTransformation = pTransformation->NextSiblingElement("Transformation");
		}

		// read model triangles
		XMLElement *pTriangles = pModel->FirstChildElement("Triangles");
		XMLElement *pTriangle = pTriangles->FirstChildElement("Triangle");

		pTriangles->QueryIntAttribute("count", &model->numberOfTriangles);

		while (pTriangle != NULL)
		{
			int v1, v2, v3;

			str = pTriangle->GetText();
			sscanf(str, "%d %d %d", &v1, &v2, &v3);

			model->triangles.push_back(Triangle(v1, v2, v3));

			pTriangle = pTriangle->NextSiblingElement("Triangle");
		}

		models.push_back(model);

		pModel = pModel->NextSiblingElement("Model");
	}
}

/*
	Initializes image with background color
*/
void Scene::initializeImage(Camera *camera)
{
	if (this->image.empty())
	{
		for (int i = 0; i < camera->horRes; i++)
		{
			vector<Color> rowOfColors;

			for (int j = 0; j < camera->verRes; j++)
			{
				rowOfColors.push_back(this->backgroundColor);
			}

			this->image.push_back(rowOfColors);
		}
	}
	// if image is filled before, just change color rgb values with the background color
	else
	{
		for (int i = 0; i < camera->horRes; i++)
		{
			for (int j = 0; j < camera->verRes; j++)
			{
				this->image[i][j].r = this->backgroundColor.r;
				this->image[i][j].g = this->backgroundColor.g;
				this->image[i][j].b = this->backgroundColor.b;
			}
		}
	}
}

/*
	If given value is less than 0, converts value to 0.
	If given value is more than 255, converts value to 255.
	Otherwise returns value itself.
*/
int Scene::makeBetweenZeroAnd255(double value)
{
	if (value >= 255.0)
		return 255;
	if (value <= 0.0)
		return 0;
	return (int)(value);
}

/*
	Writes contents of image (Color**) into a PPM file.
*/
void Scene::writeImageToPPMFile(Camera *camera)
{
	ofstream fout;

	fout.open(camera->outputFileName.c_str());

	fout << "P3" << endl;
	fout << "# " << camera->outputFileName << endl;
	fout << camera->horRes << " " << camera->verRes << endl;
	fout << "255" << endl;

	for (int j = camera->verRes - 1; j >= 0; j--)
	{
		for (int i = 0; i < camera->horRes; i++)
		{
			fout << makeBetweenZeroAnd255(this->image[i][j].r) << " "
				 << makeBetweenZeroAnd255(this->image[i][j].g) << " "
				 << makeBetweenZeroAnd255(this->image[i][j].b) << " ";
		}
		fout << endl;
	}
	fout.close();
}

/*
	Converts PPM image in given path to PNG file, by calling ImageMagick's 'convert' command.
	os_type == 1 		-> Ubuntu
	os_type == 2 		-> Windows
	os_type == other	-> No conversion
*/
void Scene::convertPPMToPNG(string ppmFileName, int osType)
{
	string command;

	// call command on Ubuntu
	if (osType == 1)
	{
		command = "convert " + ppmFileName + " " + ppmFileName + ".png";
		system(command.c_str());
	}

	// call command on Windows
	else if (osType == 2)
	{
		command = "magick convert " + ppmFileName + " " + ppmFileName + ".png";
		system(command.c_str());
	}

	// default action - don't do conversion
	else
	{
	}
}
