
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


#include "logger.h"

using namespace dns;
using namespace std;

// static
Logger* Logger::_instance = 0;
ofstream Logger::_file("/tmp/fasterconfig.log", ios::out|ios::trunc);

Logger& Logger::instance() throw () {

    if (_instance == 0) {
        _instance == new Logger();
    }

    return *_instance;
}

void Logger::trace(const char* text) throw() {

    _file << " ## " << text << endl;
}

void Logger::trace(std::string& text) throw() {

    trace(text.data());
}

void Logger::trace(std::ostringstream& stream) throw() {

    string text = stream.str();
    trace(text.data());
}

void Logger::error(const char* text) throw() {

    _file << " !! " << text << endl;
}

void Logger::error(std::string& text) throw() {

    trace(text.data());
}
