# VMath
vectors and matrices

namespace vmath

These headers consist of defenitions of templated 2D, 3D and 4D vectors as well as a 4x4 matrix.

Vector functionality:
  * dot product
  * cross product
  * axis-angle rotations  aka [Rodrugues'](https://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula#Statement)
  * debugging
  
Matrix functionality:
  * identity matrix
  * modelToWorld matrix (
  * worldToView matrix (pitch and yaw camera args)
  * viewToProjection matrix
  * everything above but vice versa.
  
Vector file has every arithmetic operator overloaded (const and non-const).
Vector file also overloads type cast operator(T), stream insertion operator<< and component acces operator[].
You can do arithmetic on vectors with other vectors or scalars.
  
  
When using these matrices in the vertex shader, simply multiply together all 3 matrices in the order that is described by the name. ie:
```
outPos = inPos * modelToWorld * worldToView * viewToProj;
```
or
```
outPos = projFromView * viewFromWorld * worldFromModel * inPos;
```
according to [this naming convention](https://www.sebastiansylvan.com/post/matrix_naming_convention/)
