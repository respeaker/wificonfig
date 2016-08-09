/*
  2016 Copyright (c) Seeed Technology Inc.  All right reserved.
  Author:Baozhu Zuo
  suli is designed for the purpose of reusing the high level implementation
  of each libraries for different platforms out of the hardware layer.
  suli2 is the new reversion of original suli. There're lot of improvements upon
  the previous version. Currently, it can be treated as the internal strategy for
  quick library development of seeed. But always welcome the community to
  follow the basis of suli to contribute grove libraries.
  The MIT License (MIT)
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/


#include <iostream>
#include <stdlib.h> //atoi

#include "application.h"
#include "logger.h"
#include "exception.h"

using namespace dns;
using namespace std;

void Application::parse_arguments(int argc, char** argv) throw (Exception) {

    if (argc != 3) {

        string text("Usage: dnsServer <port> <hostsFile>\n");
        text += "Example: dnsServer 9000 hosts\n";
        Exception e(text);
        throw (e);
    }

    m_port = atoi(argv[1]);
    if (m_port < 1 || m_port > 65535) {
        
        string text("Error: Invalid port number.\n");
        Exception e(text);
        throw (e);
    }

    m_filename.assign(argv[2]);
}

void Application::run() throw (Exception) {

    Logger& logger = Logger::instance();
    logger.trace("Application::run()");

    m_resolver.init(m_filename);
    m_server.init(m_port);
    m_server.run();
}
