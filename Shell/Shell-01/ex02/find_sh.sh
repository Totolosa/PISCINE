#!/bin/bash
find . -type f -name "*.sh" -exec basename -a -s .sh {} + 
