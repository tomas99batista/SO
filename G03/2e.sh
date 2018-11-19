#!/bin/bash
# Conditional block if

if (( $1 > 5 )) && (( $1 < 10 )) ; then
    echo "numero maior do que 5 e menor do que 10"
else
    echo "nope, fora disso"
fi