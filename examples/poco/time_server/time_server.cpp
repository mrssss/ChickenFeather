#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/ServerSocket.h>

#include <Poco/Timestamp.h>
#include <Poco/DateTimeFormatter.h>
#include <Poco/DateTimeFormat.h>
#include <Poco/Exception.h>
#include <Poco/ThreadPool.h>

#include <Poco/Util/ServerApplication.h>
#include <Poco/Util/Option.h>
#include <Poco/Util/OptionSet.h>
#include <Poco/Util/HelpFormatter.h>

#include <iostream>

class TimeRequestHandler : public Poco::Net::HTTPRequestHandler {

public:
    TimeRequestHandler(const std::string & format_) : format(format_) {}

    void handleRequest(Poco::Net::HTTPServerRequest & request, Poco::Net::HTTPServerResponse & response) {
        Poco::Util::Application & app = Poco::Util::Application::instance();
        app.logger().information("Request from %s", request.clientAddress().toString());

        Poco::Timestamp now;
        std::string dt(Poco::DateTimeFormatter::format(now, this->format));

        response.setChunkedTransferEncoding(true);
        response.setContentType("text/html");

        std::ostream & ostr = response.send();
        ostr << "<html><head><title>HTTPTimeServer powered by "
                "POCO C++ Library</title>";
        ostr << "<meta http-equiv=\"refresh\" content=\"1\"></head>";
        ostr << "<body><p style=\"text-align: center; font-size: 48px;\">";
        ostr << dt;
        ostr << "</p></body></html>";
    }

private:
    std::string format;
};

class TimeRequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory {

public:
    TimeRequestHandlerFactory(const std::string & format_) : format(format_) {}

    Poco::Net::HTTPRequestHandler * createRequestHandler(const Poco::Net::HTTPServerRequest & request) {
        if(request.getURI() == "/") {
            return new TimeRequestHandler(format);
        } else {
            return 0;
        }
    }

private:
    std::string format;
};

class TimeServer : public Poco::Util::ServerApplication {

protected:
    void initialize(Poco::Util::Application & self) {
        loadConfiguration();
        Poco::Util::ServerApplication::initialize(self);
    }

    void defineOptions(Poco::Util::OptionSet & options) {
        Poco::Util::ServerApplication::defineOptions(options);

        options.addOption(
            Poco::Util::Option("help", "h", "display argument help information")
                .required(false)
                .repeatable(false)
                .callback(Poco::Util::OptionCallback<TimeServer>(this, &TimeServer::handleHelp))
        );
    }

    void handleHelp([[maybe_unused]] const std::string & name, [[maybe_unused]] const std::string & value) {
        Poco::Util::HelpFormatter helpFormatter(options());
        helpFormatter.setCommand(commandName());
        helpFormatter.setUsage("OPTIONS");
        helpFormatter.setHeader("A web server that serves the current date and time");
        helpFormatter.format(std::cout);

        stopOptionsProcessing();

        _helpRequested = true;
    }

    int main([[maybe_unused]]const std::vector<std::string> & args) {
        if(!_helpRequested) {
            unsigned short port = static_cast<unsigned short> (config().getInt("HTTPTimeServer.port", 9980));
            std::string format(config().getString("HTTPTimeServer.format", Poco::DateTimeFormat::SORTABLE_FORMAT));

            Poco::Net::ServerSocket svs(port);
            Poco::Net::HTTPServer srv(
                new TimeRequestHandlerFactory(format),
                svs,
                new Poco::Net::HTTPServerParams
            );

            srv.start();
            waitForTerminationRequest();
            srv.stop();
        }
        return Poco::Util::Application::EXIT_OK;
    }

private:
    bool _helpRequested = false;
};

int main(int argc, char ** argv) {
    TimeServer app;
    return app.run(argc, argv);
}
