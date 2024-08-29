#pragma once

#include <memory>

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Sunflower {

	/// <summary>
	/// Class Log, Init two loggers that will print important messages to the user (core and client side)
	/// </summary>
	/// <version author="Francisco Sousa" date="8/16/2024" version="2.0"/>
	class SUNFLOWER_API Log
	{
	public:
		/// <summary>
		/// Initializes this instance.
		/// </summary>
		/// <version author="Francisco Sousa" date="8/16/2024" version="0.1"/>
		static void Init();

		/// <summary>
		/// Gets the core logger.
		/// </summary>
		/// <returns></returns>
		/// <version author="Francisco Sousa" date="8/16/2024" version="0.1"/>
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

		/// <summary>
		/// Gets the client logger.
		/// </summary>
		/// <returns></returns>
		/// <version author="Francisco Sousa" date="8/16/2024" version="0.1"/>
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return  s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core Logger Macros
#define SF_CORE_TRACE(...)		::Sunflower::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SF_CORE_WARN(...)		::Sunflower::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SF_CORE_INFO(...)		::Sunflower::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SF_CORE_ERROR(...)		::Sunflower::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SF_CORE_FATAL(...)		::Sunflower::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Logger Macros
#define SF_TRACE(...)	::Sunflower::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SF_WARN(...)	::Sunflower::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SF_INFO(...)	::Sunflower::Log::GetClientLogger()->info(__VA_ARGS__)
#define SF_ERROR(...)	::Sunflower::Log::GetClientLogger()->error(__VA_ARGS__)
#define SF_FATAL(...)	::Sunflower::Log::GetClientLogger()->fatal(__VA_ARGS__)

