#include "Scene.h"
#include "Camera.h"
#include "Light.h"
#include "Material.h"
#include "Shape.h"
#include "tinyxml2.h"
#include "Image.h"
#include "Ray.h"
#include <math.h>

using namespace tinyxml2;
#include <limits>
/* 
 * Must render the scene from each camera's viewpoint and create an image.
 * You can use the methods of the Image class to save the image as a PPM file. 
 */

Vector3f Scene::recursion(Ray primaryRay,int recDepth){
        //Color color;
        ReturnVal hit,hitFinal;
        Vector3f vectorColor;
        Shape* minObj = NULL;
        float tmin = std::numeric_limits<float>::max();
        for(Shape* x: this->objects){
                //Shape* x = this->objects[0];
                hit = x->intersect(primaryRay);
                if(hit.intersected==1 && hit.t>=0){
                        if(tmin > hit.t){
                                tmin = hit.t;
                                minObj = x;
                                hitFinal = hit;
                        }
                }
        }

        if(minObj != NULL)
        {
               int matIndex = minObj->matIndex;

                
                vectorColor = this->ambientCalculate(minObj);

                for(int i = 0; i < this->lights.size(); i++){
                        Ray shadowRay;
                        int shadowlandin = 0;
                        ReturnVal hitShadow;
                        PointLight *light = this->lights[i];
                        shadowRay.direction = (light->position - hitFinal.intersectPoint).normalized();
                        shadowRay.origin = hitFinal.intersectPoint - shadowRay.direction* this->shadowRayEps;
                        
                        float tLight = shadowRay.gett(light->position);
                        for(Shape* y: this->objects){
                            //Shape* x = this->objects[0];
                            hitShadow = y->intersect(shadowRay);
                            if(hitShadow.intersected==1 ){
                                    if(hitShadow.t>=0 && tLight > hitShadow.t){
                                            shadowlandin = 1;
                                            break;
                                    }
                            }       
                        }       
                        if(shadowlandin ==1){

                                continue;
                        }
                        //diffuse
                        vectorColor += this->diffuseCalculate(minObj, hitFinal, this->lights[i]);

                        //Vector3f wi = (this->lights[i]->position - hitFinal.intersectPoint).normalized();
                        vectorColor += this->specularCalculate(minObj, hitFinal, this->lights[i], primaryRay);
                                               

                }
                bool isMirror = false;
                if(this->materials[matIndex-1]->mirrorRef.x() > 0 || this->materials[matIndex-1]->mirrorRef.y() || this->materials[matIndex-1]->mirrorRef.z() ){
                    isMirror = true;
                }
                if(isMirror && recDepth ){
                        Vector3f wo = -primaryRay.direction; // bu eksi olmayabilir
                        Vector3f wr = (-1)*wo + 2*(hitFinal.normal)*((hitFinal.normal).dot(wo));
                        wr = wr.normalized();
                        Ray reflectionRay;
                        reflectionRay.direction = wr;
                        reflectionRay.origin = hitFinal.intersectPoint;
                        Vector3f rett = recursion(reflectionRay,recDepth-1);
                        rett.x() *= this->materials[matIndex-1]->mirrorRef.x();
                        rett.y() *= this->materials[matIndex-1]->mirrorRef.y();
                        rett.z() *= this->materials[matIndex-1]->mirrorRef.z();
                        return vectorColor + rett;
                        
                }else {
                        return vectorColor;
                }
                       

                // if minobj!=NULL end
        }
        else
        {
                vectorColor.x() = this->backgroundColor.x();
                vectorColor.y() = this->backgroundColor.y();
                vectorColor.z() = this->backgroundColor.z();
        
        }

        return vectorColor;
}

Vector3f Scene::ambientCalculate(Shape* minObj){
    Vector3f color;
    int matIndex = minObj->matIndex;
    color.x() = this->materials[matIndex-1]->ambientRef.x()*this->ambientLight.x();
    color.y() = this->materials[matIndex-1]->ambientRef.y()*this->ambientLight.y();
    color.z() = this->materials[matIndex-1]->ambientRef.z()*this->ambientLight.z();
    return color;
}
Vector3f Scene::diffuseCalculate(Shape* minObj,ReturnVal hitFinal, PointLight* light){
    Vector3f color;
    int matIndex = minObj->matIndex;
    Vector3f wi = (light->position - hitFinal.intersectPoint).normalized();
    float cosTeta = wi.dot(hitFinal.normal); //aslinda cosTeta
    if(cosTeta<0.0){
            cosTeta = 0.0;
    }
    color.x() = this->materials[matIndex-1]->diffuseRef.x() * cosTeta * light->computeLightContribution(hitFinal.intersectPoint).x();
    color.y() = this->materials[matIndex-1]->diffuseRef.y() * cosTeta * light->computeLightContribution(hitFinal.intersectPoint).y();
    color.z() = this->materials[matIndex-1]->diffuseRef.z() * cosTeta * light->computeLightContribution(hitFinal.intersectPoint).z();
    return color;

}

Vector3f Scene::specularCalculate(Shape* minObj, ReturnVal hitFinal, PointLight* light, Ray primaryRay){
    Vector3f color;
    int matIndex = minObj->matIndex;
    Vector3f wi = (light->position - hitFinal.intersectPoint).normalized();
    Vector3f wo = (primaryRay.getPoint(0) - hitFinal.intersectPoint).normalized();   //primaryRay->getPoint(0) -> camera position veriyo sanirim

    Vector3f h = (wi + wo).normalized();
    int phongExp = this->materials[matIndex-1]->phongExp;
    float cosAlpha = (hitFinal.normal).dot(h);
    if(cosAlpha<0){
            cosAlpha = 0.0;
    } 
     color.x() = this->materials[matIndex-1]->specularRef.x() * pow(cosAlpha,phongExp) * light->computeLightContribution(hitFinal.intersectPoint).x();
     color.y() = this->materials[matIndex-1]->specularRef.y() * pow(cosAlpha,phongExp) * light->computeLightContribution(hitFinal.intersectPoint).y();
     color.z() = this->materials[matIndex-1]->specularRef.z() * pow(cosAlpha,phongExp) * light->computeLightContribution(hitFinal.intersectPoint).z();
     return color;
}
int Scene::shadowCalculate(Shape* minObj, ReturnVal hitFinal, PointLight* light){
        Ray shadowRay;
        int shadowlandin = 0;
        ReturnVal hitShadow;

        shadowRay.origin = hitFinal.intersectPoint - shadowRay.direction* this->shadowRayEps;
        shadowRay.direction = (light->position - shadowRay.origin).normalized();
        float tLight = shadowRay.gett(light->position);
        for(Shape* y: this->objects){
            //Shape* x = this->objects[0];
            hitShadow = y->intersect(shadowRay);
            if(hitShadow.intersected==1 ){
                    if(hitShadow.t>=0 && tLight > hitShadow.t){
                            shadowlandin = 1;
                            break;
                    }
            }       
    }    
    return shadowlandin;
}

void Scene::renderScene(void)
{
        /***********************************************
     *                                             *
         * TODO: Implement this function               *
     *                                             *
     ***********************************************
         */
        int cameraNumber =this->cameras.size();
        int c = 0;
        //float red,grn,blu;
        for (; c < cameraNumber ; c++ ){
                Camera* cam = this->cameras.at(c);
                int col = cam->imgPlane.nx;
                int row = cam->imgPlane.ny;
                Image img(col, row);
                Color color;
                

                color.red =0;
                color.blu =0;
                color.grn =0;

                for(int i=0 ; i < col; i++){

                        for(int j = 0; j < row; j++){
                                float tmin = std::numeric_limits<float>::max(); //     kontrol
                                Ray primaryRay = cam->getPrimaryRay(j,i);       //control camera.h taki muglakliktan oturu. row mu col mu once bilmiyoz

                                //recur 
                                Vector3f sonuc = recursion(primaryRay, this->maxRecursionDepth);
                                //overflow hesabi

                                if(sonuc.x()>255)color.red = 255;
                                else color.red = sonuc.x();
                                if(sonuc.y()>255)color.grn = 255;
                                else color.grn = sonuc.y();
                                if(sonuc.z()>255)color.blu = 255;
                                else color.blu= sonuc.z();

                                img.setPixelValue(i,j,color);
                        // for pixel end
                        }
                }

                img.saveImage(cam->imageName);
        //for camera end
        }
}

// Parses XML file. 
Scene::Scene(const char *xmlPath)
{
        const char *str;
        XMLDocument xmlDoc;
        XMLError eResult;
        XMLElement *pElement;

        maxRecursionDepth = 1;
        shadowRayEps = 0.001;

        eResult = xmlDoc.LoadFile(xmlPath);

        XMLNode *pRoot = xmlDoc.FirstChild();

        pElement = pRoot->FirstChildElement("MaxRecursionDepth");
        if(pElement != nullptr)
                pElement->QueryIntText(&maxRecursionDepth);

        pElement = pRoot->FirstChildElement("BackgroundColor");
        str = pElement->GetText();
        sscanf(str, "%f %f %f", &backgroundColor.x(), &backgroundColor.y(), &backgroundColor.z());

        pElement = pRoot->FirstChildElement("ShadowRayEpsilon");
        if(pElement != nullptr)
                pElement->QueryFloatText(&shadowRayEps);

        pElement = pRoot->FirstChildElement("IntersectionTestEpsilon");
        if(pElement != nullptr)
                eResult = pElement->QueryFloatText(&intTestEps);

        // Parse cameras
        pElement = pRoot->FirstChildElement("Cameras");
        XMLElement *pCamera = pElement->FirstChildElement("Camera");
        XMLElement *camElement;
        while(pCamera != nullptr)
        {
        int id;
        char imageName[64];
        Vector3f pos, gaze, up;
        ImagePlane imgPlane;

                eResult = pCamera->QueryIntAttribute("id", &id);
                camElement = pCamera->FirstChildElement("Position");
                str = camElement->GetText();
                sscanf(str, "%f %f %f", &pos.x(), &pos.y(), &pos.z());
                camElement = pCamera->FirstChildElement("Gaze");
                str = camElement->GetText();
                sscanf(str, "%f %f %f", &gaze.x(), &gaze.y(), &gaze.z());
                camElement = pCamera->FirstChildElement("Up");
                str = camElement->GetText();
                sscanf(str, "%f %f %f", &up.x(), &up.y(), &up.z());
                camElement = pCamera->FirstChildElement("NearPlane");
                str = camElement->GetText();
                sscanf(str, "%f %f %f %f", &imgPlane.left, &imgPlane.right, &imgPlane.bottom, &imgPlane.top);
                camElement = pCamera->FirstChildElement("NearDistance");
                eResult = camElement->QueryFloatText(&imgPlane.distance);
                camElement = pCamera->FirstChildElement("ImageResolution");
                str = camElement->GetText();
                sscanf(str, "%d %d", &imgPlane.nx, &imgPlane.ny);
                camElement = pCamera->FirstChildElement("ImageName");
                str = camElement->GetText();
                strcpy(imageName, str);

                cameras.push_back(new Camera(id, imageName, pos, gaze, up, imgPlane));

                pCamera = pCamera->NextSiblingElement("Camera");
        }

        // Parse materals
        pElement = pRoot->FirstChildElement("Materials");
        XMLElement *pMaterial = pElement->FirstChildElement("Material");
        XMLElement *materialElement;
        while(pMaterial != nullptr)
        {
                materials.push_back(new Material());

                int curr = materials.size() - 1;

                eResult = pMaterial->QueryIntAttribute("id", &materials[curr]->id);
                materialElement = pMaterial->FirstChildElement("AmbientReflectance");
                str = materialElement->GetText();
                sscanf(str, "%f %f %f", &materials[curr]->ambientRef.x(), &materials[curr]->ambientRef.y(), &materials[curr]->ambientRef.z());
                materialElement = pMaterial->FirstChildElement("DiffuseReflectance");
                str = materialElement->GetText();
                sscanf(str, "%f %f %f", &materials[curr]->diffuseRef.x(), &materials[curr]->diffuseRef.y(), &materials[curr]->diffuseRef.z());
                materialElement = pMaterial->FirstChildElement("SpecularReflectance");
                str = materialElement->GetText();
                sscanf(str, "%f %f %f", &materials[curr]->specularRef.x(), &materials[curr]->specularRef.y(), &materials[curr]->specularRef.z());
                materialElement = pMaterial->FirstChildElement("MirrorReflectance");
                if(materialElement != nullptr)
                {
                        str = materialElement->GetText();
                        sscanf(str, "%f %f %f", &materials[curr]->mirrorRef.x(), &materials[curr]->mirrorRef.y(), &materials[curr]->mirrorRef.z());
                }
                                else
                {
                        materials[curr]->mirrorRef.x() = 0.0;
                        materials[curr]->mirrorRef.y() = 0.0;
                        materials[curr]->mirrorRef.z() = 0.0;
                }
                materialElement = pMaterial->FirstChildElement("PhongExponent");
                if(materialElement != nullptr)
                        materialElement->QueryIntText(&materials[curr]->phongExp);

                pMaterial = pMaterial->NextSiblingElement("Material");
        }

        // Parse vertex data
        pElement = pRoot->FirstChildElement("VertexData");
        int cursor = 0;
        Vector3f tmpPoint;
        str = pElement->GetText();
        while(str[cursor] == ' ' || str[cursor] == '\t' || str[cursor] == '\n')
                cursor++;
        while(str[cursor] != '\0')
        {
                for(int cnt = 0 ; cnt < 3 ; cnt++)
                {
                        if(cnt == 0)
                                tmpPoint.x() = atof(str + cursor);
                        else if(cnt == 1)
                                tmpPoint.y() = atof(str + cursor);
                        else
                                tmpPoint.z() = atof(str + cursor);
                        while(str[cursor] != ' ' && str[cursor] != '\t' && str[cursor] != '\n')
                                cursor++; 
                        while(str[cursor] == ' ' || str[cursor] == '\t' || str[cursor] == '\n')
                                cursor++;
                }
                vertices.push_back(tmpPoint);
        }

        // Parse objects
        pElement = pRoot->FirstChildElement("Objects");

        // Parse spheres
        XMLElement *pObject = pElement->FirstChildElement("Sphere");
        XMLElement *objElement;
        while(pObject != nullptr)
        {
                int id;
                int matIndex;
                int cIndex;
                float R;

                eResult = pObject->QueryIntAttribute("id", &id);
                objElement = pObject->FirstChildElement("Material");
                eResult = objElement->QueryIntText(&matIndex);
                objElement = pObject->FirstChildElement("Center");
                eResult = objElement->QueryIntText(&cIndex);
                objElement = pObject->FirstChildElement("Radius");
                eResult = objElement->QueryFloatText(&R);

                objects.push_back(new Sphere(id, matIndex, cIndex, R, &vertices));

                pObject = pObject->NextSiblingElement("Sphere");
        }

        // Parse triangles
        pObject = pElement->FirstChildElement("Triangle");
        while(pObject != nullptr)
        {
                int id;
                int matIndex;
                int p1Index;
                int p2Index;
                int p3Index;

                eResult = pObject->QueryIntAttribute("id", &id);
                objElement = pObject->FirstChildElement("Material");
                eResult = objElement->QueryIntText(&matIndex);
                objElement = pObject->FirstChildElement("Indices");
                str = objElement->GetText();
                sscanf(str, "%d %d %d", &p1Index, &p2Index, &p3Index);

                objects.push_back(new Triangle(id, matIndex, p1Index, p2Index, p3Index, &vertices));

                pObject = pObject->NextSiblingElement("Triangle");
        }

        // Parse meshes
        pObject = pElement->FirstChildElement("Mesh");
        while(pObject != nullptr)
        {
                int id;
                int matIndex;
                int p1Index;
                int p2Index;
                int p3Index;
                int cursor = 0;
                int vertexOffset = 0;
                vector<Triangle> faces;
                vector<int> *meshIndices = new vector<int>;

                eResult = pObject->QueryIntAttribute("id", &id);
                objElement = pObject->FirstChildElement("Material");
                eResult = objElement->QueryIntText(&matIndex);
                objElement = pObject->FirstChildElement("Faces");
                objElement->QueryIntAttribute("vertexOffset", &vertexOffset);
                str = objElement->GetText();
                while(str[cursor] == ' ' || str[cursor] == '\t' || str[cursor] == '\n')
                        cursor++;
                while(str[cursor] != '\0')
                {
                        for(int cnt = 0 ; cnt < 3 ; cnt++)
                        {
                                if(cnt == 0)
                                        p1Index = atoi(str + cursor) + vertexOffset;
                                else if(cnt == 1)
                                        p2Index = atoi(str + cursor) + vertexOffset;
                                else
                                        p3Index = atoi(str + cursor) + vertexOffset;
                                while(str[cursor] != ' ' && str[cursor] != '\t' && str[cursor] != '\n')
                                        cursor++; 
                                while(str[cursor] == ' ' || str[cursor] == '\t' || str[cursor] == '\n')
                                        cursor++;
                        }
                        faces.push_back(*(new Triangle(-1, matIndex, p1Index, p2Index, p3Index, &vertices)));
                        meshIndices->push_back(p1Index);
                        meshIndices->push_back(p2Index);
                        meshIndices->push_back(p3Index);
                }

                objects.push_back(new Mesh(id, matIndex, faces, meshIndices, &vertices));

                pObject = pObject->NextSiblingElement("Mesh");
        }

        // Parse lights
        int id;
        Vector3f position;
        Vector3f intensity;
        pElement = pRoot->FirstChildElement("Lights");

        XMLElement *pLight = pElement->FirstChildElement("AmbientLight");
        XMLElement *lightElement;
        str = pLight->GetText();
        sscanf(str, "%f %f %f", &ambientLight.x(), &ambientLight.y(), &ambientLight.z());

        pLight = pElement->FirstChildElement("PointLight");
        while(pLight != nullptr)
        {
                eResult = pLight->QueryIntAttribute("id", &id);
                lightElement = pLight->FirstChildElement("Position");
                str = lightElement->GetText();
                sscanf(str, "%f %f %f", &position.x(), &position.y(), &position.z());
                lightElement = pLight->FirstChildElement("Intensity");
                str = lightElement->GetText();
                sscanf(str, "%f %f %f", &intensity.x(), &intensity.y(), &intensity.z());

                lights.push_back(new PointLight(position, intensity));

                pLight = pLight->NextSiblingElement("PointLight");
        }
}
