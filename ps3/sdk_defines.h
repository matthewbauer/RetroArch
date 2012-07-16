/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2012 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2012 - Daniel De Matteis
 * 
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _PS3_SDK_DEFINES_H
#define _PS3_SDK_DEFINES_H

/*============================================================
	AUDIO PROTOTYPES
============================================================ */

#ifdef __PSL1GHT__
/* define all the audio/audio port functions */
#define cellAudioQuit audioQuit
#define cellAudioInit audioInit
#define cellAudioPortStart audioPortStart
#define cellAudioPortOpen audioPortOpen
#define cellAudioPortClose audioPortClose
#define cellAudioPortStop audioPortStop
#define CellAudioPortParam audioPortParam
#define cellAudioPortOpen audioPortOpen
#define cellAudioAddData audioAddData

/* define all the event queue functions */
#define sys_event_queue_receive sysEventQueueReceive
#define cellAudioSetNotifyEventQueue audioSetNotifyEventQueue
#define cellAudioRemoveNotifyEventQueue audioRemoveNotifyEventQueue
#define cellAudioCreateNotifyEventQueue audioCreateNotifyEventQueue

/* define all the lightweight mutex functions */
#define sys_lwmutex_destroy sysLwMutexDestroy
#define sys_lwmutex_lock sysLwMutexLock
#define sys_lwmutex_unlock sysLwMutexUnlock
#define sys_lwmutex_create sysLwMutexCreate

/* define all the lightweight condition functions */
#define sys_lwcond_create sysLwCondCreate
#define sys_lwcond_destroy sysLwCondDestroy
#define sys_lwcond_wait sysLwCondWait
#define sys_lwcond_signal sysLwCondSignal

#define CELL_AUDIO_BLOCK_SAMPLES AUDIO_BLOCK_SAMPLES
#define SYS_NO_TIMEOUT 0
#define param_attrib attrib
#define sys_lwmutex_attribute_t sys_lwmutex_attr_t
#define sys_lwcond_attribute_t sys_lwcond_attr_t

#else
#define numChannels nChannel
#define numBlocks nBlock
#define param_attrib attr

#endif

/*============================================================
	INPUT PAD PROTOTYPES
============================================================ */

#ifdef __PSL1GHT__
/* define all the ps3 pad structs */
#define CellPadInfo2 padInfo2
#define CellPadData padData

/* define all the ps3 pad functions */
#define cellPadGetInfo2 ioPadGetInfo2
#define cellPadGetData ioPadGetData
#define cellPadInit ioPadInit
#define cellPadEnd ioPadEnd

#define now_connect connected
#endif

/*============================================================
	INPUT MOUSE PROTOTYPES
============================================================ */

#ifdef HAVE_MOUSE

#ifdef __PSL1GHT__
/* define ps3 mouse structs */
#define CellMouseInfo mouseInfo
#define CellMouseData mouseData

/* define all the ps3 mouse functions */
#define cellMouseInit ioMouseInit
#define cellMouseGetData ioMouseGetData
#define cellMouseEnd ioMouseEnd
#define cellMouseGetInfo ioMouseGetInfo

/* PSL1GHT does not define these in its header */
#define CELL_MOUSE_BUTTON_1 (1 << 0) /* Button 1 */
#define CELL_MOUSE_BUTTON_2 (1 << 1) /* Button 2 */
#define CELL_MOUSE_BUTTON_3 (1 << 2) /* Button 3 */
#define CELL_MOUSE_BUTTON_4 (1 << 3) /* Button 4 */
#define CELL_MOUSE_BUTTON_5 (1 << 4) /* Button 5 */
#define CELL_MOUSE_BUTTON_6 (1 << 5) /* Button 6 */
#define CELL_MOUSE_BUTTON_7 (1 << 6) /* Button 7 */
#define CELL_MOUSE_BUTTON_8 (1 << 7) /* Button 8 */

#endif

#endif

/*============================================================
	OSK PROTOTYPES
============================================================ */

#ifdef HAVE_OSKUTIL

#ifdef __PSL1GHT__
/* define all the OSK functions */
#define pOskLoadAsync oskLoadAsync
#define pOskSetLayoutMode oskSetLayoutMode
#define pOskSetKeyLayoutOption oskSetKeyLayoutOption
#define pOskGetSize oskGetSize
#define pOskDisableDimmer oskDisableDimmer
#define pOskAbort oskAbort
#define pOskUnloadAsync oskUnloadAsync

/* define OSK structs / types */
#define sys_memory_container_t sys_mem_container_t
#define CellOskDialogPoint oskPoint
#define CellOskDialogInputFieldInfo oskInputFieldInfo
#define CellOskDialogCallbackReturnParam oskCallbackReturnParam
#define CellOskDialogParam oskParam

#define osk_allowed_panels allowedPanels
#define osk_prohibit_flags prohibitFlags

#define osk_inputfield_message message
#define osk_inputfield_starttext startText
#define osk_inputfield_max_length maxLength
#define osk_callback_return_param res
#define osk_callback_num_chars len
#define osk_callback_return_string str

/* define the OSK defines */
#define CELL_OSKDIALOG_10KEY_PANEL OSK_10KEY_PANEL
#define CELL_OSKDIALOG_FULLKEY_PANEL OSK_FULLKEY_PANEL
#define CELL_OSKDIALOG_LAYOUTMODE_X_ALIGN_CENTER OSK_LAYOUTMODE_HORIZONTAL_ALIGN_CENTER
#define CELL_OSKDIALOG_LAYOUTMODE_Y_ALIGN_TOP OSK_LAYOUTMODE_VERTICAL_ALIGN_TOP
#define CELL_OSKDIALOG_PANELMODE_NUMERAL OSK_PANEL_TYPE_NUMERAL
#define CELL_OSKDIALOG_PANELMODE_NUMERAL_FULL_WIDTH OSK_PANEL_TYPE_NUMERAL_FULL_WIDTH
#define CELL_OSKDIALOG_PANELMODE_ALPHABET OSK_PANEL_TYPE_ALPHABET
#define CELL_OSKDIALOG_PANELMODE_ENGLISH OSK_PANEL_TYPE_ENGLISH
#define CELL_OSKDIALOG_INPUT_FIELD_RESULT_OK (0)
#define CELL_OSKDIALOG_INPUT_FIELD_RESULT_CANCELED (1)
#define CELL_OSKDIALOG_INPUT_FIELD_RESULT_ABORT (2)
#define CELL_OSKDIALOG_INPUT_FIELD_RESULT_NO_INPUT_TEXT (3)
#define CELL_OSKDIALOG_STRING_SIZE (512)
#else
/* define all the OSK functions */
#define pOskLoadAsync cellOskDialogLoadAsync
#define pOskSetLayoutMode cellOskDialogSetLayoutMode
#define pOskSetKeyLayoutOption cellOskDialogSetKeyLayoutOption
#define pOskGetSize cellOskDialogGetSize
#define pOskDisableDimmer cellOskDialogDisableDimmer
#define pOskAbort cellOskDialogAbort
#define pOskUnloadAsync cellOskDialogUnloadAsync

/* define OSK structs / types */
#define osk_allowed_panels allowOskPanelFlg
#define osk_prohibit_flags prohibitFlgs
#define osk_inputfield_message message
#define osk_inputfield_starttext init_text
#define osk_inputfield_max_length limit_length
#define osk_callback_return_param result
#define osk_callback_num_chars numCharsResultString
#define osk_callback_return_string pResultString
#endif

#endif

/*============================================================
	JPEG/PNG DECODING/ENCODING PROTOTYPES
============================================================ */

#ifdef __PSL1GHT__
/* define all of the JPEG/PNG structs */
#define CellJpgDecMainHandle int
#define CellPngDecMainHandle int
#define CellJpgDecSubHandle int
#define CellPngDecSubHandle int
#define CellJpgDecThreadInParam jpgDecThreadInParam
#define CellPngDecThreadInParam pngDecThreadInParam
#define CellJpgDecThreadOutParam jpgDecThreadOutParam
#define CellPngDecThreadOutParam pngDecThreadOutParam
#define CellJpgDecSrc jpgDecSource
#define CellPngDecSrc pngDecSource
#define CellJpgDecOpnInfo uint32_t
#define CellPngDecOpnInfo uint32_t
#define CellJpgDecInfo jpgDecInfo
#define CellPngDecInfo pngDecInfo
#define CellJpgDecInParam jpgDecInParam
#define CellPngDecInParam pngDecInParam
#define CellJpgDecOutParam jpgDecOutParam
#define CellPngDecOutParam pngDecOutParam
#define CellJpgDecDataOutInfo jpgDecDataInfo
#define CellPngDecDataOutInfo pngDecDataInfo
#define CellJpgDecDataCtrlParam uint64_t
#define CellPngDecDataCtrlParam uint64_t

#define spu_enable enable
#define stream_select stream
#define color_alpha alpha
#define color_space space
#define output_mode mode
#define output_bytes_per_line bytes_per_line
#define output_width width
#define output_height height

/* define all of the JPEG/PNG functions */
#define cellJpgDecCreate jpgDecCreate
#define cellJpgDecOpen jpgDecOpen
#define cellJpgDecReadHeader jpgDecReadHeader
#define cellJpgDecSetParameter jpgDecSetParameter
#define cellJpgDecDecodeData jpgDecDecodeData
#define cellJpgDecClose jpgDecClose
#define cellJpgDecDestroy jpgDecDestroy

#define cellPngDecCreate pngDecCreate
#define cellPngDecOpen pngDecOpen
#define cellPngDecReadHeader pngDecReadHeader
#define cellPngDecSetParameter pngDecSetParameter
#define cellPngDecDecodeData pngDecDecodeData
#define cellPngDecClose pngDecClose
#define cellPngDecDestroy pngDecDestroy

/* define all of the JPEG/PNG defines */
#define CELL_PNGDEC_SPU_THREAD_ENABLE 1
#define CELL_JPGDEC_SPU_THREAD_ENABLE 1
#define CELL_JPGDEC_FILE JPGDEC_FILE
#define CELL_PNGDEC_FILE PNGDEC_FILE
#define CELL_JPGDEC_SPU_THREAD_ENABLE 1
#define CELL_JPGDEC_FAST JPGDEC_LOW_QUALITY
#define CELL_JPGDEC_TOP_TO_BOTTOM JPGDEC_TOP_TO_BOTTOM
#define CELL_PNGDEC_TOP_TO_BOTTOM PNGDEC_TOP_TO_BOTTOM
#define CELL_JPG_ARGB JPGDEC_ARGB
#define CELL_PNGDEC_ARGB PNGDEC_ARGB
#define CELL_JPGDEC_DEC_STATUS_FINISH 0
#define CELL_PNGDEC_DEC_STATUS_FINISH 0
#define CELL_PNGDEC_1BYTE_PER_1PIXEL 1
#define CELL_PNGDEC_STREAM_ALPHA 1
#define CELL_OK 0
#define PTR_NULL 0

#else
/* define the JPEG/PNG struct member names */
#define spu_enable spuThreadEnable
#define ppu_prio ppuThreadPriority
#define spu_prio spuThreadPriority
#define malloc_func cbCtrlMallocFunc
#define malloc_arg cbCtrlMallocArg
#define free_func cbCtrlFreeFunc
#define free_arg cbCtrlFreeArg
#define stream_select srcSelect
#define file_name fileName
#define file_offset fileOffset
#define file_size fileSize
#define stream_ptr streamPtr
#define stream_size streamSize
#define down_scale downScale
#define color_alpha outputColorAlpha
#define color_space outputColorSpace
#define cmd_ptr commandPtr
#define quality method
#define output_mode outputMode
#define output_bytes_per_line outputBytesPerLine
#define output_width outputWidth
#define output_height outputHeight
#define bit_depth outputBitDepth
#define pack_flag outputPackFlag
#define alpha_select outputAlphaSelect

#define PTR_NULL NULL

#endif

/*============================================================
	THREADING PROTOTYPES
============================================================ */

#ifdef __PSL1GHT__
/* define all the thread functions  */
#define sys_ppu_thread_create sysThreadCreate
#define sys_ppu_thread_join sysThreadJoin
#define sys_ppu_thread_exit sysThreadExit

#define SYS_PPU_THREAD_CREATE_JOINABLE 0 /* FIXME - not sure if this is correct */
#endif

/*============================================================
	MEMORY PROTOTYPES
============================================================ */

#ifdef __PSL1GHT__
#define sys_memory_container_create sysMemContainerCreate
#define sys_memory_container_destroy sysMemContainerDestroy
#endif

/*============================================================
	RSX PROTOTYPES
============================================================ */

#ifdef __PSL1GHT__
#define CELL_GCM_FALSE GCM_FALSE
#define CELL_GCM_TRUE GCM_TRUE

#define CELL_GCM_TEXTURE_NEAREST GCM_TEXTURE_NEAREST

#define CELL_GCM_ONE GCM_ONE
#define CELL_GCM_ZERO GCM_ZERO

#define CELL_GCM_SMOOTH GCM_SMOOTH

#define CellGcmSurface gcmSurface
#define CellGcmTexture gcmTexture

#define cellGcmSetWaitFlip gcmSetWaitFlip
#define cellGcmFlush rsxFlushBuffer
#define cellGcmSetFlipMode gcmSetFlipMode
#define cellGcmSetFlip gcmSetFlip
#define cellGcmGetLabelAddress gcmGetLabelAddress
#define cellGcmUnbindTile gcmUnbindTile
#define cellGcmBindTile gcmBindTile
#define cellGcmSetTileInfo gcmSetTileInfo
#define cellGcmAddressToOffset gcmAddressToOffset
#endif

#endif
