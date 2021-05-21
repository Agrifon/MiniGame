#ifndef MAIN_H
#define MAIN_H

//STD
#include <iostream>
#include <thread>

//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

//BOOST
#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif

#define ASIO_STANDALONE

#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

#include <boost/thread.hpp>
#include <boost/bind/placeholders.hpp>

//My
#include "globalVariable.h"

#endif