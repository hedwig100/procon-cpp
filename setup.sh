#!/bin/sh

export ATCODER_CONTEST=$1
source venv/bin/activate
python3 snippets_generator.py
make setup
echo "Complete Setup for contest $1"