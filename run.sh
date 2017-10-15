#!/bin/bash

nice python -u classify_all.py $1 > $2
echo "Classifying all with dataset $1 is complete. It may have failed horribly, or it may have run to completion--probably the former, looking at the stats. Go look at it yourself; you can find results in file $2." | mail -s "Job complete." mgs9y@virginia.edu
rm *.pyc
