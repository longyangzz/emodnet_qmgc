//
// Created by Ricard Campos (rcampos@eia.udg.edu).
//

#ifndef EMODNET_TOOLS_PROJECTION_TRAITS_3_EXTENDED_H
#define EMODNET_TOOLS_PROJECTION_TRAITS_3_EXTENDED_H

#include <CGAL/internal/Projection_traits_3.h>

// We had to modify the original CGAL's Projection_traits because they didn't implement the squared distance computation
// between a Segment and a Point (required by the Polyline_2 simplification algorithm in)

namespace CGAL {

namespace internal {

    template <class R,int dim>
    class Squared_distance_projected_3_extended : public Squared_distance_projected_3<R,dim>
    {
    public:
        typedef typename R::Point_3   Point_3;
        typedef typename R::Point_2   Point_2;
        typedef typename R::Line_3    Line_3;
        typedef typename R::Line_2    Line_2;
        typedef typename R::Segment_2 Segment_2;
        typedef typename R::Segment_3 Segment_3;
        typedef typename R::FT        RT;

        RT operator()(const Segment_3& s, const Point_3& p) const
        {
            Point_2 p2(this->project(p));
            Segment_2 s2(this->project(s.point(0)), this->project(s.point(1)));
            return squared_distance(p2, s2);
        }

        RT operator()(const Point_3& p, const Point_3& q) const
        {
            this->operator()(p,q);
        }

        RT operator()(const Line_3& l, const Point_3& p) const
        {
            this->operator()(l,p);
        }
    };


    template<class R, int dim>
    class Projection_traits_3_extended : public Projection_traits_3<R, dim>
    {
    public:
        // We replicate all the typedefs, as they are not inherited necessarily
        typedef Projection_traits_3<R,dim>   Traits;
        typedef R                                                   Rp;
        typedef typename R::FT                                      FT;
        typedef typename Rp::Point_3                                Point_2;
        typedef typename Rp::Segment_3                              Segment_2;
        typedef typename Rp::Vector_3                               Vector_2;
        typedef typename Rp::Triangle_3                             Triangle_2;
        typedef typename Rp::Line_3                                 Line_2;
        typedef typename Rp::Ray_3                                  Ray_2;
        typedef typename Projector<R,dim>::Less_x_2                 Less_x_2;
        typedef typename Projector<R,dim>::Less_y_2                 Less_y_2;
        typedef typename Projector<R,dim>::Compare_x_2              Compare_x_2;
        typedef typename Projector<R,dim>::Compare_y_2              Compare_y_2;
        typedef Orientation_projected_3<Rp,dim>                     Orientation_2;
        typedef Angle_projected_3<Rp,dim>                           Angle_2;
        typedef Side_of_oriented_circle_projected_3<Rp,dim>         Side_of_oriented_circle_2;
        typedef Less_signed_distance_to_line_projected_3<Rp,dim>    Less_signed_distance_to_line_2;
        typedef Side_of_bounded_circle_projected_3<Rp,dim>          Side_of_bounded_circle_2;
        typedef Compare_distance_projected_3<Rp,dim>                Compare_distance_2;
        typedef Collinear_are_ordered_along_line_projected_3<Rp,dim> Collinear_are_ordered_along_line_2;
        typedef Intersect_projected_3<Rp,dim>                       Intersect_2;
        typedef Compute_squared_radius_projected<Rp,dim>            Compute_squared_radius_2;
        typedef Compute_scalar_product_projected_3<Rp,dim>          Compute_scalar_product_2;
        typedef Compute_squared_length_projected_3<Rp,dim>          Compute_squared_length_2;
        typedef typename Rp::Construct_segment_3                    Construct_segment_2;
        typedef typename Rp::Construct_translated_point_3           Construct_translated_point_2;
        typedef typename Rp::Construct_midpoint_3                   Construct_midpoint_2;
        typedef typename Rp::Construct_vector_3                     Construct_vector_2;
        typedef typename Rp::Construct_scaled_vector_3              Construct_scaled_vector_2;
        typedef typename Rp::Construct_triangle_3                   Construct_triangle_2;
        typedef typename Rp::Construct_line_3                       Construct_line_2;
        typedef typename Projector<R,dim>::Equal_x_2                Equal_x_2;
        typedef typename Projector<R,dim>::Equal_y_2                Equal_y_2;
        typedef Circumcenter_center_projected<Rp,dim>               Construct_circumcenter_2;
        typedef Compute_area_projected<Rp,dim>                      Compute_area_2;
        typedef Point_2      Point;
        typedef Segment_2    Segment;
        typedef Triangle_2   Triangle;

        // The important changes:
        typedef Squared_distance_projected_3_extended<Rp,dim> Compute_squared_distance_2;

        Compute_squared_distance_2
        compute_squared_distance_2_object () const
        {
            return Compute_squared_distance_2();
        }
    };

} // End namespace internal

template < class R >
class Projection_traits_xy_3_extended
        : public internal::Projection_traits_3_extended<R,2>
{};

template < class R >
class Projection_traits_xz_3_extended
        : public internal::Projection_traits_3_extended<R,1>
{};

template < class R >
class Projection_traits_yz_3_extended
        : public internal::Projection_traits_3_extended<R,0>
{};

} // End namespace CGAL

#endif //EMODNET_TOOLS_PROJECTION_TRAITS_3_EXTENDED_H