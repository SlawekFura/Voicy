#pragma once

#include <sphinxbase/err.h>
#include "pocketsphinx.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sphinxbase/ad.h>


#if defined(_WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#else
#include <sys/select.h>
#endif

void prepareRecognizeFromMicrophone(cmd_ln_t *p_config, ps_decoder_t *p_ps, ad_rec_t * &ad, uint8 &utt_started);
static void sleep_msec(int32 ms);
void recognize_from_microphone(cmd_ln_t *p_config, ps_decoder_t *p_ps);