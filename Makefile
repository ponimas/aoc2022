all:
	g++ -std=c++20 -I$(HOME)/projects/vcpkg/installed/x64-linux/include $(day).cpp
	./a.out input/$(day).txt

test:
	g++ -std=c++20 -I$(HOME)/projects/vcpkg/installed/x64-linux/include $(day).cpp
	./a.out input/test.txt
