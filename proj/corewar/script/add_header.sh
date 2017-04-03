#!/bin/bash

DIR_SRC="src"
DIR_INC="includes"

SRCS=$(ls $DIR_SRC | grep "\.c" | grep -v "\~")
for FILE in $SRCS
do
    echo $FILE
    /usr/bin/vim +Stdheader +wq "$DIR_SRC/$FILE"
done

INCS=$(ls $DIR_INC | grep "\.h" | grep -v "\~")
for FILE in $INCS
do
    echo $FILE
    /usr/bin/vim +Stdheader +wq "$DIR_INC/$INCS"
done