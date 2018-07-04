import requests
import sys
import os, re
import shutil
import glob

def purge(dir, pattern):
    for f in os.listdir(dir):
        if re.search(pattern, f):
            objectPath = os.path.join(dir, f) 
            if os.path.isfile(objectPath):
                os.remove(os.path.join(dir, f))
            else:
                shutil.rmtree(objectPath)

import os, sys, tarfile

def extract(tar_url, extract_path='.'):
    dirname = os.path.dirname(__file__)
    newpath = os.path.join(dirname, extract_path)
    if not os.path.exists(newpath):
        os.makedirs(newpath)
    tar = tarfile.open(tar_url, 'r')
    for item in tar:
        tar.extract(item, newpath)
        if item.name.find(".tgz") != -1 or item.name.find(".tar") != -1:
            extract(item.name, "./" + item.name[:item.name.rfind('/')])

def rename(dir, pattern, titlePattern):
    for pathAndFilename in glob.iglob(os.path.join(dir, pattern)):
        title, ext = os.path.splitext(os.path.basename(pathAndFilename))
        os.rename(pathAndFilename, 
                  os.path.join(dir, titlePattern + ext))


successCode = 200

projectPath = os.path.abspath(__file__ + "/../../")
print "projectPath = " + projectPath
languageResourcesPath =  projectPath + '/Resources/languageResources/'
url = "http://www.speech.cs.cmu.edu/cgi-bin/tools/lmtool/run"
files = {'corpus': open(languageResourcesPath + 'wordlist.txt', 'rb')}
payload = {'formtype': 'simple' }

r = requests.post(url, data=payload, files=files)
 
if r.status_code != successCode:
    print "Sending wordlist file for processing unsuccesfull!"
    sys.exit()
else:
    print "Sending wordlist file for processing succesfull!"

begin = "http"
end = ".tgz"
address =  begin + (r.text.split(begin))[1].split(end)[0] + end

r = requests.get(address)

purge(languageResourcesPath, 'LanguageAndAcousticModel')

beginName = "TAR"
endName = ".tgz"
tarNumber =  (address.split(beginName))[1].split(endName)[0]
tarFilename =  beginName + tarNumber + endName

print tarFilename
with open(tarFilename, "wb") as code:
    code.write(r.content)

try:
    extract(tarFilename, languageResourcesPath + '/LanguageAndAcousticModel')
    print 'Done.'
except:
    name = os.path.basename(sys.argv[0])
    print name[:name.rfind('.')], '<filename>'

scriptPath = os.path.abspath(__file__ + "/../")
purge(scriptPath, 'TAR.*')

rename(languageResourcesPath + '/LanguageAndAcousticModel', r'*.*', r'base') 
