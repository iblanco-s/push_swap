#!/bin/bash

num_numbers=5 # Cambiar este valor para cambiar la cantidad de números por combinación

for i in {1..100}
do
  # Genera una cadena aleatoria de números negativos y positivos
  args=""
  for j in $(seq 1 $num_numbers)
  do
    if (( RANDOM % 2 )); then
      args+="$(($RANDOM * -1))"
    else
      args+="$RANDOM"
    fi
    args+=" "
  done
  # echo $args
  # Ejecuta el comando y guarda la salida
  # output=$(./push_swap $args | ./checker_OS $args)
	output=$(./push_swap $args | wc -l)
  # Comprueba si hay error
#   if [[ $output == "Error" ]]; then
#     echo "Combination $i: ERROR"
# 	echo $args
#   fi
  # Comprueba si la salida es correcta
#   if [[ $output == "OK" ]]; then
#     # echo "Combination $i: OK"
# 	:
#   else
#     # echo "Combination $i: KO"
#     # echo $output
# 	# guarda en una variable todas las veces que falla
# 	l=$((l+1))
#   fi
	echo $output = $args
done
echo "Combinations KO: $l/100"
