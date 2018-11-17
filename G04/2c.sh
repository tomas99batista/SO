#!/bin/bash
function numeric_to_string()
{
    if (($1 == $2)) ; then
        echo "Iguais"
        return 0

    elif (($1 > $2)) ; then
        echo "arg1 maior que arg2"
        return 1

    else
        echo "arg1 menor que arg2"
        return 2
    fi
    
}
numeric_to_string $1 $2