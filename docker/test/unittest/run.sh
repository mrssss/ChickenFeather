#!/bin/bash

function run_cmake 
{
    mkdir /build && cd /build && cmake $SRC
}

function run_build
{
    cd /build && cmake --build . --target unit_tests
}

function run_unit_test
{
    cd /build && ./unit_tests --gtest_output=xml:result.xml
}

function generate_report
{
    mkdir -p /test_output
    xsltproc $SRC/utils/gtest2html/gtest2html.xslt result.xml > /test_output/result.html
}

run_cmake
run_build
run_unit_test
generate_report
