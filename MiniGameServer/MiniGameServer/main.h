#ifndef MAIN_H
#define MAIN_H

#include <iostream>

#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif

#define ASIO_STANDALONE

#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

#include <boost/thread.hpp>
#include <boost/bind/placeholders.hpp>

#endif