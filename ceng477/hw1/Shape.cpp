#include "Shape.h"

#include "Scene.h"

#include <cstdio>
#include <limits>

Shape::Shape(void) {}

Shape::Shape(int id, int matIndex): id(id), matIndex(matIndex) {}

Sphere::Sphere(void) {}

/* Constructor for sphere. You will implement this. */
Sphere::Sphere(int id, int matIndex, int cIndex, float R, vector < Vector3f > * pVertices): Shape(id, matIndex) {
    /***********************************************
     *                                             *
     * TODO: Implement this function               *
     *                                             *
     ***********************************************
     */
    this->cIndex = cIndex;
    this->R = R;
    this -> vertices = pVertices;
    this->center = this -> vertices -> at(this -> cIndex-1);
}

/* Sphere-ray intersection routine. You will implement this. 
Note that ReturnVal structure should hold the information related to the intersection point, e.g., coordinate of that point, normal at that point etc. 
You should to declare the variables in ReturnVal structure you think you will need. It is in defs.h file. */
ReturnVal Sphere::intersect(const Ray & ray) const {
    /***********************************************
     *                                             *
     * TODO: Implement this function               *
     *                                             *
     ***********************************************
     */
    float tmin, tmax;
    // we need to solve an equation which has maybe two roots. so we need t1 and t2.
    float discriminant;
    float a, b, c;
    ReturnVal ret;

    a = ray.direction.dot(ray.direction);
    Vector3f oc = ray.origin - this->center;
    b = 2 * ray.direction.dot(oc);
    c = oc.dot(oc) - this->R * this->R;
    discriminant = b * b - 4 * a * c;


    if (discriminant < 0) {

        ret.intersected = -1;
    } else if (discriminant >= 0) {

        //tmin = -b / (2*a);
        tmin = (-b - sqrtf(discriminant)) / (2 * a);
        tmax = (-b + sqrtf(discriminant)) / (2 * a);

    //    std::cout << tmin << "    "  << tmax << "  ---  " << ray.direction.x() << " - " << ray.direction.y() << " - " << ray.direction.z() <<std::endl;
        ret.intersected = 1;
        ret.intersectPoint = ray.getPoint(tmin);
        ret.t = tmin;           
        
    }
    if(ret.intersected==1){
        Vector3f ic = ret.intersectPoint - this->center;
        ret.normal = ic / this->R;
        ret.normal = (ret.normal).normalized();
    }
    return ret;
}

Triangle::Triangle(void) {}

/* Constructor for triangle. You will implement this. */
Triangle::Triangle(int id, int matIndex, int p1Index, int p2Index, int p3Index, vector < Vector3f > * pVertices): Shape(id, matIndex) {
    this->p1Index = p1Index;
    this->p2Index = p2Index;
    this->p3Index = p3Index;
    this->vertices = pVertices;

    /***********************************************
     *                                             *
     * TODO: Implemented                           *
     *                                             *
     ***********************************************
     */


}

/* Triangle-ray intersection routine. You will implement this. 
Note that ReturnVal structure should hold the information related to the intersection point, e.g., coordinate of that point, normal at that point etc. 
You should to declare the variables in ReturnVal structure you think you will need. It is in defs.h file. */
ReturnVal Triangle::intersect(const Ray & ray) const {
    
    /***********************************************
     *                                             *
     * TODO: Implement this function               *
     *                                             *
     ***********************************************
     */
    //std::cout << "Triangle intersect ici" << std::endl;
    Vector3f a,b,c,o,d,v,sol;
    Matrix3f A,Acache;
    ReturnVal ret;

    float beta, gama,t,Adet;
    a = this->vertices->at(p1Index-1);
    b = this->vertices->at(p2Index-1);
    c = this->vertices->at(p3Index-1);
    o = ray.origin;
    d = ray.direction;

    A << a.x()-b.x(),a.x()-c.x(),d.x(),
         a.y()-b.y(),a.y()-c.y(),d.y(),
         a.z()-b.z(),a.z()-c.z(),d.z();
    Adet = A.determinant();

    if(Adet!=0){
        Acache << a.x()-b.x(),a.x()-c.x(),a.x()-o.x(), 
                  a.y()-b.y(),a.y()-c.y(),a.y()-o.y(),
                  a.z()-b.z(),a.z()-c.z(),a.z()-o.z();

        t = Acache.determinant()/Adet;
        if(t>=1){
            Acache << a.x()-o.x(),a.x()-c.x(),d.x(),
                      a.y()-o.y(),a.y()-c.y(),d.y(),
                      a.z()-o.z(),a.z()-c.z(),d.z();
            beta = Acache.determinant()/Adet;
            Acache << a.x()-b.x(),a.x()-o.x(),d.x(),
                      a.y()-b.y(),a.y()-o.y(),d.y(),
                      a.z()-b.z(),a.z()-o.z(),d.z();
            gama = Acache.determinant()/Adet;
            if(beta>=-pScene->intTestEps &&gama>=-pScene->intTestEps && beta+gama<=1+pScene->intTestEps){
                ret.intersected=1;
                ret.intersectPoint = o + t*d;
                ret.t = t;
                Vector3f bacross = (b-a).cross(c-a);

                ret.normal = bacross.normalized();
                return ret;
            }
        }
    }
    ret.intersected =-1;
    return ret;


}

Mesh::Mesh() {}

/* Constructor for mesh. You will implement this. */
Mesh::Mesh(int id, int matIndex,
    const vector < Triangle > & faces, vector < int > * pIndices, vector < Vector3f > * pVertices): Shape(id, matIndex) {
    /***********************************************
     *                                             *
     * TODO: Implement this function               *
     *                                             *
     ***********************************************
     */
    this->vertices = pVertices;
    this->faces = faces;//*******************buna bakarlar
    // for (int i = 0; i < faces.size(); i++)
    // {
    //     this->faces[i] =faces[i];
    //     /* code */
    // }




}

/* Mesh-ray intersection routine. You will implement this. 
Note that ReturnVal structure should hold the information related to the intersection point
, e.g., coordinate of that point, normal at that point etc. 
You should to declare the variables in ReturnVal structure you think you will need. It is in defs.h file. */
ReturnVal Mesh::intersect(const Ray & ray) const {
    /***********************************************
     *                                             *
     * TODO: Implement this function               *
     *                                             *
     ***********************************************
     */
    //std::cout << "Mesh intersect" << std::endl;
    int count =0;
    float tmin = std::numeric_limits<float>::max();;

    ReturnVal ret,retCache;
    
    for (int i = 0; i < this->faces.size(); i++)
    {
        //std::cout << "Mesh intersect icindeyiz-" << this->faces.at(i).id << std::endl;
        ret = this->faces.at(i).intersect(ray);
        
        if(ret.intersected ==1){
            count++;
/*            if(count ==0) 
            {
                tmin = ret.t;
                
            }else if(tmin > ret.t){
                tmin =ret.t;
            }
            count++;*/
            if(tmin >ret.t){
                tmin = ret.t;
                retCache = ret;
            }

        }

    }
    if(count) ret = retCache;
    //ret.intersected=1;
    Vector3f deneme = ray.direction.normalized();
    ret.intersectPoint = ray.origin + tmin*deneme;
    ret.t = tmin;
    return ret;

}
