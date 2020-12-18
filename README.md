# VMath
My own lighter, more intuitive glm.

namespace vmath

These headers consist of defenitions of templated 2D, 3D and 4D vectors as well as a 4x4 matrix. They are made to be easily used along with Vulkan, hence the name VMath.

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
You can do arithmetic on vectors with other vectors or scalars. Matrix file is not as fleshed out and is missing some functionality. They are not a priority right now though.
  
  
When using these matrices in the vertex shader, simply multiply together all 3 matrices in the order that is described by the name. ie:
```
outPos = inPos * modelToWorld * worldToView * viewToProj;
```
or
```
outPos = projFromView * viewFromWorld * worldFromModel * inPos;
```
according to [this naming convention](https://www.sebastiansylvan.com/post/matrix_naming_convention/)

Things to add:
  * model rotation and scale in modelToWorld()
  * worldToViewMatrix using axis-angle camera instead of yaw/pitch camera
  * 
