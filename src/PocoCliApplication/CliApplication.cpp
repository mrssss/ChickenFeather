//
// Created by Qijun Niu on 2021/9/29.
//

#include "CliApplication.h"
#include <Poco/Util/HelpFormatter.h>
#include <Poco/Util/Option.h>

using Poco::Util::HelpFormatter;
using Poco::Util::Option;
using Poco::Util::OptionCallback;

int CliApplication::main(const std::vector<std::string> & args)
{
    //    logger().information("main");
}

void CliApplication::initialize(Application & app)
{
    //    loadConfiguration();
    //    initialize(app);
    //    logger().information("initialize");
}

void CliApplication::uninitialize()
{
    //    logger().information("uninitialize");
}
void CliApplication::reinitialize(Application & app)
{
    //    logger().information("reinitialize");
}

void CliApplication::defineOptions(OptionSet & options)
{
    //    Application::defineOptions(options);

    //    options.addOption(
    //        Option("help", "h", "display help information")
    //            .required(false)
    //            .repeatable(false)
    //            .callback(OptionCallback<CliApplication>(this, &CliApplication::handleHelp))
    //    );

    //    options.addOption(
    //        Option("config-file", "f", "load configuration data from a file")
    //            .required(false)
    //            .repeatable(true)
    //            .argument("file")
    //            .callback(Poco::Util::OptionCallback<CliApplication>(this, &CliApplication::handleConfig))
    //            );

    //    options.addOption(
    //        Option("bind", "b", "bind option value to test.proterty")
    //            .required(false)
    //            .argument("value")
    //            .validator(new IntValidator(0, 100))
    //            .binding("test.property"))
    //    logger().information("defineOptions");
}

void CliApplication::handleOption(const std::string & name, const std::string & value)
{
    //    logger().information("handleOption");
}

void CliApplication::handleHelp(const std::string & name, const std::string & value)
{
    //    _helpRequested = true;
    //    displayHelp();
    //    stopOptionsProcessing();
    //    logger().information("handleHelp");
}

void CliApplication::displayHelp()
{
    //    HelpFormatter helpFormatter(options());
    //    helpFormatter.setCommand(commandName());
    //    helpFormatter.setUsage("OPTIONS");
    //    helpFormatter.setHeader(
    //        "A sample application that demonstrates some of the features "
    //        "of the Poco::Util::Application class.");
    //    helpFormatter.format(std::cout);
}
