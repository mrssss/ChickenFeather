//
// Created by Qijun Niu on 2021/9/29.
//

//! application框架包含了所有应用程序都需要的部分特性
//! 处理:
//! * 命令行参数
//! * 配置文件
//! * 初始化和shutdown
//! * 日志系统
//!
//! POCO支持两种应用程序：
//! 1. 命令行应用(前台应用)
//! 2. 服务器应用(run as daemon or windows services)
//!
//! 应用子系统(Application Subsystems)
//! * 一个应用可以包含多个不同的子系统
//! * 子系统可以模块化的扩展应用
//! * 子系统会帮助应用做初始化
//! * 当应用初始化完成，它的所有的注册过的子系统也就初始化完成了
//! * 当应用关闭，其子系统也关闭
#include <iostream>

#include "CliApplication.h"

int main(int argc, char ** argv)
{
    std::cout << "Hello World" << std::endl;
    auto app = std::make_shared<CliApplication>();
    app->run();
    return 0;
}