/*
 * dvtbAACHEEnc1.c
 *
 * XDM1.0 AACHE Encode Interface implementation
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

#include "dvtbAACHEEnc1.h"
#include "dvtbMemory.h"

void
dvtb_aacheCreateDebug(DvevmStAacHeEnc1Info *aace)
{
	SYS_DEBUG("\tHandle  : %s\n", aace->aacenc1Name);
	SYS_DEBUG("\tHandle  : %d\n", (int) aace->ceHdl);
	SYS_DEBUG("\tBase size  : %d\n", (int) aace->aacenc1Params.audenc_params.size);
	SYS_DEBUG("\tBase sample Rate  : %d\n", (int) aace->aacenc1Params.audenc_params.sampleRate);
	SYS_DEBUG("\tBase bitRate   :%d \n", (int) aace->aacenc1Params.audenc_params.bitRate);
	SYS_DEBUG("\tBase channel Mode : %d\n", (int) aace->aacenc1Params.audenc_params.channelMode);
	SYS_DEBUG("\tBase endianness : %d\n", (int) aace->aacenc1Params.audenc_params.dataEndianness);
	SYS_DEBUG("\tBase encmode : %d\n", (int) aace->aacenc1Params.audenc_params.encMode);
	SYS_DEBUG("\tBase input format : %d\n", (int) aace->aacenc1Params.audenc_params.inputFormat);
	SYS_DEBUG("\tBase inp bits :%d\n", (int) aace->aacenc1Params.audenc_params.inputBitsPerSample);
	SYS_DEBUG("\tBase maxbitrate : %d\n", (int) aace->aacenc1Params.audenc_params.maxBitRate);
	SYS_DEBUG("\tBase dual mono :%d\n", (int) aace->aacenc1Params.audenc_params.dualMonoMode);
	SYS_DEBUG("\tBase CRC flag : %d\n", (int) aace->aacenc1Params.audenc_params.crcFlag);
	SYS_DEBUG("\tBase ancflag :%d\n", (int) aace->aacenc1Params.audenc_params.ancFlag);
	SYS_DEBUG("\tBase lfe flag:%d\n", (int) aace->aacenc1Params.audenc_params.lfeFlag);
	SYS_DEBUG("\tExt outobjtype:%d\n", aace->aacenc1Params.outObjectType);
	SYS_DEBUG("\tExt OFF :%d\n", aace->aacenc1Params.outFileFormat);
	SYS_DEBUG("\tExt UseTns :%d\n", aace->aacenc1Params.useTns);
	SYS_DEBUG("\tExt UsePNS :%d\n", aace->aacenc1Params.usePns);
	SYS_DEBUG("\tExt downmix : %d\n", aace->aacenc1Params.downMixFlag);
	SYS_DEBUG("\tExt bitrate mode : %d\n", aace->aacenc1Params.bitRateMode);
	SYS_DEBUG("\tExtAncRate :%d\n", (int) aace->aacenc1Params.ancRate);
	SYS_DEBUG("\tInbufsize :%d\n", (int) aace->inBuf.descs[0].bufSize);
	SYS_DEBUG("\tOutbufsize :%d\n", (int) aace->outBuf.descs[0].bufSize);
	SYS_DEBUG("\tEntering create\n");
}

void
dvtb_aacheProcessDebug(DvevmStAacHeEnc1Info *aace)
{
	SYS_DEBUG("\enc name  : %s\n", aace->aacenc1Name);
	SYS_DEBUG("\tHandle  : %d\n", (int) aace->ceHdl);
	SYS_DEBUG("\tBase size  : %d\n", (int) aace->aacenc1Params.audenc_params.size);
	SYS_DEBUG("\tBase sample Rate  : %d\n", (int) aace->aacenc1Params.audenc_params.sampleRate);
	SYS_DEBUG("\tBase bitRate   :%d \n", (int) aace->aacenc1Params.audenc_params.bitRate);
	SYS_DEBUG("\tBase channel Mode : %d\n", (int) aace->aacenc1Params.audenc_params.channelMode);
	SYS_DEBUG("\tBase endianness : %d\n", (int) aace->aacenc1Params.audenc_params.dataEndianness);
	SYS_DEBUG("\tBase encmode : %d\n", (int) aace->aacenc1Params.audenc_params.encMode);
	SYS_DEBUG("\tBase input format : %d\n", (int) aace->aacenc1Params.audenc_params.inputFormat);
	SYS_DEBUG("\tBase inp bits :%d\n", (int) aace->aacenc1Params.audenc_params.inputBitsPerSample);
	SYS_DEBUG("\tBase maxbitrate : %d\n", (int) aace->aacenc1Params.audenc_params.maxBitRate);
	SYS_DEBUG("\tBase dual mono :%d\n", (int) aace->aacenc1Params.audenc_params.dualMonoMode);
	SYS_DEBUG("\tBase CRC flag : %d\n", (int) aace->aacenc1Params.audenc_params.crcFlag);
	SYS_DEBUG("\tBase ancflag :%d\n", (int) aace->aacenc1Params.audenc_params.ancFlag);
	SYS_DEBUG("\tBase lfe flag:%d\n", (int) aace->aacenc1Params.audenc_params.lfeFlag);
	SYS_DEBUG("\tExt outobjtype:%d\n", aace->aacenc1Params.outObjectType);
	SYS_DEBUG("\tExt OFF :%d\n", aace->aacenc1Params.outFileFormat);
	SYS_DEBUG("\tExt UseTns :%d\n", aace->aacenc1Params.useTns);
	SYS_DEBUG("\tExt UsePNS :%d\n", aace->aacenc1Params.usePns);
	SYS_DEBUG("\tExt downmix : %d\n", aace->aacenc1Params.downMixFlag);
	SYS_DEBUG("\tExt bitrate mode : %d\n", aace->aacenc1Params.bitRateMode);
	SYS_DEBUG("\tExtAncRate :%d\n", (int) aace->aacenc1Params.ancRate);
	SYS_DEBUG("\tancbufsize :%d\n", aace->ancBuf.size);
	SYS_DEBUG("\tHandle  : %d\n", (int) aace->aacenc1Hdl);
	SYS_DEBUG("\tEntering process call\n");
}

void
dvtb_controlenterDebug(DvevmStAacHeEnc1Info *aace)
{
	SYS_DEBUG("################ENTERING CONTROL CALL#########################\n");

	SYS_DEBUG("\enc name  : %s\n", aace->aacenc1Name);
	SYS_DEBUG("\tHandle  : %d\n", (int) aace->ceHdl);
	SYS_DEBUG("\tBase size  : %d\n", (int) aace->aacenc1Params.audenc_params.size);
	SYS_DEBUG("\tBase sample Rate  : %d\n", (int) aace->aacenc1Params.audenc_params.sampleRate);
	SYS_DEBUG("\tBase bitRate   :%d \n", (int) aace->aacenc1Params.audenc_params.bitRate);
	SYS_DEBUG("\tBase channel Mode : %d\n", (int) aace->aacenc1Params.audenc_params.channelMode);
	SYS_DEBUG("\tBase endianness : %d\n", (int) aace->aacenc1Params.audenc_params.dataEndianness);
	SYS_DEBUG("\tBase encmode : %d\n", (int) aace->aacenc1Params.audenc_params.encMode);
	SYS_DEBUG("\tBase input format : %d\n", (int) aace->aacenc1Params.audenc_params.inputFormat);
	SYS_DEBUG("\tBase inp bits :%d\n", (int) aace->aacenc1Params.audenc_params.inputBitsPerSample);
	SYS_DEBUG("\tBase maxbitrate : %d\n", (int) aace->aacenc1Params.audenc_params.maxBitRate);
	SYS_DEBUG("\tBase dual mono :%d\n", (int) aace->aacenc1Params.audenc_params.dualMonoMode);
	SYS_DEBUG("\tBase CRC flag : %d\n", (int) aace->aacenc1Params.audenc_params.crcFlag);
	SYS_DEBUG("\tBase ancflag :%d\n", (int) aace->aacenc1Params.audenc_params.ancFlag);
	SYS_DEBUG("\tBase lfe flag:%d\n", (int) aace->aacenc1Params.audenc_params.lfeFlag);
	SYS_DEBUG("\tExt outobjtype:%d\n", aace->aacenc1Params.outObjectType);
	SYS_DEBUG("\tExt OFF :%d\n", aace->aacenc1Params.outFileFormat);
	SYS_DEBUG("\tExt UseTns :%d\n", aace->aacenc1Params.useTns);
	SYS_DEBUG("\tExt UsePNS :%d\n", aace->aacenc1Params.usePns);
	SYS_DEBUG("\tExt downmix : %d\n", aace->aacenc1Params.downMixFlag);
	SYS_DEBUG("\tExt bitrate mode : %d\n", aace->aacenc1Params.bitRateMode);
	SYS_DEBUG("\tExtAncRate :%d\n", (int) aace->aacenc1Params.ancRate);
	SYS_DEBUG("\tInbufsize :%d\n", (int) aace->inBuf.descs[0].bufSize);
	SYS_DEBUG("\tOutbufsize :%d\n", (int) aace->outBuf.descs[0].bufSize);
	SYS_DEBUG("\tancbufsize :%d\n", aace->ancBuf.size);
	SYS_DEBUG("\tCmd id :%d\n", aace->aenc1Cmd);
}
void
dvtb_controlexitDebug(DvevmStAacHeEnc1Info *aace)
{
	SYS_DEBUG("################LEFT CONTROL CALL#########################\n");

	SYS_DEBUG("\t#####STATUS##########################\n");
	SYS_DEBUG("\tobj type:%d\n", aace->aacenc1Status.outputObjectType);
	SYS_DEBUG("\tOFF :%d\n", aace->aacenc1Status.outFileFormat);
	SYS_DEBUG("\tsize:%d\n", (int) aace->aacenc1Status.audenc_status.size);
	SYS_DEBUG("\tEerror:%d\n", (int) aace->aacenc1Status.audenc_status.extendedError);
	SYS_DEBUG("\tvalidflag:%d\n", (int) aace->aacenc1Status.audenc_status.validFlag);
	SYS_DEBUG("\tlfeflag:%d\n", (int) aace->aacenc1Status.audenc_status.lfeFlag);
	SYS_DEBUG("\tbitRate:%d\n", (int) aace->aacenc1Status.audenc_status.bitRate);
	SYS_DEBUG("\tsampleRate:%d\n", (int) aace->aacenc1Status.audenc_status.sampleRate);
	SYS_DEBUG("\tchannelMode:%d\n", (int) aace->aacenc1Status.audenc_status.channelMode);
	SYS_DEBUG("Minimum inBufs :%d\n", (int) aace->aacenc1Status.audenc_status.bufInfo.minNumInBufs);
	SYS_DEBUG("Minimum outBufs :%d\n", (int) aace->aacenc1Status.audenc_status.bufInfo.minNumOutBufs);
	SYS_DEBUG("Minimum inBuf size :%d\n", (int) aace->aacenc1Status.audenc_status.bufInfo.minInBufSize[0]);
	SYS_DEBUG("Minimum outBuf size :%d\n", (int) aace->aacenc1Status.audenc_status.bufInfo.minOutBufSize[0]);
	SYS_DEBUG("\t#####END OF STATUS##########################\n");
}

void
dvtb_aacheEnc1Cleanup(DvevmStAacHeEnc1Info *aace)
{
	if (NULL != aace->aacenc1Hdl)
		AUDENC1_delete((AUDENC1_Handle) aace->aacenc1Hdl);

	aace->aacenc1Hdl = NULL;

	if (aace->inBuf.numBufs > 0)
		dvtb_freeCmemXdm1BufDesc(&aace->inBuf);

	if (aace->outBuf.numBufs > 0)
		dvtb_freeCmemXdm1BufDesc(&aace->outBuf);

	if (NULL != aace->ancBuf.start)
		dvtb_freeSingleBufCmem(aace->ancBuf.start, aace->ancBuf.size);
}

DvevmStRetCode
dvtb_aacheEnc1Init(DvevmStAacHeEnc1Info *aace)
{
	DvevmStRetCode retCode = DVEVM_ST_SUCCESS;
	ASSERT(aace != NULL);
	ASSERT(aace->ceHdl != NULL);
	ASSERT(aace->aacenc1Name[0] != 0);

	aace->ancBuf.start = NULL;
	aace->inBuf.numBufs = 0;
	aace->outBuf.numBufs = 0;

	dvtb_aacheCreateDebug(aace);
	if (NULL == (aace->aacenc1Hdl = (IAACENC_Handle) AUDENC1_create(aace->ceHdl, aace->aacenc1Name, (IAUDENC1_Params *) &aace->aacenc1Params)))
	{
		SYS_ERROR("Unable to initialize Audio Encoder\n");
		retCode = DVEVM_ST_FAIL;
	}
	else
	{
		aace->aenc1Cmd = XDM_SETPARAMS;
		aace->ancBuf.size = 14;
		if (DVEVM_ST_FAIL == dvtb_aacheEnc1Control(aace))
		{
			SYS_ERROR("Unable to set the dynamic parameters \n");
			retCode = DVEVM_ST_FAIL;
		}
		else
		{
			aace->aenc1Cmd = XDM_GETBUFINFO;
			if (DVEVM_ST_FAIL == dvtb_aacheEnc1Control(aace))
			{
				SYS_ERROR("Unable to get the input/output buffer information\n");
				retCode = DVEVM_ST_FAIL;
			}
			else if (DVEVM_ST_FAIL == dvtb_allocCmemXdm1BufDesc(&aace->inBuf))
			{
				SYS_ERROR("Unable to allocate memory for In Buffer\n");
				retCode = DVEVM_ST_FAIL;
			}
			else if (DVEVM_ST_FAIL == dvtb_allocCmemXdm1BufDesc(&aace->outBuf))
			{
				SYS_ERROR("Unable to allocate memory for Out Buffer\n");
				retCode = DVEVM_ST_FAIL;
			}
			else if (NULL == (aace->ancBuf.start = Memory_contigAlloc(aace->ancBuf.size, Memory_DEFAULTALIGNMENT)))
			{
				SYS_ERROR("Unable to allocate memory for Out Buffer\n");
				retCode = DVEVM_ST_FAIL;
			}
			else
			{
				SYS_DEBUG("\tAudio Encoder %s initialized.\n", aace->aacenc1Name);
				memcpy(aace->ancBuf.start, "DVTB Encoded", aace->ancBuf.size);
				SYS_DEBUG("\tancBuf.start :%x\n", (unsigned int) aace->ancBuf.start);
			}
		}
	}
	if(DVEVM_ST_FAIL == retCode)
		dvtb_aacheEnc1Cleanup(aace);
	return retCode;
}

DvevmStRetCode
dvtb_aacheEnc1Encode(DvevmStAacHeEnc1Info *aace, int *encDuration)
{
	XDAS_Int32 status = -1;
	IAACENC_InArgs enc1InArgs;
	IAACENC_OutArgs enc1OutArgs;
	DvevmStTime timeStmpBfrEnc, timeStmpAftrEnc;
	DvevmStRetCode retCode = DVEVM_ST_SUCCESS;
	ASSERT(aace != NULL);
	ASSERT(aace->ceHdl != NULL);
	ASSERT(aace->aacenc1Hdl != NULL);

	enc1OutArgs.audenc_outArgs.size = sizeof(IAACENC_OutArgs);

	enc1InArgs.audenc_inArgs.size = sizeof(IAACENC_InArgs);
	enc1InArgs.audenc_inArgs.numInSamples = aace->insamples;
	if (aace->aacenc1Params.audenc_params.ancFlag)
	{
		enc1InArgs.audenc_inArgs.ancData.bufSize = aace->ancBuf.size;
		enc1InArgs.audenc_inArgs.ancData.buf = (XDAS_Int8 *) aace->ancBuf.start;
	}
	else
	{
		enc1InArgs.audenc_inArgs.ancData.bufSize = 0;
		enc1InArgs.audenc_inArgs.ancData.buf = NULL;
	}

	dvtb_aacheProcessDebug(aace);

	timeStmpBfrEnc = dvtb_getTime( );
	status = AUDENC1_process((AUDENC1_Handle) aace->aacenc1Hdl, &aace->inBuf, &aace->outBuf, (IAUDENC1_InArgs *) &enc1InArgs, (IAUDENC1_OutArgs *) &enc1OutArgs);
	timeStmpAftrEnc = dvtb_getTime( );

	*encDuration = ((timeStmpAftrEnc.tv_sec * NUM_MICROSECS_IN_SEC) + timeStmpAftrEnc.tv_usec) - ((timeStmpBfrEnc.tv_sec * NUM_MICROSECS_IN_SEC) + timeStmpBfrEnc.tv_usec);

	aace->Framenum++;

	SYS_DEBUG("\tCurr frame number : %d\n", aace->Framenum);

	aace->outsamples = enc1OutArgs.audenc_outArgs.bytesGenerated;

	if (status != IAUDENC1_EOK)
	{
		SYS_ERROR("Error (%d) in Audio Encoder Process\n", (int) status);
		SYS_ERROR("Codec Error => %d\n", (int) enc1OutArgs.audenc_outArgs.extendedError);

		retCode = DVEVM_ST_FAIL;
	}
	if (DVEVM_ST_FAIL != retCode)
	{

		aace->aenc1Cmd = XDM_GETSTATUS;

		if (DVEVM_ST_FAIL == dvtb_aacheEnc1Control(aace))
		{
			SYS_ERROR("Unable to get status info\n");
		}
		SYS_DEBUG("\tBytes Generated after STATUSCALL=> %d\n", (int) enc1OutArgs.audenc_outArgs.bytesGenerated);
	}

	return retCode;
}

DvevmStRetCode
dvtb_aacheEnc1Control(DvevmStAacHeEnc1Info *aace)
{
	DvevmStRetCode retCode = DVEVM_ST_SUCCESS;
	int status = -1, i = 0;

	ASSERT(aace != NULL);
	ASSERT(aace->aacenc1Hdl != NULL);
	dvtb_controlenterDebug(aace);

	status = AUDENC1_control((AUDENC1_Handle) aace->aacenc1Hdl, aace->aenc1Cmd, (IAUDENC1_DynamicParams *) &aace->aacenc1DynParams, (IAUDENC1_Status *) &aace->aacenc1Status);

	if (IAUDENC1_EOK != status)
	{
		SYS_ERROR("Audio Encode Control failed (%d)\n", status);
		retCode = DVEVM_ST_FAIL;
	}
	else
	{
		if (XDM_GETBUFINFO == aace->aenc1Cmd)
		{
			aace->inBuf.numBufs = aace->aacenc1Status.audenc_status.bufInfo.minNumInBufs;
			aace->outBuf.numBufs = aace->aacenc1Status.audenc_status.bufInfo.minNumOutBufs;

			for (i = 0; i < aace->inBuf.numBufs; i++)
				aace->inBuf.descs[i].bufSize = aace->aacenc1Status.audenc_status.bufInfo.minInBufSize[i];

			for (i = 0; i < aace->outBuf.numBufs; i++)
				aace->outBuf.descs[i].bufSize = aace->aacenc1Status.audenc_status.bufInfo.minOutBufSize[i];
		}

		SYS_DEBUG("Audio Encode Control => Command : %d\n", aace->aenc1Cmd);
		dvtb_controlexitDebug(aace);
	}
	return retCode;
}

DvevmStRetCode
dvtb_aacheEnc1Close(DvevmStAacHeEnc1Info *aace)
{
	DvevmStRetCode retCode = DVEVM_ST_SUCCESS;
	dvtb_aacheEnc1Cleanup(aace);
	return retCode;
}
