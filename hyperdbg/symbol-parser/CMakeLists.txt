# Code generated by Visual Studio kit, DO NOT EDIT.
set(SourceFiles
    "code/casting.cpp"
    "code/common-utils.cpp"
    "code/symbol-parser.cpp"
    "pch.cpp"
    "../include/platform/user/header/Environment.h"
    "header/common-utils.h"
    "header/symbol-parser.h"
    "pch.h"
)
include_directories(
    "../include"
    "../dependencies"
    "."
)
add_library(symbol-parser SHARED ${SourceFiles})
