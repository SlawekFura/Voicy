import os
import sys

newWord = str(sys.argv[1])
newWordPhonetic = str(sys.argv[2])

isShoppingItem = bool(input("Please write \"1\" if shopping, else \"0\": ")) 

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


voicyWordConverterPath = '../FSMs/Include/StringToEnumConverter.h'
with open(voicyWordConverterPath, 'r+') as f:
    content = f.readlines()

    ordinaryPart = [[], [], [], []]
    setLinesPart = [[], [], []]
    
    ordinaryPartNum = 0;
    setPartNum = 0;
    isCommandString = False;
    for lineNum in range(0, len(content)):
        if isCommandString:
            setLinesPart[setPartNum] += content[lineNum]
        else:
            ordinaryPart[ordinaryPartNum] += content[lineNum]
    
        if isCommandString == False and 'static' in content[lineNum]:
            isCommandString = True
            ordinaryPartNum += 1
    
        elif isCommandString == True and ',' != content[lineNum][-2]: 
            isCommandString = False
            setPartNum +=1
    
    newFile = "";
    for item in range(0, 3):
        #print str(''.join(ordinaryPart[item]))
        if(item == 0):
            setLinesPart[0] += "".join("\t\"" + newWordPhonetic.upper() + "\",\n")
        if(item == 1 and isShoppingItem):
            setLinesPart[1]  += "".join("\t\"" + newWord.upper() + ",\n")
        if(item == 2):
            setLinesPart[2] += "".join("\t{ \"" + newWordPhonetic.upper() + "\",\t" + "\"" + newWord.upper() + "\"\t\t},\n")

        setLinesPart[item] = "".join(setLinesPart[item])
        setSth = setLinesPart[item].splitlines(True)
        setSth.sort(key=lambda x: x.split('"')[1])
        #print str("".join(setSth))
        print str(setSth)
        newFile += ''.join(ordinaryPart[item]) + "".join(setSth)
    
    print str("".join(ordinaryPart[3]))
    newFile += "".join(ordinaryPart[3])
    
    print str("".join(newFile))
    
    f.seek(0)
    f.truncate(0)
    f.write(newFile)
