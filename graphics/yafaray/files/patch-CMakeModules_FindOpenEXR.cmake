--- CMakeModules/FindOpenEXR.cmake.orig	2020-07-13 08:15:40 UTC
+++ CMakeModules/FindOpenEXR.cmake
@@ -26,10 +26,13 @@ IF(ZLIB_FOUND)
 		/sw/include
 		/opt/local/include)
 
-	FIND_LIBRARY(OPENEXR_HALF_LIBRARY 
-		NAMES Half
-		PATHS ${LIBRARY_DIRS})
-  
+	FIND_PATH(IMATH_INCLUDE_PATH ImathVec.h
+		PATH_SUFFIXES Imath
+		/usr/include
+		/usr/local/include
+		/sw/include
+		/opt/local/include)
+
 	FIND_LIBRARY(OPENEXR_IEX_LIBRARY 
 		NAMES Iex
 		PATHS ${LIBRARY_DIRS})
@@ -39,7 +42,7 @@ IF(ZLIB_FOUND)
 		PATHS ${LIBRARY_DIRS})
   
 	FIND_LIBRARY(OPENEXR_ILMIMF_LIBRARY
-		NAMES IlmImf
+		NAMES OpenEXR
 		PATHS ${LIBRARY_DIRS})
 
 	FIND_LIBRARY(OPENEXR_ILMTHREAD_LIBRARY
@@ -50,15 +53,15 @@ ENDIF(ZLIB_FOUND)
 
 #MESSAGE(STATUS ${OPENEXR_IMATH_LIBRARY} ${OPENEXR_ILMIMF_LIBRARY} ${OPENEXR_IEX_LIBRARY} ${OPENEXR_HALF_LIBRARY} ${OPENEXR_ILMTHREAD_LIBRARY} ${ZLIB_LIBRARY})
 
-IF (OPENEXR_INCLUDE_PATH AND OPENEXR_IMATH_LIBRARY AND OPENEXR_ILMIMF_LIBRARY AND OPENEXR_IEX_LIBRARY AND OPENEXR_HALF_LIBRARY)
+IF (OPENEXR_INCLUDE_PATH AND IMATH_INCLUDE_PATH AND OPENEXR_IMATH_LIBRARY AND OPENEXR_ILMIMF_LIBRARY AND OPENEXR_IEX_LIBRARY)
 	SET(OPENEXR_FOUND TRUE)
-	SET(OPENEXR_INCLUDE_DIRS ${OPENEXR_INCLUDE_PATH} CACHE STRING "The include paths needed to use OpenEXR")
-	SET(OPENEXR_LIBRARIES ${OPENEXR_IMATH_LIBRARY} ${OPENEXR_ILMIMF_LIBRARY} ${OPENEXR_IEX_LIBRARY} ${OPENEXR_HALF_LIBRARY} ${ZLIB_LIBRARY} CACHE STRING "The libraries needed to use OpenEXR")
+	SET(OPENEXR_INCLUDE_DIRS ${OPENEXR_INCLUDE_PATH} ${IMATH_INCLUDE_PATH} CACHE STRING "The include paths needed to use OpenEXR")
+	SET(OPENEXR_LIBRARIES ${OPENEXR_IMATH_LIBRARY} ${OPENEXR_ILMIMF_LIBRARY} ${OPENEXR_IEX_LIBRARY} ${ZLIB_LIBRARY} CACHE STRING "The libraries needed to use OpenEXR")
 
 	IF(OPENEXR_ILMTHREAD_LIBRARY)
 		SET(OPENEXR_LIBRARIES ${OPENEXR_LIBRARIES} ${OPENEXR_ILMTHREAD_LIBRARY})
 	ENDIF(OPENEXR_ILMTHREAD_LIBRARY)
-ENDIF (OPENEXR_INCLUDE_PATH AND OPENEXR_IMATH_LIBRARY AND OPENEXR_ILMIMF_LIBRARY AND OPENEXR_IEX_LIBRARY AND OPENEXR_HALF_LIBRARY)
+ENDIF (OPENEXR_INCLUDE_PATH AND OPENEXR_IMATH_LIBRARY AND OPENEXR_ILMIMF_LIBRARY AND OPENEXR_IEX_LIBRARY)
 
 IF(OPENEXR_FOUND)
 	IF(NOT OPENEXR_FIND_QUIETLY)
@@ -75,5 +78,4 @@ MARK_AS_ADVANCED(
 	OPENEXR_LIBRARIES
 	OPENEXR_ILMIMF_LIBRARY
 	OPENEXR_IMATH_LIBRARY
-	OPENEXR_IEX_LIBRARY
-	OPENEXR_HALF_LIBRARY)
+	OPENEXR_IEX_LIBRARY)
