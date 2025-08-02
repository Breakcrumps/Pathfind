all: \
	build/hash build/filework build/print build/BasicPathfinder build/Grid build/Pos build/Benchmark build/HeuristicComparator \
	build/AStar build/HeuristicGrid \
	types/StepNode.h wrappers/UnorderedMap.h solution/Pathfinder.h types/HeuristicPos.h types/HeuristicNode.h

	g++ -O2 build/* program.cpp -o program

bench: \
	build/hash build/filework build/print build/BasicPathfinder build/Grid build/Pos build/Benchmark build/HeuristicComparator \
	build/AStar build/HeuristicGrid \
	types/StepNode.h wrappers/UnorderedMap.h solution/Pathfinder.h types/HeuristicPos.h types/HeuristicNode.h

	g++ -O2 build/* libs/src/nanobench.o program.cpp -o program

build/hash: extensions/hash.cpp extensions/hash.h
	g++ -O2 -c extensions/hash.cpp -o build/hash

build/HeuristicComparator: extensions/HeuristicComparator.cpp extensions/HeuristicComparator.h
	g++ -O2 -c extensions/HeuristicComparator.cpp -o build/HeuristicComparator

build/filework: IO/filework.cpp IO/filework.h
	g++ -O2 -c IO/filework.cpp -o build/filework

build/print: IO/print.cpp IO/print.h
	g++ -O2 -c IO/print.cpp -o build/print

build/BasicPathfinder: solution/strategies/BasicPathfinder.cpp solution/strategies/BasicPathfinder.h
	g++ -O2 -c solution/strategies/BasicPathfinder.cpp -o build/BasicPathfinder

build/AStar: solution/strategies/AStar.cpp solution/strategies/AStar.h
	g++ -O2 -c solution/strategies/AStar.cpp -o build/AStar

build/Grid: types/Grid.cpp types/Grid.h
	g++ -O2 -c types/Grid.cpp -o build/Grid

build/HeuristicGrid: types/HeuristicGrid.cpp types/HeuristicGrid.h
	g++ -O2 -c types/HeuristicGrid.cpp -o build/HeuristicGrid

build/Pos: types/Pos.cpp
	g++ -O2 -c types/Pos.cpp -o build/Pos

build/Benchmark: testing/Benchmark.cpp testing/Benchmark.h
	g++ -O2 -c testing/Benchmark.cpp -o build/Benchmark

clean:
	rm -f build/* program.exe
