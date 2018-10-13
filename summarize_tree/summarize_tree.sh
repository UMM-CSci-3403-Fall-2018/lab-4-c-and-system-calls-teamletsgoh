#!/bin/bash

path = $1

# Counting the number of directories
directories=$(find $path -type d -print | wc -w | xargs)

# Counting the number of regular files
files=$(find $path -type f -print | wc -w | xargs)

# Show results
printf "There were %d directories.\n" $directories
printf "There were %d regular files.\n" $files
