cmake_minimum_required(VERSION 3.23)

project(matrix)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-fsanitize=address")

add_subdirectory(google-test)

add_executable(play
        play/play.cpp

        api/Matrix.hpp
        api/Vector.hpp
        api/String.hpp

        src/Matrix.cpp
        src/Vector.cpp
        src/String.cpp
        src/Broadcasting.cpp
        src/MatrixСalculations.cpp
        src/ScalarСalculations.cpp
        src/GetData.cpp)

add_executable(MatrixTest
        tests/MatrixTest.cpp

        api/Matrix.hpp
        api/Vector.hpp
        api/String.hpp

        src/Matrix.cpp
        src/Vector.cpp
        src/String.cpp
        src/Broadcasting.cpp
        src/MatrixСalculations.cpp
        src/ScalarСalculations.cpp
        src/GetData.cpp)
target_link_libraries(MatrixTest gtest gtest_main)

add_executable(StringTest
        tests/StringTest.cpp

        api/Matrix.hpp
        api/Vector.hpp
        api/String.hpp

        src/Matrix.cpp
        src/Vector.cpp
        src/String.cpp
        src/Broadcasting.cpp
        src/MatrixСalculations.cpp
        src/ScalarСalculations.cpp
        src/GetData.cpp)
target_link_libraries(StringTest gtest gtest_main)

add_executable(VectorTest
        tests/VectorTest.cpp

        api/Matrix.hpp
        api/Vector.hpp
        api/String.hpp

        src/Matrix.cpp
        src/Vector.cpp
        src/String.cpp
        src/Broadcasting.cpp
        src/MatrixСalculations.cpp
        src/ScalarСalculations.cpp
        src/GetData.cpp)
target_link_libraries(VectorTest gtest gtest_main)

add_executable(GetDataTests
        tests/GetDataTests.cpp

        api/Matrix.hpp
        api/Vector.hpp
        api/String.hpp

        src/Matrix.cpp
        src/Vector.cpp
        src/String.cpp
        src/Broadcasting.cpp
        src/MatrixСalculations.cpp
        src/ScalarСalculations.cpp
        src/GetData.cpp)
target_link_libraries(GetDataTests gtest gtest_main)

add_executable(ScalarCalculationsTests
        tests/ScalarCalculationsTests.cpp

        api/Matrix.hpp
        api/Vector.hpp
        api/String.hpp

        src/Matrix.cpp
        src/Vector.cpp
        src/String.cpp
        src/Broadcasting.cpp
        src/MatrixСalculations.cpp
        src/ScalarСalculations.cpp
        src/GetData.cpp)
target_link_libraries(ScalarCalculationsTests gtest gtest_main)

add_executable(MatrixCalculationsTests
        tests/MatrixCalculationsTests.cpp

        api/Matrix.hpp
        api/Vector.hpp
        api/String.hpp

        src/Matrix.cpp
        src/Vector.cpp
        src/String.cpp
        src/Broadcasting.cpp
        src/MatrixСalculations.cpp
        src/ScalarСalculations.cpp
        src/GetData.cpp)
target_link_libraries(MatrixCalculationsTests gtest gtest_main)

add_executable(BroadcastingTests
        tests/BroadcastingTests.cpp

        api/Matrix.hpp
        api/Vector.hpp
        api/String.hpp

        src/Matrix.cpp
        src/Vector.cpp
        src/String.cpp
        src/Broadcasting.cpp
        src/MatrixСalculations.cpp
        src/ScalarСalculations.cpp
        src/GetData.cpp)
target_link_libraries(BroadcastingTests gtest gtest_main)
