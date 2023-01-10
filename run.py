import sys
import fileinput
from os import listdir, system
import pathlib

def run_cmd(i):
    cmd = '/mnt/home/jmedrala/j-pet-framework-examples/build/NewAnalysis/LargeBarrelAnalysis.x -t mcGeant -f ' + i + ' -o ../output/ -p conf_trb3.xml -u /mnt/home/jmedrala/workspace/userParams_mc.json -i 9 -l /mnt/home/jmedrala/j-pet-framework-examples/CalibrationFiles/9_RUN/detectorSetupRun9.json'
    system(cmd)

listOfFiles = []
for line in fileinput.input(sys.argv[1:]):
    lineArgs = line.strip()
    lineArgs = lineArgs.replace(" ","")
    listOfFiles.append(lineArgs)

#print(listOfFiles)
for item in listOfFiles:
    print(item)
    run_cmd(item)

