
#!/bin/bash
set -e  # Bail on the first error

FN_IN=./sample.txt
FN_WRAPPED=./wrapped.cc
FN_EXE=./wrapped
CC=g++

# Wrap the fragment in a full C++ program and compile it.
function build_wrapper () {
  cat > $FN_WRAPPED <<'EOF'
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
EOF
  cat $FN_IN >> $FN_WRAPPED
  cat >> $FN_WRAPPED <<'EOF'
return 0;
}
EOF
  $CC -o $FN_EXE $FN_WRAPPED
}

# Run the wrapper, passing input through STDIN and reading the output from STDOUT.
function run () {
  local IN=$1
  echo $IN | $FN_EXE
}

# Remove the wrapper (both code and compiled).
function clean_up () {
  rm -f $FN_WRAPPED $FN_EXE
}

build_wrapper

IN=24
OUT=$(echo "$IN" | $FN_EXE)
echo "Result = $OUT"

echo "Another result = $(run 16)"

clean_up
