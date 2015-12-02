#!/bin/sh

cd ~/42_git/proj
mkdir $1
cd $1
mkdir includes
mkdir srcs
mkdir lib
touch Makefile.temp
cat ../lem_in/Makefile >> Makefile.temp
touch includes/$1.h.temp
touch srcs/$1.c.temp
cp -R ../../lib/ft lib/
echo "# include \"libft.h\"" >> includes/$1.h.temp
echo "#include \"$1.h\"" >> srcs/$1.c.temp
#git add .
#git add ./*
#git add ./*/*
#git commit -m \"master new project $1\"
#git push origin master
