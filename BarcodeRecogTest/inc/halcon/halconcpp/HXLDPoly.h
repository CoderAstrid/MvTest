/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 19.05
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HXLDPOLY
#define HCPP_HXLDPOLY

namespace HalconCpp
{

// Represents an instance of an XLD polygon object(-array).
class LIntExport HXLDPoly : public HXLD
{

public:

  // Create an uninitialized instance
  HXLDPoly():HXLD() {}

  // Copy constructor
  HXLDPoly(const HXLDPoly& source) : HXLD(source) {}

  // Copy constructor
  HXLDPoly(const HObject& object);

  // Create HXLDPoly from object id. For copy=false takes
  // over management of input key. Type of key must match!
  explicit HXLDPoly(Hkey key, bool copy=true);

  // Access of object tuple element
  const HXLDPoly operator [] (Hlong index) const;




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Compute the union of closed polygons.
  HXLDPoly Union2ClosedPolygonsXld(const HXLDPoly& Polygons2) const;

  // Compute the symmetric difference of closed polygons.
  HXLDPoly SymmDifferenceClosedPolygonsXld(const HXLDPoly& Polygons2) const;

  // Compute the difference of closed polygons.
  HXLDPoly DifferenceClosedPolygonsXld(const HXLDPoly& Sub) const;

  // Intersect closed polygons.
  HXLDPoly IntersectionClosedPolygonsXld(const HXLDPoly& Polygons2) const;

  // Read XLD polygons from a file in ARC/INFO generate format.
  void ReadPolygonXldArcInfo(const HString& FileName);

  // Read XLD polygons from a file in ARC/INFO generate format.
  void ReadPolygonXldArcInfo(const char* FileName);

#ifdef _WIN32
  // Read XLD polygons from a file in ARC/INFO generate format.
  void ReadPolygonXldArcInfo(const wchar_t* FileName);
#endif

  // Write XLD polygons to a file in ARC/INFO generate format.
  void WritePolygonXldArcInfo(const HString& FileName) const;

  // Write XLD polygons to a file in ARC/INFO generate format.
  void WritePolygonXldArcInfo(const char* FileName) const;

#ifdef _WIN32
  // Write XLD polygons to a file in ARC/INFO generate format.
  void WritePolygonXldArcInfo(const wchar_t* FileName) const;
#endif

  // Combine road hypotheses from two resolution levels.
  HXLDPoly CombineRoadsXld(const HXLDModPara& ModParallels, const HXLDExtPara& ExtParallels, const HXLDPoly& CenterLines, const HTuple& MaxAngleParallel, const HTuple& MaxAngleColinear, const HTuple& MaxDistanceParallel, const HTuple& MaxDistanceColinear) const;

  // Combine road hypotheses from two resolution levels.
  HXLDPoly CombineRoadsXld(const HXLDModPara& ModParallels, const HXLDExtPara& ExtParallels, const HXLDPoly& CenterLines, double MaxAngleParallel, double MaxAngleColinear, double MaxDistanceParallel, double MaxDistanceColinear) const;

  // Extract parallel XLD polygons.
  HXLDPara GenParallelsXld(const HTuple& Len, const HTuple& Dist, const HTuple& Alpha, const HString& Merge) const;

  // Extract parallel XLD polygons.
  HXLDPara GenParallelsXld(double Len, double Dist, double Alpha, const HString& Merge) const;

  // Extract parallel XLD polygons.
  HXLDPara GenParallelsXld(double Len, double Dist, double Alpha, const char* Merge) const;

#ifdef _WIN32
  // Extract parallel XLD polygons.
  HXLDPara GenParallelsXld(double Len, double Dist, double Alpha, const wchar_t* Merge) const;
#endif

  // Return an XLD polygon's data (as lines).
  void GetLinesXld(HTuple* BeginRow, HTuple* BeginCol, HTuple* EndRow, HTuple* EndCol, HTuple* Length, HTuple* Phi) const;

  // Return an XLD polygon's data.
  void GetPolygonXld(HTuple* Row, HTuple* Col, HTuple* Length, HTuple* Phi) const;

  // Split XLD contours at dominant points.
  HXLDCont SplitContoursXld(const HString& Mode, Hlong Weight, Hlong Smooth) const;

  // Split XLD contours at dominant points.
  HXLDCont SplitContoursXld(const char* Mode, Hlong Weight, Hlong Smooth) const;

#ifdef _WIN32
  // Split XLD contours at dominant points.
  HXLDCont SplitContoursXld(const wchar_t* Mode, Hlong Weight, Hlong Smooth) const;
#endif

  // Apply an arbitrary affine transformation to XLD polygons.
  HXLDPoly AffineTransPolygonXld(const HHomMat2D& HomMat2D) const;

  // Calculate the difference of two object tuples.
  HXLDPoly ObjDiff(const HXLDPoly& ObjectsSub) const;

  // Copy an iconic object in the HALCON database.
  HXLDPoly CopyObj(Hlong Index, Hlong NumObj) const;

  // Concatenate two iconic object tuples.
  HXLDPoly ConcatObj(const HXLDPoly& Objects2) const;

  // Select objects from an object tuple.
  HXLDPoly SelectObj(const HTuple& Index) const;

  // Select objects from an object tuple.
  HXLDPoly SelectObj(Hlong Index) const;

  // Compare iconic objects regarding equality.
  Hlong CompareObj(const HXLDPoly& Objects2, const HTuple& Epsilon) const;

  // Compare iconic objects regarding equality.
  Hlong CompareObj(const HXLDPoly& Objects2, double Epsilon) const;

  // Compare image objects regarding equality.
  Hlong TestEqualObj(const HXLDPoly& Objects2) const;

  // Create a region from an XLD polygon.
  HRegion GenRegionPolygonXld(const HString& Mode) const;

  // Create a region from an XLD polygon.
  HRegion GenRegionPolygonXld(const char* Mode) const;

#ifdef _WIN32
  // Create a region from an XLD polygon.
  HRegion GenRegionPolygonXld(const wchar_t* Mode) const;
#endif

  // Compute the mapping between the distorted image and the rectified image based upon the points of a regular grid.
  HImage GenGridRectificationMap(const HImage& Image, HXLDPoly* Meshes, Hlong GridSpacing, const HTuple& Rotation, const HTuple& Row, const HTuple& Column, const HString& MapType) const;

  // Compute the mapping between the distorted image and the rectified image based upon the points of a regular grid.
  HImage GenGridRectificationMap(const HImage& Image, HXLDPoly* Meshes, Hlong GridSpacing, const HString& Rotation, const HTuple& Row, const HTuple& Column, const HString& MapType) const;

  // Compute the mapping between the distorted image and the rectified image based upon the points of a regular grid.
  HImage GenGridRectificationMap(const HImage& Image, HXLDPoly* Meshes, Hlong GridSpacing, const char* Rotation, const HTuple& Row, const HTuple& Column, const char* MapType) const;

#ifdef _WIN32
  // Compute the mapping between the distorted image and the rectified image based upon the points of a regular grid.
  HImage GenGridRectificationMap(const HImage& Image, HXLDPoly* Meshes, Hlong GridSpacing, const wchar_t* Rotation, const HTuple& Row, const HTuple& Column, const wchar_t* MapType) const;
#endif

  // Read XLD polygons from a DXF file.
  HTuple ReadPolygonXldDxf(const HString& FileName, const HTuple& GenParamName, const HTuple& GenParamValue);

  // Read XLD polygons from a DXF file.
  HString ReadPolygonXldDxf(const HString& FileName, const HString& GenParamName, double GenParamValue);

  // Read XLD polygons from a DXF file.
  HString ReadPolygonXldDxf(const char* FileName, const char* GenParamName, double GenParamValue);

#ifdef _WIN32
  // Read XLD polygons from a DXF file.
  HString ReadPolygonXldDxf(const wchar_t* FileName, const wchar_t* GenParamName, double GenParamValue);
#endif

  // Write XLD polygons to a file in DXF format.
  void WritePolygonXldDxf(const HString& FileName) const;

  // Write XLD polygons to a file in DXF format.
  void WritePolygonXldDxf(const char* FileName) const;

#ifdef _WIN32
  // Write XLD polygons to a file in DXF format.
  void WritePolygonXldDxf(const wchar_t* FileName) const;
#endif

  // Choose all contours or polygons containing a given point.
  HXLDPoly SelectXldPoint(const HTuple& Row, const HTuple& Column) const;

  // Choose all contours or polygons containing a given point.
  HXLDPoly SelectXldPoint(double Row, double Column) const;

  // Select contours or polygons using shape features.
  HXLDPoly SelectShapeXld(const HTuple& Features, const HString& Operation, const HTuple& Min, const HTuple& Max) const;

  // Select contours or polygons using shape features.
  HXLDPoly SelectShapeXld(const HString& Features, const HString& Operation, double Min, double Max) const;

  // Select contours or polygons using shape features.
  HXLDPoly SelectShapeXld(const char* Features, const char* Operation, double Min, double Max) const;

#ifdef _WIN32
  // Select contours or polygons using shape features.
  HXLDPoly SelectShapeXld(const wchar_t* Features, const wchar_t* Operation, double Min, double Max) const;
#endif

  // Transform the shape of contours or polygons.
  HXLDPoly ShapeTransXld(const HString& Type) const;

  // Transform the shape of contours or polygons.
  HXLDPoly ShapeTransXld(const char* Type) const;

#ifdef _WIN32
  // Transform the shape of contours or polygons.
  HXLDPoly ShapeTransXld(const wchar_t* Type) const;
#endif

  // Insert objects into an iconic object tuple.
  HXLDPoly InsertObj(const HXLDPoly& ObjectsInsert, Hlong Index) const;

  // Remove objects from an iconic object tuple.
  HXLDPoly RemoveObj(const HTuple& Index) const;

  // Remove objects from an iconic object tuple.
  HXLDPoly RemoveObj(Hlong Index) const;

  // Replaces one or more elements of an iconic object tuple.
  HXLDPoly ReplaceObj(const HXLDPoly& ObjectsReplace, const HTuple& Index) const;

  // Replaces one or more elements of an iconic object tuple.
  HXLDPoly ReplaceObj(const HXLDPoly& ObjectsReplace, Hlong Index) const;

private:

  // Verify matching semantic type ('xld_poly')!
  void AssertObjectClass();

};

}

#endif
