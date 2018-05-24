git clone https://github.com/assimp/assimp.git ./assimp

cd assimp
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX="./install" -G "Visual Studio 15 2017 Win64"
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\devenv.com" /build release "Assimp.sln"