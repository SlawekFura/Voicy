SCRIPT_PATH="$( cd "$(dirname "$0")" ; pwd -P )"``
ADAPTED_PATH="$(dirname "$SCRIPT_PATH")/adapted_cmusphinx-en-us-ptm-5.2"
/home/slawek/workspace/SpeechRecognition/sphinxbase/src/sphinx_fe/sphinx_fe -argfile $ADAPTED_PATH/feat.params -samprate 16000 -c $SCRIPT_PATH/arctic.fileids -di . -do . -ei wav -eo mfc -mswav yes
