SEt(LIBDEBUG_SRC grams.cpp util.cpp)
ADD_LIBRARY(mdebug SHARED ${LIBDEBUG_SRC})
SET_TARGET_PROPERTIES(debug_static PROPERTIES OUTPUT_NAME "debug")