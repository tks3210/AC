#!/bin/bash
#./makedir.sh [contest name]
contest_name=$1
if [ ! -e $contest_name ] 
then
    mkdir $contest_name
fi
first=$(printf "%d" \'$2)
end=$(printf "%d" \'$3)


while [ $first -le $end ]
do
  HEX=$(printf "%x" ${first})
  PREFIX=$(printf "\x${HEX}")
  ARRAY+=("$PREFIX")
  first=$(( $first + 1 ))
done

for i in ${ARRAY[@]}
do
    cp Template.cpp "${contest_name}/${contest_name}_$i.cpp"
done