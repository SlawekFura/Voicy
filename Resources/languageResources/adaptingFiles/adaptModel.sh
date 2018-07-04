rm -r ../adapted_cmusphinx-en-us-ptm-5.2  
cp -r cmusphinx* ../adapted_cmusphinx-en-us-ptm-5.2  
ADAPTED_DIR=../adapted_cmusphinx-en-us-ptm-5.2  
LANGUAGE_RESOURCES_PATH="/home/slawek/workspace/SpeechRecognition/Voicy/Resources/languageResources"
DICTIONARY_PATH="$LANGUAGE_RESOURCES_PATH/LanguageAndAcousticModel/base.dic"
BW_PATH="/home/slawek/workspace/SpeechRecognition/sphinxtrain/src/programs/bw/bw"
MAP_ADAPT_PATH="/home/slawek/workspace/SpeechRecognition/sphinxtrain/src/programs/map_adapt/map_adapt"

$BW_PATH -hmmdir $ADAPTED_DIR -moddeffn $ADAPTED_DIR/mdef.txt -ts2cbfn .ptm.  -feat 1s_c_d_dd  -svspec 0-12/13-25/26-38 -cmn current  -agc none  -dictfn $DICTIONARY_PATH  -ctlfn arctic.fileids  -lsnfn arctic.transcription  -accumdir .

$MAP_ADAPT_PATH -moddeffn cmusphinx-en-us-ptm-5.2/mdef -ts2cbfn .ptm. -meanfn cmusphinx-en-us-ptm-5.2/means -varfn cmusphinx-en-us-ptm-5.2/variances -mixwfn cmusphinx-en-us-ptm-5.2/mixture_weights -tmatfn cmusphinx-en-us-ptm-5.2/transition_matrices -accumdir . -mapmeanfn $ADAPTED_DIR/means -mapvarfn $ADAPTED_DIR/variances -mapmixwfn $ADAPTED_DIR/mixture_weights -maptmatfn $ADAPTED_DIR/transition_matrices
