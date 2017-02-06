#!/bin/bash

bn=$1

if test -z $bn
then
    echo "Uso: $0 executavel"
    exit
fi

if test ! -x $bn
then
    echo "Ficheiro $bn nao e um executavel"
    exit
fi

for i in *.in
do
    echo -n ${i%%.in}
    echo -n ' '
    { $bn < $i; } &> /dev/null
    if diff res ${i%%.in}.out &> /dev/null
    then
        echo ok
    else
        echo no
    fi
done
