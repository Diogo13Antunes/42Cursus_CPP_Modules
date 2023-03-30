#!/bin/bash

# Args
# -> Min Limit
# -> Max Limit
# -> Amount nbrs

echo `shuf -i $1-$2 -n $3 | tr "\n" " "`
