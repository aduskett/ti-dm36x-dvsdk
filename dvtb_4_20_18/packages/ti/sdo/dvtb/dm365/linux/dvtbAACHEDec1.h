/*
 * dvtbAACHEDec1.h
 *
 * XDM1.0 AACHE Decoder Interface
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

#ifndef _DVEVM_ST_AACHE_DEC1_H
#define _DVEVM_ST_AACHE_DEC1_H

#include "dvtbGlobal.h"
#include "dvtbEngine.h"
#include "dvtbDefs.h"
#include <ti/sdo/ce/audio1/auddec1.h>
#include <ti/xdais/ialg.h>
#include <ti/xdais/dm/iauddec1.h>

typedef struct ITTIAM_ENHAACPDEC_Params 
{
	IAUDDEC1_Params auddec_params;
	XDAS_Int32 i_max_channels; 
	XDAS_Int32 i_flag_08khz_out; 
	XDAS_Int32 i_flag_16khz_out; 
	XDAS_Int32 i_interleave; 
	XDAS_Int32 i_mp4_flag; 
	XDAS_Int32 i_disable_sync; 
	XDAS_Int32 i_auto_sbr_upsample; 
	XDAS_Int32 i_sampfreq; 
	XDAS_Int32 i_coupling_channel;
}IAACDEC_Params;

typedef struct ITTIAM_ENHAACPDEC_DynamicParams 
{
	IAUDDEC1_DynamicParams auddec_dynamicparams;
	
}IAACDEC_DynamicParams;

typedef struct ITTIAM_ENHAACPDEC_Status
{
	IAUDDEC1_Status  auddec_status;
	XDAS_Int32 i_channel_mask; 
	XDAS_Int32 i_channel_mode; 
	XDAS_Int32 i_sbr_mode; 
	XDAS_Int32 i_num_channels;
}IAACDEC_Status;

typedef struct ITTIAM_ENHAACPDEC_InArgs
{
	IAUDDEC1_InArgs auddec_inArgs;
	
}IAACDEC_InArgs;

typedef struct ITTIAM_ENHAACPDEC_OutArgs
{
	IAUDDEC1_OutArgs  auddec_outArgs;
	XDAS_Int32 i_init_done; 
	XDAS_Int32 i_exec_done; 
	XDAS_Int32 i_ittiam_err_code ; 
	XDAS_Int32 i_output_bits_per_sample; 
	XDAS_Int32 i_num_channels; 
	XDAS_Int32 i_channel_mask;
}IAACDEC_OutArgs;

typedef struct
{
	char adecName[MAX_NAME_LEN];
	IAACDEC_Params adecParams;

	IAUDDEC1_Cmd adecCmd;
	IAACDEC_DynamicParams adecDynParams;
	IAACDEC_Status adecStatus;
	IAACDEC_InArgs adecInArgs;
	IAACDEC_OutArgs adecOutArgs;

	int desiredChannelMode;
	int inFrameSize;
	int decFrameSize;
	unsigned int pEnable;

	DvevmStXdmBuffer inBuf;
	DvevmStXdmBuffer outBuf;

	Engine_Handle ceHdl;
	AUDDEC1_Handle adecHdl;
} DvevmStAacheDec1Info;

DvevmStRetCode
dvtb_aacheDec1Init(DvevmStAacheDec1Info *ad);

DvevmStRetCode
dvtb_aacheDec1Decode(DvevmStAacheDec1Info *ad, int *decDuration);

DvevmStRetCode
dvtb_aacheDec1Control(DvevmStAacheDec1Info *ad);

void
dvtb_aacheDec1Cleanup(DvevmStAacheDec1Info *ad);

DvevmStRetCode
dvtb_aacheDec1Close(DvevmStAacheDec1Info *ad);

#endif