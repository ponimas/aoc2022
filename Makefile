all:
	g++ -std=c++20 \
	-I$(HOME)/projects/vcpkg/installed/x64-linux/include \
	-I$(HOME)/projects/vcpkg/installed/arm64-osx/include \
	-L$(HOME)/projects/vcpkg/installed/x64-linux/lib \
	-L$(HOME)/projects/vcpkg/installed/arm64-osx/lib \
	-lfmt \
	$(day).cpp
	./a.out input/$(day).txt

test:
	FMT_HEADER_ONLY=1 g++ -std=gnu++20 \
	-I$(HOME)/projects/vcpkg/installed/x64-linux/include \
	-I$(HOME)/projects/vcpkg/installed/arm64-osx/include \
	-L$(HOME)/projects/vcpkg/installed/x64-linux/lib \
	-L$(HOME)/projects/vcpkg/installed/arm64-osx/lib \
	-lfmt \
	$(day).cpp
	./a.out input/test.txt
