

#ifndef TRAC_COLLISION_OBJECT_INL_H
#define TRAC_COLLISION_OBJECT_INL_H

#include "fcl/narrowphase/trac_collision_object.h"

namespace fcl {

  //==============================================================================
  extern template
    class FCL_EXPORT TRACCollisionObject<double>;

  //==============================================================================
  template <typename S>
    TRACCollisionObject<S>::TRACCollisionObject(const std::shared_ptr<CollisionGeometry<S>>& cgeom) :
  CollisionObject<S>( cgeom ) {

  }

  //==============================================================================
  template<typename S>
  TRACCollisionObject<S>::TRACCollisionObject(const std::shared_ptr<CollisionGeometry<S>>& cgeom,
					   const Transform3<S>& tf) :
  CollisionObject<S>( cgeom, tf ) {

  }

  //==============================================================================
  template<typename S>
  TRACCollisionObject<S>::TRACCollisionObject(const std::shared_ptr<CollisionGeometry<S>>& cgeom,
					      const Matrix3<S>& R,
					      const Vector3<S>& T) :
  CollisionObject<S>( cgeom, R, T ) {

  }

  //==============================================================================
  template<typename S>
  TRACCollisionObject<S>::~TRACCollisionObject() {

  }

  //==============================================================================
  template<typename S>
  void TRACCollisionObject<S>::set_margin( S _margin ) {
    margin_ = _margin;
  }

  //==============================================================================
  template<typename S> 
  S TRACCollisionObject<S>::get_margin() {
    return margin_;
  }

  //==============================================================================
  template<typename S>
  void TRACCollisionObject<S>::add_margin_AABB() {
  }

} // namespace fcl

#endif
