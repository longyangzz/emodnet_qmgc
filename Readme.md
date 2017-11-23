# EMODnet Quantized Mesh generator for Cesium

Library for generating terrain tiles in Cesium's quantized-mesh format from a GDAL raster file.

## Requirements

## Known issues

* This library depends on cesium-terrain-builder library (https://github.com/geo-data/cesium-terrain-builder), and thus it has the same limitation when creating tiles at lower zoom levels from large DEMs. In this case, the following error may raise:

```
ERROR 1: Integer overflow : nSrcXSize=20979, nSrcYSize=28800
ERROR 1: IReadBlock failed at X offset 0, Y offset 0
terminate called after throwing an instance of 'ctb::CTBException'
```
    
* If the case above raises, we provide the python script `qm_tiler_large_images.py` to automate the solution proposed by the cesium-terrain-builder documentation.

* While the QuantizedMesh class has read/write capabilities for the quantized mesh format with both oct-encoded per-vertex normals and water masks, the quantized mesh tiles generated by qm_tiler do not include the water mask. 

## Issues to take into account when implementing the quantized-mesh format

* The vertices and indices need to be optimized for both cache and fetching to be suitable for highwatermark encoding. We use a slightly modified version of the meshoptimizer library (https://github.com/zeux/meshoptimizer) to perform these steps.
