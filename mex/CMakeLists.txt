FIND_PACKAGE(Matlab)
SET( CMAKE_CXX_COMPILER /Applications/MATLAB_R2014a.app/bin/mex )
SET( CMAKE_C_COMPILER   /Applications/MATLAB_R2014a.app/bin/mex )
INCLUDE_DIRECTORIES(include)


#ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME}
#    POST_BUILD
#    COMMAND ./mex_link.sh ${PROJECT_NAME} ${MEX_SAVE_PATH}
#    )

   
#LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/lib)
#ADD_LIBRARY( xcorr_mex SHARED xcorr.cxx )
#TARGET_LINK_LIBRARIES( xcorr_mex LINK_PUBLIC ${CMAKE_BINARY_DIR}/librtls.a)



matlab_add_mex(
    NAME xcorr_mex
    xcorr.cxx
)


