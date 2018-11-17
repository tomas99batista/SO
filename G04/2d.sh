#!/bin/bash
function compare()
{
    if [[ $r -eq 0 ]]
    then
        echo "Iguais"
        
    elif [[ $r -eq 1 ]] 
    then
        echo "arg1 maior que arg2"
        
    else
        echo "arg1 menor que arg2"
    fi
    
}
echo "insira 2 nums"
read n1
read n2
compare $n1 $n2 
r=$?
