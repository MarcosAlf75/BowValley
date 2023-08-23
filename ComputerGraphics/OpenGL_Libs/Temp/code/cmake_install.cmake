# Install script for directory: C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Assimp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.2.4-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/Temp/lib/Debug/assimp-vc143-mtd.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/Temp/lib/Release/assimp-vc143-mt.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/Temp/lib/MinSizeRel/assimp-vc143-mt.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/Temp/lib/RelWithDebInfo/assimp-vc143-mt.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.2.4" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/Temp/bin/Debug/assimp-vc143-mtd.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/Temp/bin/Release/assimp-vc143-mt.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/Temp/bin/MinSizeRel/assimp-vc143-mt.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/Temp/bin/RelWithDebInfo/assimp-vc143-mt.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/anim.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/aabb.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/ai_assert.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/camera.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/color4.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/color4.inl"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/Temp/code/../include/assimp/config.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/ColladaMetaData.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/commonMetaData.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/defs.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/cfileio.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/light.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/material.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/material.inl"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/matrix3x3.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/matrix3x3.inl"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/matrix4x4.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/matrix4x4.inl"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/mesh.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/ObjMaterial.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/pbrmaterial.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/GltfMaterial.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/postprocess.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/quaternion.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/quaternion.inl"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/scene.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/metadata.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/texture.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/types.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/vector2.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/vector2.inl"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/vector3.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/vector3.inl"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/version.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/cimport.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/importerdesc.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/Importer.hpp"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/DefaultLogger.hpp"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/ProgressHandler.hpp"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/IOStream.hpp"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/IOSystem.hpp"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/Logger.hpp"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/LogStream.hpp"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/NullLogger.hpp"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/cexport.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/Exporter.hpp"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/DefaultIOStream.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/DefaultIOSystem.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/ZipArchiveIOSystem.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/SceneCombiner.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/fast_atof.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/qnan.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/BaseImporter.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/Hash.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/MemoryIOWrapper.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/ParsingUtils.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/StreamReader.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/StreamWriter.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/StringComparison.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/StringUtils.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/SGSpatialSort.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/GenericProperty.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/SpatialSort.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/SkeletonMeshBuilder.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/SmallVector.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/SmoothingGroups.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/SmoothingGroups.inl"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/StandardShapes.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/RemoveComments.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/Subdivision.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/Vertex.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/LineSplitter.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/TinyFormatter.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/Profiler.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/LogAux.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/Bitmap.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/XMLTools.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/IOStreamBuffer.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/CreateAnimMesh.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/XmlParser.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/BlobIOSystem.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/MathFunctions.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/Exceptional.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/ByteSwapper.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/Compiler/pushpack1.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/Compiler/poppack1.h"
    "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/ASSIMP/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/Temp/code/Debug/assimp-vc143-mtd.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "C:/VisualStudio/BowValley/ComputerGraphics/OpenGL/OpenGL_Libs/Temp/code/RelWithDebInfo/assimp-vc143-mt.pdb")
  endif()
endif()

