#pragma once

#include <asio2/config.hpp>

#if defined(ASIO_STANDALONE) || defined(ASIO2_HEADER_ONLY)
#include <asio/generic/raw_protocol.hpp>
#else
#include <boost/asio/generic/raw_protocol.hpp>
#endif