#include <stdio.h>
#include <raylib.h>
#include "vstd.h"
#include <random>
#include <vector>
#include <stdlib.h>
#include "vmath.h"
#include <array>
constexpr auto WIDTH = 400;
constexpr auto HEIGHT = 400;

constexpr auto RECT_SIZE = 6;
constexpr auto SPEED = 0.4;
constexpr auto MAX_DISTANCE_BEFORE_TURNING = 20;
typedef struct Agent {
	Rectangle Rect;
	vec2 Direction;
	f32 Speed;
	Color Color;
	f32 DistanceSinceTurn;
}agent_t;


std::array<vec2, 4> DiagonalDir{{
	{1, -1}, {1, 1}, {-1, 1}, {-1, -1}
}};

std::array<vec2, 4> NormalDir{ {
	{1, 0}, {0, 1}, {-1, 0}, {0, -1}
}};

std::array<Color, 10> Colors {{
		RED, GREEN, BLUE, DARKBLUE, BROWN, YELLOW, PURPLE, DARKBLUE, PINK, DARKGREEN
}};


enum e_DIRECTION_MODE {
	NORMAL_DIR = 0,
	DIAGONAL_DIR,
	BOTH,
	ERR
};

e_DIRECTION_MODE resolve_argument(std::string arg);
int main(int argc, const char** argv)
{
	// DEFAULTS
	int NUM_AGENTS = 50;
	e_DIRECTION_MODE DMODE = NORMAL_DIR;

	std::array<vec2, 8> Directions{ {} };
	int Size = 4;

	if (argc == 2)
	{
		printf("Not enough arguments. \n");
		printf(
			"Usage:\n"
			"random_walk [flags]\n"

			"Flags :\n"
			"-n, --numAgents	Define number of agents to draw.\n"
			"-m, --mode         Define mode of agent directions. Accepted NORMAL, DIAGONAL, BOTH.\n"
		);
		return -1;

	}
	else if (argc > 2)
	{
		for (int i = 1; i < argc; i++)
		{
			std::string flag = argv[i];
			if (i + 1 > argc)
			{
				printf(
					"Usage:\n"
					"random_walk [flags]\n"

					"Flags :\n"
					"-n, --numAgents	Define number of agents to draw.\n"
					"-m, --mode         Define mode of agent directions. Accepted NORMAL, DIAGONAL, BOTH.\n"
				);
				return -1;
			}
			if (flag == "-n" || flag == "--numAgents") 
			{
				NUM_AGENTS = atoi(argv[i + 1]);
			}
			if (flag == "-m" || flag == "--mode") 
			{
				std::string arg = argv[i + 1];
				DMODE = resolve_argument(arg);
				if (DMODE == ERR) 
				{
					printf("Argument %s is not allowed.\n", argv[i + 1]);
					return -1;
				}
			}	
		}
	}

	switch (DMODE) 
	{
		case NORMAL_DIR:
		{
			for (int i = 0; i < 4; i++) Directions[i] = NormalDir[i];
		}break;

		case DIAGONAL_DIR:
		{
			for (int i = 0; i < 4; i++) Directions[i] = DiagonalDir[i];
		}break;

		case BOTH:
		{
			Size = 8;
			for (int i = 0; i < 4; i++)
			{
				Directions[i] = NormalDir[i];
				Directions[i+4] = DiagonalDir[i];
			}
		}break;
	}


	
	
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int>distrib(0, 20);

	SetTraceLogLevel(LOG_NONE);
	InitWindow(WIDTH, HEIGHT, "random_walk");
	SetTargetFPS(200);

	std::vector<Agent> Agents;
	Agents.reserve(NUM_AGENTS);
	
	for (int i = 0; i < NUM_AGENTS; i++)
	{
		Agents.push_back({ 
			{
				WIDTH / 2.0f, HEIGHT / 2.0f, RECT_SIZE, RECT_SIZE
			}, 
			Directions[distrib(mt)%Size], SPEED, Colors[i%Colors.size()], 0
		});
	}
	
	bool Running = true;
	while (Running)
	{
		if (IsKeyPressed(KEY_ESCAPE)) Running = false;


		for (auto& a : Agents)
		{
			vec2 DistanceMoved = vec2_times_scalar(a.Direction, a.Speed);
			a.DistanceSinceTurn += VectorLength(DistanceMoved);
			if (a.DistanceSinceTurn >= MAX_DISTANCE_BEFORE_TURNING)
			{
				f32 Excess = a.DistanceSinceTurn - MAX_DISTANCE_BEFORE_TURNING;
				f32 Rest = VectorLength(DistanceMoved) - Excess;
				vec2 RestDirection = vec2_times_scalar(a.Direction, Rest);

				a.Rect.x += RestDirection.x;
				a.Rect.y += RestDirection.y;
				vec2 PrevDirection = a.Direction;
				while (true)
				{
					a.Direction = Directions[distrib(mt)%Size];
					f32 Delta = VectorLength(add_vec2(a.Direction, PrevDirection));
					if (Delta != 0) break;
				}

				DistanceMoved = vec2_times_scalar(a.Direction, Excess);
				a.DistanceSinceTurn = Excess;
			}
			
			a.Rect.x += DistanceMoved.x;
			a.Rect.y += DistanceMoved.y;
			
		}
		BeginDrawing();
			for (auto& a : Agents) DrawRectangleRec(a.Rect, a.Color);
		EndDrawing();

	}
	CloseWindow();
	return 0;
}


e_DIRECTION_MODE resolve_argument(std::string arg)
{
	e_DIRECTION_MODE ret = ERR;
	if (arg == "NORMAL") ret = NORMAL_DIR;
	if (arg == "DIAGONAL") ret = DIAGONAL_DIR;
	if (arg == "BOTH") ret = BOTH;
	return ret;
}
