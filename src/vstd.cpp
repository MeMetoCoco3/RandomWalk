#include "vstd.h"

u8 Logger::m_LogLevel = L_INFO;

f32 sign_f32(f32 val)
{
    if (val == 0)
    {
	return 0;
    }

    return val > 0 ? 1: -1;
}

vec2 vec2_times_scalar(vec2 v, f32 s)
{
    return {v.x * s, v.y * s};

}

vec2 add_vec2(vec2 v1, vec2 v2)
{
    return {v1.x+v2.x, v1.y+v2.y};
}

vec2 subtract_vec2(vec2 v1, vec2 v2)
{
    return {v1.x-v2.x, v1.y-v2.y};
}


