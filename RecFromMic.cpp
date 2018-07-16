#include "RecFromMic.h"
#include "StateMachine.h"
#include "StringToEnumConverter.h"
#include <iostream>
#include <cctype>
#include "Festival.h"

extern cmd_ln_t *config;
extern ps_decoder_t *ps;

StateMachine* s_stateMachine = new StateMachine();
Festival* Festival::s_instance = 0;

/* Sleep for specified msec */
static void sleep_msec(int32 ms)
{
#if (defined(_WIN32) && !defined(GNUWINCE)) || defined(_WIN32_WCE)
	Sleep(ms);
#else
	/* ------------------- Unix ------------------ */
	struct timeval tmo;

	tmo.tv_sec = 0;
	tmo.tv_usec = ms * 1000;

	select(0, NULL, NULL, NULL, &tmo);
#endif
}

/*
* Main utterance processing loop:
*     for (;;) {
*        start utterance and wait for speech to process
*        decoding till end-of-utterance silence will be detected
*        print utterance result;
*     }
*/
void recognize_from_microphone(cmd_ln_t *p_config, ps_decoder_t *p_ps)
{
	ad_rec_t *ad;
	int16 adbuf[2048];
	uint8 utt_started, in_speech;
	int32 k;
	char const *hyp;

	prepareRecognizeFromMicrophone(p_config, p_ps, ad, utt_started);
    Festival::instance(ad);

    std::cout<<"DUPA1"<<std::endl;
	while (1) 
	{
		if ((k = ad_read(ad, adbuf, 2048)) < 0)
			E_FATAL("Failed to read audio\n");
		ps_process_raw(p_ps, adbuf, k, FALSE, FALSE);
		in_speech = ps_get_in_speech(p_ps);
		if (in_speech && !utt_started) 
		{
			utt_started = TRUE;
			E_INFO("Listening...\n");
		}
		if (!in_speech && utt_started) 
		{
			/* speech -> silence transition, time to start new utterance  */
			ps_end_utt(p_ps);
			hyp = ps_get_hyp(p_ps, NULL);
			std::cout<<"########## recognised word: "<< hyp << " ###############"<<std::endl;
			if (hyp != NULL) 
			{
				std::string l_foundString, l_recognitionString(hyp);
				for (auto elem : s_commands)
				{
					if (l_recognitionString.find(elem) != std::string::npos)
					{
						l_foundString = elem;
						break;
					}
				}
				
			    //std::cout<<"########## recognised command: "<< s_stringPhonemsToStringConverter[l_foundString] << " ###############"<<std::endl;
				s_stateMachine->handleInput(s_stringPhonemsToStringConverter[l_foundString]);
				fflush(stdout);
			}

			if (ps_start_utt(p_ps) < 0)
				E_FATAL("Failed to start utterance\n");
			utt_started = FALSE;
			E_INFO("Ready....\n");
		}
		sleep_msec(10);
	}
	ad_close(ad);
}

void prepareRecognizeFromMicrophone(cmd_ln_t *p_config, ps_decoder_t *p_ps, ad_rec_t * &ad, uint8 &utt_started)
{
	if ((ad = ad_open_dev(cmd_ln_str_r(p_config, "-adcdev"),
		(int)cmd_ln_float32_r(p_config,
			"-samprate"))) == NULL)
		E_FATAL("Failed to open audio device\n");
	if (ad_start_rec(ad) < 0)
		E_FATAL("Failed to start recording\n");

	if (ps_start_utt(p_ps) < 0)
		E_FATAL("Failed to start utterance\n");
	utt_started = FALSE;
	E_INFO("Ready....\n");
}
