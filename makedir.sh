#!/bin/sh
#./makedir.sh [contest name]
contest_name=$1
mkdir $contest_name
for i in a b c d
do
    cp Template.cpp "${contest_name}/${contest_name}_$i.cpp"
done