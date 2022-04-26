#!/bin/bash
set -e

echo; echo "Database project configuration..."
cmake -S init_db -B init_db/build -DCMAKE_BUILD_TYPE=Release

echo; echo "Building database project..."
cmake --build init_db/build -- -j8

echo; echo; echo "Running init_db..."
./init_db/build/init_db

echo; echo "init_db run successfully " 
