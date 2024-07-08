#!/bin/bash

if [ -d "build" ]; then
    cp build/bin/branchApp ~/usr/bin/
    cp build/lib/libbranch.so ~/usr/lib/
else
    echo "Folder 'build' not found"
fi
