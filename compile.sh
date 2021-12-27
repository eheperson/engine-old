apt-get install cowsay
cowsay "hello motherfucker"

buildDIR="./build"

# delete and re-create build directory at every time
# if [ ! -d ${buildDIR} ]; then
#   mkdir ${buildDIR}
# else
#   rm -r ${buildDIR}
#   mkdir ${buildDIR}
# fi

# create build dir if dows not exists
if [ ! -d ${buildDIR} ]; then
  mkdir ${buildDIR}
fi

# -----------------------------------
#       CONFIGURE
# -----------------------------------
echo ""
echo " Configure Begin"
echo ""

# cmake -G "MinGW Makefiles" -DUSE_EXAMPLELIB=ON -S . -B ./build
# cmake -DUSE_EXAMPLELIB=ON -S . -B ./build
cmake  -S . -B ./build 


echo ""
echo " Configure End"
echo ""

# -----------------------------------
#       BUILD
# -----------------------------------
echo ""
echo " Build Begin"
echo ""

cd build
cmake --build . -v  
# or 
# mingw32-make
cd ..

echo ""
echo " Build End"
echo ""