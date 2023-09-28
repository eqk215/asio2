#pragma once

#include <asio2/config.hpp>

#if defined(ASIO_STANDALONE) || defined(ASIO2_HEADER_ONLY)
#include <asio/detail/winrt_async_op.hpp>
#else
#include <boost/asio/detail/winrt_async_op.hpp>
#endif