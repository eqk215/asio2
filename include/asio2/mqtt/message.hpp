/*
 * COPYRIGHT (C) 2017-2021, zhllxt
 *
 * author   : zhllxt
 * email    : 37792738@qq.com
 *
 * chinese : http://mqtt.p2hp.com/mqtt-5-0
 * english : https://docs.oasis-open.org/mqtt/mqtt/v5.0/os/mqtt-v5.0-os.html
 * 
 * Distributed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * (See accompanying file LICENSE or see <http://www.gnu.org/licenses/>)
 */

#ifndef __ASIO2_MQTT_MESSAGE_HPP__
#define __ASIO2_MQTT_MESSAGE_HPP__

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <asio2/mqtt/protocol_v3.hpp>
#include <asio2/mqtt/protocol_v4.hpp>
#include <asio2/mqtt/protocol_v5.hpp>

namespace asio2::mqtt
{
	template<typename M>
	inline constexpr bool is_control_message()
	{
		return (is_v3_message<M>() || is_v4_message<M>() || is_v5_message<M>());
	}

	template<typename M>
	inline constexpr bool is_nullmsg()
	{
		return (std::is_same_v<asio2::detail::remove_cvref_t<M>, mqtt::nullmsg>);
	}

	template<typename M>
	inline constexpr bool is_message()
	{
		return (is_control_message<M>() || is_nullmsg<M>());
	}

	template<typename M> inline constexpr bool is_connect_message    () { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v3::connect    > || std::is_same_v<T, mqtt::v4::connect    > || std::is_same_v<T, mqtt::v5::connect    >); }
	template<typename M> inline constexpr bool is_connack_message    () { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v3::connack    > || std::is_same_v<T, mqtt::v4::connack    > || std::is_same_v<T, mqtt::v5::connack    >); }
	template<typename M> inline constexpr bool is_publish_message    () { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v3::publish    > || std::is_same_v<T, mqtt::v4::publish    > || std::is_same_v<T, mqtt::v5::publish    >); }
	template<typename M> inline constexpr bool is_puback_message     () { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v3::puback     > || std::is_same_v<T, mqtt::v4::puback     > || std::is_same_v<T, mqtt::v5::puback     >); }
	template<typename M> inline constexpr bool is_pubrec_message     () { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v3::pubrec     > || std::is_same_v<T, mqtt::v4::pubrec     > || std::is_same_v<T, mqtt::v5::pubrec     >); }
	template<typename M> inline constexpr bool is_pubrel_message     () { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v3::pubrel     > || std::is_same_v<T, mqtt::v4::pubrel     > || std::is_same_v<T, mqtt::v5::pubrel     >); }
	template<typename M> inline constexpr bool is_pubcomp_message    () { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v3::pubcomp    > || std::is_same_v<T, mqtt::v4::pubcomp    > || std::is_same_v<T, mqtt::v5::pubcomp    >); }
	template<typename M> inline constexpr bool is_subscribe_message  () { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v3::subscribe  > || std::is_same_v<T, mqtt::v4::subscribe  > || std::is_same_v<T, mqtt::v5::subscribe  >); }
	template<typename M> inline constexpr bool is_suback_message     () { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v3::suback     > || std::is_same_v<T, mqtt::v4::suback     > || std::is_same_v<T, mqtt::v5::suback     >); }
	template<typename M> inline constexpr bool is_unsubscribe_message() { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v3::unsubscribe> || std::is_same_v<T, mqtt::v4::unsubscribe> || std::is_same_v<T, mqtt::v5::unsubscribe>); }
	template<typename M> inline constexpr bool is_unsuback_message   () { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v3::unsuback   > || std::is_same_v<T, mqtt::v4::unsuback   > || std::is_same_v<T, mqtt::v5::unsuback   >); }
	template<typename M> inline constexpr bool is_pingreq_message    () { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v3::pingreq    > || std::is_same_v<T, mqtt::v4::pingreq    > || std::is_same_v<T, mqtt::v5::pingreq    >); }
	template<typename M> inline constexpr bool is_pingresp_message   () { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v3::pingresp   > || std::is_same_v<T, mqtt::v4::pingresp   > || std::is_same_v<T, mqtt::v5::pingresp   >); }
	template<typename M> inline constexpr bool is_disconnect_message () { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v3::disconnect > || std::is_same_v<T, mqtt::v4::disconnect > || std::is_same_v<T, mqtt::v5::disconnect >); }
	template<typename M> inline constexpr bool is_auth_message       () { using T = asio2::detail::remove_cvref_t<M>; return (std::is_same_v<T, mqtt::v5::auth       > || std::is_same_v<T, mqtt::v5::auth       > || std::is_same_v<T, mqtt::v5::auth       >); }

	using message_variant = std::variant<
		mqtt::nullmsg   , // 0

		v3::connect     , // 1
		v3::connack     , // 2
		v3::publish     , // 3
		v3::puback      , // 4
		v3::pubrec      , // 5
		v3::pubrel      , // 6
		v3::pubcomp     , // 7
		v3::subscribe   , // 8
		v3::suback      , // 9
		v3::unsubscribe , // 10
		v3::unsuback    , // 11
		v3::pingreq     , // 12
		v3::pingresp    , // 13
		v3::disconnect  , // 14

		v4::connect     , // 15
		v4::connack     , // 16
		v4::publish     , // 17
		v4::puback      , // 18
		v4::pubrec      , // 19
		v4::pubrel      , // 20
		v4::pubcomp     , // 21
		v4::subscribe   , // 22
		v4::suback      , // 23
		v4::unsubscribe , // 24
		v4::unsuback    , // 25
		v4::pingreq     , // 26
		v4::pingresp    , // 27
		v4::disconnect  , // 28

		v5::connect     , // 29
		v5::connack     , // 30
		v5::publish     , // 31
		v5::puback      , // 32
		v5::pubrec      , // 33
		v5::pubrel      , // 34
		v5::pubcomp     , // 35
		v5::subscribe   , // 36
		v5::suback      , // 37
		v5::unsubscribe , // 38
		v5::unsuback    , // 39
		v5::pingreq     , // 40
		v5::pingresp    , // 41
		v5::disconnect  , // 42
		v5::auth          // 43
	>;

	//using message_index_type = std::conditional_t<
	//	std::variant_size_v<message_variant> <= (std::numeric_limits<std::uint8_t>::max)(),
	//	std::uint8_t, std::uint16_t
	//>;

	class message : public message_variant
	{
	public:
		using super = message_variant;

		// a default-constructed variant holds a value of its first alternative
		message() noexcept : message_variant()
		{
		}

		template<class T, std::enable_if_t<is_message<T>(), int> = 0>
		message(T&& v) : message_variant(std::forward<T>(v))
		{
		}

		template<class T, std::enable_if_t<is_message<T>(), int> = 0>
		message& operator=(T&& v)
		{
			this->base() = std::forward<T>(v);
			return (*this);
		}

		message(message&&) noexcept = default;
		message(message const&) = default;
		message& operator=(message&&) noexcept = default;
		message& operator=(message const&) = default;

		template<class T, std::enable_if_t<is_message<T>(), int> = 0>
		operator T&()
		{
			return std::get<T>(this->base());
		}

		template<class T, std::enable_if_t<is_message<T>(), int> = 0>
		operator const T&()
		{
			return std::get<T>(this->base());
		}

		template<class T, std::enable_if_t<is_message<T>(), int> = 0>
		operator T*() noexcept
		{
			return std::get_if<T>(std::addressof(this->base()));
		}

		template<class T, std::enable_if_t<is_message<T>(), int> = 0>
		operator const T*() noexcept
		{
			return std::get_if<T>(std::addressof(this->base()));
		}

		/**
		 * this overload will cause compile error on gcc, i don't know why:
		 * mqtt::message msg(mqtt::v3::subscribe{});
		 * mqtt::v3::subscribe sub = static_cast<mqtt::v3::subscribe>(msg);
		 * compile error : call of overloaded subscribe(asio2::mqtt::message&) is ambiguous
		 */
		//template<class T, std::enable_if_t<is_message<T>(), int> = 0>
		//operator T()
		//{
		//	return std::get<T>(this->base());
		//}

		/// Returns the base variant of the message
		inline super const& base()    const noexcept { return *this; }

		/// Returns the base variant of the message
		inline super&       base()          noexcept { return *this; }

		/// Returns the base variant of the message
		inline super const& variant() const noexcept { return *this; }

		/// Returns the base variant of the message
		inline super&       variant()       noexcept { return *this; }

		/**
		 * @function Checks if the variant holds anyone of the alternative Types...
		 */
		template<class... Types>
		inline bool has() noexcept
		{
			return (std::holds_alternative<Types>(this->base()) || ...);
		}

		/**
		 * @function Checks if the variant holds anyone of the alternative Types...
		 */
		template<class... Types>
		inline bool holds() noexcept
		{
			return (std::holds_alternative<Types>(this->base()) || ...);
		}

		/**
		 * @function Checks if the variant holds any v3 message
		 */
		inline bool holds_v3_message() const noexcept
		{
			int i = static_cast<int>(this->base().index());

			return (i >= 1 && i <= 14);
		}

		/**
		 * @function Checks if the variant holds any v4 message
		 */
		inline bool holds_v4_message() const noexcept
		{
			int i = static_cast<int>(this->base().index());

			return (i >= 15 && i <= 28);
		}

		/**
		 * @function Checks if the variant holds any v5 message
		 */
		inline bool holds_v5_message() const noexcept
		{
			int i = static_cast<int>(this->base().index());

			return (i >= 29 && i <= 43);
		}

		/**
		 * @function If this holds the alternative T, returns a pointer to the value stored in the variant.
		 * Otherwise, returns a null pointer value.
		 */
		template<class T>
		inline std::add_pointer_t<T> get_if() noexcept
		{
			return std::get_if<T>(std::addressof(this->base()));
		}

		/**
		 * @function If this holds the alternative T, returns a reference to the value stored in the variant.
		 * Otherwise, throws std::bad_variant_access.
		 */
		template<class T>
		inline T& get()
		{
			return std::get<T>(this->base());
		}

		/**
		 * @function If this holds a valid value.
		 */
		inline bool empty() noexcept
		{
			return (this->index() == std::variant_npos || std::holds_alternative<mqtt::nullmsg>(this->base()));
		}

		/**
		 * @function Invoke the callback if the variant holds the alternative Types...
		 */
		template<class... Types, class FunctionT>
		inline bool invoke_if(FunctionT&& callback) noexcept
		{
			return ((this->template _invoke_for_each_type<Types>(callback)) || ...);
		}

	protected:
		template<class T, class FunctionT>
		inline bool _invoke_for_each_type(FunctionT&& callback) noexcept
		{
			if (std::holds_alternative<T>(this->base()))
			{
				callback(std::get<T>(this->base()));
				return true;
			}
			return false;
		}
	};


	template<class, class = void>
	struct has_packet_id : std::false_type { };

	template<class T>
	struct has_packet_id<T, std::void_t<decltype(std::declval<T&>().packet_id())>> : std::true_type { };


	template<class Byte>
	inline mqtt::control_packet_type message_type_from_byte(Byte byte)
	{
		mqtt::fixed_header<0>::type_and_flags tf{};
		tf.byte = static_cast<std::uint8_t>(byte);
		return static_cast<mqtt::control_packet_type>(tf.bits.type);
	}

	template<typename = void>
	inline mqtt::control_packet_type message_type_from_data(std::string_view data)
	{
		return message_type_from_byte(data.front());
	}

	template<class Fun>
	inline void data_to_message(mqtt::version ver, std::string_view& data, Fun&& f)
	{
		mqtt::control_packet_type type = mqtt::message_type_from_data(data);

		if /**/ (ver == mqtt::version::v3)
		{
			switch (type)
			{
			case mqtt::control_packet_type::connect     : { mqtt::message m{ mqtt::v3::connect     {} }; std::get<mqtt::v3::connect     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::connack     : { mqtt::message m{ mqtt::v3::connack     {} }; std::get<mqtt::v3::connack     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::publish     : { mqtt::message m{ mqtt::v3::publish     {} }; std::get<mqtt::v3::publish     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::puback      : { mqtt::message m{ mqtt::v3::puback      {} }; std::get<mqtt::v3::puback      >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pubrec      : { mqtt::message m{ mqtt::v3::pubrec      {} }; std::get<mqtt::v3::pubrec      >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pubrel      : { mqtt::message m{ mqtt::v3::pubrel      {} }; std::get<mqtt::v3::pubrel      >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pubcomp     : { mqtt::message m{ mqtt::v3::pubcomp     {} }; std::get<mqtt::v3::pubcomp     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::subscribe   : { mqtt::message m{ mqtt::v3::subscribe   {} }; std::get<mqtt::v3::subscribe   >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::suback      : { mqtt::message m{ mqtt::v3::suback      {} }; std::get<mqtt::v3::suback      >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::unsubscribe : { mqtt::message m{ mqtt::v3::unsubscribe {} }; std::get<mqtt::v3::unsubscribe >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::unsuback    : { mqtt::message m{ mqtt::v3::unsuback    {} }; std::get<mqtt::v3::unsuback    >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pingreq     : { mqtt::message m{ mqtt::v3::pingreq     {} }; std::get<mqtt::v3::pingreq     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pingresp    : { mqtt::message m{ mqtt::v3::pingresp    {} }; std::get<mqtt::v3::pingresp    >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::disconnect  : { mqtt::message m{ mqtt::v3::disconnect  {} }; std::get<mqtt::v3::disconnect  >(m).deserialize(data); f(std::move(m)); } break;
			default:
				ASIO2_ASSERT(false);
				asio::detail::throw_error(mqtt::make_error_code(mqtt::error::malformed_packet));
				break;
			}
		}
		else if (ver == mqtt::version::v4)
		{
			switch (type)
			{
			case mqtt::control_packet_type::connect     : { mqtt::message m{ mqtt::v4::connect     {} }; std::get<mqtt::v4::connect     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::connack     : { mqtt::message m{ mqtt::v4::connack     {} }; std::get<mqtt::v4::connack     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::publish     : { mqtt::message m{ mqtt::v4::publish     {} }; std::get<mqtt::v4::publish     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::puback      : { mqtt::message m{ mqtt::v4::puback      {} }; std::get<mqtt::v4::puback      >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pubrec      : { mqtt::message m{ mqtt::v4::pubrec      {} }; std::get<mqtt::v4::pubrec      >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pubrel      : { mqtt::message m{ mqtt::v4::pubrel      {} }; std::get<mqtt::v4::pubrel      >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pubcomp     : { mqtt::message m{ mqtt::v4::pubcomp     {} }; std::get<mqtt::v4::pubcomp     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::subscribe   : { mqtt::message m{ mqtt::v4::subscribe   {} }; std::get<mqtt::v4::subscribe   >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::suback      : { mqtt::message m{ mqtt::v4::suback      {} }; std::get<mqtt::v4::suback      >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::unsubscribe : { mqtt::message m{ mqtt::v4::unsubscribe {} }; std::get<mqtt::v4::unsubscribe >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::unsuback    : { mqtt::message m{ mqtt::v4::unsuback    {} }; std::get<mqtt::v4::unsuback    >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pingreq     : { mqtt::message m{ mqtt::v4::pingreq     {} }; std::get<mqtt::v4::pingreq     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pingresp    : { mqtt::message m{ mqtt::v4::pingresp    {} }; std::get<mqtt::v4::pingresp    >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::disconnect  : { mqtt::message m{ mqtt::v4::disconnect  {} }; std::get<mqtt::v4::disconnect  >(m).deserialize(data); f(std::move(m)); } break;
			default:
				ASIO2_ASSERT(false);
				asio::detail::throw_error(mqtt::make_error_code(mqtt::error::malformed_packet));
				break;
			}
		}
		else if (ver == mqtt::version::v5)
		{
			switch (type)
			{
			case mqtt::control_packet_type::connect     : { mqtt::message m{ mqtt::v5::connect     {} }; std::get<mqtt::v5::connect     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::connack     : { mqtt::message m{ mqtt::v5::connack     {} }; std::get<mqtt::v5::connack     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::publish     : { mqtt::message m{ mqtt::v5::publish     {} }; std::get<mqtt::v5::publish     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::puback      : { mqtt::message m{ mqtt::v5::puback      {} }; std::get<mqtt::v5::puback      >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pubrec      : { mqtt::message m{ mqtt::v5::pubrec      {} }; std::get<mqtt::v5::pubrec      >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pubrel      : { mqtt::message m{ mqtt::v5::pubrel      {} }; std::get<mqtt::v5::pubrel      >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pubcomp     : { mqtt::message m{ mqtt::v5::pubcomp     {} }; std::get<mqtt::v5::pubcomp     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::subscribe   : { mqtt::message m{ mqtt::v5::subscribe   {} }; std::get<mqtt::v5::subscribe   >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::suback      : { mqtt::message m{ mqtt::v5::suback      {} }; std::get<mqtt::v5::suback      >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::unsubscribe : { mqtt::message m{ mqtt::v5::unsubscribe {} }; std::get<mqtt::v5::unsubscribe >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::unsuback    : { mqtt::message m{ mqtt::v5::unsuback    {} }; std::get<mqtt::v5::unsuback    >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pingreq     : { mqtt::message m{ mqtt::v5::pingreq     {} }; std::get<mqtt::v5::pingreq     >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::pingresp    : { mqtt::message m{ mqtt::v5::pingresp    {} }; std::get<mqtt::v5::pingresp    >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::disconnect  : { mqtt::message m{ mqtt::v5::disconnect  {} }; std::get<mqtt::v5::disconnect  >(m).deserialize(data); f(std::move(m)); } break;
			case mqtt::control_packet_type::auth        : { mqtt::message m{ mqtt::v5::auth        {} }; std::get<mqtt::v5::auth        >(m).deserialize(data); f(std::move(m)); } break;
			default:
				ASIO2_ASSERT(false);
				asio::detail::throw_error(mqtt::make_error_code(mqtt::error::malformed_packet));
				break;
			}
		}
		else
		{
			ASIO2_ASSERT(false);
			asio::detail::throw_error(mqtt::make_error_code(mqtt::error::malformed_packet));
		}

		ASIO2_ASSERT(data.empty());
	}

	template<typename = void>
	inline mqtt::version version_from_connect_data(std::string_view data)
	{
		try
		{
			mqtt::fixed_header<0> header{};
			header.deserialize(data);

			// The Protocol Name is a UTF-8 Encoded String that represents the protocol name MQTT. 
			// The string, its offset and length will not be changed by future versions of the MQTT specification.
			mqtt::utf8_string protocol_name{};
			protocol_name.deserialize(data);

			// The 8 bit unsigned value that represents the revision level of the protocol used by the Client. 
			// The value of the Protocol Level field for the version 3.1.1 of the protocol is 4 (0x04).
			mqtt::one_byte_integer protocol_version{};
			protocol_version.deserialize(data);

			return static_cast<mqtt::version>(protocol_version.value());
		}
		catch (system_error const&) {}

		return static_cast<mqtt::version>(0);
	}
}

#endif // !__ASIO2_MQTT_MESSAGE_HPP__
