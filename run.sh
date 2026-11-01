rm -rf build/
mkdir build
cd build
cmake ../
make
cd ..
cp build/conways_game_life_v0 conways_game_life_v0
rm -rf build/
./conways_game_life_v0
rm conways_game_life_v0