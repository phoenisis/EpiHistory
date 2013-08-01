

all:
	@cd ..; tar -xf SFML-2.0-rc-linux-64.tar.bz2; cd -
	g++ *.cpp -I ../SFML-2.0-rc/include/ -L ../SFML-2.0-rc/lib/ -Wl,--rpath=../SFML-2.0-rc/lib/ -lsfml-network -lsfml-system
