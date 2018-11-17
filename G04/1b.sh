#!/bin/bash
function imprime_msg()
{
    echo "Data:"
    date
    echo "Nome do PC: "
    hostname
    echo "User: "
    echo $USER
    return 0
}
imprime_msg 