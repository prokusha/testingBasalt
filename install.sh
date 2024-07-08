#!/bin/bash

if [ -d "build" ]; then
    cp build/bin/branchApp /usr/bin/branchApp
    cp build/lib/libbranch.so /usr/lib/libbranch.so.1.0.0
else
    echo "Folder 'build' not found"
fi
