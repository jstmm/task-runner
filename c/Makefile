all: task_runner

task_runner: *.c
	mkdir -p build/
	gcc -g -o build/task_runner *.c

clean:
	echo "Cleaning up..."
	rm -rvf build/**
