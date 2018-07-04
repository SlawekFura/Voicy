import os
import sys

newWord = str(sys.argv[1])
newWordPhonetic = str(sys.argv[2])

print "New word: " + newWord 
print "New word phonetically: " + newWordPhonetic 

wordlistPath = '../Resources/languageResources/wordlist.txt'
arcticFilesPath = '../Resources/languageResources/adaptingFiles'

arcticFileIds = open(arcticFilesPath + '/arctic.fileids', 'a')
arcticFileIds.write(newWord)
arcticFileIds.close()

arcticFileIds = open(arcticFilesPath + '/arctic.transcription', 'a')
lineToWrite = "<s>"
for i in range(7):
   lineToWrite += " " + newWordPhonetic.upper() 
lineToWrite += "\t</s>(" + newWord + ")"
arcticFileIds.write(lineToWrite)
arcticFileIds.close()

wordlist = open(wordlistPath, 'a')
wordlist.write(newWordPhonetic)
wordlist.close()

