#!/bin/zsh
select fname in *.c
do
  gcc -o ${fname%.c} $fname
  ./${fname%.c} 
  break
done