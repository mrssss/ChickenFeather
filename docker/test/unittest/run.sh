#!/bin/bash

function run_cmake 
{
    mkdir /build && cd /build && cmake /source
}

function run_build
{
    cd /build && cmake --build .
}

function run_unit_test
{
    cd /build && ./unit_tests --gtest_output=xml:result.xml
}

function generate_report
{
    xsltproc /source/utils/gtest2html/gtest2html.xslt result.xml > /test_output/result.html
}

run_cmake
run_build
run_unit_test
generate_report
