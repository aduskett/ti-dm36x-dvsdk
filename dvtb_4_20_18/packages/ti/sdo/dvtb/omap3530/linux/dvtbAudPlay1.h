/*
 * dvtbAudPlay1.h
 *
 * XDM1.0 Audio Decode Functionality interfaces
 *
 * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#ifndef _DVEVM_ST_AUD_PLAY1_H
#define _DVEVM_ST_AUD_PLAY_H

#include "dvtbGlobal.h"
#include "dvtbThread.h"
#include <semaphore.h>

#define AUD_OUTBUF_COUNT 8
#define AUD_FRAME_BUFF_SIZE 2880

typedef struct AudioBufDesc
{
	char *aud_outBuffer;
	int aud_bufSize;
} AudioBufDesc;

typedef enum PlayTskState
{
	CREATED = 0,
	RUNNING,
	EXITING,
	DELETED
} PlayTskState;


void
dvtb_AudDec1Play(DvevmStThreadInfo *T);

DvevmStRetCode
dvtb_audDec1SemOpen(sem_t **sem_in, sem_t **sem_out, sem_t **sem_block);

void
dvtb_audDec1SemClose(sem_t *sem_in, sem_t *sem_out, sem_t *sem_block);

void
dvtb_audDec1SemInit(sem_t *sem_in, int valIn, sem_t *sem_out, int valOut, sem_t *sem_block, int valBlock);

void
dvtb_audDec1InitThread(pthread_attr_t *attr, struct sched_param *param);

DvevmStRetCode
dvtb_audDec1AllocPlayThreadBuffs(AudioBufDesc *audioDesc, int size, int numBuff);

void
dvtb_audDec1InitPlayThreadBuffs(AudioBufDesc *audioDesc, int numBuff);

void
dvtb_audDec1FreePlayThreadBuffs(AudioBufDesc *audioDesc, int size, int numBuff);

int
dvtb_audDec1getOutPutBytes(IAUDDEC1_Status *adecStatus);

DvevmStRetCode
dvtb_audDec1ReadInput(char *inBuffer, int *totalBytesConsumed, int *bytesRemaining, int buffsize, FILE *fp, int *nBytes);

#endif
