# Random Walk
Is a generator of multiple agents (squares) moving ranodmly on the window generating beautiful patterns.
<img width="462" height="460" alt="Normal" src="https://github.com/user-attachments/assets/201bca98-6c89-4232-89a2-a3c2ebe23fef" />

# Build
You will need Raylib, MSVC and Cmake
```sh
git clone https://github.com/MeMetoCoco3/RandomWalk.git
cd RandomWalk
cmake -B build
cmake --build build --config Release
./build/Release/random_walk
```
# Usage
Press 'C' to clean screen.
Command line usage:
			random_walk [flags]
			Flags :
			-n, --numAgents	Define number of agents to draw.
			-m, --mode         Define mode of agent directions. Accepted NORMAL, DIAGONAL, BOTH.
