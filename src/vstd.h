
#ifndef VSTD
#define VSTD
#include <cstdio>
#include <string>
#include <stdint.h>

typedef uint32_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t   u8;

typedef int32_t b32;
typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef int8_t   i8;

typedef float f32;
typedef double f64;

typedef struct vec2
{
    f32 x;
    f32 y;
	
	std::string to_string(void) const
	{
		char buffer[64];
		std::snprintf(buffer, sizeof(buffer), "%.2f, %.2f\n", x, y);
		return std::string(buffer);
	}
} vec2;

typedef struct vec3
{
    f32 x;
    f32 y;
    f32 z;

	std::string to_string(void) const
	{
		char buffer[64];
		std::snprintf(buffer, sizeof(buffer), "%.2f, %.2f, %.2f\n", x, y, z);
		return std::string(buffer);
	}

} vec3;

constexpr auto Pi32 = 3.14159265359f;
//#define local_persist static
//#define global_variable static
//#define internal static


extern vec2 add_vec2(vec2 v1, vec2 v2);
extern vec2 subtract_vec2(vec2 v1, vec2 v2);
extern vec2 vec2_times_scalar(vec2 v, f32 s);
extern f32 sign_f32(f32 val);



#define INFO(msg) Logger::Info(msg, call_location{__FILE__, __func__, __LINE__})  
#define WARN(msg) Logger::Warn(msg, call_location{__FILE__, __func__, __LINE__})  
#define ERROR(msg) Logger::Error(msg, call_location{__FILE__, __func__, __LINE__})  

typedef struct call_location{
    const char * file;
    const char * func;
    int loc;
} call_location;


class Logger 
{
    public: 
	enum Level: u8{
	    L_INFO = 1<<0, 
	    L_WARN = 1<<1, 
	    L_ERROR = 1<<2 
	};

    private:
    public:
	static u8 m_LogLevel;
	static void SetLevel(u8 level)
	{
	    m_LogLevel = level;
	}
	
	static void Warn(const char *msg, call_location c_loc)
	{
	    if ((m_LogLevel & L_WARN) == L_WARN)
	    {
		printf("[WARNING]: %s|| %s %s Line:%i\n", msg, c_loc.file, c_loc.func, c_loc.loc);
	    }
	}

	static void Error(const char *msg, call_location c_loc)
	{
	    if ((m_LogLevel & L_ERROR) == L_ERROR)
	    {
		printf("[ERROR]  : %s|| %s %s Line:%i\n", msg, c_loc.file, c_loc.func, c_loc.loc);
	    }
	}

	static void Info(const char *msg, call_location c_loc)
	{
	    if ((m_LogLevel & L_INFO) == L_INFO)
	    {
		printf("[INFO]   : %s|| %s %s Line:%i\n", msg, c_loc.file, c_loc.func, c_loc.loc);
	    }
	}


};



#endif
