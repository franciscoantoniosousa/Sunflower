#pragma once

#include <memory>

#include "core.h"
#include "spdlog/spdlog.h"


namespace Sunflower {

	class SUNFLOWER_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
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
#define SF_CLIENT_TRACE(...)	::Sunflower::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SF_CLIENT_WARN(...)		::Sunflower::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SF_CLIENT_INFO(...)		::Sunflower::Log::GetClientLogger()->info(__VA_ARGS__)
#define SF_CLIENT_ERROR(...)	::Sunflower::Log::GetClientLogger()->error(__VA_ARGS__)
#define SF_CLIENT_FATAL(...)	::Sunflower::Log::GetClientLogger()->fatal(__VA_ARGS__)

