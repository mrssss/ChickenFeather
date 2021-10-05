//
// Created by Qijun Niu on 2021/9/29.
//

#ifndef CHICKENFEATHER_CLIAPPLICATION_H
#define CHICKENFEATHER_CLIAPPLICATION_H

#include <Poco/Util/Application.h>

using Poco::Util::Application;
using Poco::Util::OptionSet;

class CliApplication : public Application {
public:
    CliApplication() {}

private:
    const char * name() const override { return "CliApplication"; }

    int main(const std::vector<std::string> & args) override;

    void initialize(Application & app) override;

    void uninitialize() override;
    void reinitialize(Application & app) override;

    void defineOptions(OptionSet & options) override;

    void handleOption(const std::string & name, const std::string & value) override;

    void handleHelp(const std::string & name, const std::string & value);
    void displayHelp();

    void handleConfig();

private:
    bool _helpRequested;
};


#endif //CHICKENFEATHER_CLIAPPLICATION_H
