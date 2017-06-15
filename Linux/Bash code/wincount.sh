#!/bin/bash

matchCount=0
runCount=0
secs=10                        # Set interval (duration) in seconds.
endTime=$(( $(date +%s) + secs )) # Calculate end time.

while [ $(date +%s) -lt $endTime ]; do  # Loop until interval has elapsed.
	(( runCount++ ))
	case $(./program) in
		*\[seven\]\ \[seven\]\ \[seven\]* ) (( matchCount++ )) ;;
	esac
done
echo "runCount=(( runCount ))"
echo "matchCount=(( matchCount ))"

