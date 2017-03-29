#!/bin/sh

mkdir includes
mkdir srcs
mkdir lib
touch Makefile
cat ../corewar/Real_corewar/Makefile >> Makefile
touch includes/$1.h
touch srcs/$1.c
ln -s ../../lib/ft lib/ft
echo "#ifndef _H"
echo "# define _H"
echo "# include \"libft.h\"" >> includes/$1.h
echo "#endif"
echo "#include \"$1.h\"" >> srcs/$1.c
git add -A
git commit -m \"master: new project $1\"
git push origin master
