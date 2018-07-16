#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <festival/festival.h>

#include "RecFromMic.h"



#define MODELDIR "/home/slawek/workspace/SpeechRecognition/Voicy/Resources/languageResources/LanguageAndAcousticModel"
//#define DIRNUMBER "9112"

#define HEAP_SIZE 210000
#define LOAD_INIT_FILES 1


static ps_decoder_t *ps;
static cmd_ln_t *config;
static FILE *rawfd;


int main()
{
    festival_initialize(LOAD_INIT_FILES, HEAP_SIZE);
    err_set_logfp(NULL);

/*  config = cmd_ln_init(NULL, ps_args(), TRUE,
        "-hmm", MODELDIR "/pocketsphinx/model/en-us/en-us-adapt",
        //"-kws", MODELDIR "/keyphrase.list",
        "-lm", MODELDIR "/TAR" DIRNUMBER "/6288.lm",
        "-dict", MODELDIR "/TAR" DIRNUMBER "/6288.dic",
        NULL);*/
    //config = cmd_ln_init(NULL, ps_args(), TRUE,
    //    "-hmm", MODELDIR "/newEn/adapted",
    //    //"-kws", MODELDIR "/keyphrase.list",
    //    "-lm", MODELDIR "/TAR" DIRNUMBER "/" DIRNUMBER ".lm",
    //    "-dict", MODELDIR "/TAR" DIRNUMBER "/" DIRNUMBER ".dic",
    //    NULL);
    config = cmd_ln_init(NULL, ps_args(), TRUE,
        "-hmm", "/home/slawek/workspace/SpeechRecognition/Voicy/Resources/languageResources/adapted_cmusphinx-en-us-ptm-5.2",
        //"-kws", MODELDIR "/keyphrase.list",
        "-lm", MODELDIR "/base.lm",
        "-dict", MODELDIR "/base.dic",
        NULL);
 
    ps = ps_init(config);

    recognize_from_microphone(config, ps);

    ps_free(ps);
    cmd_ln_free_r(config);

    return 0;
}
