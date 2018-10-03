

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
    printf("TRACCollisionObject::computeAABB *********************************\n");
    this->cgeom->computeLocalAABB();
    printf("Add margin AABB: %f ***********************\n", margin_ );
    add_margin_AABB();
    CollisionObject<S>::computeAABB();
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
  //-- This function is only inteded to be called within computeAABB(), never on its own
  template<typename S>
  void TRACCollisionObject<S>::add_margin_AABB() {

    // Increase the radius and min/max of abb
    this->cgeom->aabb_radius = this->cgeom->aabb_radius + margin_;

    fcl::Vector3<S> min_val = this->cgeom->aabb_local.min_;
    fcl::Vector3<S> max_val = this->cgeom->aabb_local.max_;

    this->cgeom->aabb_local.min_ = min_val - fcl::Vector3<S>( margin_, margin_, margin_);
    this->cgeom->aabb_local.max_ = max_val + fcl::Vector3<S>( margin_, margin_, margin_);

  }

  

} // namespace fcl

#endif
