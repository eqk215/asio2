#pragma once

#include <asio2/config.hpp>

#if defined(ASIO_STANDALONE) || defined(ASIO2_HEADER_ONLY)
#include <asio/experimental/channel_traits.hpp>
#else
#include <boost/asio/experimental/channel_traits.hpp>
#endif