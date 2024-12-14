all: task_runner

task_runner: *.cpp
	mkdir -p build/
	g++ -std=c++23 -g -o build/task_runner *.cpp

clean:
	echo "Cleaning up..."
	rm -rvf build/**
