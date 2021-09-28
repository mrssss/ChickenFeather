//
// Created by Qijun Niu on 2021/9/29.
//

#include "CliApplication.h"

int CliApplication::main(const std::vector<std::string> & args) {
    logger().information("main");
}

void CliApplication::initialize(Application & app) {
    logger().information("initialize");
}

void CliApplication::uninitialize() {
    logger().information("uninitialize");
}
void CliApplication::reinitialize(Application & app) {
    logger().information("reinitialize");
}

void CliApplication::defineOptions(OptionSet & options) {
    logger().information("defineOptions");
}
void CliApplication::handleOption(const std::string & name, const std::string & value) {
    logger().information("handleOption");
}