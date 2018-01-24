//
// Created by Ricard Campos (rcampos@eia.udg.edu).
//

#ifndef EMODNET_TOOLS_SURFACE_SIMPLIFICATION_VOID_CONCRETE_STRATEGY_H
#define EMODNET_TOOLS_SURFACE_SIMPLIFICATION_VOID_CONCRETE_STRATEGY_H

#include "tin_creation/tin_creator.h"

namespace TinCreation {

/**
 * A Delaunay triangulation is created with the input points, no simplification is applied.
 * Also, the constrain<X>Vertices parameters are ignored. This creation strategy is useful to just triangulate regular
 * grids, where the vertices at the borders are always the same for neighboring tiles.
 */
class TinCreationDelaunayStrategy : public TinCreationStrategy {
public:
    TinCreationDelaunayStrategy() {};

    Polyhedron create(const std::vector<Point_3> &dataPts,
                      const bool &constrainEasternVertices,
                      const bool &constrainWesternVertices,
                      const bool &constrainNorthernVertices,
                      const bool &constrainSouthernVertices);
};

} // End namespace TinCreation

#endif //EMODNET_TOOLS_SURFACE_SIMPLIFICATION_VOID_CONCRETE_STRATEGY_H