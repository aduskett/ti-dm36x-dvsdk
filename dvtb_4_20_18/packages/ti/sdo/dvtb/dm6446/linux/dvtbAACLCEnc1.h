/*
 * dvtbAACLCEnc1.h
 *
 * XDM1.0 AACLC Encode Interface
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

#ifndef _DVEVM_ST_AACLC_ENC1_H
#define _DVEVM_ST_AACLC_ENC1_H

#include "dvtbGlobal.h"
#include "dvtbEngine.h"
#include <ti/sdo/ce/audio1/audenc1.h>
#include "dvtbAACEncExtParams.h"

#define AACLCENC1_FRAME_SIZE          (1024)//(80)
#define AACLCENC1_MAX_SR              (64000) //(16000)
#define AACLCENC1_BR                  (48000)
#define AACLCENC1_SR                  (44100)
#define AACLCENC1_MAX_BR              (192000)
#define AACLCENC1_MODE                (0)
#define AACLCENC1_BPS                 (16)
#define AACLCENC1_DMONO               (0)
#define AACLCENC1_CRC                 (0)
#define AACLCENC1_ANC                 (1)
#define AACLCENC1_LFE                 (0)
#define AACLCENC1_MAX_CH              (2) //(1)
#define AACLCENC1_MAX_BR              (192000) //(AACENC_MAX_SR*AACENC_MAX_CH*16)  /* Assuming 16bits per sample */
#define AACLCENC1_INBUF_SIZE          (8192)//(1648)//(4096)
#define AACLCENC1_OUTBUF_SIZE         (3000)
#define AACLCENC1_DMIX                (0)
#define AACLCENC1_OTYPE               (AACENC_OBJ_TYP_LC)
#define AACLCENC1_OFF                 (AACENC_TT_ADTS)
#define AACLCENC1_ARATE               (-1)
#define AACLCENC1_BRM                 (1)
#define DEFAULT_AACLCENC1_TIME        (10)

typedef struct
{

	char aacenc1Name[MAX_NAME_LEN];

	IAACENC_Params aacenc1Params;
	IAUDENC1_Cmd aenc1Cmd;
	IAACENC_DynamicParams aacenc1DynParams;
	IAACENC_Status aacenc1Status;
	IAACENC_InArgs aacenc1InArgs;
	IAACENC_OutArgs aacenc1OutArgs;

	XDM1_BufDesc inBuf;
	XDM1_BufDesc outBuf;

	DvevmStBuffer ancBuf;

	Engine_Handle ceHdl;
	AUDENC1_Handle aacenc1Hdl;
	unsigned int seconds; /* Number of seconds for audio capture */
	unsigned int outsamples;
	unsigned int insamples;
	volatile int Framenum;

} DvevmStAacLcEnc1Info;

DvevmStRetCode
dvtb_aaclcEnc1Init(DvevmStAacLcEnc1Info *aace);

DvevmStRetCode
dvtb_aaclcEnc1Encode(DvevmStAacLcEnc1Info *aace, int *encDuration);

void
dvtb_aaclcEnc1Cleanup(DvevmStAacLcEnc1Info *aace);

DvevmStRetCode
dvtb_aaclcEnc1Control(DvevmStAacLcEnc1Info *aace);

DvevmStRetCode
dvtb_aaclcEnc1Close(DvevmStAacLcEnc1Info *aace);

#endif
