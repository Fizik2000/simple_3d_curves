all: curves run

curves:
	mkdir -p build
	cd build && cmake ..
	cd build && cmake --build .

run:
	cd build && ./curves

format:
	clang-format -i header/*.h source/*.cc

clean:
	rm -rf build
