/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 19.05
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HIOSTREAM
#define HCPP_HIOSTREAM

#ifndef HCPP_NO_USE_IOSTREAM

// Inline functions for serialization from/into streams.
//
// Windows does not like passing file handles across DLL boundaries, therefore
// these functions are to be used inline in your application.

#include <iostream>

namespace HalconCpp
{

#  define H_SERIAL_HEADER_SIZE 16

  // Serialize object instance to output stream
  void inline HSerializedItem::Serialize(std::ostream& stream)
  {
    Hlong size;
    const char* ptr = (const char*) GetSerializedItemPtr(&size);
    stream.write(ptr,size);
  }

  // Deserialize object instance from input stream
  HSerializedItem inline HSerializedItem::Deserialize(std::istream& stream)
  {
    char   header[H_SERIAL_HEADER_SIZE];
    HUINT8 size;
    char   *serialized;
  
    // Read, parse and verify header
    stream.read(header,H_SERIAL_HEADER_SIZE);
    serialized = DeserializeInitFromHeader(header,!stream.fail()&&!stream.eof(),&size);
  
    // Read and verify serializated data
    stream.read(serialized+H_SERIAL_HEADER_SIZE,(std::streamsize)size);
  
    // Return serialized item
    return DeserializeBufferToItem(size,!stream.fail()&& !stream.eof(),serialized);
  }

  // Serialize a HTemplate instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HTemplate& TemplateID)
  {
    TemplateID.SerializeTemplate().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HTemplate
  inline std::istream& operator >> (std::istream& stream, HTemplate& TemplateID)
  {
    TemplateID.DeserializeTemplate(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HNCCModel instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HNCCModel& ModelID)
  {
    ModelID.SerializeNccModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HNCCModel
  inline std::istream& operator >> (std::istream& stream, HNCCModel& ModelID)
  {
    ModelID.DeserializeNccModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HShapeModel instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HShapeModel& ModelID)
  {
    ModelID.SerializeShapeModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HShapeModel
  inline std::istream& operator >> (std::istream& stream, HShapeModel& ModelID)
  {
    ModelID.DeserializeShapeModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HObjectModel3D instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HObjectModel3D& ObjectModel3D)
  {
    ObjectModel3D.SerializeObjectModel3d().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HObjectModel3D
  inline std::istream& operator >> (std::istream& stream, HObjectModel3D& ObjectModel3D)
  {
    ObjectModel3D.DeserializeObjectModel3d(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HSurfaceModel instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HSurfaceModel& SurfaceModelID)
  {
    SurfaceModelID.SerializeSurfaceModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HSurfaceModel
  inline std::istream& operator >> (std::istream& stream, HSurfaceModel& SurfaceModelID)
  {
    SurfaceModelID.DeserializeSurfaceModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HDeformableSurfaceModel instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HDeformableSurfaceModel& DeformableSurfaceModel)
  {
    DeformableSurfaceModel.SerializeDeformableSurfaceModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HDeformableSurfaceModel
  inline std::istream& operator >> (std::istream& stream, HDeformableSurfaceModel& DeformableSurfaceModel)
  {
    DeformableSurfaceModel.DeserializeDeformableSurfaceModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HShapeModel3D instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HShapeModel3D& ShapeModel3DID)
  {
    ShapeModel3DID.SerializeShapeModel3d().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HShapeModel3D
  inline std::istream& operator >> (std::istream& stream, HShapeModel3D& ShapeModel3DID)
  {
    ShapeModel3DID.DeserializeShapeModel3d(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HDeformableModel instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HDeformableModel& ModelID)
  {
    ModelID.SerializeDeformableModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HDeformableModel
  inline std::istream& operator >> (std::istream& stream, HDeformableModel& ModelID)
  {
    ModelID.DeserializeDeformableModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HDescriptorModel instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HDescriptorModel& ModelID)
  {
    ModelID.SerializeDescriptorModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HDescriptorModel
  inline std::istream& operator >> (std::istream& stream, HDescriptorModel& ModelID)
  {
    ModelID.DeserializeDescriptorModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HVariationModel instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HVariationModel& ModelID)
  {
    ModelID.SerializeVariationModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HVariationModel
  inline std::istream& operator >> (std::istream& stream, HVariationModel& ModelID)
  {
    ModelID.DeserializeVariationModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HCalibData instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HCalibData& CalibDataID)
  {
    CalibDataID.SerializeCalibData().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HCalibData
  inline std::istream& operator >> (std::istream& stream, HCalibData& CalibDataID)
  {
    CalibDataID.DeserializeCalibData(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HCameraSetupModel instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HCameraSetupModel& CameraSetupModelID)
  {
    CameraSetupModelID.SerializeCameraSetupModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HCameraSetupModel
  inline std::istream& operator >> (std::istream& stream, HCameraSetupModel& CameraSetupModelID)
  {
    CameraSetupModelID.DeserializeCameraSetupModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HComponentTraining instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HComponentTraining& ComponentTrainingID)
  {
    ComponentTrainingID.SerializeTrainingComponents().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HComponentTraining
  inline std::istream& operator >> (std::istream& stream, HComponentTraining& ComponentTrainingID)
  {
    ComponentTrainingID.DeserializeTrainingComponents(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HComponentModel instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HComponentModel& ComponentModelID)
  {
    ComponentModelID.SerializeComponentModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HComponentModel
  inline std::istream& operator >> (std::istream& stream, HComponentModel& ComponentModelID)
  {
    ComponentModelID.DeserializeComponentModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HMeasure instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HMeasure& MeasureHandle)
  {
    MeasureHandle.SerializeMeasure().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HMeasure
  inline std::istream& operator >> (std::istream& stream, HMeasure& MeasureHandle)
  {
    MeasureHandle.DeserializeMeasure(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HMatrix instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HMatrix& MatrixID)
  {
    MatrixID.SerializeMatrix().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HMatrix
  inline std::istream& operator >> (std::istream& stream, HMatrix& MatrixID)
  {
    MatrixID.DeserializeMatrix(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HBarCode instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HBarCode& BarCodeHandle)
  {
    BarCodeHandle.SerializeBarCodeModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HBarCode
  inline std::istream& operator >> (std::istream& stream, HBarCode& BarCodeHandle)
  {
    BarCodeHandle.DeserializeBarCodeModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HDataCode2D instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HDataCode2D& DataCodeHandle)
  {
    DataCodeHandle.SerializeDataCode2dModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HDataCode2D
  inline std::istream& operator >> (std::istream& stream, HDataCode2D& DataCodeHandle)
  {
    DataCodeHandle.DeserializeDataCode2dModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HObject instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HObject& Object)
  {
    Object.SerializeObject().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HObject
  inline std::istream& operator >> (std::istream& stream, HObject& Object)
  {
    Object.DeserializeObject(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HImage instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HImage& Image)
  {
    Image.SerializeImage().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HImage
  inline std::istream& operator >> (std::istream& stream, HImage& Image)
  {
    Image.DeserializeImage(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HRegion instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HRegion& Region)
  {
    Region.SerializeRegion().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HRegion
  inline std::istream& operator >> (std::istream& stream, HRegion& Region)
  {
    Region.DeserializeRegion(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HXLD instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HXLD& XLD)
  {
    XLD.SerializeXld().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HXLD
  inline std::istream& operator >> (std::istream& stream, HXLD& XLD)
  {
    XLD.DeserializeXld(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HTuple instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HTuple& Tuple)
  {
    Tuple.SerializeTuple().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HTuple
  inline std::istream& operator >> (std::istream& stream, HTuple& Tuple)
  {
    Tuple = HTuple::DeserializeTuple(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HOCRBox instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HOCRBox& OcrHandle)
  {
    OcrHandle.SerializeOcr().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HOCRBox
  inline std::istream& operator >> (std::istream& stream, HOCRBox& OcrHandle)
  {
    OcrHandle.DeserializeOcr(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HOCRMlp instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HOCRMlp& OCRHandle)
  {
    OCRHandle.SerializeOcrClassMlp().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HOCRMlp
  inline std::istream& operator >> (std::istream& stream, HOCRMlp& OCRHandle)
  {
    OCRHandle.DeserializeOcrClassMlp(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HOCRSvm instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HOCRSvm& OCRHandle)
  {
    OCRHandle.SerializeOcrClassSvm().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HOCRSvm
  inline std::istream& operator >> (std::istream& stream, HOCRSvm& OCRHandle)
  {
    OCRHandle.DeserializeOcrClassSvm(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HOCV instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HOCV& OCVHandle)
  {
    OCVHandle.SerializeOcv().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HOCV
  inline std::istream& operator >> (std::istream& stream, HOCV& OCVHandle)
  {
    OCVHandle.DeserializeOcv(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HClassBox instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HClassBox& ClassifHandle)
  {
    ClassifHandle.SerializeClassBox().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HClassBox
  inline std::istream& operator >> (std::istream& stream, HClassBox& ClassifHandle)
  {
    ClassifHandle.DeserializeClassBox(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HClassMlp instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HClassMlp& MLPHandle)
  {
    MLPHandle.SerializeClassMlp().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HClassMlp
  inline std::istream& operator >> (std::istream& stream, HClassMlp& MLPHandle)
  {
    MLPHandle.DeserializeClassMlp(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HClassSvm instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HClassSvm& SVMHandle)
  {
    SVMHandle.SerializeClassSvm().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HClassSvm
  inline std::istream& operator >> (std::istream& stream, HClassSvm& SVMHandle)
  {
    SVMHandle.DeserializeClassSvm(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HClassGmm instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HClassGmm& GMMHandle)
  {
    GMMHandle.SerializeClassGmm().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HClassGmm
  inline std::istream& operator >> (std::istream& stream, HClassGmm& GMMHandle)
  {
    GMMHandle.DeserializeClassGmm(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HDlClassifier instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HDlClassifier& DLClassifierHandle)
  {
    DLClassifierHandle.SerializeDlClassifier().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HDlClassifier
  inline std::istream& operator >> (std::istream& stream, HDlClassifier& DLClassifierHandle)
  {
    DLClassifierHandle.DeserializeDlClassifier(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HDlModel instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HDlModel& DLModelHandle)
  {
    DLModelHandle.SerializeDlModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HDlModel
  inline std::istream& operator >> (std::istream& stream, HDlModel& DLModelHandle)
  {
    DLModelHandle.DeserializeDlModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HCamPar instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HCamPar& CameraParam)
  {
    CameraParam.SerializeCamPar().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HCamPar
  inline std::istream& operator >> (std::istream& stream, HCamPar& CameraParam)
  {
    CameraParam.DeserializeCamPar(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HPose instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HPose& Pose)
  {
    Pose.SerializePose().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HPose
  inline std::istream& operator >> (std::istream& stream, HPose& Pose)
  {
    Pose.DeserializePose(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HHomMat2D instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HHomMat2D& HomMat2D)
  {
    HomMat2D.SerializeHomMat2d().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HHomMat2D
  inline std::istream& operator >> (std::istream& stream, HHomMat2D& HomMat2D)
  {
    HomMat2D.DeserializeHomMat2d(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HHomMat3D instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HHomMat3D& HomMat3D)
  {
    HomMat3D.SerializeHomMat3d().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HHomMat3D
  inline std::istream& operator >> (std::istream& stream, HHomMat3D& HomMat3D)
  {
    HomMat3D.DeserializeHomMat3d(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HQuaternion instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HQuaternion& Quaternion)
  {
    Quaternion.SerializeQuat().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HQuaternion
  inline std::istream& operator >> (std::istream& stream, HQuaternion& Quaternion)
  {
    Quaternion.DeserializeQuat(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HDualQuaternion instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HDualQuaternion& DualQuaternion)
  {
    DualQuaternion.SerializeDualQuat().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HDualQuaternion
  inline std::istream& operator >> (std::istream& stream, HDualQuaternion& DualQuaternion)
  {
    DualQuaternion.DeserializeDualQuat(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HSheetOfLightModel instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HSheetOfLightModel& SheetOfLightModelID)
  {
    SheetOfLightModelID.SerializeSheetOfLightModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HSheetOfLightModel
  inline std::istream& operator >> (std::istream& stream, HSheetOfLightModel& SheetOfLightModelID)
  {
    SheetOfLightModelID.DeserializeSheetOfLightModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HMetrologyModel instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HMetrologyModel& MetrologyHandle)
  {
    MetrologyHandle.SerializeMetrologyModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HMetrologyModel
  inline std::istream& operator >> (std::istream& stream, HMetrologyModel& MetrologyHandle)
  {
    MetrologyHandle.DeserializeMetrologyModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HClassKnn instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HClassKnn& KNNHandle)
  {
    KNNHandle.SerializeClassKnn().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HClassKnn
  inline std::istream& operator >> (std::istream& stream, HClassKnn& KNNHandle)
  {
    KNNHandle.DeserializeClassKnn(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HOCRKnn instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HOCRKnn& OCRHandle)
  {
    OCRHandle.SerializeOcrClassKnn().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HOCRKnn
  inline std::istream& operator >> (std::istream& stream, HOCRKnn& OCRHandle)
  {
    OCRHandle.DeserializeOcrClassKnn(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HOCRCnn instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HOCRCnn& OCRHandle)
  {
    OCRHandle.SerializeOcrClassCnn().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HOCRCnn
  inline std::istream& operator >> (std::istream& stream, HOCRCnn& OCRHandle)
  {
    OCRHandle.DeserializeOcrClassCnn(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HClassTrainData instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HClassTrainData& ClassTrainDataHandle)
  {
    ClassTrainDataHandle.SerializeClassTrainData().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HClassTrainData
  inline std::istream& operator >> (std::istream& stream, HClassTrainData& ClassTrainDataHandle)
  {
    ClassTrainDataHandle.DeserializeClassTrainData(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HSampleIdentifier instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HSampleIdentifier& SampleIdentifier)
  {
    SampleIdentifier.SerializeSampleIdentifier().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HSampleIdentifier
  inline std::istream& operator >> (std::istream& stream, HSampleIdentifier& SampleIdentifier)
  {
    SampleIdentifier.DeserializeSampleIdentifier(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HXLDDistTrans instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HXLDDistTrans& DistanceTransformID)
  {
    DistanceTransformID.SerializeDistanceTransformXld().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HXLDDistTrans
  inline std::istream& operator >> (std::istream& stream, HXLDDistTrans& DistanceTransformID)
  {
    DistanceTransformID.DeserializeDistanceTransformXld(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HTextureInspectionModel instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HTextureInspectionModel& TextureInspectionModel)
  {
    TextureInspectionModel.SerializeTextureInspectionModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HTextureInspectionModel
  inline std::istream& operator >> (std::istream& stream, HTextureInspectionModel& TextureInspectionModel)
  {
    TextureInspectionModel.DeserializeTextureInspectionModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HStructuredLightModel instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HStructuredLightModel& StructuredLightModel)
  {
    StructuredLightModel.SerializeStructuredLightModel().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HStructuredLightModel
  inline std::istream& operator >> (std::istream& stream, HStructuredLightModel& StructuredLightModel)
  {
    StructuredLightModel.DeserializeStructuredLightModel(HSerializedItem::Deserialize(stream));
    return stream;
  }

  // Serialize a HHandle instance to a binary output stream
  inline std::ostream& operator << (std::ostream& stream, const HHandle& Handle)
  {
    Handle.SerializeHandle().Serialize(stream);
    return stream;
  }
  
  // Deserialize binary input stream to a HHandle
  inline std::istream& operator >> (std::istream& stream, HHandle& Handle)
  {
    Handle.DeserializeHandle(HSerializedItem::Deserialize(stream));
    return stream;
  }


  // Serialize a HString instance to an output stream
  inline std::ostream& operator<<(std::ostream& stream, const HString& val)
  {
    return (stream << val.TextA());
  }

#if defined(_WIN32)
  // Serialize a HString instance to an output stream
  inline std::wostream& operator<<(std::wostream& stream, const HString& val)
  {
    return (stream << val.TextW());
  }
#endif

} // namespace HalconCpp

#endif // HCPP_NO_USE_IOSTREAM
#endif // HCPP_HIOSTREAM

