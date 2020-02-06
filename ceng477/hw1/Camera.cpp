#include "Camera.h"
#include <math.h>

Camera::Camera(int id,                      // Id of the camera
               const char* imageName,       // Name of the output PPM file 
               const Vector3f& pos,         // Camera position
               const Vector3f& gaze,        // Camera gaze direction
               const Vector3f& up,          // Camera up direction
               const ImagePlane& imgPlane)  // Image plane parameters
{
  this->id = id;
  strcpy(this->imageName, imageName);

  //this->imageName = *imageName;
  
  this->pos.x() = pos.x();
  this->pos.y() = pos.y();
  this->pos.z() = pos.z();
  this->gaze.x() = gaze.x();
  this->gaze.y() = gaze.y();
  this->gaze.z() = gaze.z();
  this->up.x() = up.x();
  this->up.y() = up.y();
  this->up.z() = up.z();
  //this->up = up.normalized();
  this->u = (this->up.cross((-1)*this->gaze)).normalized();
  this->gaze = (this->gaze).normalized();
  
  this->imgPlane = imgPlane; //kontrol et
  //this->imgPlane = *(this->imgPlane);
  /***********************************************
     *                                             *
      * TODO: Implement this function               *
     *                                             *
     ***********************************************
      */
}

/* Takes coordinate of an image pixel as row and col, and
 * returns the ray going through that pixel. 
 */
Ray Camera::getPrimaryRay(int row, int col) const
{
  Vector3f m,q,s;
  // m.x() = this->pos.x() - this->gaze.x() * this->imgPlane.distance;
  // m.y() = this->pos.y() - this->gaze.y() * this->imgPlane.distance;
  // m.z() = this->pos.z() - this->gaze.z() * this->imgPlane.distance;

  m = this->pos + this->gaze * this->imgPlane.distance;
  q = m + this->imgPlane.left * this->u + this->imgPlane.top * this->up;
  float su = (col + 0.5)  * ((this->imgPlane.right - this->imgPlane.left ) / this->imgPlane.nx);
  float sv = (row + 0.5)  * ((this->imgPlane.top - this->imgPlane.bottom ) / this->imgPlane.ny);

  s = q + su * this->u - sv * this->up;

  Ray ret;
  ret.origin = this->pos;
  ret.direction = s - this->pos;
  ret.direction = (ret.direction).normalized();   //control et gerek yok mu
  return ret;

     /***********************************************
     *                                             *
      * TODO: Implement this function               *
     *                                             *
     ***********************************************
      */
}

