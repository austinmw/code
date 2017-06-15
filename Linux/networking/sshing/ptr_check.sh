#!/bin/bash
rm my_ptr.txt
touch my_ptr.txt
dig +noall +answer -x `ipconfig getifaddr en0` >> my_ptr.txt