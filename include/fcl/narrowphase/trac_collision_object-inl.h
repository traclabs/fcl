

#ifndef TRAC_COLLISION_OBJECT_INL_H
#define TRAC_COLLISION_OBJECT_INL_H

#include "fcl/narrowphase/trac_collision_object.h"

namespace fcl {

  //==============================================================================
  extern template
    class FCL_EXPORT TRACCollisionObject<double>;

  //==============================================================================
  template <typename S>
    TRACCollisionObject<S>::TRACCollisionObject(const std::shared_ptr<CollisionGeometry<S>>& cgeom) : margin_(0),
  CollisionObject<S>( cgeom ) {
    
  }

  //==============================================================================
  template<typename S>
  TRACCollisionObject<S>::TRACCollisionObject(const std::shared_ptr<CollisionGeometry<S>>& cgeom,
					   const Transform3<S>& tf) :
  margin_(0),
  CollisionObject<S>( cgeom, tf ) {

  }

  //==============================================================================
  template<typename S>
  TRACCollisionObject<S>::TRACCollisionObject(const std::shared_ptr<CollisionGeometry<S>>& cgeom,
					      const Matrix3<S>& R,
					      const Vector3<S>& T) :
  margin_(0),
  CollisionObject<S>( cgeom, R, T ) {

  }

  //==============================================================================
  template<typename S>
  TRACCollisionObject<S>::~TRACCollisionObject() {

  }

  //==============================================================================
  template<typename S>
  void TRACCollisionObject<S>::computeAABB() {
    CollisionObject<S>::computeAABB();
    add_margin_AABB();
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
    fcl::Vector3<S> added_margin_min;
    added_margin_min << aabb.min_(0)-margin_, aabb.min_(1)-margin_, aabb.min_(2)-margin_;
    this->aabb.min_ = added_margin_min;
    
    fcl::Vector3<S> added_margin_max;
    added_margin_max << aabb.max_(0)+margin_, aabb.max_(1)+margin_, aabb.max_(2)+margin_;
    this->aabb.max_ = added_margin_max;
  }

  

} // namespace fcl

#endif
