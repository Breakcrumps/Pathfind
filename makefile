all: \
	build/hash build/filework build/print build/BasicPathfinder build/Grid build/Pos build/benchmark build/HeuristicComparator \
	build/AStar build/HeuristicGrid \
	types/StepNode.h wrappers/UnorderedMap.h solution/Pathfinder.h types/HeuristicPos.h types/HeuristicNode.h

	g++ build/* program.cpp -o program

build/hash: extensions/hash.cpp extensions/hash.h
	g++ -c extensions/hash.cpp -o build/hash

build/HeuristicComparator: extensions/HeuristicComparator.cpp extensions/HeuristicComparator.h
	g++ -c extensions/HeuristicComparator.cpp -o build/HeuristicComparator

build/filework: IO/filework.cpp IO/filework.h
	g++ -c IO/filework.cpp -o build/filework

build/print: IO/print.cpp IO/print.h
	g++ -c IO/print.cpp -o build/print

build/BasicPathfinder: solution/strategies/BasicPathfinder.cpp solution/strategies/BasicPathfinder.h
	g++ -c solution/strategies/BasicPathfinder.cpp -o build/BasicPathfinder

build/AStar: solution/strategies/AStar.cpp solution/strategies/AStar.h
	g++ -c solution/strategies/AStar.cpp -o build/AStar

build/Grid: types/Grid.cpp types/Grid.h
	g++ -c types/Grid.cpp -o build/Grid

build/HeuristicGrid: types/HeuristicGrid.cpp types/HeuristicGrid.h
	g++ -c types/HeuristicGrid.cpp -o build/HeuristicGrid

build/Pos: types/Pos.cpp
	g++ -c types/Pos.cpp -o build/Pos

build/benchmark: testing/benchmark.cpp testing/benchmark.h
	g++ -c testing/benchmark.cpp -o build/benchmark

clean:
	rm -f build/* program.exe
