# Random Walk
Is a generator of multiple agents (squares) moving ranodmly on the window generating beautiful patterns.
<img width="462" height="460" alt="Normal" src="https://github.com/user-attachments/assets/201bca98-6c89-4232-89a2-a3c2ebe23fef" />
<img width="462" height="462" alt="Diagonal" src="https://github.com/user-attachments/assets/1d1ec8b9-3b72-4e71-b622-ce261762519b" />
<img width="361" height="341" alt="Both" src="https://github.com/user-attachments/assets/065242c1-4d7f-44c6-bf31-630a530217e0" />

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
