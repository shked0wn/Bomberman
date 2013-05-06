#ifndef __CAMERA_HPP_
#define __CAMERA_HPP_

#include <GL/gl.h>
#include <GL/glu.h>

#include <GameClock.hpp>
#include <Input.hpp>

#include "Vector3f.hpp"

class Camera {
private:
  Vector3f	position_;
  Vector3f	rotation_;

public:
  Camera(void);

  void	initialize(void);
  void	update(gdl::GameClock const &, gdl::Input &);
};

#endif
