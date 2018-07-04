newWord=$1
newWordPhonetically=$2

if [ $# -eq 0 ]
  then
    exit "No arguments supplied"
fi

python addWord.py $newWord $newWordPhonetically
sort ../Resources/languageResources/wordlist.txt -o ../Resources/languageResources/wordlist.txt
sort ../Resources/languageResources/adaptingFiles/arctic.fileids -o ../Resources/languageResources/adaptingFiles/arctic.fileids
sort ../Resources/languageResources/adaptingFiles/arctic.transcription -t '(' -o ../Resources/languageResources/adaptingFiles/arctic.transcription
arecord -d 13 -f cd -r16000 -c1 ../Resources/languageResources/adaptingFiles/$newWord.wav

cd ../Resources/languageResources/adaptingFiles
bash generateAcousticFeatureFiles.sh
