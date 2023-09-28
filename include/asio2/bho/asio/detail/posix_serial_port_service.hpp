#pragma once

#include <asio2/config.hpp>

#if defined(ASIO_STANDALONE) || defined(ASIO2_HEADER_ONLY)
#include <asio/detail/posix_serial_port_service.hpp>
#else
#include <boost/asio/detail/posix_serial_port_service.hpp>
#endif