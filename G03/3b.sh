#!/bin/bash

if [[ -d $1 ]];
#if [[ -x $1 ]];
then
    echo "é uma diretoria"
else
    echo "nao e diretoria"
fi
